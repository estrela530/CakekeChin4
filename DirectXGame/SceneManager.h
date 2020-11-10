#pragma once
#include "BaseScene.h"
#include "GameScene.h"
#include "TitleScene.h"
#include <map>

enum SCENE
{
	TITLE,
	GAME,

	NONE
};

class SceneManager
{
public:

	void Init(DirectXCommon* dxcommon, Input* input, Audio* audio);

	std::map<SCENE, BaseScene*> scenes;
	// シーンを追加
	void AddScene(SCENE sceneEnum, BaseScene* scene);
	//シーンを引数によって変える関数
	void ChangeScene(SCENE scene);
	//static void Initialize();
	//現在のシーン更新
	void Update();
	//描画関数
	void Draw();
private:
	BaseScene* m_pScene = nullptr;//現在のシーン　

	DirectXCommon* m_DXCommon;
	Input* m_Input;
	Audio* m_Audio;
};