#pragma once
//�g�p����ւ����[
#include "GameL\SceneObjManager.h"
//�g�p����l�[������0-
using namespace GameL;

//�I�u�W�F�N�g�F���[�ނ��[��
class CObjGameOver :public CObj
{
public :
	CObjGameOver() {};
	~CObjGameOver() {};
	void Init();
	void Action();
	void Draw();
private:
	bool m_key_flag;


};