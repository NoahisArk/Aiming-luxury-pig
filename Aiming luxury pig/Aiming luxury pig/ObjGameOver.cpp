//使用するへっだーふぁいる
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjGameOver.h"

//使用するネームスペー主
using namespace GameL;

//イニシャライズ
void CObjGameOver::Init()
{
	m_key_flag = false;//キーフラグ
}

//アクション
void CObjGameOver::Action()
{
	//エンターキーを押してシーン:げーむTitleに移行する
	if (Input::GetVKey(VK_RETURN) == true)
	{
		Scene::SetScene(new CSceneTitle());
		m_key_flag = false;
	}
	else
	{
		m_key_flag = true;
    }
}

//ドロ
void CObjGameOver::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	
	

		RECT_F src;//描画元切り取り位置
		RECT_F dst;//描画先表示位置

	Font::SetStrTex(L"橘お肉");
	Font::SetStrTex(L"橘お肉");
	Font::SetStrTex(L"橘お肉 Enter_Key");
	
		src.m_top = -1000.0f;
		src.m_left = 100.0f;
		src.m_right = 600.0f;
		src.m_bottom =50.0f;

		dst.m_top = -50.0f;
		dst.m_left = 0.0f;
		dst.m_right = 1050.0;
		dst.m_bottom = 1500.0;




		Draw::Draw(3, &src, &dst, c, 0.0f);

		
	
}