#pragma once
#include "MyDxlibCommon.h"
#include "DxLib.h"

class Bullet
{
public:
	/*publicメンバ変数*/
	int X;//X座標
	int Y;//Y座標
	/*コンストラクタ*/
	Bullet(int x, int y,int r, int speed, unsigned int color);
	/*メンバ関数*/
	void Update();
	void Draw();
	void DebugDraw();
private:
	/*privateメンバ変数*/
	int _r;
	int _speed;
	unsigned int _color;
};

Bullet::Bullet(int x, int y, int r, int speed, unsigned int color):
	X(x),
	Y(y),
	_r(r),
	_speed(speed),
	_color(color)
{
	//インスタンス作成時に変更する可能性があるものだけコンストラクタで初期化。
}

/// <summary>
/// 計算処理の更新
/// </summary>
void Bullet::Update()
{
	X += _speed;
}

/// <summary>
/// 表示処理の更新
/// </summary>
void Bullet::Draw()
{
	DrawCircle(X,Y,_r,_color,1);
}

/// <summary>
/// Debug表示の更新
/// </summary>
void Bullet::DebugDraw()
{

}