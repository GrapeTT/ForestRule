#include "Wolf.h"



CWolf::CWolf(int key, CAnimal *animal)//key������������
{
	if (key == 1)
	{
		type = 5;
		m_age = 0;
		sex = rand() % 2;
		fertilityIndex = 16 + rand() % 5 + 4;
		energy = 6 + rand() % 2;
		physicalStrength = 90 + rand() % 3;
	}
	else
	{
		if (key == 2)
		{
			type = 5;
			m_age = 1 + rand() % 4;
			sex = rand() % 2;
			fertilityIndex = 8 - m_age + rand() % 5 + 12;
			energy = 6 + rand() % 2;
			physicalStrength = 80 + rand() % 13;
		}
		else
		{
			if (key == 3)
			{
				type = 6;
				energy = 9 + rand() % 3;
				m_age = 9 + rand() % 5;
				sex = rand() % 2;
				fertilityIndex = rand() % 5 + 4;
				physicalStrength = 80 + rand() % 13;
			}
		}
	}
	number = animal->operateNumber(3);
	createPos(animal);
}

void CWolf::freeMove(CAnimal *animal)//�����ƶ�:0���� 1б���� 2���� 3б���� 4���� 5б���� 6���� 7б����
{
	if (feedGoal != -1 ||drinkIndex == 0 || ifBack == 1)
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
			if (x - 1 < 0)
				continue;
			i = x - 1;
			j = y;
		}
		//�ж��Ƿ���б�����˶�
		if (direction == 1)
		{
			if (x - 1 < 0 || y + 1 >= 40)
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
			if (x + 1 >= 13 || y + 1 >= 40)
				continue;
			i = x + 1;
			j = y + 1;
		}
		//�ж��Ƿ��������˶�
		if (direction == 4)
		{
			if (x + 1 >= 13)
				continue;
			i = x + 1;
			j = y;
		}
		//�ж��Ƿ���б�����˶�
		if (direction == 5)
		{
			if (x + 1 >= 13 || y - 1 < 0)
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
			if (x - 1 < 0 || y - 1 < 0)
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

void CWolf::toDrinking(CAnimal *animal)//ȥ��ˮ
{
	if (feedGoal != -1)
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

	if (pos_x == 12)
	{
		drinkIndex = 1;
		ifBack = 1;
		return;
	}

	int direction = -1;
	if (pos_x < 12 && pos_y <= 37)
		direction = 4;
	else
	{
		if (pos_x < 12 && pos_y > 37)
			direction = 5;
		else
		{
			if (pos_x > 12 && pos_y <= 37)
				direction = 0;
			else
				direction = 7;
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

void CWolf::backHome(CAnimal *animal)//����
{
	if (feedGoal != -1 || drinkIndex == 0 || ifBack == 0)
		return;

	if (pos_x <= 7 && pos_y <= 21)
	{
		ifBack = 0;
		return;
	}

	int direction = -1;
	if (pos_x > 7 && pos_y > 21)
		direction = 7;
	else
	{
		if (pos_x > 7)
			direction = 0;
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

int CWolf::searchPrey(CAnimal *animal)//Ѱ������
{	
	if (ifBack == 1)
		return -1;

	if (feedGoal != -1)
		return -1;

	if (physicalStrength > 90)
		feedIndex = 1;

	if (feedIndex == -1)
	    feedIndex = 0;
	int i = 0, j = 0, k = 0;
	int x = pos_x;
	int y = pos_y;
	int max1 = 0, max2 = 0, max3 = 0;
	int posAnimal = 0;

	if (feedIndex == 0)
		max1 = 6;
	else
		max1 = 4;
	for (i = 1; i <= max1; i++)
	{
		if (x - i < 0)
			j = 0;
		else
			j = x - i;
		if (x + i >= 26)
			max2 = 25;
		else
			max2 = x + i;
		if (y + i >= 80)
			max3 = 79;
		else
			max3 = y + i;
		for (; j <= max2; j++)
		{
			if (y - i < 0)
				k = 0;
			else
				k = y - i;
			for (; k <= max3; k++)
			{
				if (j >= x - i + 1 && j <= x + i - 1 && k >= y - i + 1 && k <= y + i - 1)
					continue;
				posAnimal = animal->getPos(j, k);
				if (posAnimal >= 1 && posAnimal <= 4)
				{
					if ((goal_x > 16 && goal_y < 29) || (goal_x < 9 && goal_y > 50))
						return 0;
					goal_x = j;
					goal_y = k;
					return 1;
				}
			}
		}
	}
	return 0;//δ����Ŀ��
}

void CWolf::catchPrey(CAnimal *animal)//׷������
{
	if (feedGoal == -1)
		return;

	if ((goal_x > 16 && goal_y < 29) || (goal_x < 9 && goal_y > 50))
	{
		ifBack = 1;
		feedGoal = -1;
		goal_x = -1;
		goal_y = -1;
		return;
	}

	int direction = -1;
	if (fabs((double)pos_x - (double)goal_x) / fabs((double)pos_y - (double)goal_y) < (double)0.5)
	{
		if (goal_y < pos_y)
			direction = 6;
		else
			direction = 2;
	}
	else
	{
		if (fabs((double)pos_y - (double)goal_y) / fabs((double)pos_x - (double)goal_x) < (double)0.5)
		{
			if (goal_x < pos_x)
				direction = 0;
			else
				direction = 4;
		}
		else
		{
			if (goal_x < pos_x)
			{
				if (goal_y < pos_y)
					direction = 7;
				else
					direction = 1;
			}
			else
			{
				if (goal_y < pos_y)
					direction = 5;
				else
					direction = 3;
			}
		}
	}

	int speed = 0;
	if (type == 5)
		speed = rand() % 2 + 1;
	else
		speed = rand() % 2 + 2;
	int i = 0, j = 0;
	int x = pos_x, y = pos_y;
	int _x = 0, _y = 0;
	int posAnimal = 0;
	int mark = 0;
	int max = 1;
	int value = 0;
	while (speed > 0)
	{
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
					if (x - speed < 0)
						continue;
					_x = x - speed;
					_y = y;
				}
				//�ж��Ƿ���б�����˶�
				if (direction + value == 1)
				{
					if (x - speed < 0 || y + speed >= 80)
						continue;
					_x = x - speed;
					_y = y + speed;
				}
				//�ж��Ƿ��������˶�
				if (direction + value == 2)
				{
					if (y + speed >= 80)
						continue;
					_x = x;
					_y = y + speed;
				}
				//�ж��Ƿ���б�����˶�
				if (direction + value == 3)
				{
					if (x + speed >= 26 || y + speed >= 80)
						continue;
					_x = x + speed;
					_y = y + speed;
				}
				//�ж��Ƿ��������˶�
				if (direction + value == 4)
				{
					if (x + speed >= 26)
						continue;
					_x = x + speed;
					_y = y;
				}
				//�ж��Ƿ���б�����˶�
				if (direction + value == 5)
				{
					if (x + speed >= 26 || y - speed < 0)
						continue;
					_x = x + speed;
					_y = y - speed;
				}
				//�ж��Ƿ��������˶�
				if (direction + value == 6)
				{
					if (y - speed < 0)
						continue;
					_x = x;
					_y = y - speed;
				}
				//�ж��Ƿ���б�����˶�
				if (direction + value == 7)
				{
					if (x - speed < 0 || y - speed < 0)
						continue;
					_x = x - speed;
					_y = y - speed;
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

int CWolf::feed(CAnimal *animal)//��ʳ
{
	if (feedGoal == -1)
		return -1;

	int posAnimal = 0;
	int key = -1;//�ж���û�в�ʳ�ɹ�:-1δ������ʳ 0ʧ�� 1�ɹ�

	if (abs(goal_x - pos_x) > 3 || abs(goal_y - pos_y) > 3)
		return -1;

	key = 0;
	posAnimal = animal->getPos(goal_x, goal_y);
	if (type == 5)//���ǲ�ʳ
	{
		if (posAnimal == 1 || posAnimal == 3)
		{
			if (abs(goal_x - pos_x) <= 1 && abs(goal_y - pos_y) <= 1)
				key = 1;
			if (abs(goal_x - pos_x) == 2 && abs(goal_y - pos_y) <= 2)
			{
				if (rand() % 10 <= 8)
					key = 1;
			}
			if (abs(goal_x - pos_x) == 3 && abs(goal_y - pos_y) <= 3)
			{
				if (rand() % 10 <= 6)
					key = 1;
			}
		}
	}
	else//�����ǲ�ʳ
	{
		if (posAnimal == 1 || posAnimal == 3)
			key = 1;
		if (posAnimal == 2 || posAnimal == 4)
		{
			if (abs(goal_x - pos_x) <= 1 && abs(goal_y - pos_y) <= 1)
				key = 1;
			if (abs(goal_x - pos_x) == 2 && abs(goal_y - pos_y) <= 2)
			{
				if (rand() % 10 <= 8)
					key = 1;
			}
			if (abs(goal_x - pos_x) == 3 && abs(goal_y - pos_y) <= 3)
			{
				if (rand() % 10 <= 6)
					key = 1;
			}
		}
	}

	if (key == 1)
	{
		animal->updatePos(pos_x, pos_y, 0);
		pos_x = goal_x;
		pos_y = goal_y;
		animal->updatePos(pos_x, pos_y, type);
	}
	return key;
}

void CWolf::saveData(CAnimal *animal)//��������Ϣ���ļ�
{
	animal->fWolf << setw(3) << number << "�� ";
	if (type == 5)
		animal->fWolf << "����" << ":" << endl;
	else
		animal->fWolf << "������" << ":" << endl;
	if (sex == 0)
		animal->fWolf << "          ����:" << setw(3) << m_age << "      " << "�Ա�:" << "��" << endl;
	else
		animal->fWolf << "          ����:" << setw(3) << m_age << "      " << "�Ա�:" << "��" << endl;
	animal->fWolf << "          ����:" << setw(3) << energy << "      " << "����:" << physicalStrength << endl;
	animal->fWolf << "          λ��:(" << setw(2) << pos_x << "," << setw(2) << pos_y << ")  " << "����ָ��:" << fertilityIndex << endl;
	animal->fWolf << endl;
}

CWolf::~CWolf()
{
}
