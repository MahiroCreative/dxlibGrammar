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
	double _scale;//�X�P�[��
	double _rotate;//��]�x
	bool _isHit;//�����蔻��
	bool _isVisible;//�\������
public:
	/*�R���X�g���N�^*/
	Player(int DrawHandle,int X,int Y, int R):
		_speed(1),
		_maxShotNum(0),
		_shotCount(0),
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
	};
	
	/*Getter*/

	/*Setter*/

	/*�����o�֐�*/
	/// <summary>
	/// �v���C���[�����X�V
	/// </summary>
	void Update()
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
	/// �v���C���[�̕\���X�V
	/// </summary>
	void Draw()
	{

	}
};
