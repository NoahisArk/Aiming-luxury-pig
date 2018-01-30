//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "GameHead.h"
#include "ObjTrap.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjTrap::CObjTrap(float x, float y)
{
	m_px = x;//�ʒu
	m_py = y;
}
//�C�j�V�����C�Y
void CObjTrap::Init()
{
	//block�Ƃ̏Փˏ�Ԋm�F�p
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	//�����蔻��p��HitBox���쐬
	Hits::SetHitBox(this, m_px, m_py, 30, 30, ELEMENT_ENEMY, OBJ_TRAP, 1);
}

//�A�N�V����
void CObjTrap::Action()
{
	//�u���b�N�^�C�v���m�p�̕ϐ����Ȃ����߂̃_�~�[
	int d;

	//�u���b�N�Ƃ̓����蔻����s
	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	pb->BlockHit(&m_px, &m_py, false,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
		&d);

	//�u���b�N���������Ă���
	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//HitBox�̈ʒu�̕ύX
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_px + block->GetScroll(), m_py);

	//��l���̈ʒu���擾
	//CObjPigHero*hero = (CObjPigHero*)Objs::GetObj(OBJ_PIGHERO);

	//�G�Ɠ������Ă��邩�m�F
	if (hit->CheckObjNameHit(OBJ_PIGHERO) != nullptr)
	{
			//���g�ɍ폜���߂��o���B
			this->SetStatus(false);

			//�V�[�����Q�[���I�[�o�[�Ɉڍs����
			Scene::SetScene(new CSceneGameOver());
	}
}

//�h���[
void CObjTrap::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f, 1.0f, 1.0f, 1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top    = 307.0f;
	src.m_left   = 162.0f;
	src.m_right  = -0.0f;
	src.m_bottom = 450.0f;

	//�u���b�N���������Ă���
	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//�\���ʒu�̐ݒ�
	dst.m_top    = 0.0f + m_py;
	dst.m_left   = (     0.0f*m_posture) + m_px + block->GetScroll();
	dst.m_right  = (30 - 0.0f*m_posture) + m_px + block->GetScroll();
	dst.m_bottom = 30.0f + m_py;

	//�`��
	Draw::Draw(0, &src, &dst, c, 0.0f);
}