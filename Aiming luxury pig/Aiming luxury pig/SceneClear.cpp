
//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"

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
	Font::SetStrTex(L"ぱりぴ");
	Font::SetStrTex(L"paripi");

	//クリアオブジェクト作成
	CObjClear* obj = new CObjClear();//クリアオブジェクト作成
	Objs::InsertObj(obj, OBJ_CLEAR, 10);//クリアオブジェクト登録
	
}

//実行中メソッド
void CSceneClear::Scene()
{

}