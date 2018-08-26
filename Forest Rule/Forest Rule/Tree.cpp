#include "Tree.h"



CTree::CTree(int key, CPlant *plant)//key������������
{
	if (key == 1)
	{
		type = 1;
		m_age = 0;
	}
	else
	{
		if (key == 2)
		{
			type = 1;
			m_age = 3 + rand() % 25;
		}
		else
		{
			if (key == 3)
			{
				type = 2;
				m_age = 35 + rand() % 120;
			}
		}
	}
	number = plant->operateNumber(1);
	createPos(plant);
}

void CTree::saveData(CPlant *plant)//��������Ϣ���ļ�
{
	plant->fTree << setw(3) << number << "�� ";
	if (type == 1)
		plant->fTree << "С��" << ":" << endl;
	else
		plant->fTree << "����" << ":" << endl;
	plant->fTree << "          ����:" << setw(3) << m_age << "     " << "λ��:(" << setw(2) << pos_x << "," << setw(2) << pos_y << ")" << endl;
	plant->fTree << endl;
}

CTree::~CTree()
{
}
