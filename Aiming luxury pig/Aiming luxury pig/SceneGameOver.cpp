//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"

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
	Font::SetStrTex(L"橘お肉");
	Font::SetStrTex(L"橘お肉");
	Font::SetStrTex(L"橘お肉 Enter_Key");
	
	//ゲームオーバーオブジェ
	CObjGameOver* obj = new CObjGameOver();
	Objs::InsertObj(obj, OBJ_GAME_OVER,12 );

	Draw::LoadImageW(L"GameOver.png", 3, TEX_SIZE_512);

}

//実行中メソッド
void CSceneGameOver::Scene()
{

}