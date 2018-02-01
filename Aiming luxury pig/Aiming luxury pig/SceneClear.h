#pragma once
//使用するへっだーファイル
#include "GameL\SceneManager.h"

//使用するねむすぺ
using namespace GameL;

//シーン：クリア
class CSceneClear :public CScene
{
public :
	CSceneClear();
	~CSceneClear();
	void InitScene();
	void Scene();
private:
};