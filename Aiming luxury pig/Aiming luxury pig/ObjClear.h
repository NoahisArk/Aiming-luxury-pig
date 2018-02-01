#pragma once
//使用するへだ
#include "GameL\SceneObjManager.h"
//使用するねむすぺ
using namespace GameL;

//オブジェクトくりあ
class CObjClear :public CObj
{
public:
	CObjClear() {};
	~CObjClear() {};
	void Init();
	void Action();
	void Draw();
private:
	bool m_key_flag;
};