#pragma once
#include "Bullet.h"
#include "Enemy.h"
#include "MyDxlibCommon.h"
#include "DxLib.h"

class Player
{
public:
	/*publicメンバ変数*/
	int X;//x座標
	int Y;//y座標
	/*コンストラクタ*/
	Player();
	/*Init*/
	void Init(int drawHandle, int x, int y, int r, int speed, Enemy* enemy);
	/*メンバ関数*/
	void Update();//処理の更新
	void Draw();//表示の更新
	void DebugDraw();//Debug表示の更新
private:
	/*privateメンバ変数*/
	int _drawHandle;//画像ハンドル
	int _r;//半径
	int _speed;//スピード
	//変更される可能性の無いものはここで初期化
	unsigned int _colColer = ColorCode::LIME;//コリジョン色
	int _scale = 1;//スケール
	int _rotate = 0;//回転度
	bool _isShotFlag = false;//ショットフラグ
	bool _isHit = false;//当たり判定
	bool _isVisible = true;//表示判定
	//Input用の変数
	IsKeyInput _isEnterInput{ false,false,KEY_INPUT_RETURN };//Enter.
	IsKeyInput _isUpInput{ false,false,KEY_INPUT_W };//Up.
	IsKeyInput _isDownInput{ false,false,KEY_INPUT_S };//Down.
	IsKeyInput _isLeftInput{ false,false,KEY_INPUT_A };//Left.
	IsKeyInput _isRightInput{ false,false,KEY_INPUT_D };//Right.
	//PlayerBullet.
	Bullet* _pPBullet[3];
	Enemy* _pEnemy;
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
Player::Player() :
	_drawHandle(NULL),
	X(NULL),
	Y(NULL),
	_r(NULL),
	_speed(NULL),
	_pEnemy(nullptr)
{
	//弾丸の初期化
	for (int i = 0; i < 3; i++)
	{
		_pPBullet[i] = nullptr;
	}
}

/*Init*/
/// <summary>
/// メンバ変数の初期化
/// </summary>
void Player::Init(int drawHandle, int x, int y, int r, int speed, Enemy* enemy)
{
	_drawHandle = drawHandle;
	X = x;
	Y = y;
	_r = r;
	_speed = speed;
	_pEnemy = enemy;
}

/*メンバ関数*/
/// <summary>
/// 計算の更新
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

	/*PlayerBulletの生成*/
	if (_isEnterInput.IsNow)
	{
		for (int i = 0; i < 3; i++)
		{
			if (_pPBullet[i] == nullptr)
			{
				_pPBullet[i] = new Bullet(X, Y, 3, 8, ColorCode::YELLOW);
				break;
			}
		}
	}

	/*PlayerBulletの更新*/
	for (int i = 0; i < 3; i++)
	{
		//弾丸が存在するなら、更新
		if (_pPBullet[i] != nullptr)
		{
			_pPBullet[i]->Update();
		}
	}

	/*PlayerBulletの削除*/
	for (int i = 0; i < 3; i++)
	{
		//弾丸が存在し、かつ、画面から出ていたら削除
		if (_pPBullet[i] != nullptr && _pPBullet[i]->X > 1280)
		{
			//削除処理
			delete _pPBullet[i];
			_pPBullet[i] = nullptr;
		}
	}

	/*当たり判定*/

}
/// <summary>
/// 表示処理の更新
/// </summary>
void Player::Draw()
{
	//Playerの描画
	DrawRotaGraph(X, Y, 1, 0, _drawHandle, 1);

	//Bulletの描画
	for (int i = 0; i < 3; i++)
	{
		if (_pPBullet[i] != nullptr)
		{
			_pPBullet[i]->Draw();
		}
	}
}
/// <summary>
/// Debug表示の更新
/// </summary>
void Player::DebugDraw()
{
	//コリジョンの描画
	DrawCircle(X, Y, _r, ColorCode::LIME, 0);

}
