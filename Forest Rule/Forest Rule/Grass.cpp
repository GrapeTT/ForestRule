#include "Grass.h"



CGrass::CGrass(int key, CPlant *plant)//key控制生成类型
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

void CGrass::saveData(CPlant *plant)//保存草信息至文件
{
	plant->fGrass << setw(3) << number << "号 ";
	if (type == 3)
		plant->fGrass << "嫩草" << ":" << endl;
	else
		plant->fGrass << "小草" << ":" << endl;
	plant->fGrass << "          年龄:" << setw(3) << m_age << endl;
	plant->fGrass << "          能量:" << setw(3) << energy << "     " << "位置:(" << setw(2) << pos_x << "," << setw(2) << pos_y << ")" << endl;
	plant->fGrass << endl;
}

CGrass::~CGrass()
{
}
