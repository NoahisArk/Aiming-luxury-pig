#pragma once
//�g�p����ւ�
#include "GameL\SceneObjManager.h"
//�g�p����˂ނ���
using namespace GameL;

//�I�u�W�F�N�g���肠
class CObjClear :public CObj
{
public:
	CObjClear() {};
	~CObjClear() {};
	void Init();
	void Action();
	void Draw();
private:
	bool m_key_flag;
};