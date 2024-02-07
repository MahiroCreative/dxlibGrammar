#pragma once
#include "MyGameCommon.h"
#include "DxLib.h"

class Player
{
private:
	/*privateメンバ変数*/
	int _r;//半径
	int _speed;//スピード
	int _maxShotNum;//最大弾数
	int _shotCount;//発射弾数
	//変更される可能性の無いものはここで初期化
	int _colColer = ColorCode::LIME;//コリジョン色
	int _scale = 1;//スケール
	int _rotate = 0;//回転度
	bool _isHit = false;//当たり判定
	bool _isVisible = true;//表示判定
public:
	/*publicメンバ変数*/
	int X;//x座標
	int Y;//y座標

	/*コンストラクタ*/
	Player(int x, int y, int r, int speed, int maxShotNum);
	
	/*Getter*/

	/*Setter*/

	/*メンバ関数*/
	void Update();//処理の更新
	void Draw();//表示の更新
	void DebugDraw();//Debug表示の更新
};

/*コンストラクタ*/
/// <summary>
/// Playerのコンストラクタ
/// </summary>
/// <param name="x">X座標</param>
/// <param name="y">Y座標</param>
/// <param name="r">半径</param>
/// <param name="speed">速度</param>
/// <param name="maxShotNum">最大発射数</param>
Player::Player(int x,int y,int r,int speed,int maxShotNum) :
	X(x),
	Y(y),
	_r(r),
	_speed(speed),
	_maxShotNum(maxShotNum),
	_shotCount(0)
{
	//↑変更される可能性のあるものだけコンストラクタで初期化している。
}

/*ゲッター*/


/*セッター*/



/*メンバ関数*/
/// <summary>
/// 計算処理の更新
/// </summary>
void Player::Update()
{

}
/// <summary>
/// 表示処理の更新
/// </summary>
void Player::Draw()
{

}
/// <summary>
/// Debug表示の更新
/// </summary>
void Player::DebugDraw()
{

}
