//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"
#include "GameHead.h"
#include "ObjPigHero.h"
#include "ObjClear.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjBlock::CObjBlock( int map2[20][250])
{
	
	//�}�b�v�f�[�^���R�s�[:�m�[�}��
	memcpy(m_map2, map2, sizeof(int)*(20 * 250));
	
}
//�C�j�V�����C�Y
void CObjBlock::Init()
{
	m_scroll = 0.0f;
}

//�A�N�V����
void CObjBlock::Action()
{
	//��l���ʒu���擾
	CObjPigHero*hero = (CObjPigHero*)Objs::GetObj(OBJ_PIGHERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//����X�N���[�����C��
	if (hx < 80)
	{
		hero->SetX(80);//��l���̓��C���𒴂��Ȃ��悤�ɂ���
		m_scroll -= hero->GetVX();//��l�����{�������ׂ��l��m_scroll�ɉ�����
	}

	//�O���X�N���[�����C��
	if (hx > 300)
	{
		hero->SetX(300);//��l���̓��C���𒴂��Ȃ��悤�ɂ���
		m_scroll -= hero->GetVX();//��l�����{�������ׂ����̒l��m_scroll�ɉ�����
	}
	//�G�o�����C��
	//��l���̈ʒu+500��G�o�����C���ɂ���
	float line = hx + (-m_scroll) + 300;

	//�G�o�����C����v�f�ԍ���
	int ex = ((int)line) / 30;

	//�G�o�����C���̗������
	for (int i = 0; i < 20; i++)
	{
		//��̒�����4��T��
		if (m_map2[i][ex] == 4)
		{
			//4������΁A�G���o��
			CObjEnemy* obje = new CObjEnemy(ex * 30.0f, i * 30.0f);
			Objs::InsertObj(obje, OBJ_ENEMY, 13);

			//�G�o���ꏊ�̒l��0�ɂ���
			m_map2[i][ex] = 0;
		}
	}
	//�G�o�����C���̗������
	for (int i = 0; i < 20; i++)
	{
		//��̒�����8��T��
		if (m_map2[i][ex] == 8)
		{
			//4������΁A�G���o��
			CObjBombEnemy* obje = new CObjBombEnemy(ex * 30.0f, i * 30.0f);
			Objs::InsertObj(obje, OBJ_BOMBENEMY, 13);

			//�G�o���ꏊ�̒l��0�ɂ���
			m_map2[i][ex] = 0;
		}
	}
	//㩏o�����C���̗������
	for (int i = 0; i < 20; i++)
	{
		//��̒�����6��T��
		if (m_map2[i][ex] == 6)
		{
			//6������΁A㩂��o��
			CObjTrap* obje = new CObjTrap(ex * 30.0f, i * 30.0f);
			Objs::InsertObj(obje, OBJ_TRAP, 12);

			//㩏o���ꏊ�̒l��0�ɂ���
			m_map2[i][ex] = 0;
		}
	}
}
//�h���[
void CObjBlock::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�w�i�\��
	src.m_top    = 2.0f;
	src.m_left   = 2.0f;
	src.m_right  = 402.0f;
	src.m_bottom = 151.0f;
	dst.m_top    = 0.0f;
	dst.m_left   = 0.0f;
	dst.m_right  = 800.0;
	dst.m_bottom = 600.0;
	Draw::Draw(1, &src, &dst, c, 0.0f);

	//�}�b�v�`�b�v�ɂ��block�ݒu
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 250; j++)
		{
			if (m_map2[i][j] > 0)
			{
				//�\���ʒu�̐ݒ�
				dst.m_top    = i * 30.0f;
				dst.m_left   = j * 30.0f  + m_scroll;
				dst.m_right  = dst.m_left + 30.0;
				dst.m_bottom = dst.m_top  + 30.0;
				if (m_map2[i][j] == 2)
				{
					//�X�^�[�g�u���b�N : �؂���ʒu
					src.m_top = 2.0f;
					src.m_left = 164.0f;
					src.m_right = 324.0f;
					src.m_bottom = 149.0f;
					//�`��
					Draw::Draw(0, &src, &dst, c, 0.0f);
				}
				else if (m_map2[i][j] == 3)
				{
					//�S�[���u���b�N : �؂���ʒu
					src.m_top = 2.0f;
					src.m_left = 3.0f;
					src.m_right = 160.0f;
					src.m_bottom = 149.0f;

					//�`��
					Draw::Draw(0, &src, &dst, c, 0.0f);
				}
				else if (m_map2[i][j] == 5)
				{
					//�y : �؂���ʒu
					src.m_top    =   3.0f;
					src.m_left   = 330.0f;
					src.m_right  = 400.0f;
					src.m_bottom = 149.0f;

					//�`��
					Draw::Draw(0, &src, &dst, c, 0.0f);
				}
				else if (m_map2[i][j] == 7)
				{
					//�� : �؂���ʒu
					src.m_top    = 160.0f;
					src.m_left   =  10.0f;
					src.m_right  = 160.0f;
					src.m_bottom = 304.0f;

					//�`��
					Draw::Draw(0, &src, &dst, c, 0.0f);
				}
				else if (m_map2[i][j] == 4)
				{
					//�G(�I�I�J�~)�F�؂���ʒu
					;
				}
				else if (m_map2[i][j] == 6)
				{
					//�(�g���b�v)�F�؂���ʒu
					;
				}
				else if (m_map2[i][j] == 8)
				{
					//�G(�I�I�J�~(���e))�F�؂���ʒu
					;
				}
				else
				{
					BlockDraw(320.0f, 0.0f, &dst, c);
					//�`��
					//Draw::Draw(0, &src, &dst, c, 0.0f);
				}
			}
		}
	}
}

//BlockDrawMethod�֐�
//����1 float  x ;���\�[�X�؂���ʒuX
//����2 float  y ;���\�[�X�؂���ʒuY
//����3 RECT_F*dst;�`��ʒu
//����4 float c[];�J���[���
//�u���b�N������`��p�B���\�[�X�؂���ʒu�̂�x.y��
//�ݒ�ł���
void CObjBlock::BlockDraw(float x, float y, RECT_F*dst, float c[])
{
	RECT_F src;
	//�u���b�N : �؂���ʒu
	src.m_top    = 158.0f;
	src.m_left   = 175.0f;
	src.m_right  = src.m_left + 150.0f;
	src.m_bottom = src.m_top  + 145.0f;
	//�`��
	Draw::Draw(0, &src, dst, c, 0.0f);
}
//BlockHit�֐�
//����1 float*x�@      :������s��object��X�ʒu
//����2 float*y�@      :������s��object��Y�ʒu
//����3 bool  scroll_on:������s��object�̓X�N���[���̉e����^���邩�ǂ���(true=�^����@false=�^���Ȃ�)
//����4 bool* up       :�㉺���E����̏㕔���ɓ������Ă��邩�ǂ�����Ԃ�
//����5 bool* down     :�㉺���E����̉������ɓ������Ă��邩�ǂ�����Ԃ�
//����6 bool* left     :�㉺���E����̍������ɓ������Ă��邩�ǂ�����Ԃ�
//����7 bool* right    :�㉺���E����̉E�����ɓ������Ă��邩�ǂ�����Ԃ�
//����8 float* vx      :���E���莞�̔����ɂ��ړ������E�͂̒l��ς��ĕԂ�
//����9 float* vy      :�㉺���莞�ɂ�鎩�R�����^���̈ړ������E�͂̒l��ς��ĕԂ�
//����10 int*  bt      :����������A����ȃu���b�N�̃^�C�v��Ԃ�
//������s��object�ƃu���b�N������ŁA�����蔻��Ə㉺���E������s��
//���̌��ʂ͈���4�`10�ɕԂ�
void CObjBlock::BlockHit(
	float *x, float*y, bool scroll_on,
	bool*up, bool*down, bool *left, bool*right,
	float*vx, float*vy, int*bt
)
{
	//��l���̏Փˏ�Ԋm�F�p�t���O�̏�����
	*up    = false;
	*down  = false;
	*left  = false;
	*right = false;

	//����ł���block�̎�ނ̏�����
	*bt = 0;

	//mmap�̑S�v�f�ɃA�N�Z�X
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 250; j++)
		{
			if (m_map2[i][j] > 0 && m_map2[i][j] != 4)
			{
				//�v�f�ԍ������W�ɕύX
				float bx = j * 30.0f;
				float by = i * 30.0f;

				//�X�N���[���̉e��
				float scroll = scroll_on ? m_scroll : 0;

				//�I�u�W�F�N�g�ƃu���b�N�̓�����
				if ((*x + (-scroll) + 30.0f>bx) && (*x + (-scroll)<bx + 30.0f) && (*y + 30.0f>by) && (*y<by + 30.0f))
				{
					//�㉺���E����

					//vector�̍쐬
					float rvx = (*x + (-scroll)) - bx;
					float rvy = *y - by;
					//���������߂�
					float len = sqrt(rvx*rvx + rvy*rvy);
					//�p�x�����߂�
					float r = atan2(rvy, rvx);
					r = r*180.0f / 3.14f;

					if (r <= 0.0f)
						r = abs(r);
					else
						r = 360.0f - abs(r);
					//len��������̒����̂��Z���ꍇ����ɓ���
					if (len < 33.0f)
					{
						//�p�x�ŏ㉺���E�𔻒�
						if ((r < 30 && r>0) || r > 315)
						{
							//�E
							*right = true;//��l���̍��̕������Փ˂��Ă���
							*x = bx + 30.0f + (scroll);//�u���b�N�ʒu+��l���̕�
							*vx = 0.2f;//-VX*�����W��
						}
						if (r > 45 && r < 135)
						{
							//��
							*down = true;//��l�̉��̕������Փ˂��Ă���
							*y = by - 30.0f;//�u���b�N�ʒu-��l���̕�
											//��ނ�n���̃X�^�[�g�ƃS�[���̂ݕύX����
							if (m_map2[i][j] >= 2)
								*bt = m_map2[i][j];//�u���b�N�̗v�f(type)����l���ɓn��
							*vy = 0.0f;
						}
						if (r > 120 && r < 225)
						{
							//��
							*left = true;//��l���̉E�̕������Փ˂��Ă���
							*x = bx - 30.0f + (scroll);//�u���b�N�ʒu-��l���̕�
							*vx = -0.2f;//-VX*�����W��
						}
						if (r > 210 && r < 315)
						{
							//��
							*up = true;//��l���̏�̕������Փ˂��Ă���
							*y = by + 27.0f;//�u���b�N�̈ʒu+��l���̕�
							if (*vy < 0)
							{
								*vy = 0.0f;
							}
						}
					}
				}
			}
		}
	}
}


