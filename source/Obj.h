#pragma once
#include <string>
#include <map>
#include "VECTOR2.h"

enum ANIM_TBL {
	ANIM_TBL_START_ID,		//��Ұ��݂̊J�n
	ANIM_TBL_FRAME,			//��Ұ��݂̺ϐ�
	ANIM_TBL_INV,			//�ς��Ƃ̊Ԋu
	ANIM_TBL_MAX
};

class GameCtrl;

class Obj
{
public:
	Obj();
	Obj(VECTOR2 drawOffset);	//�󂯎����drawOffset�������̎���drawOffset�ɓ����
	bool init(
		std::string fileName,
		VECTOR2 divSize,
		VECTOR2 divCnt
	);	//�摜��̧�ٖ�,��������,�������̏�����
	bool init(
		std::string fileName,
		VECTOR2 divSize,
		VECTOR2 divCnt,
		VECTOR2 pos
	);	//�摜��̧�ٖ�,��������,�������̏�����,���W
	virtual ~Obj();
	void UpDate(const GameCtrl &controller);	//���X�V	���۰װ���̂��߲����n��
	virtual void Draw(void);	//�`��
	void Draw(unsigned int id);	//ID�w��`��
	const VECTOR2 &GetPos(void);	//���W�擾�֐�

	bool AddAnim(
		std::string animName,
		int id_x,
		int id_y,
		int frame,
		int inv
	);	//��Ұ��݂̖��O,����,���,�ϐ�,�Ԋu�̐ݒ�
	bool SetAnim(std::string animName);
	std::string GetAnim(void);

private:
	virtual void SetMove(const GameCtrl &controller) = 0;

	std::string animName;	//�\�������Ұ��ݖ�
	std::map<std::string, int[ANIM_TBL_MAX]> animTable;

protected:
	std::string imageName;	//�\������摜��̧�ٖ�
	VECTOR2 divSize;		//�摜�̕�������
	VECTOR2 divCnt;			//�摜�̕�����

	unsigned int animCnt;	//��Ұ��̶݂���

	VECTOR2 pos;			//�\��������W
	void SetPos(VECTOR2 pos);

	const VECTOR2 drawOffset;		//�`��̾��
};