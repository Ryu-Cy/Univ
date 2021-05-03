////////////////////////////////////////////////////////////////////////////////
// Filename: modelclass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "modelclass.h"


ModelClass::ModelClass()
{
	m_vertexBuffer = 0;
	m_indexBuffer = 0;
}


ModelClass::ModelClass(const ModelClass& other)
{
}


ModelClass::~ModelClass()
{
}


bool ModelClass::Initialize(ID3D11Device* device, int num)
{
	bool result;

	// Initialize the vertex and index buffers.
	result = InitializeBuffers(device, num);
	if (!result)
	{
		return false;
	}

	return true;
}


void ModelClass::Shutdown()
{
	// Shutdown the vertex and index buffers.
	ShutdownBuffers();

	return;
}


void ModelClass::Render(ID3D11DeviceContext* deviceContext)
{
	// Put the vertex and index buffers on the graphics pipeline to prepare them for drawing.
	RenderBuffers(deviceContext);

	return;
}


int ModelClass::GetIndexCount()
{
	return m_indexCount;
}

bool ModelClass::InitializeBuffers(ID3D11Device* device, int num)
{
	VertexType* vertices;
	VertexType* vertices2;
	VertexType* vertices3;
	unsigned long* indices;
	unsigned long* indices2;
	unsigned long* indices3;
	D3D11_BUFFER_DESC vertexBufferDesc, indexBufferDesc;
	D3D11_SUBRESOURCE_DATA vertexData, indexData;
	HRESULT result;

	// Set the number of vertices in the vertex array.
	m_vertexCount = 12;

	// Set the number of indices in the index array.
	m_indexCount = 12;

	// Create the vertex array.
	vertices = new VertexType[m_vertexCount];
	if (!vertices)
	{
		return false;
	}

	// Create the index array.
	indices = new unsigned long[m_indexCount];
	if (!indices)
	{
		return false;
	}

	// Create the vertex array.
	vertices2 = new VertexType[m_vertexCount];
	if (!vertices2)
	{
		return false;
	}

	// Create the index array.
	indices2 = new unsigned long[m_indexCount];
	if (!indices2)
	{
		return false;
	}

	// Create the vertex array.
	vertices3 = new VertexType[m_vertexCount];
	if (!vertices3)
	{
		return false;
	}

	// Create the index array.
	indices3 = new unsigned long[m_indexCount];
	if (!indices3)
	{
		return false;
	}

	// Rectangle

	// Load the vertex array with data.
	vertices[0].position = D3DXVECTOR3(-1.0f, 1.0f, 0.0f);
	vertices[0].color = D3DXVECTOR4(0.0f, 1.0f, 0.0f, 1.0f);
	vertices[1].position = D3DXVECTOR3(1.0f, 1.0f, 0.0f);
	vertices[1].color = D3DXVECTOR4(0.0f, 1.0f, 0.0f, 1.0f);
	vertices[2].position = D3DXVECTOR3(1.0f, -1.0f, 0.0f);
	vertices[2].color = D3DXVECTOR4(0.0f, 1.0f, 0.0f, 1.0f);

	vertices[3].position = D3DXVECTOR3(1.0f, -1.0f, 0.0f);
	vertices[3].color = D3DXVECTOR4(0.0f, 1.0f, 0.0f, 1.0f);
	vertices[4].position = D3DXVECTOR3(-1.0f, -1.0f, 0.0f);
	vertices[4].color = D3DXVECTOR4(0.0f, 1.0f, 0.0f, 1.0f);
	vertices[5].position = D3DXVECTOR3(-1.0f, 1.0f, 0.0f);
	vertices[5].color = D3DXVECTOR4(0.0f, 1.0f, 0.0f, 1.0f);

	// Load the index array with data.
	// Create the triangle in the clockwise order (counterclockwise: back face culling).
	indices[0] = 0; 
	indices[1] = 1;
	indices[2] = 2;

	indices[3] = 3;
	indices[4] = 4;
	indices[5] = 5;

	// Pentagon

	vertices2[0].position = D3DXVECTOR3(-4.0f, 2.0f, 0.0f);
	vertices2[0].color = D3DXVECTOR4(1.0f, 0.0f, 0.0f, 1.0f);
	vertices2[1].position = D3DXVECTOR3(-3.0f, 2.5f, 0.0f);
	vertices2[1].color = D3DXVECTOR4(1.0f, 0.0f, 0.0f, 1.0f);
	vertices2[2].position = D3DXVECTOR3(-2.0f, 2.0f, 0.0f);
	vertices2[2].color = D3DXVECTOR4(1.0f, 0.0f, 0.0f, 1.0f);

	vertices2[3].position = D3DXVECTOR3(-4.0f, 2.0f, 0.0f);
	vertices2[3].color = D3DXVECTOR4(1.0f, 0.0f, 0.0f, 1.0f);
	vertices2[4].position = D3DXVECTOR3(-2.0f, 2.0f, 0.0f);
	vertices2[4].color = D3DXVECTOR4(1.0f, 0.0f, 0.0f, 1.0f);
	vertices2[5].position = D3DXVECTOR3(-2.25f, 1.5f, 0.0f);
	vertices2[5].color = D3DXVECTOR4(1.0f, 0.0f, 0.0f, 1.0f);

	vertices2[6].position = D3DXVECTOR3(-2.25f, 1.5f, 0.0f);
	vertices2[6].color = D3DXVECTOR4(1.0f, 0.0f, 0.0f, 1.0f);
	vertices2[7].position = D3DXVECTOR3(-3.75f, 1.5f, 0.0f);
	vertices2[7].color = D3DXVECTOR4(1.0f, 0.0f, 0.0f, 1.0f);
	vertices2[8].position = D3DXVECTOR3(-4.0f, 2.0f, 0.0f);
	vertices2[8].color = D3DXVECTOR4(1.0f, 0.0f, 0.0f, 1.0f);

	indices2[0] = 0;
	indices2[1] = 1;
	indices2[2] = 2;

	indices2[3] = 3;
	indices2[4] = 4;
	indices2[5] = 5;

	indices2[6] = 6;
	indices2[7] = 7;
	indices2[8] = 8;

	// Hexagon

	vertices3[0].position = D3DXVECTOR3(2.0f, -2.0f, 0.0f);
	vertices3[0].color = D3DXVECTOR4(0.0f, 0.0f, 1.0f, 1.0f);
	vertices3[1].position = D3DXVECTOR3(3.0f, -1.5f, 0.0f);
	vertices3[1].color = D3DXVECTOR4(0.0f, 0.0f, 1.0f, 1.0f);
	vertices3[2].position = D3DXVECTOR3(4.0f, -2.0f, 0.0f);
	vertices3[2].color = D3DXVECTOR4(0.0f, 0.0f, 1.0f, 1.0f);

	vertices3[3].position = D3DXVECTOR3(2.0f, -2.0f, 0.0f);
	vertices3[3].color = D3DXVECTOR4(0.0f, 0.0f, 1.0f, 1.0f);
	vertices3[4].position = D3DXVECTOR3(4.0f, -2.0f, 0.0f);
	vertices3[4].color = D3DXVECTOR4(0.0f, 0.0f, 1.0f, 1.0f);
	vertices3[5].position = D3DXVECTOR3(4.0f, -2.5f, 0.0f);
	vertices3[5].color = D3DXVECTOR4(0.0f, 0.0f, 1.0f, 1.0f);

	vertices3[6].position = D3DXVECTOR3(2.0f, -2.5f, 0.0f);
	vertices3[6].color = D3DXVECTOR4(0.0f, 0.0f, 1.0f, 1.0f);
	vertices3[7].position = D3DXVECTOR3(4.0f, -2.5f, 0.0f);
	vertices3[7].color = D3DXVECTOR4(0.0f, 0.0f, 1.0f, 1.0f);
	vertices3[8].position = D3DXVECTOR3(3.0f, -3.0f, 0.0f);
	vertices3[8].color = D3DXVECTOR4(0.0f, 0.0f, 1.0f, 1.0f);

	vertices3[9].position = D3DXVECTOR3(2.0f, -2.0f, 0.0f);
	vertices3[9].color = D3DXVECTOR4(0.0f, 0.0f, 1.0f, 1.0f);
	vertices3[10].position = D3DXVECTOR3(4.0f, -2.5f, 0.0f);
	vertices3[10].color = D3DXVECTOR4(0.0f, 0.0f, 1.0f, 1.0f);
	vertices3[11].position = D3DXVECTOR3(2.0f, -2.5f, 0.0f);
	vertices3[11].color = D3DXVECTOR4(0.0f, 0.0f, 1.0f, 1.0f);

	indices3[0] = 0;
	indices3[1] = 1;
	indices3[2] = 2;

	indices3[3] = 3;
	indices3[4] = 4;
	indices3[5] = 5;

	indices3[6] = 6;
	indices3[7] = 7;
	indices3[8] = 8;

	indices3[9] = 9;
	indices3[10] = 10;
	indices3[11] = 11;

	if (num == 1)
	{
		// Set up the description of the static vertex buffer.
		vertexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
		vertexBufferDesc.ByteWidth = sizeof(VertexType) * m_vertexCount;
		vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		vertexBufferDesc.CPUAccessFlags = 0;
		vertexBufferDesc.MiscFlags = 0;
		vertexBufferDesc.StructureByteStride = 0;

		// Give the subresource structure a pointer to the vertex data.
		vertexData.pSysMem = vertices;
		vertexData.SysMemPitch = 0;
		vertexData.SysMemSlicePitch = 0;

		// Now create the vertex buffer.
		result = device->CreateBuffer(&vertexBufferDesc, &vertexData, &m_vertexBuffer);
		if (FAILED(result))
		{
			return false;
		}

		// Set up the description of the static index buffer.
		indexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
		indexBufferDesc.ByteWidth = sizeof(unsigned long) * m_indexCount;
		indexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
		indexBufferDesc.CPUAccessFlags = 0;
		indexBufferDesc.MiscFlags = 0;
		indexBufferDesc.StructureByteStride = 0;

		// Give the subresource structure a pointer to the index data.
		indexData.pSysMem = indices;
		indexData.SysMemPitch = 0;
		indexData.SysMemSlicePitch = 0;

		// Create the index buffer.
		result = device->CreateBuffer(&indexBufferDesc, &indexData, &m_indexBuffer);
		if (FAILED(result))
		{
			return false;
		}
	}
	else if (num == 2)
	{
		// Set up the description of the static vertex buffer.
		vertexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
		vertexBufferDesc.ByteWidth = sizeof(VertexType) * m_vertexCount;
		vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		vertexBufferDesc.CPUAccessFlags = 0;
		vertexBufferDesc.MiscFlags = 0;
		vertexBufferDesc.StructureByteStride = 0;

		// Give the subresource structure a pointer to the vertex data.
		vertexData.pSysMem = vertices2;
		vertexData.SysMemPitch = 0;
		vertexData.SysMemSlicePitch = 0;

		// Now create the vertex buffer.
		result = device->CreateBuffer(&vertexBufferDesc, &vertexData, &m_vertexBuffer);
		if (FAILED(result))
		{
			return false;
		}

		// Set up the description of the static index buffer.
		indexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
		indexBufferDesc.ByteWidth = sizeof(unsigned long) * m_indexCount;
		indexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
		indexBufferDesc.CPUAccessFlags = 0;
		indexBufferDesc.MiscFlags = 0;
		indexBufferDesc.StructureByteStride = 0;

		// Give the subresource structure a pointer to the index data.
		indexData.pSysMem = indices2;
		indexData.SysMemPitch = 0;
		indexData.SysMemSlicePitch = 0;

		// Create the index buffer.
		result = device->CreateBuffer(&indexBufferDesc, &indexData, &m_indexBuffer);
		if (FAILED(result))
		{
			return false;
		}
	}
	else if (num == 3)
	{
		// Set up the description of the static vertex buffer.
		vertexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
		vertexBufferDesc.ByteWidth = sizeof(VertexType) * m_vertexCount;
		vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		vertexBufferDesc.CPUAccessFlags = 0;
		vertexBufferDesc.MiscFlags = 0;
		vertexBufferDesc.StructureByteStride = 0;

		// Give the subresource structure a pointer to the vertex data.
		vertexData.pSysMem = vertices3;
		vertexData.SysMemPitch = 0;
		vertexData.SysMemSlicePitch = 0;

		// Now create the vertex buffer.
		result = device->CreateBuffer(&vertexBufferDesc, &vertexData, &m_vertexBuffer);
		if (FAILED(result))
		{
			return false;
		}

		// Set up the description of the static index buffer.
		indexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
		indexBufferDesc.ByteWidth = sizeof(unsigned long) * m_indexCount;
		indexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
		indexBufferDesc.CPUAccessFlags = 0;
		indexBufferDesc.MiscFlags = 0;
		indexBufferDesc.StructureByteStride = 0;

		// Give the subresource structure a pointer to the index data.
		indexData.pSysMem = indices3;
		indexData.SysMemPitch = 0;
		indexData.SysMemSlicePitch = 0;

		// Create the index buffer.
		result = device->CreateBuffer(&indexBufferDesc, &indexData, &m_indexBuffer);
		if (FAILED(result))
		{
			return false;
		}
	}
	

	// Release the arrays now that the vertex and index buffers have been created and loaded.
	delete[] vertices;
	vertices = 0;

	delete[] indices;
	indices = 0;

	return true;
}


void ModelClass::ShutdownBuffers()
{
	// Release the index buffer.
	if (m_indexBuffer)
	{
		m_indexBuffer->Release();
		m_indexBuffer = 0;
	}

	// Release the vertex buffer.
	if (m_vertexBuffer)
	{
		m_vertexBuffer->Release();
		m_vertexBuffer = 0;
	}

	return;
}

// This sets the vertex buffer and index buffer as active on the input assembler in the GPU. 
// Once the GPU has an active vertex buffer, it can then use the shader to render that buffer. 
// This function also defines how those buffers should be drawn such as triangles, lines, fans, 
// and etc using the IASetPrimitiveTopology DirectX function.
void ModelClass::RenderBuffers(ID3D11DeviceContext* deviceContext)
{
	unsigned int stride;
	unsigned int offset;

	// Set vertex buffer stride and offset.
	stride = sizeof(VertexType);
	offset = 0;

	// Set the vertex buffer to active in the input assembler so it can be rendered.
	deviceContext->IASetVertexBuffers(0, 1, &m_vertexBuffer, &stride, &offset);

	// Set the index buffer to active in the input assembler so it can be rendered.
	deviceContext->IASetIndexBuffer(m_indexBuffer, DXGI_FORMAT_R32_UINT, 0);

	// Set the type of primitive that should be rendered from this vertex buffer, in this case triangles.
	deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	return;
}