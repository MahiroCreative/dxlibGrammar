#pragma once
class Player
{
private:
	/*privateメンバ変数*/
	int _r;//半径
public:
	/*publicメンバ変数*/
	int X;//x座標
	int Y;//y座標

	/*コンストラクタ*/
	Player(int X,int Y);
	
	/*Getter*/

	/*Setter*/

	/*メンバ関数*/
	void Update();//処理の更新
	void Draw();//表示の更新
	void DebugDraw();//Debug表示の更新
};

/*コンストラクタ*/
Player::Player(int x,int y):
	_r(12)
{
	//引数初期化
	X = x;
	Y = y;

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
