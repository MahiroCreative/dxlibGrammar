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