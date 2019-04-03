#pragma once
#include <array>
#include "Obj.h"
#include "MapCtrl.h"
#include "Player.h"
#include "classObj.h"
#include "VECTOR2.h"

#define MOVE_SPEED (50)

enum CURSOR_KEY {
	CURSOR_UP,
	CURSOR_DOWN,
	CURSOR_LEFT,
	CURSOR_RIGHT,
	CURSOR_END,
	CURSOR_MAX
};

using CURSOR_ARY = std::array<int[PL_MAX], CURSOR_MAX>;

class MapCursor :
	public Obj
{
public:
	MapCursor();
	MapCursor(VECTOR2 setUpPos, PL_NUMBER player, VECTOR2 drawOffset);		// MAP_ID,inputFlam,keyGetRng,drawOffset������������
	~MapCursor();
	void Draw(void);					// ���ق̓_�ŏ��� SetDrawBlendMode�֐��g�p

private:
	void SetMove(const GameCtrl &controller, weakListObj objList);
	bool CheckDeath(void);		// ܰ��Ӱ�ޒ��ł����false

	int keyGetRng;	// ����ڰѐ��@���𗣂����珉����
	int inputFlam;	// ���������Ă����ڰѐ��@�����ĂȂ��Ƃ���۸ر
	bool warpFlag;

	CURSOR_ARY keyTable;	// ���͂������̕����@speedTable�ƕ��������킹��
	DIR_TBL_ARY speedTable;		// ��ۯ��̈ړ���߰�� dirTable�ƕ��������킹��

	PL_NUMBER player;
};