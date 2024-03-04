#pragma once
#include "Bullet.h"
#include "MyDxlibCommon.h"
#include "DxLib.h"

class Enemy
{
public:
	/*publicメンバ変数*/
	int X=NULL;//x座標
	int Y=NULL;//y座標
	/*コンストラクタ*/
	Enemy();
	/*Init*/
	void Init(int x, int y, int r, int speed,int visible);
	/*Getter*/
	/*Setter*/
	/*メンバ関数*/
	void Update();//処理の更新
	void Draw();//表示の更新
	void DebugDraw();//Debug表示の更新
private:
	/*privateメンバ変数*/
	int _r=NULL;//半径
	int _speed=NULL;//スピード
	int _bulletSpeed=NULL;//弾丸の速度
	//変更される可能性の無いものはここで初期化
	unsigned int _color = ColorCode::AQUA;//色
	unsigned int _hitColor = ColorCode::RED;//Hit色
	bool _isHit = false;//当たり判定
	bool _isVisible = false;//表示判定
};

/*コンストラクタ*/
/// <summary>
/// Enemyのコンストラクタ(インスタンス作成のみ)
/// </summary>
Enemy::Enemy(){}

/*Init*/
void Enemy::Init(int x, int y, int r, int speed,int visible)
{

}

/// <summary>
/// 計算処理の更新
/// </summary>
void Enemy::Update()
{
	//移動
	Y += _speed;
	//反転
	if (Y > 640 || Y < 80)
	{
		_speed = -_speed;
	}
}

/// <summary>
/// 表示処理の更新
/// </summary>
void Enemy::Draw()
{
	DrawCircle(X, Y, _r, _color, 1);
}

void Enemy::DebugDraw()
{

}