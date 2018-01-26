//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjBlock.h"
#include "ObjSelect.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjSelect::Init()
{
	m_key_flag = false;
}

//�A�N�V����
void CObjSelect::Action()
{
	//��������͂��ăV�[��:�Q�[�����C���Ɉڍs����
	if (Input::GetVKey('1') == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneMain());
			m_key_flag = false;
		}
	}
	if (Input::GetVKey('2') == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneMain());
			m_key_flag = false;
		}
	}
	if (Input::GetVKey('3') == true)
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

//�h���[
void CObjSelect::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 700.0f;
	src.m_bottom = 1100.0f;

	dst.m_top = 40.0f;
	dst.m_left = 50.0f;
	dst.m_right = 1200.0f;
	dst.m_bottom = 1200.0f;

	Draw::Draw(6, &src, &dst, c, 0.0f);
}