#pragma once
//�I�u�W�F�N�g�w�b�_
#include "Bullet.h"
#include "Player.h"
#include "Enemy.h"
//���L�w�b�_(�ˑ��֌W���������̂قǍŌ�)
#include "MyDxlibCommon.h"
#include "DxLib.h"//�����ł��g���̂ōŌ�



/*�T�v*/
//���́wGrammer�V���[�Y�x�ł�DxLib��Q�[���v���O���~���O�̊�b�I�Ȏg�����ƍl������i�K�I�ɂ��܂��B
//���������e�͕K�v�Œ���ł��B�������o�܂��B�܂��ڍׂȉ�������Ă��܂���B
//�������t�@�����X��O���T�C�g���Q�l�ɂ��Ă��������B
//�y���t�@�����X�z
// https://dxlib.xsrv.jp/dxfunc.html

/*����̗v�f*/
//�E�Q�[���v���O���~���O
// �@- �I�u�W�F�N�g�w����p�����Q�[���v���O���~���O
//�EC/C++����
//   - �N���X

/*�R�����g*/
//�{���Ȃ�N���X�����ۂ�.h��.cpp�ɕ����邪�A�R�[�h�̊ȕ։��̂��߂ɑS��.h�ɋL�q���Ă���B
//���ۂɃQ�[�����̍ۂɂ�.h��.cpp�ɕ����Ăق����B
//�R���X�g���N�^�Ƃ��A�Q�b�^�[�Ƃ��Z�b�^�[�Ƃ��̉���͂����ł͂��Ȃ��B
//�܂��A�����蔻��̃J���[�R�[�h�ȂǁA�悭�g���萔�Ȃǂ�"Common.h"�ɂ܂Ƃ߂��B



//Dxlib�̃G���g���[�|�C���g
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	/*�ϐ�*/
	LONGLONG roopStartTime = 0;
	bool gameRoop = true;

	/*Dxlib������*/
	SetGraphMode(WindowSize::SIZE_X, WindowSize::SIZE_Y, 32);//��ʃT�C�Y�Ɖ𑜓x
	ChangeWindowMode(true);//Window���[�h
	if (DxLib_Init() == -1) { return -1; }//Dxlib������
	SetDrawScreen(DX_SCREEN_BACK);//�_�u���o�b�t�@�����O

	/*�Q�[���ϐ�*/
	int playerDrawHandle = LoadGraph("Chara.png");
	//�N���X�͊�{�I�Ƀ|�C���^�ŉ^�p����B
	Player* pPlayer = new Player{ playerDrawHandle, 20, 360, 12, 4 };
	Enemy* pEnemy = new Enemy{ 1100,360,64,2 };

	/*�Q�[�����[�v��*/
	//gameRoop.
	while (gameRoop)
	{
		//���[�v�J�n�����̊m��
		roopStartTime = GetNowHiPerformanceCount();
		//����ʂ̏�����
		ClearDrawScreen();

		/*Update*/
		//player.
		pPlayer->Update();
		//enemy.
		pEnemy->Update();

		//Bullet.


		/*Draw*/
		//player.
		pPlayer->Draw();
		//enemy.
		pEnemy->Draw();

		/*DebguDraw*/
		int debugNum = 0;
		DrawFormatString(0, 0, ColorCode::RED, "WSAD(�㉺���E),���N���b�N(�V���b�g)");
		DrawFormatString(0, 20, ColorCode::RED, "debugNum:%d",debugNum);


		//����ʂ�\��
		ScreenFlip();
		//���t���b�V������(-1�Ȃ�G���[)
		if (ProcessMessage() < 0) { break; }
		//���[�v�I������
		if (CheckHitKey(KEY_INPUT_ESCAPE)) { break; }
		//fps�Œ�(60fps:16.66ms)
		//���[�v�J�n��������16.66ms�o�܂Œ�~
		while (GetNowHiPerformanceCount() - roopStartTime < 16667) {}
	}

	/*�I������*/
	DxLib_End();//Dxlib�I������
	return 0;//�I�� 
}
