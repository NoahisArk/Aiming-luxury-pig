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
	
	

		RECT_F src;//�`�挳�؂���ʒu
		RECT_F dst;//�`���\���ʒu

	Font::SetStrTex(L"�k����");
	Font::SetStrTex(L"�k����");
	Font::SetStrTex(L"�k���� Enter_Key");
	
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