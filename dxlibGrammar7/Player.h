#pragma once
class Player
{
private:
	/*private�����o�ϐ�*/
	int _r;//���a
public:
	/*public�����o�ϐ�*/
	int X;//x���W
	int Y;//y���W

	/*�R���X�g���N�^*/
	Player(int X,int Y);
	
	/*Getter*/

	/*Setter*/

	/*�����o�֐�*/
	void Update();//�����̍X�V
	void Draw();//�\���̍X�V
	void DebugDraw();//Debug�\���̍X�V
};

/*�R���X�g���N�^*/
Player::Player(int x,int y):
	X(x),
	Y(y),
	_r(12)
{

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
