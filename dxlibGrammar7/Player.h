#pragma once
#include "MyGameCommon.h"
#include "DxLib.h"

class Player
{
private:
	/*private�����o�ϐ�*/
	int _r;//���a
	int _speed;//�X�s�[�h
	int _maxShotNum;//�ő�e��
	int _shotCount;//���˒e��
	//�ύX�����\���̖������̂͂����ŏ�����
	int _colColer = ColorCode::LIME;//�R���W�����F
	int _scale = 1;//�X�P�[��
	int _rotate = 0;//��]�x
	bool _isHit = false;//�����蔻��
	bool _isVisible = true;//�\������
public:
	/*public�����o�ϐ�*/
	int X;//x���W
	int Y;//y���W

	/*�R���X�g���N�^*/
	Player(int x, int y, int r, int speed, int maxShotNum);
	
	/*Getter*/

	/*Setter*/

	/*�����o�֐�*/
	void Update();//�����̍X�V
	void Draw();//�\���̍X�V
	void DebugDraw();//Debug�\���̍X�V
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
Player::Player(int x,int y,int r,int speed,int maxShotNum) :
	X(x),
	Y(y),
	_r(r),
	_speed(speed),
	_maxShotNum(maxShotNum),
	_shotCount(0)
{
	//���ύX�����\���̂�����̂����R���X�g���N�^�ŏ��������Ă���B
}

/*�Q�b�^�[*/


/*�Z�b�^�[*/



/*�����o�֐�*/
/// <summary>
/// �v�Z�����̍X�V
/// </summary>
void Player::Update()
{

}
/// <summary>
/// �\�������̍X�V
/// </summary>
void Player::Draw()
{

}
/// <summary>
/// Debug�\���̍X�V
/// </summary>
void Player::DebugDraw()
{

}
