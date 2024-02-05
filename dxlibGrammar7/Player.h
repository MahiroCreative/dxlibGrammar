#pragma once
class Player
{
private:
	/*�����o�ϐ�*/
	int _drawHandle;//�摜�n���h��
	int _x;//X���W
	int _y;//Y���W
	int _r;//���a
	int _speed;//�X�s�[�h
	int _maxShotNum;//�ő唭�ː�
	int _shotCount;//���݂̔��ː�
	int _colColor;//�R���W�����̐F
	double _scale;//�X�P�[��
	double _rotate;//��]�x
	bool _isHit;//�����蔻��
	bool _isVisible;//�\������
public:
	/*�R���X�g���N�^*/
	Player(int DrawHandle, int X, int Y, int R);
	
	/*Getter*/

	/*Setter*/

	/*�����o�֐�*/
	void Update();//�����̍X�V
	void Draw();//�\���̍X�V
	void DebugDraw();//Debug�\���̍X�V
};

/*�R���X�g���N�^*/
Player::Player(int DrawHandle, int X, int Y, int R):
	_speed(1),
	_maxShotNum(0),
	_shotCount(0),
	_colColor(GetColor(255,0,255)),//�s���N
	_scale(1),
	_rotate(0),
	_isHit(false),
	_isVisible(true)
{
	//�����o�ϐ��̏�����
	_drawHandle = DrawHandle;
	_x = X;
	_y = Y;
	_r = R;
}

/*�Q�b�^�[*/


/*�Z�b�^�[*/



/*�����o�֐�*/
/// <summary>
/// �v�Z�����̍X�V
/// </summary>
void Player::Update()
{
	//�ړ�����
	if (CheckHitKey(KEY_INPUT_W))//W�ŏ�ړ�
	{
		_y -= _speed;
	}
	else if (CheckHitKey(KEY_INPUT_S))//S�ŉ��ړ�
	{
		_y += _speed;
	}
	else if (CheckHitKey(KEY_INPUT_D))//D�ŉE�ړ�
	{
		_x += _speed;
	}
	else if (CheckHitKey(KEY_INPUT_A))//A�ō��ړ�
	{
		_x -= _speed;
	}
}
/// <summary>
/// �\�������̍X�V
/// </summary>
void Player::Draw()
{
	//Player�̕\��
	DrawRotaGraph(_x, _y, _scale, _rotate, _drawHandle, 1);
}
/// <summary>
/// Debug�\���̍X�V
/// </summary>
void Player::DebugDraw()
{
	DrawCircle(_x,_y,_r,_colColor,0);
}
