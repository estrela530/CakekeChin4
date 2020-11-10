#pragma once

#include "SafeDelete.h"
#include "SceneManager.h"

#include <DirectXMath.h>
#include "Input.h"
#include "Sprite.h"
#include "Object3d.h"
#include "DebugText.h"
#include "Audio.h"
#include "BaseScene.h"

class TitleScene :public BaseScene
{
private: // エイリアス
// Microsoft::WRL::を省略
	template <class T> using ComPtr = Microsoft::WRL::ComPtr<T>;
	// DirectX::を省略
	using XMFLOAT2 = DirectX::XMFLOAT2;
	using XMFLOAT3 = DirectX::XMFLOAT3;
	using XMFLOAT4 = DirectX::XMFLOAT4;
	using XMMATRIX = DirectX::XMMATRIX;

private://静的メンバ変数
	static const int debugTextTexNumber = 0;
public:
	TitleScene();
	//デストラクタ
	~TitleScene();
	//初期化
	virtual void Initialize(DirectXCommon* dxCommon, Input* input, Audio* audio) override;



	//毎フレーム管理
	virtual void Update() override;

	//描画
	virtual void Draw() override;

private://メンバ変数

	DirectXCommon* dxCommon = nullptr;
	Input* input = nullptr;
	Audio* audio = nullptr;
	DebugText debugText;

	Sprite* spriteBG = nullptr;
	Object3d* object3d = nullptr;
};