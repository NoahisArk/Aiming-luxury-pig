
//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�ւ����[
#include "SceneClear.h"
#include "GameHead.h"

//�R���X�g���N�^
CSceneClear::CSceneClear()
{

}
//�f�X�g���N�^
CSceneClear::~CSceneClear()
{


}
//���������\�b�h
void CSceneClear::InitScene()
{
	Font::SetStrTex(L"�ς��");
	Font::SetStrTex(L"paripi");

	//�N���A�I�u�W�F�N�g�쐬
	CObjClear* obj = new CObjClear();//�N���A�I�u�W�F�N�g�쐬
	Objs::InsertObj(obj, OBJ_CLEAR, 10);//�N���A�I�u�W�F�N�g�o�^
	
}

//���s�����\�b�h
void CSceneClear::Scene()
{

}