//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "GameHead.h"
#include "ObjTrap.h"

//使用するネームスペース
using namespace GameL;

CObjTrap::CObjTrap(float x, float y)
{
	m_px = x;//位置
	m_py = y;
}
//イニシャライズ
void CObjTrap::Init()
{
	//blockとの衝突状態確認用
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	//当たり判定用のHitBoxを作成
	Hits::SetHitBox(this, m_px, m_py, 30, 30, ELEMENT_ENEMY, OBJ_TRAP, 1);
}

//アクション
void CObjTrap::Action()
{
	//ブロックタイプ検知用の変数がないためのダミー
	int d;

	//ブロックとの当たり判定実行
	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	pb->BlockHit(&m_px, &m_py, false,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
		&d);

	//ブロック情報を持ってくる
	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//HitBoxの位置の変更
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_px + block->GetScroll(), m_py);

	//主人公の位置を取得
	//CObjPigHero*hero = (CObjPigHero*)Objs::GetObj(OBJ_PIGHERO);

	//敵と当たっているか確認
	if (hit->CheckObjNameHit(OBJ_PIGHERO) != nullptr)
	{
			//自身に削除命令を出す。
			this->SetStatus(false);

			//シーンをゲームオーバーに移行する
			Scene::SetScene(new CSceneGameOver());
	}
}

//ドロー
void CObjTrap::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f, 1.0f, 1.0f, 1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top    = 307.0f;
	src.m_left   = 162.0f;
	src.m_right  = -0.0f;
	src.m_bottom = 450.0f;

	//ブロック情報を持ってくる
	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//表示位置の設定
	dst.m_top    = 0.0f + m_py;
	dst.m_left   = (     0.0f*m_posture) + m_px + block->GetScroll();
	dst.m_right  = (30 - 0.0f*m_posture) + m_px + block->GetScroll();
	dst.m_bottom = 30.0f + m_py;

	//描画
	Draw::Draw(0, &src, &dst, c, 0.0f);
}