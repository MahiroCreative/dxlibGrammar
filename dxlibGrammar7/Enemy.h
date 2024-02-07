#pragma once
#include "MyDxlibCommon.h"
#include "DxLib.h"

class Enemy
{
private:
	/*privateメンバ変数*/
	int _r;//半径
	int _speed;//スピード
	//変更される可能性の無いものはここで初期化
	unsigned int _color = ColorCode::AQUA;//色
	bool _isHit = false;//当たり判定
	bool _isVisible = true;//表示判定
public:
	/*publicメンバ変数*/
	int X;//x座標
	int Y;//y座標

	/*コンストラクタ*/
	Enemy(int x, int y, int r, int speed);

	/*Getter*/

	/*Setter*/

	/*メンバ関数*/
	void Update();//処理の更新
	void Draw();//表示の更新
	void DebugDraw();//Debug表示の更新
};