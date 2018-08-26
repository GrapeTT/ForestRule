#include "Animal.h"


CAnimal::CAnimal()
{
}

void CAnimal::createAnimal()//生成动物(设置数量)
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

int CAnimal::operateNumber(int key)//操作(改变并获得)种群编号:1羊 2鹿 3狼 4虎
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

void CAnimal::createPos(CAnimal *animal)//生成位置
{
	int x = 0, y = 0;

	if (type == 1 || type == 2)//产羊
	{
		x = (rand() % 8) + 16;
		y = (rand() % 20) + 10;
		while (animal->getPos(x, y) > 0)//已存在动物，再次生成位置
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

	if (type == 3 || type == 4)//产鹿
	{
		x = (rand() % 8) + 2;
		y = (rand() % 20) + 50;
		while (animal->getPos(x, y) > 0)//已存在动物，再次生成位置
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

	if (type == 5 || type == 6)//产狼
	{
		x = (rand() % 4) + 4;
		y = (rand() % 5) + 17;
		while (animal->getPos(x, y) > 0)//已存在动物，再次生成位置
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

	if (type == 7 || type == 8)//产虎
	{
		x = (rand() % 4) + 18;
		y = (rand() % 5) + 58;
		while (animal->getPos(x, y) > 0)//已存在动物，再次生成位置
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

void CAnimal::updatePos(int &i, int &j, int key)//更新位置信息
{
	m_pos[i][j] = key;
}

int CAnimal::breed(int key)//繁殖规则:1羊 2鹿 3狼 4虎
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

int CAnimal::die()//死亡规则
{
	if (type == 1 || type == 2)//羊
	{
		if (energy <= 0)
			return 1;
		if (m_age > 25)
			return 2;
		return 0;
	}

	if (type == 3 || type == 4)//鹿
	{
		if (energy <= 0)
			return 1;
		if (m_age > 28)
			return 2;
		return 0;
	}

	if (type == 5 || type == 6)//狼
	{
		if (energy <= 0)
			return 1;
		if (m_age > 30)
			return 2;
		return 0;
	}

	if (type == 7 || type == 8)//虎
	{
		if (energy <= 0)
			return 1;
		if (m_age > 35)
			return 2;
		return 0;
	}
}

int CAnimal::getPos(int &i, int &j)const//获得当前位置的信息
{
	return m_pos[i][j];
}

void CAnimal::freeMove(CAnimal *animal)//自由移动:0向上 1斜右上 2向右 3斜右下 4向下 5斜左下 6向左 7斜左上
{
	
}

void CAnimal::toDrinking(CAnimal *animal)//去饮水
{

}

void CAnimal::backHome(CAnimal *animal)//返家
{

}

int CAnimal::feed(CAnimal *animal)//捕食规则
{
	return 0;
}

int CAnimal::searchPrey(CAnimal *animal)//寻找猎物
{
	return 0;
}

void CAnimal::catchPrey(CAnimal *animal)//追赶猎物
{

}

int CAnimal::searchEnemy(CAnimal *animal)//搜索敌人
{
	return 0;
}

void CAnimal::hideEnemy(CAnimal *animal)//躲避敌人
{

}

void CAnimal::changeAmount(int key, int value)//改变动物数量信息(key控制):1幼羊 2成年羊 3幼鹿 4成年鹿 5幼狼 6成年狼 7幼虎 8成年虎
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

int CAnimal::getInfo(int key)const//获得动物数量信息:1幼羊 2成年羊 3所有羊 4幼鹿 5成年鹿 6所有鹿 7幼狼 8成年狼 9所有狼 10幼虎 11成年虎 12所有虎 13所有动物
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

void CAnimal::printPos(int &i, int &j)const//输出动物
{
	if (m_pos[i][j] == 1)//输出幼羊
	{
		cout << 'H';
		return;
	}
	if (m_pos[i][j] == 2)//输出成年羊
	{
		cout << 'S';
		return;
	}

	if (m_pos[i][j] == 3)//输出幼鹿
	{
		cout << 'R';
		return;
	}
	if (m_pos[i][j] == 4)//输出成年鹿
	{
		cout << 'D';
		return;
	}

	if (m_pos[i][j] == 5)//输出幼狼
	{
		cout << 'F';
		return;
	}
	if (m_pos[i][j] == 6)//输出成年狼
	{
		cout << 'W';
		return;
	}

	if (m_pos[i][j] == 7)//输出幼虎
	{
		cout << 'G';
		return;
	}
	if (m_pos[i][j] == 8)//输出成年虎
	{
		cout << 'T';
		return;
	}

	cout << ' ';
}

void CAnimal::saveData(CAnimal *animal)//保存动物信息至文件
{
}

CAnimal::~CAnimal()
{
}
