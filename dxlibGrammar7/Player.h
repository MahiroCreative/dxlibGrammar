#pragma once
#include "MyDxlibCommon.h"
#include "DxLib.h"

class Player
{
private:
	/*privateメンバ変数*/
	int _drawHandle;//画像ハンドル
	int _r;//半径
	int _speed;//スピード
	//変更される可能性の無いものはここで初期化
	unsigned int _colColer = ColorCode::LIME;//コリジョン色
	int _scale = 1;//スケール
	int _rotate = 0;//回転度
	bool _isShot = false;//ショット判定
	bool _isHit = false;//当たり判定
	bool _isVisible = true;//表示判定
	//Input用の変数
	IsKeyInput _isEnterInput{false,false,KEY_INPUT_RETURN };//Enter.
	IsKeyInput _isUpInput{false,false,KEY_INPUT_W};//Up.
	IsKeyInput _isDownInput{ false,false,KEY_INPUT_S };//Down.
	IsKeyInput _isLeftInput{ false,false,KEY_INPUT_A };//Left.
	IsKeyInput _isRightInput{ false,false,KEY_INPUT_D };//Right.
public:
	/*publicメンバ変数*/
	int X;//x座標
	int Y;//y座標

	/*コンストラクタ*/
	Player(int drawHandle,int x, int y, int r, int speed);
	
	/*Getter*/
	bool GetShotFlag();

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
Player::Player(int drawHandle, int x, int y, int r,int speed) :
	_drawHandle(drawHandle),
	X(x),
	Y(y),
	_r(r),
	_speed(speed)
{
	//↑インスタンス作成時に変更する可能性があるものだけコンストラクタで初期化。
}

/*ゲッター*/
bool Player::GetShotFlag()
{
	return _isShot;
}

/*セッター*/



/*メンバ関数*/
/// <summary>
/// 計算処理の更新
/// </summary>
void Player::Update()
{
	/*KeyUpdate*/
	_isEnterInput = InputKeyUpdate(_isEnterInput);//Enter.
	_isUpInput = InputKeyUpdate(_isUpInput);//Up.
	_isDownInput = InputKeyUpdate(_isDownInput);//Donw.
	_isLeftInput = InputKeyUpdate(_isLeftInput);//Left.
	_isRightInput = InputKeyUpdate(_isRightInput);//Right.

	/*移動処理*/
	//Up.
	if (_isUpInput.IsHold == true)
	{
		Y -= _speed;
	}
	//Down.
	if (_isDownInput.IsHold == true)
	{
		Y += _speed;
	}
	//Left.
	if (_isLeftInput.IsHold == true)
	{
		X -= _speed;
	}
	//Right.
	if (_isRightInput.IsHold == true)
	{
		X += _speed;
	}

	/*攻撃*/
	if (_isEnterInput.IsNow == true)
	{
		_isShot = true;
	}
	else
	{
		_isShot = false;
	}
	
}
/// <summary>
/// 表示処理の更新
/// </summary>
void Player::Draw()
{
	DrawRotaGraph(X,Y,1,0,_drawHandle,1);
}
/// <summary>
/// Debug表示の更新
/// </summary>
void Player::DebugDraw()
{

}
