#include "Grass.h"



CGrass::CGrass(int key, CPlant *plant)//key������������
{
	if (key == 1)
	{
		type = 3;
		energy = 1;
		m_age = 0;
	}
	else
	{
		if (key == 2)
		{
			type = 3;
			energy = 1;
			m_age = rand() % 2;
		}
		else
		{
			if (key == 3)
			{
				type = 4;
				energy = 2;
				m_age = 2 + rand() % 2;
			}
		}
	}
	number = plant->operateNumber(2);
	createPos(plant);
}

void CGrass::saveData(CPlant *plant)//�������Ϣ���ļ�
{
	plant->fGrass << setw(3) << number << "�� ";
	if (type == 3)
		plant->fGrass << "�۲�" << ":" << endl;
	else
		plant->fGrass << "С��" << ":" << endl;
	plant->fGrass << "          ����:" << setw(3) << m_age << endl;
	plant->fGrass << "          ����:" << setw(3) << energy << "     " << "λ��:(" << setw(2) << pos_x << "," << setw(2) << pos_y << ")" << endl;
	plant->fGrass << endl;
}

CGrass::~CGrass()
{
}
