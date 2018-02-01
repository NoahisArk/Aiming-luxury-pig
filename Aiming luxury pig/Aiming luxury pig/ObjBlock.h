#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g:�u���b�N&�w�i
class CObjBlock :public CObj
{
public:
	CObjBlock(int map2[20][250]);
	~CObjBlock() {};
	void Init();//�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();//�h���[

	void SetScroll(float s) { m_scroll = s; }
	float GetScroll()		{ return m_scroll; }
	//�u���b�N�Ƃ̓����蔻��
	void BlockHit(
		float *x, float*y, bool scroll_on,
		bool*up, bool*down, bool*left, bool*right,
		float*vx, float*vy, int*bt
	);	

private:
	void BlockDraw(float x, float y, RECT_F*dst, float c[]);
	int m_map2[20][250];//�}�b�v���m�[�}��

	float m_scroll;//���E�X�N���[���p

	//�e�X�g�p�ϐ�
	//float m_px, m_py;//�e�X�g�p��_�\���p
};