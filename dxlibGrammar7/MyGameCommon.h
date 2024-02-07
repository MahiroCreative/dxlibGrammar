#pragma once
#include "Dxlib.h"

namespace WindowSize
{
	constexpr int SIZE_X = 1280;//画面サイズX
	constexpr int SIZE_Y = 720;//画面サイズY
}

namespace ColorCode
{
	//プログラム実行時決まる定数はconst.
	//下の場合だとGetColor関数で計算されてから決まるのでconst.
	const unsigned int BLACK = GetColor(0, 0, 0);//黒
	const unsigned int RED = GetColor(255, 0, 0);//赤
	const unsigned int LIME = GetColor(0, 255, 0);//ライム
	const unsigned int BLUE = GetColor(0, 0, 255);//青
	const unsigned int YELLOW = GetColor(255, 255, 0);//黄
	const unsigned int AQUA = GetColor(0, 255, 255);//アクア
	const unsigned int MAGENTA = GetColor(255, 0, 255);//マゼンタ
}