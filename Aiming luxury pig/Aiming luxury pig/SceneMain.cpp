//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\DrawFont.h"
#include "GameL\UserData.h"
#include "GameL\Audio.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p����w�b�_�[
#include "SceneMain.h"
#include "GameHead.h"

//�R���X�g���N�^
CSceneMain::CSceneMain()
{


}

//�f�X�g���N�^
CSceneMain::~CSceneMain()
{


}

//���������\�b�h
void CSceneMain::InitScene()
{

	//���y���̓ǂݍ���
	Audio::LoadAudio(0, L"Scenetitle.wav", BACK_MUSIC);

	Audio::LoadAudio(1, L"jamp.wav", EFFECT);

	//�{�����[����1.5���₷
	float v = Audio::VolumeMaster(1.5);

	//���y�X�^�[�g
	Audio::Start(0);

	//�O���f�[�^�̓ǂݍ���(�X�e�[�W���)
	unique_ptr<wchar_t>p;//�X�e�[�W���|�C���^�[
	int size;//�X�e�[�W���̑傫��
	p = Save::ExternalDataOpen(L"Book4_1.csv", &size);//�O���f�[�^�̓ǂݍ���
	p = Save::ExternalDataOpen(L"�m�[�}��.csv", &size);//�O���f�[�^�̓ǂݍ���
	p = Save::ExternalDataOpen(L"�V��.csv", &size);//�O���f�[�^�̓ǂݍ���

	int map1[20][150];
	int count = 1;
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 150; j++)
		{
			int w = 0;
			swscanf_s(&p.get()[count], L"%d", &w);

			map1[i][j] = w;
			count += 2;
		}
	}
	int map2[20][250];
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 250; j++)
		{
			int w = 0;
			swscanf_s(&p.get()[count], L"%d", &w);

			map2[i][j] = w;
			count += 2;
		}
	}
	int map3[20][300];
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 300; j++)
		{
			int w = 0;
			swscanf_s(&p.get()[count], L"%d", &w);

			map3[i][j] = w;
			count += 2;
		}
	}
	//Font�쐬
	Font::SetStrTex(L"0123456789���b");

	//�O���t�B�b�N�ǂݍ��� : �w�i,�N���A,�Q�[���I�[�o
	Draw::LoadImageW(L"background.png", 1, TEX_SIZE_512);
	//�O���t�B�b�N�ǂݍ��� : �u���b�N,�
	Draw::LoadImageW(L"Block.png", 0, TEX_SIZE_512);
	//�O���t�B�b�N�ǂݍ��� : ��l��,�I�I�J�~,�I�I�J�~�e
	Draw::LoadImageW(L"character.png", 2, TEX_SIZE_512);


	//��l���I�u�W�F�N�g�쐬
	CObjPigHero* obj = new CObjPigHero();
	Objs::InsertObj(obj, OBJ_PIGHERO, 10);

	//block�I�u�W�F�N�g�쐬
	CObjBlock* objb = new CObjBlock(map1,map2,map3);
	Objs::InsertObj(objb, OBJ_BLOCK, 9);

	//�^�C���I�u�W�F�N�g�쐬
	CObjTime* objt = new CObjTime();
	Objs::InsertObj(objt, OBJ_TIME, 11);
}

//���s�����\�b�h
void CSceneMain::Scene()
{

}