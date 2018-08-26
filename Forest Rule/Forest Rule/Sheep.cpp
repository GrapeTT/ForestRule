#include "Sheep.h"



CSheep::CSheep(int key, CAnimal *animal)//key������������
{
	if (key == 1)
	{
		type = 1;
		energy = 5 + rand() % 2;
		m_age = 0;
		sex = rand() % 2;
		fertilityIndex = 6 + rand() % 3 + 2;
		physicalStrength = 90 + rand() % 3;
	}
	else
	{
		if (key == 2)
		{
			type = 1;
			energy = 5 + rand() % 2;
			m_age = 1 + rand() % 4;
			sex = rand() % 2;
			fertilityIndex = 6 - m_age + rand() % 3 + 2;
			physicalStrength = 80 + rand() % 13;
		}
		else
		{
			if (key == 3)
			{
				type = 2;
				energy = 7 + rand() % 3;
				m_age = 7 + rand() % 5;
				sex = rand() % 2;
				fertilityIndex = rand() % 2 + 4;
				physicalStrength = 80 + rand() % 13;
			}
		}
	}
	number = animal->operateNumber(1);
	createPos(animal);
}

void CSheep::freeMove(CAnimal *animal)//�����ƶ�:0���� 1б���� 2���� 3б���� 4���� 5б���� 6���� 7б����
{
	if (drinkIndex == 0 || ifBack == 1 || hideIndex == 0)
		return;

	if (rand() % 100 == 66)//���ܲ��ƶ�
		return;
	int direction = -1;
	int x = pos_x, y = pos_y;
	int posAnimal = 0;
	int i = 0, j = 0, k = 0;
	int judge[8] = { 0 };//����Ƿ����߹�ĳһ����:0δ�߹� 1�߹�

	for (; k < 8; k++)
	{
		direction = rand() % 8;
		while (judge[direction] != 0)
		{
			direction = rand() % 8;
		}
		judge[direction] = 1;
		//�ж��Ƿ��������˶�
		if (direction == 0)
		{
			if (x - 1 < 13)
				continue;
			i = x - 1;
			j = y;
		}
		//�ж��Ƿ���б�����˶�
		if (direction == 1)
		{
			if (x - 1 < 13 || y + 1 >= 40)
				continue;
			i = x - 1;
			j = y + 1;
		}
		//�ж��Ƿ��������˶�
		if (direction == 2)
		{
			if (y + 1 >= 40)
				continue;
			i = x;
			j = y + 1;
		}
		//�ж��Ƿ���б�����˶�
		if (direction == 3)
		{
			if (x + 1 >= 26 || y + 1 >= 40)
				continue;
			i = x + 1;
			j = y + 1;
		}
		//�ж��Ƿ��������˶�
		if (direction == 4)
		{
			if (x + 1 >= 26)
				continue;
			i = x + 1;
			j = y;
		}
		//�ж��Ƿ���б�����˶�
		if (direction == 5)
		{
			if (x + 1 >= 26 || y - 1 < 0)
				continue;
			i = x + 1;
			j = y - 1;
		}
		//�ж��Ƿ��������˶�
		if (direction == 6)
		{
			if (y - 1 < 0)
				continue;
			i = x;
			j = y - 1;
		}
		//�ж��Ƿ���б�����˶�
		if (direction == 7)
		{
			if (x - 1 < 13 || y - 1 < 0)
				continue;
			i = x - 1;
			j = y - 1;
		}

		posAnimal = animal->getPos(i, j);
		if (posAnimal > 0)
			continue;
		else
			break;
	}

	if (k == 8)
		return;
	pos_x = i;
	pos_y = j;
	int key = animal->getPos(x, y);
	animal->updatePos(i, j, key);
	animal->updatePos(x, y, 0);
}

void CSheep::toDrinking(CAnimal *animal)//ȥ��ˮ
{
	if (hideIndex == 0)
		return;

	if (drinkIndex == 1)
		return;

	if (drinkIndex == -1)
	{
		if (rand() % 100 < 10)//���ܵ�ǰ����ˮ
			drinkIndex = 0;
		else
			return;
	}

	if (pos_x == 13)
	{
		drinkIndex = 1;
		ifBack = 1;
		return;
	}

	int direction = -1;
	if (pos_x > 13 && pos_y <= 37)
		direction = 0;
	else
	{
		if (pos_x > 13 && pos_y > 37)
			direction = 7;
		else
		{
			if (pos_x < 13 && pos_y <= 37)
				direction = 4;
			else
				direction = 5;
		}
	}
	int i = 0, j = 0;
	int x = pos_x, y = pos_y;
	int _x = 0, _y = 0;
	int posAnimal = 0;
	int mark = 0;
	int max = 0;
	int value = 0;
	for (i = 0; i < 3; i++)
	{
		if (i == 0)
			max = 1;
		else
			max = 2;
		mark = rand() % 2;//�ж�����
		for (j = 0; j < max; j++)
		{
			if (mark == 0)
			{
				value = -i;
				mark = 1;
			}
			else
			{
				value = i;
				mark = 0;
			}
			//�ж��Ƿ��������˶�
			if (direction + value == 0)
			{
				if (x - 1 < 0)
					continue;
				_x = x - 1;
				_y = y;
			}
			//�ж��Ƿ���б�����˶�
			if (direction + value == 1)
			{
				if (x - 1 < 0 || y + 1 >= 80)
					continue;
				_x = x - 1;
				_y = y + 1;
			}
			//�ж��Ƿ��������˶�
			if (direction + value == 2)
			{
				if (y + 1 >= 80)
					continue;
				_x = x;
				_y = y + 1;
			}
			//�ж��Ƿ���б�����˶�
			if (direction + value == 3)
			{
				if (x + 1 >= 26 || y + 1 >= 80)
					continue;
				_x = x + 1;
				_y = y + 1;
			}
			//�ж��Ƿ��������˶�
			if (direction + value == 4)
			{
				if (x + 1 >= 26)
					continue;
				_x = x + 1;
				_y = y;
			}
			//�ж��Ƿ���б�����˶�
			if (direction + value == 5)
			{
				if (x + 1 >= 26 || y - 1 < 0)
					continue;
				_x = x + 1;
				_y = y - 1;
			}
			//�ж��Ƿ��������˶�
			if (direction + value == 6)
			{
				if (y - 1 < 0)
					continue;
				_x = x;
				_y = y - 1;
			}
			//�ж��Ƿ���б�����˶�
			if (direction + value == 7)
			{
				if (x - 1 < 0 || y - 1 < 0)
					continue;
				_x = x - 1;
				_y = y - 1;
			}
			posAnimal = animal->getPos(_x, _y);
			if (posAnimal == 0)//�����ƶ�
			{
				pos_x = _x;
				pos_y = _y;
				animal->updatePos(x, y, 0);
				animal->updatePos(_x, _y, type);
				return;
			}
			else
				continue;
		}
	}
}

void CSheep::backHome(CAnimal *animal)//����
{
	if (drinkIndex == 0 || ifBack == 0 || hideIndex == 0)
		return;

	if (pos_x > 16 && pos_y < 29)
	{
		ifBack = 0;
		return;
	}

	int direction = -1;
	if (pos_x <= 16 && pos_y >= 29)
		direction = 5;
	else
	{
		if (pos_x <= 16 && pos_y < 29)
			direction = 4;
		else
			direction = 6;
	}

	int i = 0, j = 0;
	int x = pos_x, y = pos_y;
	int _x = 0, _y = 0;
	int posAnimal = 0;
	int mark = 0;
	int max = 1;
	int value = 0;
	for (i = 0; i < 3; i++)
	{
		if (i == 1)
			max = 2;
		mark = rand() % 2;//�ж�����
		for (j = 0; j < max; j++)
		{
			if (mark == 0)
			{
				value = -i;
				mark = 1;
			}
			else
			{
				value = i;
				mark = 0;
			}
			//�ж��Ƿ��������˶�
			if (direction + value == 0)
			{
				if (x - 1 < 0)
					continue;
				_x = x - 1;
				_y = y;
			}
			//�ж��Ƿ��������˶�
			if (direction + value == 2)
			{
				if (y + 1 >= 80)
					continue;
				_x = x;
				_y = y + 1;
			}
			//�ж��Ƿ���б�����˶�
			if (direction + value == 3)
			{
			if (x + 1 >= 26 || y + 1 >= 80)
			continue;
			_x = x + 1;
			_y = y + 1;
			}
			//�ж��Ƿ��������˶�
			if (direction + value == 4)
			{
				if (x + 1 >= 26)
					continue;
				_x = x + 1;
				_y = y;
			}
			//�ж��Ƿ���б�����˶�
			if (direction + value == 5)
			{
				if (x + 1 >= 26 || y - 1 < 0)
					continue;
				_x = x + 1;
				_y = y - 1;
			}
			//�ж��Ƿ��������˶�
			if (direction + value == 6)
			{
				if (y - 1 < 0)
					continue;
				_x = x;
				_y = y - 1;
			}
			//�ж��Ƿ���б�����˶�
			if (direction + value == 7)
			{
				if (x - 1 < 0 || y - 1 < 0)
					continue;
				_x = x - 1;
				_y = y - 1;
			}
			posAnimal = animal->getPos(_x, _y);
			if (posAnimal == 0)//�����ƶ�
			{
				pos_x = _x;
				pos_y = _y;
				animal->updatePos(x, y, 0);
				animal->updatePos(_x, _y, type);
				return;
			}
			else
				continue;
		}
	}
}

int CSheep::searchEnemy(CAnimal *animal)//��������
{
	if (hideIndex == 0)
		return -1;

	if (pos_x > 16 && pos_y < 29)//�ڼ��������������
		return -1;

	//����ֵ:0δ���ֵ��� 1���ֵ���

	int i = 0, j = 0, k = 0;
	int x = pos_x;
	int y = pos_y;
	int max1 = 0, max2 = 0;
	int posAnimal = 0;
	for (k = 1; k <= 3; k++)
	{
		if (x - k < 0)
			i = 0;
		else
			i = x - k;
		if (x + k >= 26)
			max1 = 25;
		else
			max1 = x + k;
		if (y + k >= 80)
			max2 = 79;
		else
			max2 = y + k;
		for (; i <= max1; i++)
		{
			if (y - k < 0)
				j = 0;
			else
				j = y - k;
			for (; j <= max2; j++)
			{
				if (i >= x - k + 1 && i <= x + k - 1 && j >= y - k + 1 && j <= y + k - 1)
					continue;
				posAnimal = animal->getPos(i, j);
				if (posAnimal >= 5 && posAnimal <= 8)
					return 1;
			}
		}
	}
	//û�е���
	return 0;
}

void CSheep::hideEnemy(CAnimal *animal)//��ܵ���
{
	if (hideIndex == -1)
		return;

	if (pos_x > 16 && pos_y < 29)
	{
		hideIndex = -1;
		return;
	}

	int direction = -1;
	if (pos_x <= 16 && pos_y >= 29)
		direction = 5;
	else
	{
		if (pos_x <= 16 && pos_y < 29)
			direction = 4;
		else
			direction = 6;
	}

	int i = 0, j = 0;
	int x = pos_x, y = pos_y;
	int _x = 0, _y = 0;
	int posAnimal = 0;
	int mark = 0;
	int max = 1;
	int value = 0;
	int speed = rand() % 2 + 1;
	while (speed > 0)
	{
		for (i = 0; i < 4; i++)
		{
			if (i == 1)
				max = 2;
			mark = rand() % 2;//�ж�����
			for (j = 0; j < max; j++)
			{
				if (mark == 0)
				{
					value = -i;
					mark = 1;
				}
				else
				{
					value = i;
					mark = 0;
				}
				//�ж��Ƿ��������˶�
				if (direction + value == 0)
				{
					if (x - 1 < 0)
						continue;
					_x = x - 1;
					_y = y;
				}
				//�ж��Ƿ��������˶�
				if (direction + value == 2)
				{
					if (y + 1 >= 80)
						continue;
					_x = x;
					_y = y + 1;
				}
				//�ж��Ƿ���б�����˶�
				if (direction + value == 3)
				{
					if (x + 1 >= 26 || y + 1 >= 80)
						continue;
					_x = x + 1;
					_y = y + 1;
				}
				//�ж��Ƿ��������˶�
				if (direction + value == 4)
				{
					if (x + 1 >= 26)
						continue;
					_x = x + 1;
					_y = y;
				}
				//�ж��Ƿ���б�����˶�
				if (direction + value == 5)
				{
					if (x + 1 >= 26 || y - 1 < 0)
						continue;
					_x = x + 1;
					_y = y - 1;
				}
				//�ж��Ƿ��������˶�
				if (direction + value == 6)
				{
					if (y - 1 < 0)
						continue;
					_x = x;
					_y = y - 1;
				}
				//�ж��Ƿ���б�����˶�
				if (direction + value == 7)
				{
					if (x - 1 < 0 || y - 1 < 0)
						continue;
					_x = x - 1;
					_y = y - 1;
				}
				posAnimal = animal->getPos(_x, _y);
				if (posAnimal == 0)//�����ƶ�
				{
					pos_x = _x;
					pos_y = _y;
					animal->updatePos(x, y, 0);
					animal->updatePos(_x, _y, type);
					return;
				}
				else
					continue;
			}
		}
		speed--;
	}
}

int CSheep::feed(CAnimal *animal)//��ʳ
{
	if (physicalStrength >= 90)
		return 0;
	else
		return 1;
}

void CSheep::saveData(CAnimal *animal)//��������Ϣ���ļ�
{
	animal->fSheep<< setw(3) << number  << "�� ";
	if (type == 1)
		animal->fSheep << "����" << ":" << endl;
	else
		animal->fSheep << "������" << ":" << endl;
	if (sex == 0)
		animal->fSheep << "          ����:" << setw(3) << m_age << "      " << "�Ա�:" << "��" << endl;
	else
		animal->fSheep << "          ����:" << setw(3) << m_age << "      " << "�Ա�:" << "��" << endl;
	animal->fSheep << "          ����:" << setw(3) << energy << "      " << "����:" << physicalStrength << endl;
	animal->fSheep << "          λ��:(" << setw(2) << pos_x << "," << setw(2) << pos_y <<")  " << "����ָ��:" << fertilityIndex << endl;
	animal->fSheep << endl;
}

CSheep::~CSheep()
{
}
