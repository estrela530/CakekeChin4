#include "WinApp.h"
#include "DirectXCommon.h"
#include "Audio.h"
#include "GameScene.h"
#include "SceneManager.h"
#include "BaseScene.h"
#include "TitleScene.h"


// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// 汎用機能
	WinApp* win = nullptr;
	DirectXCommon* dxCommon = nullptr;
	Input* input = nullptr;
	Audio* audio = nullptr;
	//GameScene* gameScene = nullptr;
	SceneManager* sceneManager = nullptr;

	// ゲームウィンドウの作成
	win = new WinApp();
	win->CreateGameWindow();

	//DirectX初期化処理
	dxCommon = new DirectXCommon();
	dxCommon->Initialize(win);

#pragma region 汎用機能初期化
	// 入力の初期化
	input = new Input();
	if (!input->Initialize(win->GetInstance(), win->GetHwnd())) {
		assert(0);
		return 1;
	}
	// オーディオの初期化
	audio = new Audio();
	if (!audio->Initialize()) {
		assert(0);
		return 1;
	}
	// スプライト静的初期化
	if (!Sprite::StaticInitialize(dxCommon->GetDevice(), WinApp::window_width, WinApp::window_height)) {
		assert(0);
		return 1;
	}

	// 3Dオブジェクト静的初期化
	if (!Object3d::StaticInitialize(dxCommon->GetDevice(), WinApp::window_width, WinApp::window_height)) {
		assert(0);
		return 1;
	}

	// 3Dオブジェクト2静的初期化
	if (!Object3d2::StaticInitialize(dxCommon->GetDevice(), WinApp::window_width, WinApp::window_height)) {
		assert(0);
		return 1;
	}

	// ボールの静的初期化
	if (!Ball::StaticInitialize(dxCommon->GetDevice(), WinApp::window_width, WinApp::window_height)) {
		assert(0);
		return 1;
	}

#pragma endregion

	// ゲームシーンの初期化
	//gameScene = new GameScene();
	//gameScene->Initialize(dxCommon, input, audio);
	sceneManager = new SceneManager();//追加ーーーー
	sceneManager->Init(dxCommon, input, audio);

	sceneManager->AddScene(SCENE::TITLE, new TitleScene());
	sceneManager->AddScene(SCENE::GAME, new GameScene());
	sceneManager->ChangeScene(GAME);//ここでシーン切り替え

	// メインループ
	while (true)
	{
		// メッセージ処理
		if (win->ProcessMessage()) { break; }

		// 入力関連の毎フレーム処理
		input->Update();
		// ゲームシーンの毎フレーム処理
		sceneManager->Update();

		// 描画開始
		dxCommon->PreDraw();
		// ゲームシーンの描画
		sceneManager->Draw();
		// 描画終了
		dxCommon->PostDraw();
	}
	// 各種解放
	safe_delete(sceneManager);
	//safe_delete(gameScene);
	safe_delete(audio);
	safe_delete(input);
	safe_delete(dxCommon);

	// ゲームウィンドウの破棄
	win->TerminateGameWindow();
	safe_delete(win);

	return 0;
}