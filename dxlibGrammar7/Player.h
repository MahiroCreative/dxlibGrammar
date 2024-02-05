#pragma once
class Player
{
private:
	/*メンバ変数*/
	int _drawHandle;//画像ハンドル
	int _x;//X座標
	int _y;//Y座標
	int _r;//半径
	int _speed;//スピード
	int _maxShotNum;//最大発射数
	int _shotCount;//現在の発射数
	double _scale;//スケール
	double _rotate;//回転度
	bool _isHit;//当たり判定
	bool _isVisible;//表示判定
public:
	/*コンストラクタ*/
	Player(int DrawHandle,int X,int Y, int R):
		_speed(1),
		_maxShotNum(0),
		_shotCount(0),
		_scale(1),
		_rotate(0),
		_isHit(false),
		_isVisible(true)
	{
		//メンバ変数の初期化
		_drawHandle = DrawHandle;
		_x = X;
		_y = Y;
		_r = R;
	};
	
	/*Getter*/

	/*Setter*/

	/*メンバ関数*/
	/// <summary>
	/// プレイヤー処理更新
	/// </summary>
	void Update()
	{
		//移動処理
		if (CheckHitKey(KEY_INPUT_W))//Wで上移動
		{
			_y -= _speed;
		}
		else if (CheckHitKey(KEY_INPUT_S))//Sで下移動
		{
			_y += _speed;
		}
		else if (CheckHitKey(KEY_INPUT_D))//Dで右移動
		{
			_x += _speed;
		}
		else if (CheckHitKey(KEY_INPUT_A))//Aで左移動
		{
			_x -= _speed;
		}
	}
	/// <summary>
	/// プレイヤーの表示更新
	/// </summary>
	void Draw()
	{

	}
};
