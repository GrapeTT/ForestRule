#include "Plant.h"


CPlant::CPlant()
{
}

void CPlant::createPlant()//生成植物
{
	m_allGrass = rand() % 100 + 980;
	m_youngGrass = m_allGrass / 5;
	m_adultGrass = m_allGrass - m_youngGrass;

	m_allTree = rand() % 100 + 600;
	m_youngTree = m_allTree / 6;
	m_adultTree = m_allTree - m_youngTree;

	m_allPlant = m_allGrass + m_allTree;
}

int CPlant::operateNumber(int key)//操作(改变并获得)种群编号:1树 2草
{
	if (key == 1)
	{
		treeNumber++;
		return treeNumber;
	}
	if (key == 2)
	{
		grassNumber++;
		return grassNumber;
	}
}

void CPlant::createPos(CPlant *plant)//生成位置
{
	int x = 0, y = 0;
	int i = 0;
	if (type == 1 || type == 2)//产树
	{
		x = rand() % 26;
		y = rand() % 80;
		if (x < 13 && y > 39)
			i = 0;
		else
		{
			if (x > 12 && y > 39)
				i = 1;
			else
			{
				if (x > 12 && y < 40)
					i = 2;
				else
					i = 3;
			}
		}
		while (plant->getPos(x, y) > 0 || plant->getTreeRegion(i) > 200)//已存在植物或区域内树已达上限，再次生成位置
		{
			x = rand() % 26;
			y = rand() % 80;
			if (x < 13 && y > 39)
				i = 0;
			else
			{
				if (x > 12 && y > 39)
					i = 1;
				else
				{
					if (x > 12 && y < 40)
						i = 2;
					else
						i = 3;
				}
			}
		}
		plant->changeTreeRegion(x, y, 1);
		pos_x = x;
		pos_y = y;
		if (type == 7)
			plant->updatePos(x, y, 1);
		else
			plant->updatePos(x, y, 2);
		return;
	}

	if (type == 3 || type == 4)//产草
	{
		x = rand() % 26;
		y = rand() % 80;
		while (plant->getPos(x, y) > 0)//已存在植物，再次生成位置
		{
			x = rand() % 26;
			y = rand() % 80;
		}
		pos_x = x;
		pos_y = y;
		if (type == 5)
			plant->updatePos(x, y, 3);
		else
			plant->updatePos(x, y, 4);
		return;
	}
}

void CPlant::updatePos(int &i, int &j, int key)//更新位置信息
{
	m_pos[i][j] = key;
}

int CPlant::getPos(int &i, int &j)const//获得当前位置的信息
{
	return m_pos[i][j];
}

int CPlant::getTreeRegion(int i)//获得森林某个区树的数目
{
	return treeRegion[i];
}

void CPlant::changeTreeRegion(int x, int y, int value)//改变森林每个区树的数目
{
	int i = 0;
	if (x < 13 && y > 39)
		i = 0;
	else
	{
		if (x > 12 && y > 39)
			i = 1;
		else
		{
			if (x > 12 && y < 40)
				i = 2;
			else
				i = 3;
		}
	}
	treeRegion[i] += value;
}

int CPlant::breed(int key)//繁殖规则:1树 2草
{
	if (key == 1)
	{
		if (m_allTree < 800)
			return 1;
		return 0;
	}

	if (key == 2)
	{
		if (m_allGrass < 1280)
			return 1;
		return 0;
	}
}

int CPlant::die()//死亡规则
{
	if (type == 2)//树
	{
		if (m_age > 200)
			return 1;
		return 0;
	}

	if (type == 4)//草
	{
		if (m_age > 6)
			return 1;
		return 0;
	}
}

void CPlant::changeAmount(int key, int value)//改变动物数量信息(key控制):1小树 2大树 3嫩草 4小草
{
	if (key == 1)
	{
		m_youngTree += value;
		m_allTree += value;
		m_allPlant += value;
		return;
	}
	if (key == 2)
	{
		m_adultTree += value;
		m_allTree += value;
		m_allPlant += value;
		return;
	}

	if (key == 3)
	{
		m_youngGrass += value;
		m_allGrass += value;
		m_allPlant += value;
		return;
	}
	if (key == 4)
	{
		m_adultGrass += value;
		m_allGrass += value;
		m_allPlant += value;
		return;
	}
}

int CPlant::getInfo(int key)const//获得植物数量信息:1小树 2大树 3所有树  4嫩草 5小草 6所有草 7所有植物
{
	if (key == 1)
		return m_youngTree;
	if (key == 2)
		return m_adultTree;
	if (key == 3)
		return m_allTree;
	if (key == 4)
		return m_youngGrass;
	if (key == 5)
		return m_adultGrass;
	if (key == 6)
		return m_allGrass;
	if (key == 7)
		return m_allPlant;
}

void CPlant::saveData(CPlant *plant)//保存植物信息至文件
{
}

CPlant::~CPlant()
{
}
