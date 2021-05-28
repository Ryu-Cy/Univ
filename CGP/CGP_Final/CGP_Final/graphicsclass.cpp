////////////////////////////////////////////////////////////////////////////////
// Filename: graphicsclass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "graphicsclass.h"


GraphicsClass::GraphicsClass()
{
	m_D3D = 0;
	m_Camera = 0;
	m_LightShader = 0;
	m_Light = 0;
	for (int i = 0; i < 2; i++)
		m_Model[i] = 0;

	getCard = false;

	camRotX = 0.0f;
	camRotZ = -10.0f;

	m_TextureShader = 0;
	m_Bitmap = 0;

	m_Text = 0;

	m_SkyDome = 0;
	m_SkyDomeShader = 0;
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
	m_Camera->SetLookAt(0.0f, 0.0f, 0.1f);

	// Create the model[CardKey] object.
	m_Model[0] = new ModelClass;
	if (!m_Model[0])
	{
		return false;
	}

	// Initialize the model[CardKey] object.
	result = m_Model[0]->Initialize(m_D3D->GetDevice(), "../CGP_Final/data/KeyCard/Chip_key_2/Material/key.obj", L"../CGP_Final/data/KeyCard/Chip_key_2/Texturizer/metal_1.jpg", 
		L"../CGP_Final/data/KeyCard/Chip_key_2/Texturizer/stars-1920x1200-galaxy-4k-6362.jpg", L"../CGP_Final/data/KeyCard/Chip_key_2/Texturizer/Blury.jpg", 
		L"../CGP_Final/data/KeyCard/Chip_key_2/Texturizer/Lake.jpg");

	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}

	// Create the model[Map1] object.
	m_Model[1] = new ModelClass;
	if (!m_Model[1])
	{
		return false;
	}

	// Initialize the model[Map1] object.
	result = m_Model[1]->Initialize(m_D3D->GetDevice(), "../CGP_Final/data/Map/map1.obj", L"../CGP_Final/data/Map/map11.jpg",
		L"../CGP_Final/data/Map/map12.jpg", L"../CGP_Final/data/Map/map13.jpg", L"../CGP_Final/data/Map/map14.jpg");

	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}

	// Create the model[Map2] object.
	m_Model[2] = new ModelClass;
	if (!m_Model[2])
	{
		return false;
	}

	// Initialize the model[Map2] object.
	result = m_Model[2]->Initialize(m_D3D->GetDevice(), "../CGP_Final/data/Map/map2.obj", L"../CGP_Final/data/Map/map21.jpg",
		L"../CGP_Final/data/Map/map22.jpg", L"../CGP_Final/data/Map/map23.jpg", L"../CGP_Final/data/Map/map23.jpg");

	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model2 object.", L"Error", MB_OK);
		return false;
	}

	// Create the model[Map3] object.
	m_Model[3] = new ModelClass;
	if (!m_Model[3])
	{
		return false;
	}

	// Initialize the model[Map3] object.
	result = m_Model[3]->Initialize(m_D3D->GetDevice(), "../CGP_Final/data/Map/map3.obj", L"../CGP_Final/data/Map/map31.jpg", 
		L"../CGP_Final/data/Map/map32.jpg", L"../CGP_Final/data/Map/map33.jpg", L"../CGP_Final/data/Map/map34.jpg");

	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model3 object.", L"Error", MB_OK);
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

	m_SkyDome = new SkyDomeClass;
	if (!m_SkyDome)
	{
		return false;
	}

	// Initialize the sky dome object.
	result = m_SkyDome->Initialize(m_D3D->GetDevice());
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the sky dome object.", L"Error", MB_OK);
		return false;
	}

	// Create the sky dome shader object.
	m_SkyDomeShader = new SkyDomeShaderClass;
	if (!m_SkyDomeShader)
	{
		return false;
	}

	// Initialize the sky dome shader object.
	result = m_SkyDomeShader->Initialize(m_D3D->GetDevice(), hwnd);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the sky dome shader object.", L"Error", MB_OK);
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
	for (int i = 0; i < 4; i++)
	{
		if (m_Model[i])
		{
			m_Model[i]->Shutdown();
			delete m_Model[i];
			m_Model[i] = 0;
		}
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

	// Release the sky dome object.
	if (m_SkyDome)
	{
		m_SkyDome->Shutdown();
		delete m_SkyDome;
		m_SkyDome = 0;
	}

	// Release the sky dome shader object.
	if (m_SkyDomeShader)
	{
		m_SkyDomeShader->Shutdown();
		delete m_SkyDomeShader;
		m_SkyDomeShader = 0;
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

	m_Camera->SetPosition(camRotX, 100.0f, camRotZ);

	if ((m_Camera->GetPosition().x >= -1.0f && m_Camera->GetPosition().x <= 1.0f) && (m_Camera->GetPosition().z >= 4.5f && m_Camera->GetPosition().z <= 5.5f))
	{
		getCard = true;
	}
	
	return true;
}

bool GraphicsClass::Render(float rotation)
{
	// worldMatrix[0-8] = CardKey, worldMatrix[9] = Map / Ui
	D3DXMATRIX worldMatrix[10], viewMatrix, projectionMatrix, orthoMatrix;
	bool result;
	D3DXVECTOR3 cameraPosition;


	// Clear the buffers to begin the scene.
	m_D3D->BeginScene(0.0f, 0.0f, 0.0f, 1.0f);

	// Generate the view matrix based on the camera's position.
	m_Camera->Render();

	// Get the world, view, and projection matrices from the camera and d3d objects.
	m_Camera->GetViewMatrix(viewMatrix);
	for (int i = 0; i < 10; i++)
		m_D3D->GetWorldMatrix(worldMatrix[i]);
	m_D3D->GetProjectionMatrix(projectionMatrix);
	m_D3D->GetOrthoMatrix(orthoMatrix);

	//m_D3D->SetWorldMatrix(worldMatrix);

	// Get the position of the camera.
	cameraPosition = m_Camera->GetPosition();

	// Translate the sky dome to be centered around the camera position.
	D3DXMatrixTranslation(&worldMatrix[9], cameraPosition.x, cameraPosition.y, cameraPosition.z);

	// Turn off back face culling.
	m_D3D->TurnOffCulling();

	// Turn off the Z buffer to begin all 2D rendering.
	m_D3D->TurnZBufferOff();

	m_SkyDome->Render(m_D3D->GetDeviceContext());
	m_SkyDomeShader->Render(m_D3D->GetDeviceContext(), m_SkyDome->GetIndexCount(), worldMatrix[9], viewMatrix, projectionMatrix,
		m_SkyDome->GetApexColor(), m_SkyDome->GetCenterColor());

	m_D3D->TurnOnCulling();

	m_D3D->GetWorldMatrix(worldMatrix[9]);

	// Put the bitmap vertex and index buffers on the graphics pipeline to prepare them for drawing.
	result = m_Bitmap->Render(m_D3D->GetDeviceContext(), 200, 200);
	if (!result)
	{
		return false;
	}

	// Render the bitmap with the texture shader.
	result = m_TextureShader->Render(m_D3D->GetDeviceContext(), m_Bitmap->GetIndexCount(), worldMatrix[6], viewMatrix, orthoMatrix, m_Bitmap->GetTexture());
	if (!result)
	{
		return false;
	}


	// Turn on the alpha blending before rendering the text.
	m_D3D->TurnOnAlphaBlending();

	// Render the text strings.
	result = m_Text->Render(m_D3D->GetDeviceContext(), worldMatrix[6], orthoMatrix);
	if (!result)
	{
		return false;
	}

	// Turn off alpha blending after rendering the text.
	m_D3D->TurnOffAlphaBlending();

	// Turn the Z buffer back on now that all 2D rendering has completed.
	m_D3D->TurnZBufferOn();

	// Rotate the world matrix by the rotation value so that the triangle will spin.
	D3DXMatrixScaling(&worldMatrix[1], 0.2f, 0.15f, 0.2f);
	D3DXMatrixTranslation(&worldMatrix[2], 0.8f, -0.5f, 3.5f);
	D3DXMatrixRotationX(&worldMatrix[3], lY * 0.03f * 0.0174532925f);
	D3DXMatrixRotationY(&worldMatrix[4], lX * 0.03f * 0.0174532925f);
	D3DXMatrixTranslation(&worldMatrix[5], m_Camera->GetPosition().x, m_Camera->GetPosition().y, m_Camera->GetPosition().z);

	D3DXMatrixScaling(&worldMatrix[6], 0.5f, 0.5f, 0.5f);
	D3DXMatrixRotationY(&worldMatrix[7], 1.75f);
	D3DXMatrixTranslation(&worldMatrix[8], 0.0f, 100.0f, 5.0f);

	//m_D3D->SetWorldMatrix(worldMatrix1);

	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	// CardKey
	m_Model[0]->Render(m_D3D->GetDeviceContext());

	// Render the model using the light shader.
	if (getCard)
		for (int i = 1; i < 6; i++)
			worldMatrix[0] *= worldMatrix[i];
	else
		for (int i = 6; i < 9; i++)
			worldMatrix[0] *= worldMatrix[i];

	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model[0]->GetIndexCount(), worldMatrix[0], viewMatrix, projectionMatrix,
		*m_Model[0]->GetTexture(), m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	// Map1-3
	m_Model[1]->Render(m_D3D->GetDeviceContext());

	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model[1]->GetIndexCount(), worldMatrix[9], viewMatrix, projectionMatrix,
		*m_Model[1]->GetTexture(), m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	m_Model[2]->Render(m_D3D->GetDeviceContext());

	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model[2]->GetIndexCount(), worldMatrix[9], viewMatrix, projectionMatrix,
		*m_Model[2]->GetTexture(), m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	m_Model[3]->Render(m_D3D->GetDeviceContext());

	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model[3]->GetIndexCount(), worldMatrix[9], viewMatrix, projectionMatrix,
		*m_Model[3]->GetTexture(), m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
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