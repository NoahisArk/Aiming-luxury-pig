#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト:ブロック&背景
class CObjBlock :public CObj
{
public:
	CObjBlock(int map2[20][400]);
	~CObjBlock() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー

	void SetScroll(float s) { m_scroll = s; }
	float GetScroll()		{ return m_scroll; }
	//ブロックとの当たり判定
	void BlockHit(
		float *x, float*y, bool scroll_on,
		bool*up, bool*down, bool*left, bool*right,
		float*vx, float*vy, int*bt
	);	

private:
	void BlockDraw(float x, float y, RECT_F*dst, float c[]);
	int m_map2[20][400];//マップ情報ノーマル

	float m_scroll;//左右スクロール用

	//テスト用変数
	//float m_px, m_py;//テスト用交点表示用
};