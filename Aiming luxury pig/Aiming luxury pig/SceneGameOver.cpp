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
#include "SceneGameOver.h"
#include "GameHead.h"

//コンストラクタ
CSceneGameOver::CSceneGameOver()
{

}

//デストラクタ
CSceneGameOver::~CSceneGameOver()
{


}

//初期かメソッド
void CSceneGameOver::InitScene()
{
	//出力させる文字のグラフィックを作成
	Font::SetStrTex(L"");
	Font::SetStrTex(L"");
	Font::SetStrTex(L"");
	
	//音楽情報の読み込み
	Audio::LoadAudio(0, L"gameover.wav", BACK_MUSIC);

	//ボリュームを1.0に戻す
	float v = Audio::VolumeMaster(0);//マスターボリュームを0.8下げる
	v = Audio::VolumeMaster((1.0 - v));

	//音楽スタート
	Audio::Start(0);

	//ゲームオーバーオブジェ
	CObjGameOver* obj = new CObjGameOver();
	Objs::InsertObj(obj, OBJ_GAME_OVER,12 );

	Draw::LoadImageW(L"Game Over.png", 3, TEX_SIZE_512);

}

//実行中メソッド
void CSceneGameOver::Scene()
{

}