#pragma once
#include "Bullet.h"
#include "MyDxlibCommon.h"
#include "DxLib.h"

class Enemy
{
public:
	/*publicメンバ変数*/
	int X;//x座標
	int Y;//y座標
	/*コンストラクタ*/
	Enemy(int x, int y, int r, int speed);
	/*Init*/
	void Init();
	/*Getter*/
	/*Setter*/
	/*メンバ関数*/
	void Update();//処理の更新
	void Draw();//表示の更新
	void DebugDraw();//Debug表示の更新
private:
	/*privateメンバ変数*/
	int _r;//半径
	int _speed;//スピード
	int _bulletSpeed;//弾丸の速度
	//変更される可能性の無いものはここで初期化
	unsigned int _color = ColorCode::AQUA;//色
	unsigned int _hitColor = ColorCode::RED;//Hit色
	bool _isHit = false;//当たり判定
	bool _isVisible = true;//表示判定
	//PlayerBullet.
	Bullet* _pEBullet;
};

/// <summary>
/// Enemyコンストラクタ。
/// </summary>
/// <param name="x">X座標</param>
/// <param name="y">Y座標</param>
/// <param name="r">半径</param>
/// <param name="speed">速度</param>
Enemy::Enemy(int x, int y, int r, int speed) :
	X(x),
	Y(y),
	_r(r),
	_speed(speed),
	_bulletSpeed(-4),
	_pEBullet(nullptr)
{
	//↑インスタンス作成時に変更する可能性があるものだけコンストラクタで初期化。
}

/*Init*/
/// <summary>
/// 編集初期化
/// </summary>
void Enemy::Init()
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

	/*EnemyBullet発射*/
	if (_pEBullet == nullptr)
	{
		_pEBullet = new Bullet(X, Y, 32, _bulletSpeed, ColorCode::MAGENTA);
	}

	/*EnemyBullet更新*/
	if (_pEBullet != nullptr)
	{
		_pEBullet->Update();
	}

	//弾丸が存在し、かつ、画面から出ていたら削除
	if (_pEBullet != nullptr && (_pEBullet->X < -120))
	{
		//削除処理
		delete _pEBullet;
		_pEBullet = nullptr;

		//弾丸速度上昇
		if (_bulletSpeed > -16)
		{
			_bulletSpeed += -1;
		}

	}

}

/// <summary>
/// 表示処理の更新
/// </summary>
void Enemy::Draw()
{
	DrawCircle(X, Y, _r, _color, 1);

	/*EnemyBullet*/
	if (_pEBullet != nullptr)
	{
		_pEBullet->Draw();
	}
}

void Enemy::DebugDraw()
{

}