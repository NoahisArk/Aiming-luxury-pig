//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"

//使用するネームスペース
using namespace GameL;

//使用へっだー
#include "SceneClear.h"
#include "GameHead.h"

//コンストラクタ
CSceneClear::CSceneClear()
{

}

//デストラクタ
CSceneClear::~CSceneClear()
{

}

//初期かメソッド
void CSceneClear::InitScene()
{
	//音楽情報の読み込み
	Audio::LoadAudio(0, L"clear.wav", BACK_MUSIC);

	//ボリュームを1.0に戻す
	float v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster(1.0 - v);

	//音楽スタート
	Audio::Start(0);


	Font::SetStrTex(L"");
	Font::SetStrTex(L"");

	Draw::LoadImageW(L"Game Clear.png", 4, TEX_SIZE_512);

	//クリアオブジェクト作成
	CObjClear* obj = new CObjClear();//クリアオブジェクト作成
	Objs::InsertObj(obj, OBJ_CLEAR, 12);//クリアオブジェクト登録
}

//実行中メソッド
void CSceneClear::Scene()
{

}