//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "GameHead.h"
#include "ObjPigHero.h"
#include "GameL\Audio.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjPigHero::Init()
{
	m_px = 0.0f;//位置
	m_py = 550.0f;
	m_vx = 0.0f;//移動ベクトル
	m_vy = 0.0f;
	m_posture = 1.0f;//右向き0.0f左向き1.0f

	m_ani_time = 0;
	m_ani_frame = 1;//静止フレームを初期にする

	m_speed_power = 0.5f;//通常速度
	m_ani_max_time = 4;//アニメーション間隔幅

	//blockとの衝突状態確認用
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	m_block_type = 0;//踏んでいるblockの種類を確認用

	//当たり判定用のHitBoxを作成
	Hits::SetHitBox(this, m_px, m_py, 30, 30, ELEMENT_PLAYER, OBJ_PIGHERO, 1);
}

//アクション
void CObjPigHero::Action()
{
	//落下によるゲームオーバー
	if (m_py > 1000.0f)
	{
		//場外に出たらゲームオーバー。
		this->SetStatus(false);
		
		//ゲームオーバー画面に移行
		Scene::SetScene(new CSceneGameOver());
	}
	//Xキー入力でジャンプ
	if (Input::GetVKey('X') == true)
	{
		if (m_hit_down == true)
		{
			//ジャンプ音を鳴らす
			Audio::Start(1);
			m_vy = -12.5;
		}
	}
	//Zキー入力で速度アップ
	if (Input::GetVKey('Z') == true)
	{
		//ダッシュ時の速度
		m_speed_power = 1.1f;
		m_ani_max_time = 4;
	}
	else
	{
		//通常速度
		m_speed_power = 0.5f;
		m_ani_max_time = 4;
	}
	
	//キーの入力方向
	if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_vx += m_speed_power;
		m_posture = 1.0f;
		m_ani_time += 1;
	}
	else if (Input::GetVKey(VK_LEFT) == true)
	{
		m_vx -= m_speed_power;
		m_posture = 0.0f;
		m_ani_time += 1;
	}
	else
	{
		m_ani_frame = 1;//キー入力がない場合静止フレームにする
		m_ani_time = 0;
	}

	if (m_ani_time > m_ani_max_time)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
	}

	if (m_ani_frame == 3)
	{
		m_ani_frame = 0;
	}
	//摩擦
	m_vx += -(m_vx*0.120);

	//自由落下運動
	m_vy += 9.8 / (16.0f);

	//ブロックとの当たり判定実行
	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	pb->BlockHit(&m_px, &m_py, true,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right,
		&m_vx, &m_vy, &m_block_type
	);
	//自身のHitBoxを持ってくる
	CHitBox*hit = Hits::GetHitBox(this);

	//敵と当たっているか確認
	if (hit->CheckObjNameHit(OBJ_ENEMY) != nullptr)
	{
		//主人公が敵とどの角度で当たっているかを確認
		HIT_DATA**hit_data;//当たった時の細かな情報を入れるための構造体
		hit_data = hit->SearchObjNameHit(OBJ_ENEMY);//hit_dataに主人公と当たっている他全てのHitBoxとの情報を入れる
		
		for (int i = 0; i < hit->GetCount(); i++)
		{
			//敵の左右に当たったら
			if (hit_data[i] != nullptr)
			{
				float r = hit_data[i]->r;
				if ((r < 45 && r >= 0) || r > 315)
				{
					m_vx = -15.0f;//左に移動させる
				}
				if (r > 135 && r < 225)
				{
					m_vx = +15.0f;//右に移動させる
				}
				if (r = 225 && r < 315)
				{
					//敵の移動方向を主人公の位置に加算
					m_px += ((CObjEnemy*)hit_data[i]->o)->GetVx();

					CObjBlock*b = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

					//後方スクロールライン
					if (m_px < 80)
					{
						m_px = 80;
						b->SetScroll(b->GetScroll() + 5.0);
					}
					//前方スクロール
					if (m_px > 300)
					{
						m_px = 300;
						b->SetScroll(b->GetScroll() - 5.0);
					}
					//頭に載せる処理
					if (m_vy < -1.0f)
					{
						//ジャンプしてる場合下記の影響を出ないようにする
					}
					else
					{
						//主人公が敵の頭に乗っているので、Yvecは0にして落下させない
						//また、地面に当たっている判定にする
						m_vy = 0.0f;
						m_hit_down = true;
					}
				}
			}
		}
	}

	//位置の更新
	m_px += m_vx;
	m_py += m_vy;

	//HitBoxの位置の変更
	hit->SetPos(m_px, m_py);
}

//ドロー
void CObjPigHero::Draw()
{
	int AniData[4] =
	{
		1,0,2,0,
	};
	//描画カラー情報
	float c[4] = { 1.0f, 1.0f, 1.0f, 1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f + AniData[m_ani_frame] * 150;
	src.m_right = 155.0 + AniData[m_ani_frame] * 150;
	src.m_bottom = 160.0f;

	//表示位置の設定
	dst.m_top = 0.0f + m_py;
	dst.m_left = (30.0f*m_posture) + m_px;
	dst.m_right = (30 - 30.0f*m_posture) + m_px;
	dst.m_bottom = 35.0f + m_py;

	//描画
	Draw::Draw(2, &src, &dst, c, 0.0f);
}