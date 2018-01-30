//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"
#include "GameHead.h"
#include "ObjPigHero.h"
#include "ObjClear.h"

//使用するネームスペース
using namespace GameL;

CObjBlock::CObjBlock( int map2[20][250])
{
	
	//マップデータをコピー:ノーマル
	memcpy(m_map2, map2, sizeof(int)*(20 * 250));
	
}
//イニシャライズ
void CObjBlock::Init()
{
	m_scroll = 0.0f;
}

//アクション
void CObjBlock::Action()
{
	//主人公位置を取得
	CObjPigHero*hero = (CObjPigHero*)Objs::GetObj(OBJ_PIGHERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//後方スクロールライン
	if (hx < 80)
	{
		hero->SetX(80);//主人公はラインを超えないようにする
		m_scroll -= hero->GetVX();//主人公が本来動くべき値をm_scrollに加える
	}

	//前方スクロールライン
	if (hx > 300)
	{
		hero->SetX(300);//主人公はラインを超えないようにする
		m_scroll -= hero->GetVX();//主人公が本来動くべき分の値をm_scrollに加える
	}
	//敵出現ライン
	//主人公の位置+500を敵出現ラインにする
	float line = hx + (-m_scroll) + 300;

	//敵出現ラインを要素番号化
	int ex = ((int)line) / 30;

	//敵出現ラインの列を検索
	for (int i = 0; i < 20; i++)
	{
		//列の中から4を探す
		if (m_map2[i][ex] == 4)
		{
			//4があれば、敵を出現
			CObjEnemy* obje = new CObjEnemy(ex * 30.0f, i * 30.0f);
			Objs::InsertObj(obje, OBJ_ENEMY, 13);

			//敵出現場所の値を0にする
			m_map2[i][ex] = 0;
		}
	}
	//敵出現ラインの列を検索
	for (int i = 0; i < 20; i++)
	{
		//列の中から8を探す
		if (m_map2[i][ex] == 8)
		{
			//4があれば、敵を出現
			CObjBombEnemy* obje = new CObjBombEnemy(ex * 30.0f, i * 30.0f);
			Objs::InsertObj(obje, OBJ_BOMBENEMY, 13);

			//敵出現場所の値を0にする
			m_map2[i][ex] = 0;
		}
	}
	//罠出現ラインの列を検索
	for (int i = 0; i < 20; i++)
	{
		//列の中から6を探す
		if (m_map2[i][ex] == 6)
		{
			//6があれば、罠を出現
			CObjTrap* obje = new CObjTrap(ex * 30.0f, i * 30.0f);
			Objs::InsertObj(obje, OBJ_TRAP, 12);

			//罠出現場所の値を0にする
			m_map2[i][ex] = 0;
		}
	}
}
//ドロー
void CObjBlock::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//背景表示
	src.m_top    = 2.0f;
	src.m_left   = 2.0f;
	src.m_right  = 402.0f;
	src.m_bottom = 151.0f;
	dst.m_top    = 0.0f;
	dst.m_left   = 0.0f;
	dst.m_right  = 800.0;
	dst.m_bottom = 600.0;
	Draw::Draw(1, &src, &dst, c, 0.0f);

	//マップチップによるblock設置
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 250; j++)
		{
			if (m_map2[i][j] > 0)
			{
				//表示位置の設定
				dst.m_top    = i * 30.0f;
				dst.m_left   = j * 30.0f  + m_scroll;
				dst.m_right  = dst.m_left + 30.0;
				dst.m_bottom = dst.m_top  + 30.0;
				if (m_map2[i][j] == 2)
				{
					//スタートブロック : 切り取り位置
					src.m_top = 2.0f;
					src.m_left = 164.0f;
					src.m_right = 324.0f;
					src.m_bottom = 149.0f;
					//描画
					Draw::Draw(0, &src, &dst, c, 0.0f);
				}
				else if (m_map2[i][j] == 3)
				{
					//ゴールブロック : 切り取り位置
					src.m_top = 2.0f;
					src.m_left = 3.0f;
					src.m_right = 160.0f;
					src.m_bottom = 149.0f;

					//描画
					Draw::Draw(0, &src, &dst, c, 0.0f);
				}
				else if (m_map2[i][j] == 5)
				{
					//土 : 切り取り位置
					src.m_top    =   3.0f;
					src.m_left   = 330.0f;
					src.m_right  = 400.0f;
					src.m_bottom = 149.0f;

					//描画
					Draw::Draw(0, &src, &dst, c, 0.0f);
				}
				else if (m_map2[i][j] == 7)
				{
					//草 : 切り取り位置
					src.m_top    = 160.0f;
					src.m_left   =  10.0f;
					src.m_right  = 160.0f;
					src.m_bottom = 304.0f;

					//描画
					Draw::Draw(0, &src, &dst, c, 0.0f);
				}
				else if (m_map2[i][j] == 4)
				{
					//敵(オオカミ)：切り取り位置
					;
				}
				else if (m_map2[i][j] == 6)
				{
					//罠(トラップ)：切り取り位置
					;
				}
				else if (m_map2[i][j] == 8)
				{
					//敵(オオカミ(爆弾))：切り取り位置
					;
				}
				else
				{
					BlockDraw(320.0f, 0.0f, &dst, c);
					//描画
					//Draw::Draw(0, &src, &dst, c, 0.0f);
				}
			}
		}
	}
}

//BlockDrawMethod関数
//引数1 float  x ;リソース切り取り位置X
//引数2 float  y ;リソース切り取り位置Y
//引数3 RECT_F*dst;描画位置
//引数4 float c[];カラー情報
//ブロックを限定描画用。リソース切り取り位置のみx.yで
//設定できる
void CObjBlock::BlockDraw(float x, float y, RECT_F*dst, float c[])
{
	RECT_F src;
	//ブロック : 切り取り位置
	src.m_top    = 158.0f;
	src.m_left   = 175.0f;
	src.m_right  = src.m_left + 150.0f;
	src.m_bottom = src.m_top  + 145.0f;
	//描画
	Draw::Draw(0, &src, dst, c, 0.0f);
}
//BlockHit関数
//引数1 float*x　      :判定を行うobjectのX位置
//引数2 float*y　      :判定を行うobjectのY位置
//引数3 bool  scroll_on:判定を行うobjectはスクロールの影響を与えるかどうか(true=与える　false=与えない)
//引数4 bool* up       :上下左右判定の上部分に当たっているかどうかを返す
//引数5 bool* down     :上下左右判定の下部分に当たっているかどうかを返す
//引数6 bool* left     :上下左右判定の左部分に当たっているかどうかを返す
//引数7 bool* right    :上下左右判定の右部分に当たっているかどうかを返す
//引数8 float* vx      :左右判定時の反発による移動方向・力の値を変えて返す
//引数9 float* vy      :上下判定時による自由落下運動の移動方向・力の値を変えて返す
//引数10 int*  bt      :下部分判定、特殊なブロックのタイプを返す
//判定を行うobjectとブロックを限定で、当たり判定と上下左右判定を行う
//その結果は引数4～10に返す
void CObjBlock::BlockHit(
	float *x, float*y, bool scroll_on,
	bool*up, bool*down, bool *left, bool*right,
	float*vx, float*vy, int*bt
)
{
	//主人公の衝突状態確認用フラグの初期化
	*up    = false;
	*down  = false;
	*left  = false;
	*right = false;

	//踏んでいるblockの種類の初期化
	*bt = 0;

	//mmapの全要素にアクセス
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 250; j++)
		{
			if (m_map2[i][j] > 0 && m_map2[i][j] != 4)
			{
				//要素番号を座標に変更
				float bx = j * 30.0f;
				float by = i * 30.0f;

				//スクロールの影響
				float scroll = scroll_on ? m_scroll : 0;

				//オブジェクトとブロックの当判定
				if ((*x + (-scroll) + 30.0f>bx) && (*x + (-scroll)<bx + 30.0f) && (*y + 30.0f>by) && (*y<by + 30.0f))
				{
					//上下左右判定

					//vectorの作成
					float rvx = (*x + (-scroll)) - bx;
					float rvy = *y - by;
					//長さを求める
					float len = sqrt(rvx*rvx + rvy*rvy);
					//角度を求める
					float r = atan2(rvy, rvx);
					r = r*180.0f / 3.14f;

					if (r <= 0.0f)
						r = abs(r);
					else
						r = 360.0f - abs(r);
					//lenがある一定の長さのより短い場合判定に入る
					if (len < 33.0f)
					{
						//角度で上下左右を判定
						if ((r < 30 && r>0) || r > 315)
						{
							//右
							*right = true;//主人公の左の部分が衝突している
							*x = bx + 30.0f + (scroll);//ブロック位置+主人公の幅
							*vx = 0.2f;//-VX*反発係数
						}
						if (r > 45 && r < 135)
						{
							//上
							*down = true;//主人の下の部分が衝突している
							*y = by - 30.0f;//ブロック位置-主人公の幅
											//種類を渡すのスタートとゴールのみ変更する
							if (m_map2[i][j] >= 2)
								*bt = m_map2[i][j];//ブロックの要素(type)を主人公に渡す
							*vy = 0.0f;
						}
						if (r > 120 && r < 225)
						{
							//左
							*left = true;//主人公の右の部分が衝突している
							*x = bx - 30.0f + (scroll);//ブロック位置-主人公の幅
							*vx = -0.2f;//-VX*反発係数
						}
						if (r > 210 && r < 315)
						{
							//下
							*up = true;//主人公の上の部分が衝突している
							*y = by + 27.0f;//ブロックの位置+主人公の幅
							if (*vy < 0)
							{
								*vy = 0.0f;
							}
						}
					}
				}
			}
		}
	}
}


