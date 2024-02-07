#pragma once
#include "Dxlib.h"

namespace WindowSize
{
	constexpr int SIZE_X = 1280;//��ʃT�C�YX
	constexpr int SIZE_Y = 720;//��ʃT�C�YY
}

namespace ColorCode
{
	//�v���O�������s�����܂�萔��const.
	//���̏ꍇ����GetColor�֐��Ōv�Z����Ă��猈�܂�̂�const.
	const unsigned int BLACK = GetColor(0, 0, 0);//��
	const unsigned int RED = GetColor(255, 0, 0);//��
	const unsigned int LIME = GetColor(0, 255, 0);//���C��
	const unsigned int BLUE = GetColor(0, 0, 255);//��
	const unsigned int YELLOW = GetColor(255, 255, 0);//��
	const unsigned int AQUA = GetColor(0, 255, 255);//�A�N�A
	const unsigned int MAGENTA = GetColor(255, 0, 255);//�}�[���^
}