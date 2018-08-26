#include "Animal.h"


CAnimal::CAnimal()
{
}

void CAnimal::createAnimal()//���ɶ���(��������)
{
	m_youngSheep = rand() % 11 + 10;
	m_adultSheep = rand() % 11 + 20;
	m_allSheep = m_youngSheep + m_adultSheep;

	m_youngDeer = rand() % 11 + 10;
	m_adultDeer = rand() % 11 + 20;
	m_allDeer = m_youngDeer + m_adultDeer;

	m_youngWolf = rand() % 2 + 1;
	m_adultWolf = rand() % 3 + 4;
	m_allWolf = m_youngWolf + m_adultWolf;

	m_youngTiger = rand() % 2 + 1;
	m_adultTiger = rand() % 3 + 3;
	m_allTiger = m_youngTiger + m_adultTiger;

	m_allAnimal = m_allSheep + m_allDeer + m_allWolf + m_allTiger;
}

int CAnimal::operateNumber(int key)//����(�ı䲢���)��Ⱥ���:1�� 2¹ 3�� 4��
{
	if (key == 1)
	{
		sheepNumber++;
		return sheepNumber;
	}
	if (key == 2)
	{
		deerNumber++;
		return deerNumber;
	}
	if (key == 3)
	{
		wolfNumber++;
		return wolfNumber;
	}
	if (key == 4)
	{
		tigerNumber++;
		return tigerNumber;
	}
}

void CAnimal::createPos(CAnimal *animal)//����λ��
{
	int x = 0, y = 0;

	if (type == 1 || type == 2)//����
	{
		x = (rand() % 8) + 16;
		y = (rand() % 20) + 10;
		while (animal->getPos(x, y) > 0)//�Ѵ��ڶ���ٴ�����λ��
		{
			x = (rand() % 8) + 16;
			y = (rand() % 20) + 10;
		}
		pos_x = x;
		pos_y = y;
		if (type == 1)
			animal->updatePos(x, y, 1);
		else
			animal->updatePos(x, y, 2);
		return;
	}

	if (type == 3 || type == 4)//��¹
	{
		x = (rand() % 8) + 2;
		y = (rand() % 20) + 50;
		while (animal->getPos(x, y) > 0)//�Ѵ��ڶ���ٴ�����λ��
		{
			x = (rand() % 8) + 2;
			y = (rand() % 20) + 50;
		}
		pos_x = x;
		pos_y = y;
		if (type == 3)
			animal->updatePos(x, y, 3);
		else
			animal->updatePos(x, y, 4);
		return;
	}

	if (type == 5 || type == 6)//����
	{
		x = (rand() % 4) + 4;
		y = (rand() % 5) + 17;
		while (animal->getPos(x, y) > 0)//�Ѵ��ڶ���ٴ�����λ��
		{
			x = (rand() % 4) + 4;
			y = (rand() % 5) + 17;
		}
		pos_x = x;
		pos_y = y;
		if (type == 5)
			animal->updatePos(x, y, 5);
		else
			animal->updatePos(x, y, 6);
		return;
	}

	if (type == 7 || type == 8)//����
	{
		x = (rand() % 4) + 18;
		y = (rand() % 5) + 58;
		while (animal->getPos(x, y) > 0)//�Ѵ��ڶ���ٴ�����λ��
		{
			x = (rand() % 4) + 18;
			y = (rand() % 5) + 58;
		}
		pos_x = x;
		pos_y = y;
		if (type == 7)
			animal->updatePos(x, y, 7);
		else
			animal->updatePos(x, y, 8);
		return;
	}
}

void CAnimal::updatePos(int &i, int &j, int key)//����λ����Ϣ
{
	m_pos[i][j] = key;
}

int CAnimal::breed(int key)//��ֳ����:1�� 2¹ 3�� 4��
{
	if (key == 1)
	{
		if (m_allSheep < 100)
			return 1;
		return 0;
	}

	if (key == 2)
	{
		if (m_allDeer < 100)
			return 1;
		return 0;
	}

	if (key == 3)
	{
		if (m_allWolf < 13)
			return 1;
		return 0;
	}

	if (key == 4)
	{
		if (m_allTiger < 9)
			return 1;
		return 0;
	}
}

int CAnimal::die()//��������
{
	if (type == 1 || type == 2)//��
	{
		if (energy <= 0)
			return 1;
		if (m_age > 25)
			return 2;
		return 0;
	}

	if (type == 3 || type == 4)//¹
	{
		if (energy <= 0)
			return 1;
		if (m_age > 28)
			return 2;
		return 0;
	}

	if (type == 5 || type == 6)//��
	{
		if (energy <= 0)
			return 1;
		if (m_age > 30)
			return 2;
		return 0;
	}

	if (type == 7 || type == 8)//��
	{
		if (energy <= 0)
			return 1;
		if (m_age > 35)
			return 2;
		return 0;
	}
}

int CAnimal::getPos(int &i, int &j)const//��õ�ǰλ�õ���Ϣ
{
	return m_pos[i][j];
}

void CAnimal::freeMove(CAnimal *animal)//�����ƶ�:0���� 1б���� 2���� 3б���� 4���� 5б���� 6���� 7б����
{
	
}

void CAnimal::toDrinking(CAnimal *animal)//ȥ��ˮ
{

}

void CAnimal::backHome(CAnimal *animal)//����
{

}

int CAnimal::feed(CAnimal *animal)//��ʳ����
{
	return 0;
}

int CAnimal::searchPrey(CAnimal *animal)//Ѱ������
{
	return 0;
}

void CAnimal::catchPrey(CAnimal *animal)//׷������
{

}

int CAnimal::searchEnemy(CAnimal *animal)//��������
{
	return 0;
}

void CAnimal::hideEnemy(CAnimal *animal)//��ܵ���
{

}

void CAnimal::changeAmount(int key, int value)//�ı䶯��������Ϣ(key����):1���� 2������ 3��¹ 4����¹ 5���� 6������ 7�׻� 8���껢
{
	if (key == 1)
	{
		m_youngSheep += value;
		m_allSheep += value;
		m_allAnimal += value;
		return;
	}
	if (key == 2)
	{
		m_adultSheep += value;
		m_allSheep += value;
		m_allAnimal += value;
		return;
	}

	if (key == 3)
	{
		m_youngDeer += value;
		m_allDeer += value;
		m_allAnimal += value;
		return;
	}
	if (key == 4)
	{
		m_adultDeer += value;
		m_allDeer += value;
		m_allAnimal += value;
		return;
	}

	if (key == 5)
	{
		m_youngWolf += value;
		m_allWolf += value;
		m_allAnimal += value;
		return;
	}
	if (key == 6)
	{
		m_adultWolf += value;
		m_allWolf += value;
		m_allAnimal += value;
		return;
	}

	if (key == 7)
	{
		m_youngTiger += value;
		m_allTiger += value;
		m_allAnimal += value;
		return;
	}
	if (key == 8)
	{
		m_adultTiger += value;
		m_allTiger += value;
		m_allAnimal += value;
		return;
	}
}

int CAnimal::getInfo(int key)const//��ö���������Ϣ:1���� 2������ 3������ 4��¹ 5����¹ 6����¹ 7���� 8������ 9������ 10�׻� 11���껢 12���л� 13���ж���
{
	if (key == 1)
		return m_youngSheep;
	if (key == 2)
		return m_adultSheep;
	if (key == 3)
		return m_allSheep;

	if (key == 4)
		return m_youngDeer;
	if (key == 5)
		return m_adultDeer;
	if (key == 6)
		return m_allDeer;

	if (key == 7)
		return m_youngWolf;
	if (key == 8)
		return m_adultWolf;
	if (key == 9)
		return m_allWolf;

	if (key == 10)
		return m_youngTiger;
	if (key == 11)
		return m_adultTiger;
	if (key == 12)
		return m_allTiger;

	if (key == 13)
		return m_allAnimal;
}

void CAnimal::printPos(int &i, int &j)const//�������
{
	if (m_pos[i][j] == 1)//�������
	{
		cout << 'H';
		return;
	}
	if (m_pos[i][j] == 2)//���������
	{
		cout << 'S';
		return;
	}

	if (m_pos[i][j] == 3)//�����¹
	{
		cout << 'R';
		return;
	}
	if (m_pos[i][j] == 4)//�������¹
	{
		cout << 'D';
		return;
	}

	if (m_pos[i][j] == 5)//�������
	{
		cout << 'F';
		return;
	}
	if (m_pos[i][j] == 6)//���������
	{
		cout << 'W';
		return;
	}

	if (m_pos[i][j] == 7)//����׻�
	{
		cout << 'G';
		return;
	}
	if (m_pos[i][j] == 8)//������껢
	{
		cout << 'T';
		return;
	}

	cout << ' ';
}

void CAnimal::saveData(CAnimal *animal)//���涯����Ϣ���ļ�
{
}

CAnimal::~CAnimal()
{
}
