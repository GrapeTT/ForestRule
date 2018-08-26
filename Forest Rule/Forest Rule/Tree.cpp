#include "Tree.h"



CTree::CTree(int key, CPlant *plant)//key控制生成类型
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

void CTree::saveData(CPlant *plant)//保存树信息至文件
{
	plant->fTree << setw(3) << number << "号 ";
	if (type == 1)
		plant->fTree << "小树" << ":" << endl;
	else
		plant->fTree << "大树" << ":" << endl;
	plant->fTree << "          年龄:" << setw(3) << m_age << "     " << "位置:(" << setw(2) << pos_x << "," << setw(2) << pos_y << ")" << endl;
	plant->fTree << endl;
}

CTree::~CTree()
{
}
