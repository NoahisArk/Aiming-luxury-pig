#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�G
class CObjBombEnemy :public CObj
{
public:
	CObjBombEnemy(float x, float y);
	CObjBombEnemy() {};
	~CObjBombEnemy() {};
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

	int m_ani_time;//�A�j���[�V�����t���[��
	int m_ani_frame;//�`��t���[��

	float m_speed_power;//�X�s�[�h�p���[
	float m_ani_max_time;//�A�j���[�V��������

						 //block�Ƃ̏Փˏ�Ԋm�F�p
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;

	//�ړ��̌�������p
	bool m_move;
};
