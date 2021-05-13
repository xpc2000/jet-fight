#include "view.h"
#include "easyx.h"
#include "Enemy.h"
#include "SmallEnemy.h"

IMAGE boom1, boom2, boom3, boom4;
IMAGE smallboom1, smallboom2, smallboom3, smallboom4;
int position = 1; 
IMAGE img, photo1;
MOUSEMSG k, m;
void LoadBoom()
{	
	loadimage(&boom1, _T("C:\\Users\\xiepe\\Desktop\\resource\\boom\\boom1.png"));
	loadimage(&boom2, _T("C:\\Users\\xiepe\\Desktop\\resource\\boom\\boom2.png"));
	loadimage(&boom3, _T("C:\\Users\\xiepe\\Desktop\\resource\\boom\\boom3.png"));
	loadimage(&boom4, _T("C:\\Users\\xiepe\\Desktop\\resource\\boom\\boom4.png"));

	loadimage(&smallboom1, _T("C:\\Users\\xiepe\\Desktop\\resource\\boom\\smallboom1.png"));
	loadimage(&smallboom2, _T("C:\\Users\\xiepe\\Desktop\\resource\\boom\\smallboom2.png"));
	loadimage(&smallboom3, _T("C:\\Users\\xiepe\\Desktop\\resource\\boom\\smallboom3.png"));
	loadimage(&smallboom4, _T("C:\\Users\\xiepe\\Desktop\\resource\\boom\\smallboom4.png"));
}

void InitGame()
{
	LoadBoom();
	mciSendString(_T("open C:\\Users\\xiepe\\Desktop\\resource\\Avengers.mp3 alias mysong"), NULL, 0, NULL);		// ������
	mciSendString(_T("play MySong repeat"), NULL, 0, NULL);         			// ѭ������

	// ��ʼ����ʼ���洰��
	loadimage(&img, _T("C:\\Users\\xiepe\\Desktop\\resource\\qitarui.jpg"), 640, 480);
	loadimage(&photo1, _T("C:\\Users\\xiepe\\Desktop\\resource\\ironmanvision.jpg"), 640, 480);

	position = 1;
	cleardevice();
	putimage(0, 0, &img);
	//��ʾͼƬ	
	setfillcolor(GREEN);
	setbkmode(TRANSPARENT);
	fillrectangle(470, 80, 630, 130);
	outtextxy(490, 100, _T("��Ϸ����"));
	fillrectangle(470, 180, 630, 230);
	outtextxy(490, 200, _T("��Ϸ����"));
	fillrectangle(470, 280, 630, 330);
	outtextxy(490, 300, _T("��ʼ��Ϸ"));
	outtextxy(100, 100, _T("Defending Earth"));
	while (true)
	{
		while (MouseHit())
		{
			k = GetMouseMsg();
			if (k.uMsg == WM_LBUTTONDOWN)
			{
				if (k.x >= 470 && k.x <= 630 && k.y >= 80 && k.y <= 130)
				{
					rule();
				}
				else if (k.x >= 470 && k.x <= 630 && k.y >= 180 && k.y <= 230)
				{
					about();
				}
				else if (k.x >= 470 && k.x <= 630 && k.y >= 280 && k.y <= 330)
				{
					position = 0;
				}

			}
			if (position != 1)
				break;
		}
		if (position != 1)
			break;
	}
	cleardevice();
	// ���طɻ�
	if (position == 0)
	{
		loadimage(&ship, _T("C:\\Users\\xiepe\\Desktop\\resource\\shieldplane1.png"));
		loadimage(&ship1, _T("C:\\Users\\xiepe\\Desktop\\resource\\cover2.png"));
		// ���صл�
		loadimage(&enemy, _T("C:\\Users\\xiepe\\Desktop\\resource\\Thanos2.png"));
		loadimage(&enemy1, _T("C:\\Users\\xiepe\\Desktop\\resource\\cover1.jpg"));
		// ����С�л�
		loadimage(&smallenemy, _T("C:\\Users\\xiepe\\Desktop\\resource\\Chitauri.png"));
		loadimage(&smallenemy1, _T("C:\\Users\\xiepe\\Desktop\\resource\\cover3.png"));
		myenemy.direction = DOWN;
		myenemy.m_nStartHight = 0;
		myenemy.m_Move = 0;
		myenemy.m_Fire = 0;
		myenemy.m_Boom = 0;
	}

}
void rule()//��Ϸ����
{
	cleardevice();
	putimage(0, 0, &img);
	fillrectangle(470, 400, 630, 450);
	outtextxy(490, 420, _T("����"));
	outtextxy(100, 50, _T("W��S��A��D �ƶ�"));
	outtextxy(100, 100, _T("K ���䵼��"));
	outtextxy(100, 150, _T("�ո����ͣ"));
	outtextxy(100, 200, _T("���������"));
	outtextxy(100, 250, _T("��Ҫ�öԷ��Ĺ����ں;���ɴ������㣬������Ѫ"));
	outtextxy(100, 350, _T("����ս���Ϸ���Ѫ������Ѫ����0ʱ��������Ϸ������"));
	while (true)
	{
		while (MouseHit())
		{
			m = GetMouseMsg();
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				if (m.x >= 470 && m.x <= 630 && m.y >= 400 && m.y <= 450)
				{
					position = 2;
					cleardevice();
					break;
				}
			}
		}
		if (position == 2)
			break;
	}

}
void about()//��Ϸ����
{
	cleardevice();
	putimage(0, 0, &photo1);
	fillrectangle(470, 400, 630, 450);
	outtextxy(490, 420, _T("����"));
	outtextxy(100, 50, _T("�����������ˡ�2�У�糺�Ů��������˹���˿�����"));
	outtextxy(100, 100, _T("��������ͨ���涴��������Ļ���"));
	outtextxy(100, 150, _T("����Ϸ�����ڴ˻����Ͻ��иı�"));
	outtextxy(100, 200, _T("������������ʽս��ӭս��������"));
	while (true)
	{
		while (MouseHit())
		{
			m = GetMouseMsg();
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				if (m.x >= 470 && m.x <= 630 && m.y >= 400 && m.y <= 450)
				{
					position = 3;
					cleardevice();
					break;
				}
			}
		}
		if (position == 3)
			break;
	}

}
void ShowBullet()
{
	// ��ʾ�ɴ��ӵ�
	for (Iter = VectorBullets.begin(); Iter != VectorBullets.end(); Iter++)
	{
		if (VectorBullets.size() == 0)
		{
			break;
		}
		if (*Iter == nullptr)
		{
			break;
		}
		(*Iter)->ShowClear();
		(*Iter)->MoveUp();
		(*Iter)->ShowYellow();
	}

	// ��ʾ�л��ӵ�
	for (Iter = VectorEnenyBullets.begin(); Iter != VectorEnenyBullets.end(); Iter++)
	{
		if (VectorEnenyBullets.size() == 0)
		{
			break;
		}
		if (*Iter == nullptr)
		{
			break;
		}
		(*Iter)->ShowClear();
		(*Iter)->MoveDown();
		(*Iter)->ShowBlue();
	}
}

void ShowInPut()
{
	if (myinput & UPINPUT)
	{
		myship.ShowClear();
	}

	if (myinput & DOWNINPUT)
	{
		myship.ShowClear();
	}

	if (myinput & LEFTINPUT)
	{
		myship.ShowClear();
	}

	if (myinput & RIGHTINPUT)
	{
		myship.ShowClear();
	}
}