//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"

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
	//���y���̓ǂݍ���
	Audio::LoadAudio(0, L"clear.wav", BACK_MUSIC);

	//�{�����[����1.0�ɖ߂�
	float v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster(1.0 - v);

	//���y�X�^�[�g
	Audio::Start(0);

	Font::SetStrTex(L"");
	Font::SetStrTex(L"");

	Draw::LoadImageW(L"Game Clear.png", 4, TEX_SIZE_512);

	//�N���A�I�u�W�F�N�g�쐬
	CObjClear* obj = new CObjClear();//�N���A�I�u�W�F�N�g�쐬
	Objs::InsertObj(obj, OBJ_CLEAR, 12);//�N���A�I�u�W�F�N�g�o�^
}

//���s�����\�b�h
void CSceneClear::Scene()
{

}