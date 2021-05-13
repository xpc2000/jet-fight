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
	mciSendString(_T("open C:\\Users\\xiepe\\Desktop\\resource\\Avengers.mp3 alias mysong"), NULL, 0, NULL);		// 打开音乐
	mciSendString(_T("play MySong repeat"), NULL, 0, NULL);         			// 循环播放

	// 初始化开始界面窗口
	loadimage(&img, _T("C:\\Users\\xiepe\\Desktop\\resource\\qitarui.jpg"), 640, 480);
	loadimage(&photo1, _T("C:\\Users\\xiepe\\Desktop\\resource\\ironmanvision.jpg"), 640, 480);

	position = 1;
	cleardevice();
	putimage(0, 0, &img);
	//显示图片	
	setfillcolor(GREEN);
	setbkmode(TRANSPARENT);
	fillrectangle(470, 80, 630, 130);
	outtextxy(490, 100, _T("游戏规则"));
	fillrectangle(470, 180, 630, 230);
	outtextxy(490, 200, _T("游戏背景"));
	fillrectangle(470, 280, 630, 330);
	outtextxy(490, 300, _T("开始游戏"));
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
	// 加载飞机
	if (position == 0)
	{
		loadimage(&ship, _T("C:\\Users\\xiepe\\Desktop\\resource\\shieldplane1.png"));
		loadimage(&ship1, _T("C:\\Users\\xiepe\\Desktop\\resource\\cover2.png"));
		// 加载敌机
		loadimage(&enemy, _T("C:\\Users\\xiepe\\Desktop\\resource\\Thanos2.png"));
		loadimage(&enemy1, _T("C:\\Users\\xiepe\\Desktop\\resource\\cover1.jpg"));
		// 加载小敌机
		loadimage(&smallenemy, _T("C:\\Users\\xiepe\\Desktop\\resource\\Chitauri.png"));
		loadimage(&smallenemy1, _T("C:\\Users\\xiepe\\Desktop\\resource\\cover3.png"));
		myenemy.direction = DOWN;
		myenemy.m_nStartHight = 0;
		myenemy.m_Move = 0;
		myenemy.m_Fire = 0;
		myenemy.m_Boom = 0;
	}

}
void rule()//游戏规则
{
	cleardevice();
	putimage(0, 0, &img);
	fillrectangle(470, 400, 630, 450);
	outtextxy(490, 420, _T("返回"));
	outtextxy(100, 50, _T("W、S、A、D 移动"));
	outtextxy(100, 100, _T("K 发射导弹"));
	outtextxy(100, 150, _T("空格键暂停"));
	outtextxy(100, 200, _T("任意键继续"));
	outtextxy(100, 250, _T("不要让对方的光束炮和鲸鱼飞船碰到你，否则会掉血"));
	outtextxy(100, 350, _T("己方战机上方有血量条，血掉到0时，本轮游戏即结束"));
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
void about()//游戏介绍
{
	cleardevice();
	putimage(0, 0, &photo1);
	fillrectangle(470, 400, 630, 450);
	outtextxy(490, 420, _T("返回"));
	outtextxy(100, 50, _T("《复仇者联盟》2中，绯红女巫让托尼斯塔克看到了"));
	outtextxy(100, 100, _T("齐塔瑞大军通过虫洞进攻地球的幻象"));
	outtextxy(100, 150, _T("本游戏就是在此基础上进行改编"));
	outtextxy(100, 200, _T("复仇者联盟昆式战机迎战齐塔瑞大军"));
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
	// 显示飞船子弹
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

	// 显示敌机子弹
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