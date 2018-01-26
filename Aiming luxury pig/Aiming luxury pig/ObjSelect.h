#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクトタイトル
class CObjSelect :public CObj
{
public:
	CObjSelect() {};
	~CObjSelect() {};
	void Init();
	void Action();
	void Draw();
private:
	bool m_key_flag;//キーフラグ
};