#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include"Manage.h"
using namespace std;
int main()
{
	cout << "��                                   ��ENTER����ʼ���С�" << endl;
	cout << "                                     �� ECS���˳����� ��                                 ��" << endl;

	char s;
	while (true)
	{
		s = _getch();
		if (s == 0x0D)//ENTER����ʼ����
		{
			system("cls");
			break;
		}
		else
		{
			if (s == 0x1b)//ESC���˳�����
				return 0;
			else
			{
				cout << endl;
				cout << "�����������������:";
			}
		}
	}

	//����ʼ����
	CManage *manage = new CManage;
	if (manage->start() == 1)
	{
		cout << "ECS���˳�,ENTER��������������:";
		while (true)
		{
			s = _getch();
			if (s == 0x0D)//ENTER������
			{
				system("cls");
				if (manage->start() == 0)
					break;
			}
			else
			{
				if (s == 0x1b)//ESC���˳�
					break;
				else
				{
					cout << endl;
					cout << "�����������������:";
					continue;
				}

			}
			cout << "ECS���˳�,ENTER��������������:";
		}
	}
	manage->save();
	manage->end();
	delete manage;
	return 0;
}