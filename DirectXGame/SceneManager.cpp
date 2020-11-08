#include "SceneManager.h"
#include "BaseScene.h"
#include "GameScene.h"
#include "TitleScene.h"

void SceneManager::Init(DirectXCommon * dxcommon, Input * input, Audio * audio)
{
	m_DXCommon = dxcommon;
	m_Audio = audio;
	m_Input = input;
}

//Å‰‚ÌƒV[ƒ“‚Í‹ó
void SceneManager::AddScene(SCENE sceneEnum, BaseScene * scene)
{
	scenes[sceneEnum] = scene;
}

void SceneManager::ChangeScene(SCENE scene)
{
	m_pScene = scenes[scene];
	m_pScene->Initialize(m_DXCommon, m_Input, m_Audio);
};


void SceneManager::Update()
{
	m_pScene->Update();

};

void SceneManager::Draw()
{
	m_pScene->Draw();
};
