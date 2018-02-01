//使用するヘッダーファイル
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjTitle.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjTitle::Init()
{
	m_key_flag = false;
}

//アクション
void CObjTitle::Action()
{
	//エンターキーを押してシーン:select画面に移行する
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneMain());
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}
}

//ドロー
void CObjTitle::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	src.m_top	 = 0.0f;
	src.m_left	 = 10.0f;
	src.m_right	 = 650.0f;
	src.m_bottom = 1000.0f;

	dst.m_top	 = 80.0f;
	dst.m_left	 = 50.0f;
	dst.m_right	 = 1000.0f;
	dst.m_bottom = 1200.0f;

	Draw::Draw(4, &src, &dst, c, 0.0f);
}