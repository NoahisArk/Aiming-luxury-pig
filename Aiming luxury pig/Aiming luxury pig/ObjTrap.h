#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�G
class CObjTrap :public CObj
{
public:
	CObjTrap(float x, float y);
	CObjTrap() {};
	~CObjTrap() {};
	void Init();//�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();//�h���[

	float GetVx() { return m_vx; }

private:
	float m_px;//�ʒu
	float m_py;
	float m_vx;//�ړ��x�N�g��
	float m_vy;
	float m_posture;//�p��

	bool  m_del;

	//block�Ƃ̏Փˏ�Ԋm�F�p
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;
};
