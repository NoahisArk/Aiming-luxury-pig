#pragma once
//使用するへっだー
#include "GameL\SceneObjManager.h"
//使用するネームすぺ0-
using namespace GameL;

//オブジェクト：げーむおーば
class CObjGameOver :public CObj
{
public :
	CObjGameOver() {};
	~CObjGameOver() {};
	void Init();
	void Action();
	void Draw();
private:
	bool m_key_flag;


};