//�g�p����ւ����[�ӂ�����
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjGameOver.h"

//�g�p����l�[���X�y�[��
using namespace GameL;

//�C�j�V�����C�Y
void CObjGameOver::Init()
{
	m_key_flag = false;//�L�[�t���O
}

//�A�N�V����
void CObjGameOver::Action()
{
	//�G���^�[�L�[�������ăV�[��:���[��Title�Ɉڍs����
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

//�h��
void CObjGameOver::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"�k���񂨓�", 200, 420, 32, c);
	Font::StrDraw(L"�k���񂨓�", 350, 320, 32, c);
	Font::StrDraw(L"�k���񂨓�", 180, 190, 32, c);
}