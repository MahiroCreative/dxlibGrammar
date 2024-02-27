#pragma once
#include "Bullet.h"
#include "Enemy.h"
#include "MyDxlibCommon.h"
#include "DxLib.h"

class Player
{
public:
	/*public�����o�ϐ�*/
	int X;//x���W
	int Y;//y���W
	/*�R���X�g���N�^*/
	Player();
	/*Init*/
	void Init(int drawHandle, int x, int y, int r, int speed, Enemy* enemy);
	/*�����o�֐�*/
	void Update();//�����̍X�V
	void Draw();//�\���̍X�V
	void DebugDraw();//Debug�\���̍X�V
private:
	/*private�����o�ϐ�*/
	int _drawHandle;//�摜�n���h��
	int _r;//���a
	int _speed;//�X�s�[�h
	//�ύX�����\���̖������̂͂����ŏ�����
	unsigned int _colColer = ColorCode::LIME;//�R���W�����F
	int _scale = 1;//�X�P�[��
	int _rotate = 0;//��]�x
	bool _isShotFlag = false;//�V���b�g�t���O
	bool _isHit = false;//�����蔻��
	bool _isVisible = true;//�\������
	//Input�p�̕ϐ�
	IsKeyInput _isEnterInput{ false,false,KEY_INPUT_RETURN };//Enter.
	IsKeyInput _isUpInput{ false,false,KEY_INPUT_W };//Up.
	IsKeyInput _isDownInput{ false,false,KEY_INPUT_S };//Down.
	IsKeyInput _isLeftInput{ false,false,KEY_INPUT_A };//Left.
	IsKeyInput _isRightInput{ false,false,KEY_INPUT_D };//Right.
	//PlayerBullet.
	Bullet* _pPBullet[3];
	Enemy* _pEnemy;
};

/*�R���X�g���N�^*/
/// <summary>
/// Player�̃R���X�g���N�^
/// </summary>
/// <param name="x">X���W</param>
/// <param name="y">Y���W</param>
/// <param name="r">���a</param>
/// <param name="speed">���x</param>
/// <param name="maxShotNum">�ő唭�ː�</param>
Player::Player() :
	_drawHandle(NULL),
	X(NULL),
	Y(NULL),
	_r(NULL),
	_speed(NULL),
	_pEnemy(nullptr)
{
	//�e�ۂ̏�����
	for (int i = 0; i < 3; i++)
	{
		_pPBullet[i] = nullptr;
	}
}

/*Init*/
/// <summary>
/// �����o�ϐ��̏�����
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

/*�����o�֐�*/
/// <summary>
/// �v�Z�̍X�V
/// </summary>
void Player::Update()
{
	/*KeyUpdate*/
	_isEnterInput = InputKeyUpdate(_isEnterInput);//Enter.
	_isUpInput = InputKeyUpdate(_isUpInput);//Up.
	_isDownInput = InputKeyUpdate(_isDownInput);//Donw.
	_isLeftInput = InputKeyUpdate(_isLeftInput);//Left.
	_isRightInput = InputKeyUpdate(_isRightInput);//Right.

	/*�ړ�����*/
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

	/*PlayerBullet�̐���*/
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

	/*PlayerBullet�̍X�V*/
	for (int i = 0; i < 3; i++)
	{
		//�e�ۂ����݂���Ȃ�A�X�V
		if (_pPBullet[i] != nullptr)
		{
			_pPBullet[i]->Update();
		}
	}

	/*PlayerBullet�̍폜*/
	for (int i = 0; i < 3; i++)
	{
		//�e�ۂ����݂��A���A��ʂ���o�Ă�����폜
		if (_pPBullet[i] != nullptr && _pPBullet[i]->X > 1280)
		{
			//�폜����
			delete _pPBullet[i];
			_pPBullet[i] = nullptr;
		}
	}

	/*�����蔻��*/

}
/// <summary>
/// �\�������̍X�V
/// </summary>
void Player::Draw()
{
	//Player�̕`��
	DrawRotaGraph(X, Y, 1, 0, _drawHandle, 1);

	//Bullet�̕`��
	for (int i = 0; i < 3; i++)
	{
		if (_pPBullet[i] != nullptr)
		{
			_pPBullet[i]->Draw();
		}
	}
}
/// <summary>
/// Debug�\���̍X�V
/// </summary>
void Player::DebugDraw()
{
	//�R���W�����̕`��
	DrawCircle(X, Y, _r, ColorCode::LIME, 0);

}
