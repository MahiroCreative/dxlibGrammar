#pragma once
#include "MyDxlibCommon.h"
#include "DxLib.h"

class Player
{
private:
	/*private�����o�ϐ�*/
	int _drawHandle;//�摜�n���h��
	int _r;//���a
	int _speed;//�X�s�[�h
	//�ύX�����\���̖������̂͂����ŏ�����
	unsigned int _colColer = ColorCode::LIME;//�R���W�����F
	int _scale = 1;//�X�P�[��
	int _rotate = 0;//��]�x
	bool _isShot = false;//�V���b�g����
	bool _isHit = false;//�����蔻��
	bool _isVisible = true;//�\������
	//Input�p�̕ϐ�
	IsKeyInput _isEnterInput{false,false,KEY_INPUT_RETURN };//Enter.
	IsKeyInput _isUpInput{false,false,KEY_INPUT_W};//Up.
	IsKeyInput _isDownInput{ false,false,KEY_INPUT_S };//Down.
	IsKeyInput _isLeftInput{ false,false,KEY_INPUT_A };//Left.
	IsKeyInput _isRightInput{ false,false,KEY_INPUT_D };//Right.
public:
	/*public�����o�ϐ�*/
	int X;//x���W
	int Y;//y���W

	/*�R���X�g���N�^*/
	Player(int drawHandle,int x, int y, int r, int speed);
	
	/*Getter*/
	bool GetShotFlag();

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
Player::Player(int drawHandle, int x, int y, int r,int speed) :
	_drawHandle(drawHandle),
	X(x),
	Y(y),
	_r(r),
	_speed(speed)
{
	//���C���X�^���X�쐬���ɕύX����\����������̂����R���X�g���N�^�ŏ������B
}

/*�Q�b�^�[*/
bool Player::GetShotFlag()
{
	return _isShot;
}

/*�Z�b�^�[*/



/*�����o�֐�*/
/// <summary>
/// �v�Z�����̍X�V
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

	/*�U��*/
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
/// �\�������̍X�V
/// </summary>
void Player::Draw()
{
	DrawRotaGraph(X,Y,1,0,_drawHandle,1);
}
/// <summary>
/// Debug�\���̍X�V
/// </summary>
void Player::DebugDraw()
{

}
