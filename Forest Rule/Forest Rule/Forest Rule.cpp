#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include"Manage.h"
using namespace std;
int main()
{
	cout << "『                                   ☆ENTER键开始运行☆" << endl;
	cout << "                                     ☆ ECS键退出程序 ☆                                 』" << endl;

	char s;
	while (true)
	{
		s = _getch();
		if (s == 0x0D)//ENTER键开始运行
		{
			system("cls");
			break;
		}
		else
		{
			if (s == 0x1b)//ESC键退出程序
				return 0;
			else
			{
				cout << endl;
				cout << "输入错误！请重新输入:";
			}
		}
	}

	//程序开始运行
	CManage *manage = new CManage;
	if (manage->start() == 1)
	{
		cout << "ECS键退出,ENTER键继续！请输入:";
		while (true)
		{
			s = _getch();
			if (s == 0x0D)//ENTER键继续
			{
				system("cls");
				if (manage->start() == 0)
					break;
			}
			else
			{
				if (s == 0x1b)//ESC键退出
					break;
				else
				{
					cout << endl;
					cout << "输入错误！请重新输入:";
					continue;
				}

			}
			cout << "ECS键退出,ENTER键继续！请输入:";
		}
	}
	manage->save();
	manage->end();
	delete manage;
	return 0;
}