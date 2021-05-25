////////////////////////////////////////////////////////////////////////////////
// Filename: graphicsclass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "graphicsclass.h"


GraphicsClass::GraphicsClass()
{
	m_D3D = 0;
	m_Camera = 0;
	m_Model = 0;
	m_Model1 = 0;
	m_LightShader = 0;
	m_Light = 0;

	//m_Input = 0;
	//m_System = 0;
	getCard = false;

	camRotX = 0.0f;
	camRotZ = -10.0f;

	m_TextureShader = 0;
	m_Bitmap = 0;

	m_Text = 0;
}


GraphicsClass::GraphicsClass(const GraphicsClass& other)
{
}


GraphicsClass::~GraphicsClass()
{
}


bool GraphicsClass::Initialize(int screenWidth, int screenHeight, HWND hwnd)
{
	bool result;

	D3DXMATRIX baseViewMatrix;

	// Create the Direct3D object.
	m_D3D = new D3DClass;
	if (!m_D3D)
	{
		return false;
	}

	// Initialize the Direct3D object.
	result = m_D3D->Initialize(screenWidth, screenHeight, VSYNC_ENABLED, hwnd, FULL_SCREEN, SCREEN_DEPTH, SCREEN_NEAR);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize Direct3D.", L"Error", MB_OK);
		return false;
	}

	// Create the camera object.
	m_Camera = new CameraClass;
	if (!m_Camera)
	{
		return false;
	}

	// Set the initial position of the camera.
	m_Camera->SetPosition(0.0f, 0.0f, -10.0f);
	m_Camera->SetLookAt(0.0f, 0.0f, 1.0f);
	//	m_Camera->SetPosition(0.0f, 0.5f, -3.0f);

	// Create the model object.
	m_Model = new ModelClass;
	if (!m_Model)
	{
		return false;
	}

	// Initialize the model object.
	result = m_Model->Initialize(m_D3D->GetDevice(), "../CGP_Final/data/Map/map.obj", L"../CGP_Final/data/Map/model_01_AlbedoTransparency.jpg");

	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}

	// Create the model object.
	m_Model1 = new ModelClass;
	if (!m_Model1)
	{
		return false;
	}

	// Initialize the model object.
	result = m_Model1->Initialize(m_D3D->GetDevice(), "../CGP_Final/data/cube.obj", L"../CGP_Final/data/seafloor.dds");

	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}

	// Create the light shader object.
	m_LightShader = new LightShaderClass;
	if (!m_LightShader)
	{
		return false;
	}

	// Initialize the light shader object.
	result = m_LightShader->Initialize(m_D3D->GetDevice(), hwnd);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the light shader object.", L"Error", MB_OK);
		return false;
	}

	// Create the light object.
	m_Light = new LightClass;
	if (!m_Light)
	{
		return false;
	}

	// Initialize the light object.
	m_Light->SetAmbientColor(0.15f, 0.15f, 0.15f, 1.0f);
	m_Light->SetDiffuseColor(1.0f, 1.0f, 1.0f, 1.0f);
	m_Light->SetDirection(0.0f, 0.0f, 1.0f);
	m_Light->SetSpecularColor(1.0f, 1.0f, 1.0f, 1.0f);
	m_Light->SetSpecularPower(32.0f);
	
	// Create the texture shader object.
	m_TextureShader = new TextureShaderClass;
	if (!m_TextureShader)
	{
		return false;
	}

	// Initialize the texture shader object.
	result = m_TextureShader->Initialize(m_D3D->GetDevice(), hwnd);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the texture shader object.", L"Error", MB_OK);
		return false;
	}


	// Create the bitmap object.
	m_Bitmap = new BitmapClass;
	if (!m_Bitmap)
	{
		return false;
	}

	// Initialize the bitmap object.
	result = m_Bitmap->Initialize(m_D3D->GetDevice(), screenWidth, screenHeight, L"../CGP_Final/data/seafloor.dds", 256, 256);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the bitmap object.", L"Error", MB_OK);
		return false;
	}

	// Initialize a base view matrix with the camera for 2D user interface rendering.
//	m_Camera->SetPosition(0.0f, 0.0f, -1.0f);
	m_Camera->Render();
	m_Camera->GetViewMatrix(baseViewMatrix);

	// Create the text object.
	m_Text = new TextClass;
	if (!m_Text)
	{
		return false;
	}

	// Initialize the text object.
	result = m_Text->Initialize(m_D3D->GetDevice(), m_D3D->GetDeviceContext(), hwnd, screenWidth, screenHeight, baseViewMatrix);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the text object.", L"Error", MB_OK);
		return false;
	}

	return true;
}


void GraphicsClass::Shutdown()
{
	// Release the bitmap object.
	if (m_Bitmap)
	{
		m_Bitmap->Shutdown();
		delete m_Bitmap;
		m_Bitmap = 0;
	}

	// Release the texture shader object.
	if (m_TextureShader)
	{
		m_TextureShader->Shutdown();
		delete m_TextureShader;
		m_TextureShader = 0;
	}

	// Release the light object.
	if (m_Light)
	{
		delete m_Light;
		m_Light = 0;
	}

	// Release the light shader object.
	if (m_LightShader)
	{
		m_LightShader->Shutdown();
		delete m_LightShader;
		m_LightShader = 0;
	}

	// Release the model object.
	if (m_Model)
	{
		m_Model->Shutdown();
		delete m_Model;
		m_Model = 0;
	}

	// Release the model object.
	if (m_Model1)
	{
		m_Model1->Shutdown();
		delete m_Model1;
		m_Model1 = 0;
	}

	// Release the camera object.
	if (m_Camera)
	{
		delete m_Camera;
		m_Camera = 0;
	}

	// Release the D3D object.
	if (m_D3D)
	{
		m_D3D->Shutdown();
		delete m_D3D;
		m_D3D = 0;
	}

	// Release the text object.
	if (m_Text)
	{
		m_Text->Shutdown();
		delete m_Text;
		m_Text = 0;
	}

	return;
}


bool GraphicsClass::Frame(int mouseX, int mouseY, int fps, int cpu, float frameTime)
{
	bool result;
	static float rotation = 0.0f;
	
	// Update the rotation variable each frame.
	rotation += (float)D3DX_PI * 0.005f;
	if (rotation > 360.0f)
	{
		rotation -= 360.0f;
	}

	// Set the location of the mouse.
	result = m_Text->SetMousePosition(mouseX, mouseY, m_D3D->GetDeviceContext());
	if (!result)
	{
		return false;
	}

	// Set the frames per second.
	result = m_Text->SetFps(fps, m_D3D->GetDeviceContext());
	if (!result)
	{
		return false;
	}

	// Set the cpu usage.
	result = m_Text->SetCpu(cpu, m_D3D->GetDeviceContext());
	if (!result)
	{
		return false;
	}

	// Render the graphics scene.
	result = Render(rotation);
	if (!result)
	{
		return false;
	}

	camRotX += m_Camera->GetMoveZ() * 1.5f * sin(m_Camera->GetRotY());
	camRotX += m_Camera->GetMoveX() * 1.5f * cos(m_Camera->GetRotY());

	camRotZ += m_Camera->GetMoveZ() * 1.5f * cos(m_Camera->GetRotY());
	camRotZ += m_Camera->GetMoveX() * 1.5f * -sin(m_Camera->GetRotY());

	/*if (((m_Model->GetModelPosition(1).x <= camRotX || m_Model->GetModelPosition(1).x >= camRotX) && 
		(m_Model->GetModelPosition(1).z <= camRotZ || m_Model->GetModelPosition(1).z >= camRotZ)))
	{
		m_Camera->SetPosition(camRotX, 0.0f, camRotZ);
	}*/
	m_Camera->SetPosition(camRotX, 100.0f, camRotZ);

	if ((m_Camera->GetPosition().x >= -0.5f && m_Camera->GetPosition().x <= 0.5f) && (m_Camera->GetPosition().z >= 4.5f && m_Camera->GetPosition().z <= 5.5f))
	{
		getCard = true;
	}
	
	return true;
}

//bool GraphicsClass::Frame(int fps, int cpu, float frameTime)
//{
//	bool result;
//	static float rotation = 0.0f;
//
//	// Update the rotation variable each frame.
//	rotation += (float)D3DX_PI * 0.005f;
//	if (rotation > 360.0f)
//	{
//		rotation -= 360.0f;
//	}
//
//	// Set the frames per second.
//	result = m_Text->SetFps(fps, m_D3D->GetDeviceContext());
//	if (!result)
//	{
//		return false;
//	}
//
//	// Set the cpu usage.
//	result = m_Text->SetCpu(cpu, m_D3D->GetDeviceContext());
//	if (!result)
//	{
//		return false;
//	}
//
//	// Render the graphics scene.
//	result = Render(rotation);
//	if (!result)
//	{
//		return false;
//	}
//
//	// Set the position of the camera.
////	m_Camera->SetPosition(0.0f, 0.0f, -10.0f); 
//
//	return true;
//}

bool GraphicsClass::Render(float rotation)
{
	D3DXMATRIX worldMatrix, worldMatrix1, worldMatrix2, worldMatrix3, worldMatrix4, worldMatrix5, worldMatrix6, viewMatrix, projectionMatrix, projectionMatrix1, orthoMatrix;
	bool result;


	// Clear the buffers to begin the scene.
	m_D3D->BeginScene(0.0f, 0.0f, 0.0f, 1.0f);

	// Generate the view matrix based on the camera's position.
	m_Camera->Render();

	// Get the world, view, and projection matrices from the camera and d3d objects.
	m_Camera->GetViewMatrix(viewMatrix);
	m_D3D->GetWorldMatrix(worldMatrix);
	m_D3D->GetWorldMatrix(worldMatrix1);
	m_D3D->GetWorldMatrix(worldMatrix2);
	m_D3D->GetWorldMatrix(worldMatrix3);
	m_D3D->GetWorldMatrix(worldMatrix4);
	m_D3D->GetWorldMatrix(worldMatrix5);
	m_D3D->GetWorldMatrix(worldMatrix6);
	m_D3D->GetProjectionMatrix(projectionMatrix);
	m_D3D->GetProjectionMatrix(projectionMatrix1);

	m_D3D->GetOrthoMatrix(orthoMatrix);

	//m_D3D->SetWorldMatrix(worldMatrix);

	// Turn off the Z buffer to begin all 2D rendering.
	m_D3D->TurnZBufferOff();

	// Put the bitmap vertex and index buffers on the graphics pipeline to prepare them for drawing.
	result = m_Bitmap->Render(m_D3D->GetDeviceContext(), 200, 200);
	if (!result)
	{
		return false;
	}

	// Render the bitmap with the texture shader.
	result = m_TextureShader->Render(m_D3D->GetDeviceContext(), m_Bitmap->GetIndexCount(), worldMatrix, viewMatrix, orthoMatrix, m_Bitmap->GetTexture());
	if (!result)
	{
		return false;
	}


	// Turn on the alpha blending before rendering the text.
	m_D3D->TurnOnAlphaBlending();

	// Render the text strings.
	result = m_Text->Render(m_D3D->GetDeviceContext(), worldMatrix, orthoMatrix);
	if (!result)
	{
		return false;
	}

	// Turn off alpha blending after rendering the text.
	m_D3D->TurnOffAlphaBlending();

	// Turn the Z buffer back on now that all 2D rendering has completed.
	m_D3D->TurnZBufferOn();

	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	m_Model->Render(m_D3D->GetDeviceContext());

	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix1,
		m_Model->GetTexture(), m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	// Rotate the world matrix by the rotation value so that the triangle will spin.
	D3DXMatrixTranslation(&worldMatrix1, 0.7f, -0.5f, 3.5f);
	D3DXMatrixRotationX(&worldMatrix2, lY * 0.03f * 0.0174532925f);
	D3DXMatrixRotationY(&worldMatrix3, lX * 0.03f * 0.0174532925f);
	D3DXMatrixTranslation(&worldMatrix4, m_Camera->GetPosition().x, m_Camera->GetPosition().y, m_Camera->GetPosition().z);
	
	D3DXMatrixTranslation(&worldMatrix5, 0.0f, 100.0f, 5.0f);

	//m_D3D->SetWorldMatrix(worldMatrix1);

	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	m_Model1->Render(m_D3D->GetDeviceContext());

	// Render the model using the light shader.
	if (getCard)
	{
		worldMatrix6 = worldMatrix1 * worldMatrix2 * worldMatrix3 * worldMatrix4;
	}
	else
	{
		worldMatrix6 = worldMatrix5;
	}
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model1->GetIndexCount(), worldMatrix6, viewMatrix, projectionMatrix1,
		m_Model1->GetTexture(), m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	

	// Present the rendered scene to the screen.
	m_D3D->EndScene();

	return true;
}

CameraClass* GraphicsClass::GetCamera()
{
	return m_Camera;
}