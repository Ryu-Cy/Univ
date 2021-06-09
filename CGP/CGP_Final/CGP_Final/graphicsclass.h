////////////////////////////////////////////////////////////////////////////////
// Filename: graphicsclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _GRAPHICSCLASS_H_
#define _GRAPHICSCLASS_H_


///////////////////////
// MY CLASS INCLUDES //
///////////////////////
#include "d3dclass.h"
#include "cameraclass.h"
#include "modelclass.h"
#include "lightshaderclass.h"
#include "lightclass.h"

#include "inputclass.h"

#include "textureshaderclass.h"
#include "bitmapclass.h"

#include "skydomeclass.h"
#include "skydomeshaderclass.h"

#include "fireclass.h"
#include "fireshaderclass.h"

#include "textclass.h"

/////////////
// GLOBALS //
/////////////
const bool FULL_SCREEN = false;
const bool VSYNC_ENABLED = true;
const float SCREEN_DEPTH = 10000.0f;
const float SCREEN_NEAR = 0.1f;


////////////////////////////////////////////////////////////////////////////////
// Class name: GraphicsClass
////////////////////////////////////////////////////////////////////////////////
class GraphicsClass
{
public:
	GraphicsClass();
	GraphicsClass(const GraphicsClass&);
	~GraphicsClass();

	bool Initialize(int, int, HWND);
	void Shutdown();
	bool Frame(int, int, int, int, float);
	bool Frame(int, int, float);
	bool Render();
	bool Render(float);

	CameraClass* GetCamera();

	float camRotX, camRotY, camRotZ;
	float lX, lY;

	int mapNum;
	int inCorridor;
	int blink;

	bool getCard;
	bool turnOnLight;
	bool isInteractDoor;
	bool isInteractEscape;

	int num_of_polygons;
	int num_of_objects;

private:
	D3DClass* m_D3D;
	CameraClass* m_Camera;
	ModelClass* m_Card;
	ModelClass* m_Map[3];
	ModelClass* m_Door[2];
	FireClass* m_Fire[3];
	LightShaderClass* m_LightShader;
	LightClass* m_Light;

	InputClass* m_Input;

	TextureShaderClass* m_TextureShader;
	BitmapClass* m_Bitmap;

	TextClass* m_Text;

	SkyDomeClass* m_SkyDome;
	SkyDomeShaderClass* m_SkyDomeShader;

	FireShaderClass* m_FireShader;
};

#endif