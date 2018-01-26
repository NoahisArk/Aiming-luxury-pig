//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\DrawFont.h"
#include "GameL\UserData.h"
#include "GameL\Audio.h"
//使用するネームスペース
using namespace GameL;

//使用するヘッダー
#include "SceneMain.h"
#include "GameHead.h"

//コンストラクタ
CSceneMain::CSceneMain()
{


}

//デストラクタ
CSceneMain::~CSceneMain()
{


}

//初期化メソッド
void CSceneMain::InitScene()
{

	//音楽情報の読み込み
	Audio::LoadAudio(0, L"Scenetitle.wav", BACK_MUSIC);

	Audio::LoadAudio(1, L"jamp.wav", EFFECT);

	//ボリュームを1.5増やす
	float v = Audio::VolumeMaster(1.5);

	//音楽スタート
	Audio::Start(0);

	//外部データの読み込み(ステージ情報)
	unique_ptr<wchar_t>p;//ステージ情報ポインター
	int size;//ステージ情報の大きさ
	p = Save::ExternalDataOpen(L"Book4_1.csv", &size);//外部データの読み込み
	p = Save::ExternalDataOpen(L"ノーマル.csv", &size);//外部データの読み込み
	p = Save::ExternalDataOpen(L"天国.csv", &size);//外部データの読み込み

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
	//Font作成
	Font::SetStrTex(L"0123456789分秒");

	//グラフィック読み込み : 背景,クリア,ゲームオーバ
	Draw::LoadImageW(L"background.png", 1, TEX_SIZE_512);
	//グラフィック読み込み : ブロック,罠
	Draw::LoadImageW(L"Block.png", 0, TEX_SIZE_512);
	//グラフィック読み込み : 主人公,オオカミ,オオカミ弾
	Draw::LoadImageW(L"character.png", 2, TEX_SIZE_512);


	//主人公オブジェクト作成
	CObjPigHero* obj = new CObjPigHero();
	Objs::InsertObj(obj, OBJ_PIGHERO, 10);

	//blockオブジェクト作成
	CObjBlock* objb = new CObjBlock(map1,map2,map3);
	Objs::InsertObj(objb, OBJ_BLOCK, 9);

	//タイムオブジェクト作成
	CObjTime* objt = new CObjTime();
	Objs::InsertObj(objt, OBJ_TIME, 11);
}

//実行中メソッド
void CSceneMain::Scene()
{

}