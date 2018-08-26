#include "Plant.h"


CPlant::CPlant()
{
}

void CPlant::createPlant()//����ֲ��
{
	m_allGrass = rand() % 100 + 980;
	m_youngGrass = m_allGrass / 5;
	m_adultGrass = m_allGrass - m_youngGrass;

	m_allTree = rand() % 100 + 600;
	m_youngTree = m_allTree / 6;
	m_adultTree = m_allTree - m_youngTree;

	m_allPlant = m_allGrass + m_allTree;
}

int CPlant::operateNumber(int key)//����(�ı䲢���)��Ⱥ���:1�� 2��
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

void CPlant::createPos(CPlant *plant)//����λ��
{
	int x = 0, y = 0;
	int i = 0;
	if (type == 1 || type == 2)//����
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
		while (plant->getPos(x, y) > 0 || plant->getTreeRegion(i) > 200)//�Ѵ���ֲ������������Ѵ����ޣ��ٴ�����λ��
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

	if (type == 3 || type == 4)//����
	{
		x = rand() % 26;
		y = rand() % 80;
		while (plant->getPos(x, y) > 0)//�Ѵ���ֲ��ٴ�����λ��
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

void CPlant::updatePos(int &i, int &j, int key)//����λ����Ϣ
{
	m_pos[i][j] = key;
}

int CPlant::getPos(int &i, int &j)const//��õ�ǰλ�õ���Ϣ
{
	return m_pos[i][j];
}

int CPlant::getTreeRegion(int i)//���ɭ��ĳ����������Ŀ
{
	return treeRegion[i];
}

void CPlant::changeTreeRegion(int x, int y, int value)//�ı�ɭ��ÿ����������Ŀ
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

int CPlant::breed(int key)//��ֳ����:1�� 2��
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

int CPlant::die()//��������
{
	if (type == 2)//��
	{
		if (m_age > 200)
			return 1;
		return 0;
	}

	if (type == 4)//��
	{
		if (m_age > 6)
			return 1;
		return 0;
	}
}

void CPlant::changeAmount(int key, int value)//�ı䶯��������Ϣ(key����):1С�� 2���� 3�۲� 4С��
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

int CPlant::getInfo(int key)const//���ֲ��������Ϣ:1С�� 2���� 3������  4�۲� 5С�� 6���в� 7����ֲ��
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

void CPlant::saveData(CPlant *plant)//����ֲ����Ϣ���ļ�
{
}

CPlant::~CPlant()
{
}
