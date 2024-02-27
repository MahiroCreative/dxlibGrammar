#pragma once
#include "Bullet.h"
#include "MyDxlibCommon.h"
#include "DxLib.h"

class Enemy
{
public:
	/*public�����o�ϐ�*/
	int X;//x���W
	int Y;//y���W
	/*�R���X�g���N�^*/
	Enemy(int x, int y, int r, int speed);
	/*Init*/
	void Init();
	/*Getter*/
	/*Setter*/
	/*�����o�֐�*/
	void Update();//�����̍X�V
	void Draw();//�\���̍X�V
	void DebugDraw();//Debug�\���̍X�V
private:
	/*private�����o�ϐ�*/
	int _r;//���a
	int _speed;//�X�s�[�h
	int _bulletSpeed;//�e�ۂ̑��x
	//�ύX�����\���̖������̂͂����ŏ�����
	unsigned int _color = ColorCode::AQUA;//�F
	unsigned int _hitColor = ColorCode::RED;//Hit�F
	bool _isHit = false;//�����蔻��
	bool _isVisible = true;//�\������
	//PlayerBullet.
	Bullet* _pEBullet;
};

/// <summary>
/// Enemy�R���X�g���N�^�B
/// </summary>
/// <param name="x">X���W</param>
/// <param name="y">Y���W</param>
/// <param name="r">���a</param>
/// <param name="speed">���x</param>
Enemy::Enemy(int x, int y, int r, int speed) :
	X(x),
	Y(y),
	_r(r),
	_speed(speed),
	_bulletSpeed(-4),
	_pEBullet(nullptr)
{
	//���C���X�^���X�쐬���ɕύX����\����������̂����R���X�g���N�^�ŏ������B
}

/*Init*/
/// <summary>
/// �ҏW������
/// </summary>
void Enemy::Init()
{

}

/// <summary>
/// �v�Z�����̍X�V
/// </summary>
void Enemy::Update()
{
	//�ړ�
	Y += _speed;
	//���]
	if (Y > 640 || Y < 80)
	{
		_speed = -_speed;
	}

	/*EnemyBullet����*/
	if (_pEBullet == nullptr)
	{
		_pEBullet = new Bullet(X, Y, 32, _bulletSpeed, ColorCode::MAGENTA);
	}

	/*EnemyBullet�X�V*/
	if (_pEBullet != nullptr)
	{
		_pEBullet->Update();
	}

	//�e�ۂ����݂��A���A��ʂ���o�Ă�����폜
	if (_pEBullet != nullptr && (_pEBullet->X < -120))
	{
		//�폜����
		delete _pEBullet;
		_pEBullet = nullptr;

		//�e�ۑ��x�㏸
		if (_bulletSpeed > -16)
		{
			_bulletSpeed += -1;
		}

	}

}

/// <summary>
/// �\�������̍X�V
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