#include "SceneManager.h"
#include "TitleScene.h"

#include <cassert>//ヘッダで式が真であることを表す


TitleScene::TitleScene()
{
}

TitleScene::~TitleScene()
{
	safe_delete(spriteBG);
}


void TitleScene::Initialize(DirectXCommon* dxCommon, Input* input, Audio* audio)
{
	//nullptrチェック
	assert(dxCommon);
	assert(input);
	assert(audio);

	this->dxCommon = dxCommon;
	this->input = input;
	this->audio = audio;
	if (!Sprite::LoadTexture(debugTextTexNumber, L"Resources/texture.png"))
	{
		assert(0);
		return;
	}
	debugText.Initialize(debugTextTexNumber);

	// テクスチャ読み込み
	if (!Sprite::LoadTexture(1, L"Resources/texture.png")) {
		assert(0);
		return;
	}

	///	// 3Dオブジェクト生成
	//object3d = Object3d::Create();
	//object3d->Update();
	//背景スプライト生成
	spriteBG = Sprite::Create(1, { 0.0f,0.0f });


}


void TitleScene::Update()
{

}

void TitleScene::Draw()
{
	// コマンドリストの取得
	ID3D12GraphicsCommandList* cmdList = dxCommon->GetCommandList();

#pragma region 描画
	// 背景スプライト描画前処理
	Sprite::PreDraw(cmdList);
	// 背景スプライト描画
	spriteBG->Draw();


	// スプライト描画後処理
	Sprite::PostDraw();
	// 深度バッファクリア
	dxCommon->ClearDepthBuffer();

	Sprite::PreDraw(cmdList);

	//デバッグテキストの描画
	debugText.DrawAll(cmdList);
	//スプライト描画後の処理
	Sprite::PostDraw();
#pragma endregion 

}
