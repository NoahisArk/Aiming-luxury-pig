#pragma once
//使用するへっだーファイル
#include "GameL\SceneManager.h"

//使用するネームスペーす
using namespace GameL;

//シーン　ゲームオーバー
class CSceneGameOver :public CScene
{
public:
	CSceneGameOver();
	~CSceneGameOver();
	void InitScene();
	void Scene();
private:
};