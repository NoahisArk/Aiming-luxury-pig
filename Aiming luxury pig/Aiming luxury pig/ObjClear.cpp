//使用するへだふぁいる
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjClear.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjClear::Init()
{
	m_key_flag = false;
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


		src.m_top = -450.0f;
		src.m_left = 200.0f;
		src.m_right = 402.0f;
		src.m_bottom = 300.0f;

		dst.m_top = -50.0f;
		dst.m_left = 0.0f;
		dst.m_right = 800.0;
		dst.m_bottom = 1320.0;


		Draw::Draw(4, &src, &dst, c, 0.0f);



	
}