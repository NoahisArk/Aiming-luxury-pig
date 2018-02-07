//�g�p����ւ��ӂ�����
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\UserData.h"

#include "GameHead.h"
#include "ObjClear.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjClear::Init()
{
	m_key_flag = false;
	//Save::Open();
	
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
	
	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

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

	//m_time����b�������߂�
	int minute = 0;//��
	int second = 0;//�b
	
	second = (m_time / 60) % 60;//�b
	minute = (m_time / 60) / 60;//��

	wchar_t str[128];
	//���F�b�̒l�𕶎���

	if (second<10)
		swprintf_s(str, L"%d��0%d�b", minute, second);//�b��1�s�ڂ�0��p��
	else
		swprintf_s(str, L"%d��%d�b", minute, second);

	Font::StrDraw(str, 10, 10, 20, c);


	Draw::Draw(4, &src, &dst, c, 0.0f);
}