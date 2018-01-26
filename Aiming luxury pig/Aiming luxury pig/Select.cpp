//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "Select.h"
#include "GameHead.h"

//コンストラクタ
CSelect::CSelect()
{

}

//デストラクタ
CSelect::~CSelect()
{

}

//ゲームメイン初期化メソッド
void CSelect::InitScene()
{
	//音楽情報の読み込み
	//Audio::LoadAudio(0, L"title.wav", SOUND_TYPE::BACK_MUSIC);

	//バックミュージックスタート
	//float Volume = Audio::VolumeMaster(-0.8f);//マスターボリュームを0.8下げる
	//Audio::Start(0);	//音楽スタート

	//出力させる文字のグラフィックを作成
	Font::SetStrTex(L"PIG-TO-ESCAPE");

	//セレクトオブジェクト作成
	CObjSelect* obj = new CObjSelect();
	Objs::InsertObj(obj, OBJ_SELECT, 10);

	Draw::LoadImageW(L"選択画面.png", 6, TEX_SIZE_512);


}

//ゲームメイン実行中メソッド
void CSelect::Scene()
{

}