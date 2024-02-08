#pragma once
#include "MyDxlibCommon.h"
#include "DxLib.h"

class Enemy
{
private:
	/*private�����o�ϐ�*/
	int _r;//���a
	int _speed;//�X�s�[�h
	//�ύX�����\���̖������̂͂����ŏ�����
	unsigned int _color = ColorCode::AQUA;//�F
	unsigned int _hitColor = ColorCode::RED;//Hit�F
	bool _isHit = false;//�����蔻��
	bool _isVisible = true;//�\������
public:
	/*public�����o�ϐ�*/
	int X;//x���W
	int Y;//y���W

	/*�R���X�g���N�^*/
	Enemy(int x, int y, int r, int speed);

	/*Getter*/

	/*Setter*/

	/*�����o�֐�*/
	void Update();//�����̍X�V
	void Draw();//�\���̍X�V
	void DebugDraw();//Debug�\���̍X�V
};

/// <summary>
/// Enemy�R���X�g���N�^�B
/// </summary>
/// <param name="x">X���W</param>
/// <param name="y">Y���W</param>
/// <param name="r">���a</param>
/// <param name="speed">���x</param>
Enemy::Enemy(int x, int y, int r, int speed):
	X(x),
	Y(y),
	_r(r),
	_speed(speed)
{

}

/// <summary>
/// �v�Z�����̍X�V
/// </summary>
void Enemy::Update()
{
	//�ړ�
}

/// <summary>
/// �\�������̍X�V
/// </summary>
void Enemy::Draw()
{
	DrawCircle(X,Y,_r,_color,1);
}