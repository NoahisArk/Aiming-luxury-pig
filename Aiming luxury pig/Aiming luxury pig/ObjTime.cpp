//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"
#include "GameHead.h"
#include "ObjTime.h"
#include"GameL\UserData.h"
//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjTime::Init()
{
	m_time = 0;
	m_flag_time = false;
}

//アクション
void CObjTime::Action()
{
	//主人公を取得
	CObjPigHero*hero = (CObjPigHero*)Objs::GetObj(OBJ_PIGHERO);

	if (hero != NULL)
	{
		//スタートブロックを踏んでいるならフラグをオンにする
		if (hero->GetBT() == 2)
		{
			m_flag_time = true;
		}
		else if (hero->GetBT() == 3)
		{
			m_flag_time = false;
			if (hero->GetBT() == 3)
			{
				this->SetStatus(false);
				//Hits::DeleteHitBox(this);				
				Scene::SetScene(new CSceneClear());
			}
		}
	}
	
	//フラグがオンの時、時間を進める
	if (m_flag_time == true)
	{
		m_time++;
		((UserData*)Save::GetData())->m_time = m_time;
	}
}

//ドロー
void CObjTime::Draw()
{
	//m_timeから秒分を求める
	int minute;//分
	int second;//秒

	second = (m_time / 60) % 60;//秒
	minute = (m_time / 60) / 60;//分

	float c[4] = { 0.0f, 0.0f, 0.0f, 1.0f };

	wchar_t str[128];
	//分：秒の値を文字列化

	if (second<10)
		swprintf_s(str, L"%d分0%d秒", minute, second);//秒の1行目に0を用意
	else
		swprintf_s(str, L"%d分%d秒", minute, second);

	Font::StrDraw(str, 10, 10, 20, c);
}