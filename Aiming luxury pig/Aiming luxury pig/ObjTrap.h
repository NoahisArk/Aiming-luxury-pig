#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト敵
class CObjTrap :public CObj
{
public:
	CObjTrap(float x, float y);
	CObjTrap() {};
	~CObjTrap() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー

	float GetVx() { return m_vx; }

private:
	float m_px;//位置
	float m_py;
	float m_vx;//移動ベクトル
	float m_vy;
	float m_posture;//姿勢

	bool  m_del;

	//blockとの衝突状態確認用
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;
};
