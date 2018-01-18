//�g�p����ւ��ӂ�����
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjClear.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjClear::Init()
{

	m_key_flag = false;

}

//�A�N�V����
void CObjClear::Action()
{
	//�G���^�[�L�[�������ăV�[��:�Q�[�����C���Ɉڍs����
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
//�h���[
void CObjClear::Draw()
{
float c[4] = { 1.0f,1.0f,1.0f,1.0f };

Font::StrDraw(L"�ۏĂ��k", 150, 250, 32, c);
Font::StrDraw(L"��^v^", 200, 430, 32, c);

	Font::StrDraw(L"^v^", 320, 400, 32, c);
}