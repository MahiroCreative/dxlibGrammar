#pragma once
#include "MyDxlibCommon.h"
#include "DxLib.h"

class Bullet
{
public:
	/*public�����o�ϐ�*/
	int X;//X���W
	int Y;//Y���W
	/*�R���X�g���N�^*/
	Bullet(int x, int y,int r, int speed, unsigned int color);
	/*�����o�֐�*/
	void Update();
	void Draw();
	void DebugDraw();
private:
	/*private�����o�ϐ�*/
	int _r;
	int _speed;
	unsigned int _color;
};

Bullet::Bullet(int x, int y, int r, int speed, unsigned int color):
	X(x),
	Y(y),
	_r(r),
	_speed(speed),
	_color(color)
{
	//�C���X�^���X�쐬���ɕύX����\����������̂����R���X�g���N�^�ŏ������B
}

/// <summary>
/// �v�Z�����̍X�V
/// </summary>
void Bullet::Update()
{
	X += _speed;
}

/// <summary>
/// �\�������̍X�V
/// </summary>
void Bullet::Draw()
{
	DrawCircle(X,Y,_r,_color,1);
}

/// <summary>
/// Debug�\���̍X�V
/// </summary>
void Bullet::DebugDraw()
{

}