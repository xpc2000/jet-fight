#pragma once
#include "control.h"
#include "Ship.h"

void InitGame();				// ��ʼ����Ϸ
void ShowBullet();				// ��ʾ�ӵ�
void ShowInPut();				// ���ݲ�����ʾ
void LoadBoom();
void about();                   //��Ϸ��������
void rule();                    //��Ϸ�������

extern IMAGE boom1, boom2, boom3, boom4;
extern IMAGE smallboom1, smallboom2, smallboom3, smallboom4;
extern int position;