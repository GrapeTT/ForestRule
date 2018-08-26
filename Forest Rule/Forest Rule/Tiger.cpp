#include "Tiger.h"



CTiger::CTiger(int key, CAnimal *animal)//key控制生成类型
{
	if (key == 1)
	{
		type = 7;
		m_age = 0;
		sex = rand() % 2;
		fertilityIndex = 16 + rand() % 5 + 4;
		energy = 7 + rand() % 2;
		physicalStrength = 90 + rand() % 3;
	}
	else
	{
		if (key == 2)
		{
			type = 7;
			m_age = 2 + rand() % 4;
			sex = rand() % 2;
			fertilityIndex = 8 - m_age + rand() % 5 + 12;
			energy = 7 + rand() % 2;
			physicalStrength = 80 + rand() % 13;
		}
		else
		{
			if (key == 3)
			{
				type = 8;
				energy = 11 + rand() % 3;
				m_age = 11 + rand() % 5;
				sex = rand() % 2;
				fertilityIndex = rand() % 5 + 4;
				physicalStrength = 80 + rand() % 13;
			}
		}
	}
	number = animal->operateNumber(4);
	createPos(animal);
}

void CTiger::freeMove(CAnimal *animal)//自由移动:0向上 1斜右上 2向右 3斜右下 4向下 5斜左下 6向左 7斜左上
{
	if (feedGoal != -1 || drinkIndex == 0 || ifBack == 1)
		return;

	if (rand() % 100 == 66)//可能不移动
		return;
	int direction = -1;
	int x = pos_x, y = pos_y;
	int posAnimal = 0;
	int i = 0, j = 0, k = 0;
	int judge[8] = { 0 };//标记是否尝试走过某一方向:0未走过 1走过

	for (; k < 8; k++)
	{
		direction = rand() % 8;
		while (judge[direction] != 0)
		{
			direction = rand() % 8;
		}
		judge[direction] = 1;
		//判断是否能向上运动
		if (direction == 0)
		{
			if (x - 1 < 13)
				continue;
			i = x - 1;
			j = y;
		}
		//判断是否能斜右上运动
		if (direction == 1)
		{
			if (x - 1 < 13 || y + 1 >= 80)
				continue;
			i = x - 1;
			j = y + 1;
		}
		//判断是否能向右运动
		if (direction == 2)
		{
			if (y + 1 >= 80)
				continue;
			i = x;
			j = y + 1;
		}
		//判断是否能斜右下运动
		if (direction == 3)
		{
			if (x + 1 >= 26 || y + 1 >= 80)
				continue;
			i = x + 1;
			j = y + 1;
		}
		//判断是否能向下运动
		if (direction == 4)
		{
			if (x + 1 >= 26)
				continue;
			i = x + 1;
			j = y;
		}
		//判断是否能斜左下运动
		if (direction == 5)
		{
			if (x + 1 >= 26 || y - 1 < 40)
				continue;
			i = x + 1;
			j = y - 1;
		}
		//判断是否能向左运动
		if (direction == 6)
		{
			if (y - 1 < 40)
				continue;
			i = x;
			j = y - 1;
		}
		//判断是否能斜左上运动
		if (direction == 7)
		{
			if (x - 1 < 13 || y - 1 < 40)
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

void CTiger::toDrinking(CAnimal *animal)//去饮水
{
	if (feedGoal != -1)
		return;

	if (drinkIndex == 1)
		return;

	if (drinkIndex == -1)
	{
		if (rand() % 100 < 10)//可能当前不饮水
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
	if (pos_x > 13 && pos_y >= 42)
		direction = 0;
	else
	{
		if (pos_x > 13 && pos_y < 42)
			direction = 1;
		else
		{
			if (pos_x < 13 && pos_y >= 42)
				direction = 4;
			else
				direction = 3;
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
		mark = rand() % 2;//判断左右
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
			//判断是否能向上运动
			if (direction + value == 0)
			{
				if (x - 1 < 0)
					continue;
				_x = x - 1;
				_y = y;
			}
			//判断是否能斜右上运动
			if (direction + value == 1)
			{
				if (x - 1 < 0 || y + 1 >= 80)
					continue;
				_x = x - 1;
				_y = y + 1;
			}
			//判断是否能向右运动
			if (direction + value == 2)
			{
				if (y + 1 >= 80)
					continue;
				_x = x;
				_y = y + 1;
			}
			//判断是否能斜右下运动
			if (direction + value == 3)
			{
				if (x + 1 >= 26 || y + 1 >= 80)
					continue;
				_x = x + 1;
				_y = y + 1;
			}
			//判断是否能向下运动
			if (direction + value == 4)
			{
				if (x + 1 >= 26)
					continue;
				_x = x + 1;
				_y = y;
			}
			//判断是否能斜左下运动
			if (direction + value == 5)
			{
				if (x + 1 >= 26 || y - 1 < 0)
					continue;
				_x = x + 1;
				_y = y - 1;
			}
			//判断是否能向左运动
			if (direction + value == 6)
			{
				if (y - 1 < 0)
					continue;
				_x = x;
				_y = y - 1;
			}
			//判断是否能斜左上运动
			if (direction + value == 7)
			{
				if (x - 1 < 0 || y - 1 < 0)
					continue;
				_x = x - 1;
				_y = y - 1;
			}
			posAnimal = animal->getPos(_x, _y);
			if (posAnimal == 0)//进行移动
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

void CTiger::backHome(CAnimal *animal)//返家
{
	if (feedGoal != -1 || drinkIndex == 0 || ifBack == 0)
		return;

	if (pos_x >= 18 && pos_y >= 58)
	{
		ifBack = 0;
		return;
	}

	int direction = -1;
	if (pos_x < 18 && pos_y < 58)
		direction = 3;
	else
	{
		if (pos_x < 18)
			direction = 4;
		else
			direction = 2;
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
		mark = rand() % 2;//判断左右
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
			//判断是否能向上运动
			if (direction + value == 0)
			{
				if (x - 1 < 0)
					continue;
				_x = x - 1;
				_y = y;
			}
			//判断是否能斜右上运动
			if (direction + value == 1)
			{
				if (x - 1 < 0 || y + 1 >= 80)
					continue;
				_x = x - 1;
				_y = y + 1;
			}
			//判断是否能向右运动
			if (direction + value == 2)
			{
				if (y + 1 >= 80)
					continue;
				_x = x;
				_y = y + 1;
			}
			//判断是否能斜右下运动
			if (direction + value == 3)
			{
				if (x + 1 >= 26 || y + 1 >= 80)
					continue;
				_x = x + 1;
				_y = y + 1;
			}
			//判断是否能向下运动
			if (direction + value == 4)
			{
				if (x + 1 >= 26)
					continue;
				_x = x + 1;
				_y = y;
			}
			//判断是否能斜左下运动
			if (direction + value == 5)
			{
				if (x + 1 >= 26 || y - 1 < 0)
					continue;
				_x = x + 1;
				_y = y - 1;
			}
			//判断是否能向左运动
			if (direction + value == 6)
			{
				if (y - 1 < 0)
					continue;
				_x = x;
				_y = y - 1;
			}
			posAnimal = animal->getPos(_x, _y);
			if (posAnimal == 0)//进行移动
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

int CTiger::searchPrey(CAnimal *animal)//寻找猎物
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
	return 0;//未发现目标
}

void CTiger::catchPrey(CAnimal *animal)//追赶猎物
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
			mark = rand() % 2;//判断左右
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
				//判断是否能向上运动
				if (direction + value == 0)
				{
					if (x - speed < 0)
						continue;
					_x = x - speed;
					_y = y;
				}
				//判断是否能斜右上运动
				if (direction + value == 1)
				{
					if (x - speed < 0 || y + speed >= 80)
						continue;
					_x = x - speed;
					_y = y + speed;
				}
				//判断是否能向右运动
				if (direction + value == 2)
				{
					if (y + speed >= 80)
						continue;
					_x = x;
					_y = y + speed;
				}
				//判断是否能斜右下运动
				if (direction + value == 3)
				{
					if (x + speed >= 26 || y + speed >= 80)
						continue;
					_x = x + speed;
					_y = y + speed;
				}
				//判断是否能向下运动
				if (direction + value == 4)
				{
					if (x + speed >= 26)
						continue;
					_x = x + speed;
					_y = y;
				}
				//判断是否能斜左下运动
				if (direction + value == 5)
				{
					if (x + speed >= 26 || y - speed < 0)
						continue;
					_x = x + speed;
					_y = y - speed;
				}
				//判断是否能向左运动
				if (direction + value == 6)
				{
					if (y - speed < 0)
						continue;
					_x = x;
					_y = y - speed;
				}
				//判断是否能斜左上运动
				if (direction + value == 7)
				{
					if (x - speed < 0 || y - speed < 0)
						continue;
					_x = x - speed;
					_y = y - speed;
				}
				posAnimal = animal->getPos(_x, _y);
				if (posAnimal == 0)//进行移动
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

int CTiger::feed(CAnimal *animal)//捕食
{
	if (feedGoal == -1)
		return -1;

	int posAnimal = 0;
	int key = -1;//判断有没有捕食成功:-1未发生捕食 0失败 1成功

	if (abs(goal_x - pos_x) > 3 || abs(goal_y - pos_y) > 3)
		return -1;

	key = 0;
	posAnimal = animal->getPos(goal_x, goal_y);
	if (type == 7)//幼虎捕食
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
	else//成年虎捕食
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
		feedIndex = 1;
		ifBack = 1;
		animal->updatePos(pos_x, pos_y, 0);
		pos_x = goal_x;
		pos_y = goal_y;
		animal->updatePos(pos_x, pos_y, type);
		feedGoal = -1;
		goal_x = -1;
		goal_y = -1;
	}
	return key;
}

void CTiger::saveData(CAnimal *animal)//保存狼信息至文件
{
	animal->fTiger << setw(3) << number << "号 ";
	if (type == 7)
		animal->fTiger << "幼虎" << ":" << endl;
	else
		animal->fTiger << "成年虎" << ":" << endl;
	if (sex == 0)
		animal->fTiger << "          年龄:" << setw(3) << m_age << "      " << "性别:" << "雌" << endl;
	else
		animal->fTiger << "          年龄:" << setw(3) << m_age << "      " << "性别:" << "雄" << endl;
	animal->fTiger << "          能量:" << setw(3) << energy << "      " << "体力:" << physicalStrength << endl;
	animal->fTiger << "          位置:(" << setw(2) << pos_x << "," << setw(2) << pos_y << ")  " << "抑育指数:" << fertilityIndex << endl;
	animal->fTiger << endl;
}

CTiger::~CTiger()
{
}
