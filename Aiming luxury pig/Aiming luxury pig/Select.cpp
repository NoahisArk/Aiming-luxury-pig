//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "Select.h"
#include "GameHead.h"

//�R���X�g���N�^
CSelect::CSelect()
{

}

//�f�X�g���N�^
CSelect::~CSelect()
{

}

//�Q�[�����C�����������\�b�h
void CSelect::InitScene()
{
	//���y���̓ǂݍ���
	//Audio::LoadAudio(0, L"title.wav", SOUND_TYPE::BACK_MUSIC);

	//�o�b�N�~���[�W�b�N�X�^�[�g
	//float Volume = Audio::VolumeMaster(-0.8f);//�}�X�^�[�{�����[����0.8������
	//Audio::Start(0);	//���y�X�^�[�g

	//�o�͂����镶���̃O���t�B�b�N���쐬
	Font::SetStrTex(L"PIG-TO-ESCAPE");

	//�Z���N�g�I�u�W�F�N�g�쐬
	CObjSelect* obj = new CObjSelect();
	Objs::InsertObj(obj, OBJ_SELECT, 10);

	Draw::LoadImageW(L"�I�����.png", 6, TEX_SIZE_512);


}

//�Q�[�����C�����s�����\�b�h
void CSelect::Scene()
{

}