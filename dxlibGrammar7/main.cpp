#pragma once
//オブジェクトヘッダ
#include "Bullet.h"
#include "Player.h"
#include "Enemy.h"
//共有ヘッダ(依存関係が強いものほど最後)
#include "MyDxlibCommon.h"
#include "DxLib.h"//何処でも使うので最後



/*概要*/
//この『Grammerシリーズ』ではDxLibやゲームプログラミングの基礎的な使い方と考え方を段階的にやります。
//解説する内容は必要最低限です。抜けが出ます。また詳細な解説をしていません。
//随時リファレンスや外部サイトを参考にしてください。
//【リファレンス】
// https://dxlib.xsrv.jp/dxfunc.html

/*今回の要素*/
//・ゲームプログラミング
// 　- オブジェクト指向を用いたゲームプログラミング
//・C/C++言語
//   - クラス

/*コメント*/
//本来ならクラスを作る際に.hと.cppに分けるが、コードの簡便化のために全て.hに記述している。
//実際にゲーム作りの際には.hと.cppに分けてほしい。
//コンストラクタとか、ゲッターとかセッターとかの解説はここではしない。
//また、当たり判定のカラーコードなど、よく使う定数などは"Common.h"にまとめた。



//Dxlibのエントリーポイント
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	/*変数*/
	LONGLONG roopStartTime = 0;
	bool gameRoop = true;

	/*Dxlib初期化*/
	SetGraphMode(WindowSize::SIZE_X, WindowSize::SIZE_Y, 32);//画面サイズと解像度
	ChangeWindowMode(true);//Windowモード
	if (DxLib_Init() == -1) { return -1; }//Dxlib初期化
	SetDrawScreen(DX_SCREEN_BACK);//ダブルバッファリング

	/*ゲーム変数*/
	int playerDrawHandle = LoadGraph("Chara.png");
	//クラスは基本的にポインタで運用する。
	Player* pPlayer = new Player{ playerDrawHandle, 20, 360, 12, 4 };
	Enemy* pEnemy = new Enemy{ 1100,360,64,2 };

	/*ゲームループ部*/
	//gameRoop.
	while (gameRoop)
	{
		//ループ開始時刻の確保
		roopStartTime = GetNowHiPerformanceCount();
		//裏画面の初期化
		ClearDrawScreen();

		/*Update*/
		//player.
		pPlayer->Update();
		//enemy.
		pEnemy->Update();

		//Bullet.


		/*Draw*/
		//player.
		pPlayer->Draw();
		//enemy.
		pEnemy->Draw();

		/*DebguDraw*/
		int debugNum = 0;
		DrawFormatString(0, 0, ColorCode::RED, "WSAD(上下左右),左クリック(ショット)");
		DrawFormatString(0, 20, ColorCode::RED, "debugNum:%d",debugNum);


		//裏画面を表へ
		ScreenFlip();
		//リフレッシュ処理(-1ならエラー)
		if (ProcessMessage() < 0) { break; }
		//ループ終了処理
		if (CheckHitKey(KEY_INPUT_ESCAPE)) { break; }
		//fps固定(60fps:16.66ms)
		//ループ開始時刻から16.66ms経つまで停止
		while (GetNowHiPerformanceCount() - roopStartTime < 16667) {}
	}

	/*終了処理*/
	DxLib_End();//Dxlib終了処理
	return 0;//終了 
}
