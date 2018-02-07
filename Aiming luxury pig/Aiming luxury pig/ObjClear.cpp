//使用するへだふぁいる
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\UserData.h"

#include "GameHead.h"
#include "ObjClear.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjClear::Init()
{
	m_key_flag = false;
	//Save::Open();
	
}

//アクション
void CObjClear::Action()
{


	
	//エンターキーを押してシーン:ゲームメインに移行する
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneTitle());
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}
}

//ドロー
void CObjClear::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	
	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	src.m_top    =    0.0f;
	src.m_left   =    0.0f;
	src.m_right  =  700.0f;
	src.m_bottom = 1100.0f;

	dst.m_top    =   60.0f;
	dst.m_left   =   50.0f;
	dst.m_right  = 1000.0f;
	dst.m_bottom = 1200.0f;

	float d[4] = { 1.0f,1.0f,1.0f,1.0f };
	int m_time = 0;
	m_time=((UserData*)Save::GetData())->m_time;

	//m_timeから秒分を求める
	int minute = 0;//分
	int second = 0;//秒
	
	second = (m_time / 60) % 60;//秒
	minute = (m_time / 60) / 60;//分

	wchar_t str[128];
	//分：秒の値を文字列化

	if (second<10)
		swprintf_s(str, L"%d分0%d秒", minute, second);//秒の1行目に0を用意
	else
		swprintf_s(str, L"%d分%d秒", minute, second);

	Font::StrDraw(str, 10, 10, 20, c);


	Draw::Draw(4, &src, &dst, c, 0.0f);
}