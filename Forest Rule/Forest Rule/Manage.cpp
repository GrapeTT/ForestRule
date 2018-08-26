#include "Manage.h"



CManage::CManage()
{
	srand(time(NULL));
	plant->createPlant();
	animal->createAnimal();

	int i = 0;
	int young = 0, adult = 0;

	//树
	young = plant->getInfo(1);
	adult = plant->getInfo(2);
	for (i = 0; i < young; i++)
		plants.push_back(new CTree(2, plant));
	for (i = 0; i < adult; i++)
		plants.push_back(new CTree(3, plant));
	//草
	young = plant->getInfo(4);
	adult = plant->getInfo(5);
	for (i = 0; i < young; i++)
		plants.push_back(new CGrass(2, plant));
	for (i = 0; i < adult; i++)
		plants.push_back(new CGrass(3, plant));
	//羊
	young = animal->getInfo(1);
	adult = animal->getInfo(2);
	for (i = 0; i < young; i++)
		animals.push_back(new CSheep(2, animal));
	for (i = 0; i < adult; i++)
		animals.push_back(new CSheep(3, animal));
	//鹿
	young = animal->getInfo(4);
	adult = animal->getInfo(5);
	for (i = 0; i < young; i++)
		animals.push_back(new CDeer(2, animal));
	for (i = 0; i < adult; i++)
		animals.push_back(new CDeer(3, animal));
	//狼
	young = animal->getInfo(7);
	adult = animal->getInfo(8);
	for (i = 0; i < young; i++)
		animals.push_back(new CWolf(2, animal));
	for (i = 0; i < adult; i++)
		animals.push_back(new CWolf(3, animal));
	//虎
	young = animal->getInfo(10);
	adult = animal->getInfo(11);
	for (i = 0; i < young; i++)
		animals.push_back(new CTiger(2, animal));
	for (i = 0; i < adult; i++)
		animals.push_back(new CTiger(3, animal));
}

int CManage::start()//生态系统开始运行
{
	int time = 0, i = 0, j = 0;
	cout << "请输入要运行的天数:";
	cin >> time;
	getchar();

	system("cls");
	drawForest();
	Sleep(1000);

	for (i = 0; i < time; i++)
	{
		date++;

		//气候变换
		if (date % 5 == 4)
			climate->controlSeason();
		climate->controlWeather();

		if (animal->getInfo(13) == 0)//动物数量为0
		{
			cout << endl;
			cout << "动物已全部死亡!!!是否仍要继续运行?(ENTER键继续,ESC键退出):";
			char s;
			while (true)
			{
				s = _getch();
				if (s == 0x0D)//ENTER键继续
					break;
				else
				{
					if (s == 0x1b)//ESC键退出
						return 0;
				}
			}
		}
		
		if (date % 10 == 9)//可能发生灾难
			occurEvents();

		//动物一天的运动过程
		for (j = 0; j < 24; j++)
		{
			travelAnimals(j);
			system("cls");
			drawForest();
			Sleep(300);
		}

		//更新动物信息
		updatePlantVector();
		updateAnimalVector();

		//生物繁殖
		executePlantBreed();
		executeAnimalBreed();

		//绘制出一天结束后森林的状态以及输出一天中发生的事件
		system("cls");
		drawForest();
		events->print();

		if (i < time - 1)
		{
			cout << "任意键继续:";
			_getch();
		}
	}
	return 1;
}

void CManage::travelAnimals(int time)//遍历动物容器:time为一天中的运行次数
{
	int i = 0;
	int pos = 0;
	for (i = 0; i < animals.size(); i++)
	{
		if (time > 17)
			animals[i]->ifBack = 1;
		//羊
		if (animals[i]->type == 1 || animals[i]->type == 2)
		{
			if (animals[i]->feed(animal) == 1 && animals[i]->hideIndex == -1)
			{
				pos = plant->getPos(animals[i]->pos_x, animals[i]->pos_y);
				if (pos == 3 || pos == 4)
					executeFeed(i);
			}
			if (animals[i]->searchEnemy(animal) == 1)
				noticeOthers(animals[i]->type);
			animals[i]->hideEnemy(animal);
			animals[i]->toDrinking(animal);
			animals[i]->backHome(animal);
			animals[i]->freeMove(animal);
			continue;
		}
		//鹿
		if (animals[i]->type == 3 || animals[i]->type == 4)
		{
			if (animals[i]->feed(animal) == 1 && animals[i]->hideIndex == -1)
			{
				pos = plant->getPos(animals[i]->pos_x, animals[i]->pos_y);
				if (pos == 3 || pos == 4)
					executeFeed(i);
			}
			if (animals[i]->searchEnemy(animal) == 1)
				noticeOthers(animals[i]->type);
			animals[i]->hideEnemy(animal);
			animals[i]->toDrinking(animal);
			animals[i]->backHome(animal);
			animals[i]->freeMove(animal);
			continue;
		}
		//狼
		if (animals[i]->type == 5 || animals[i]->type == 6)
		{
			if (animals[i]->searchPrey(animal) == 1)
			{
				events->changeFeed(1);
				lockGoal(i);
			}
			if (animals[i]->feed(animal) == 1)
			{
				events->changeFeed(2);
				if (executeFeed(i) < i)
					i--;
			}
			if (animals[i]->feedGoal != -1)
			{
				animals[i]->goal_x = animals[animals[i]->feedGoal]->pos_x;
				animals[i]->goal_y = animals[animals[i]->feedGoal]->pos_y;
			}
			animals[i]->catchPrey(animal);
			animals[i]->toDrinking(animal);
			animals[i]->backHome(animal);
			animals[i]->freeMove(animal);
			continue;
		}
		//虎
		if (animals[i]->type == 7 || animals[i]->type == 8)
		{
			if (animals[i]->searchPrey(animal) == 1)
			{
				events->changeFeed(3);
				lockGoal(i);
			}
			if (animals[i]->feed(animal) == 1)
			{
				events->changeFeed(4);
				if (executeFeed(i) < i)
					i--;
			}
			if (animals[i]->feedGoal != -1)
			{
				animals[i]->goal_x = animals[animals[i]->feedGoal]->pos_x;
				animals[i]->goal_y = animals[animals[i]->feedGoal]->pos_y;
			}
			animals[i]->catchPrey(animal);
			animals[i]->toDrinking(animal);
			animals[i]->backHome(animal);
			animals[i]->freeMove(animal);
			continue;
		}
	}
}

void CManage::lockGoal(int i)//锁定目标
{
	int type = animals[i]->type;
	if (type % 2 == 0)
		type -= 1;
	 
	int j = 0, k = 0;
	for (; j < animals.size(); j++)
	{
		if (animals[j]->pos_x == animals[i]->goal_x && animals[j]->pos_y == animals[i]->goal_y)
			break;
	}
	if (type == 5)//狼一般团体作战
	{
		for (; k < animals.size(); k++)
		{
			if (animals[k]->type == type || animals[k]->type == type + 1)
				animals[k]->feedGoal = j;
		}
	}
	else//老虎一般单独行动
	{
		animals[i]->feedGoal = j;
	}
}

void CManage::noticeOthers(int type)//发现敌人，通知其他同伴
{
	if (type % 2 == 0)
		type -= 1;

	for (int i = 0; i < animals.size(); i++)
	{
		if (animals[i]->type == type || animals[i]->type == type + 1)
		{
			if (type == 1)
			{
				if (animals[i]->pos_x <= 16 || animals[i]->pos_y >= 29)
					animals[i]->hideIndex = 0;
			}
			else
			{
				if (animals[i]->pos_x >= 9 || animals[i]->pos_y <= 50)
					animals[i]->hideIndex = 0;
			}
		}
	}
}

int CManage::executeFeed(int i)//执行动物捕食
{
	int key = 0;
	if (animals[i]->type >= 1 && animals[i]->type <= 4)
		key = 1;
	else
		key = 2;
	int j = cleanVector(key, i);
	return j;
}

int CManage::cleanVector(int key, int j)//查找并清除某个vector中的某个元素(key区分类别):1植物 2动物
{
	int type = animals[j]->type;
	if (type % 2 == 0)
		type -= 1;

	int x = animals[j]->pos_x;
	int y = animals[j]->pos_y;
	int i = 0, k = 0;

	if (key == 1)//羊或鹿吃草
	{
		for (; i < plants.size(); i++)
		{
			if (plants[i]->pos_x == x && plants[i]->pos_y == y)
			{
				plant->changeAmount(plants[i]->type, -1);
				plant->updatePos(x, y, 0);
				animals[j]->physicalStrength += plants[i]->energy;
				if (animals[j]->physicalStrength > 100)
					animals[j]->physicalStrength = 100;
				delete plants[i];
				plants.erase(plants.begin() + i);
				return -1;
			}
		}
	}

	if (key == 2)//狼或虎捕食
	{
		for (; i < animals.size(); i++)
		{
			if (animals[i]->pos_x == x && animals[i]->pos_y == y && animals[i]->type != animals[j]->type)
			{
				animal->changeAmount(animals[i]->type, -1);
				if (type == 5)//狼群团体增益
				{
					for (; k < animals.size(); k++)
					{
						if (animals[k]->type == type || animals[k]->type == type + 1)
						{
							animals[k]->feedIndex = 1;
							animals[k]->ifBack = 1;
							animals[k]->feedGoal = -1;
							animals[k]->goal_x = -1;
							animals[k]->goal_y = -1;
							animals[k]->physicalStrength += animals[i]->energy;
							if (animals[k]->physicalStrength > 100)
								animals[k]->physicalStrength = 100;
						}
					}
				}
				else//单只虎和幼虎增益
				{
					animals[j]->physicalStrength += animals[i]->energy;
					if (animals[j]->physicalStrength > 100)
						animals[j]->physicalStrength = 100;
					for (; k < animals.size(); k++)
					{
						if (animals[k]->type == type)
						{
							animals[k]->feedIndex = 1;
							animals[k]->physicalStrength += animals[i]->energy;
							if (animals[k]->physicalStrength > 100)
								animals[k]->physicalStrength = 100;
						}
					}
				}
				delete animals[i];
				animals.erase(animals.begin() + i);
				return i;
			}
		}
	}
}

void CManage::addVector(int key)//扩充容器:1树 2草 3羊 4鹿 5狼 6虎
{
	//树
	if (key == 1)
	{
		plants.push_back(new CTree(1, plant));
		plant->changeAmount(1, 1);
		return;
	}
	//草
	if (key == 2)
	{
		plants.push_back(new CGrass(1, plant));
		plant->changeAmount(3, 1);
		return;
	}
	//羊
	if (key == 3)
	{
		animals.push_back(new CSheep(1, animal));
		animal->changeAmount(1, 1);
		return;
	}
	//鹿
	if (key == 4)
	{
		animals.push_back(new CDeer(1, animal));
		animal->changeAmount(3, 1);
		return;
	}
	//狼
	if (key == 5)
	{
		animals.push_back(new CWolf(1, animal));
		animal->changeAmount(5, 1);
		return;
	}
	//虎
	if (key == 6)
	{
		animals.push_back(new CTiger(1, animal));
		animal->changeAmount(7, 1);
		return;
	}
}

void CManage::updatePlantVector()//更新植物容器
{
	int i = 0;

	for (i = 0; i < plants.size(); i++)
	{
		//草
		if (plants[i]->type == 3)
		{
			plants[i]->m_age++;
			if (plants[i]->m_age > 1)
			{
				plants[i]->type = 4;
				plants[i]->energy++;
				plant->updatePos(plants[i]->pos_x, plants[i]->pos_y, 4);
				plant->changeAmount(3, -1);
				plant->changeAmount(4, 1);
			}
			continue;
		}
		if (plants[i]->type == 4)
		{
			plants[i]->m_age++;
			if (plants[i]->die() == 1)
			{
				plant->updatePos(plants[i]->pos_x, plants[i]->pos_y, 0);
				plant->changeAmount(4, -1);
				delete plants[i];
				plants.erase(plants.begin() + i);
				i--;
			}
			continue;
		}
		//树
		if (plants[i]->type == 1)
		{
			plants[i]->m_age++;
			if (plants[i]->m_age > 30)
			{
				plants[i]->type = 2;
				plant->updatePos(plants[i]->pos_x, plants[i]->pos_y, 2);
				plant->changeAmount(1, -1);
				plant->changeAmount(2, 1);
			}
			continue;
		}
		if (plants[i]->type == 2)
		{
			plants[i]->m_age++;
			if (plants[i]->die() == 1)
			{
				plant->updatePos(plants[i]->pos_x, plants[i]->pos_y, 0);
				plant->changeTreeRegion(plants[i]->pos_x, plants[i]->pos_y, -1);
				plant->changeAmount(2, -1);
				delete plants[i];
				plants.erase(plants.begin() + i);
				i--;
			}
			continue;
		}
	}
}

void CManage::updateAnimalVector()//更新动物容器
{
	int i = 0;
	int death = 0;
	int feeds = 0;

	for (i = 0; i < animals.size(); i++)
	{
		//羊
		if (animals[i]->type == 1 || animals[i]->type == 2)
		{
			if (animals[i]->feed(animal) == 1)//如果没饱且有草
			{
				int pos = plant->getPos(animals[i]->pos_x, animals[i]->pos_y);
				if (pos == 3 || pos == 4)
					executeFeed(i);
			}
			if (animals[i]->physicalStrength < 60)
				animals[i]->energy -= 2;
			else
			{
				if (animals[i]->physicalStrength >= 90 && animals[i]->energy < 6)
					animals[i]->energy++;
			}
			animals[i]->physicalStrength -= 10;
			if (animals[i]->physicalStrength < 0)
				animals[i]->physicalStrength = 0;
			animals[i]->m_age++;
			death = animals[i]->die();
			if (death > 0)
			{
				if (death == 1)
					events->changeStarve(1);
				else
					events->changeNaturalDeath(1);
				animal->updatePos(animals[i]->pos_x, animals[i]->pos_y, 0);
				animal->changeAmount(animals[i]->type, -1);
				delete animals[i];
				animals.erase(animals.begin() + i);
				i--;
				continue;
			}
			if (animals[i]->m_age == 7)
			{
				animals[i]->type = 2;
				animals[i]->energy += 2;
				animal->updatePos(animals[i]->pos_x, animals[i]->pos_y, 2);
				animal->changeAmount(1, -1);
				animal->changeAmount(2, 1);
			}
			if (animals[i]->fertilityIndex > 0)
				animals[i]->fertilityIndex--;
			animals[i]->drinkIndex = -1;
			animals[i]->ifBack = 0;
			animals[i]->hideIndex = -1;
			if (animals[i]->pos_x <= 16 || animals[i]->pos_y >= 29)//若不在家,则返回
			{
				animal->updatePos(animals[i]->pos_x, animals[i]->pos_y, 0);
				animals[i]->createPos(animal);
			}
			continue;
		}
		//鹿
		if (animals[i]->type == 3 || animals[i]->type == 4)
		{
			if (animals[i]->feed(animal) == 1)//如果没饱且有草
			{
				int pos = plant->getPos(animals[i]->pos_x, animals[i]->pos_y);
				if (pos == 3 || pos == 4)
					executeFeed(i);
			}
			if (animals[i]->physicalStrength < 60)
				animals[i]->energy -= 2;
			else
			{
				if (animals[i]->physicalStrength >= 90 && animals[i]->energy < 6)
					animals[i]->energy++;
			}
			animals[i]->physicalStrength -= 10;
			if (animals[i]->physicalStrength < 0)
				animals[i]->physicalStrength = 0;
			animals[i]->m_age++;
			death = animals[i]->die();
			if (death > 0)
			{
				if (death == 1)
					events->changeStarve(2);
				else
					events->changeNaturalDeath(2);
				animal->updatePos(animals[i]->pos_x, animals[i]->pos_y, 0);
				animal->changeAmount(animals[i]->type, -1);
				delete animals[i];
				animals.erase(animals.begin() + i);
				i--;
				continue;
			}
			if (animals[i]->m_age == 7)
			{
				animals[i]->type = 4;
				animals[i]->energy += 2;
				animal->updatePos(animals[i]->pos_x, animals[i]->pos_y, 4);
				animal->changeAmount(3, -1);
				animal->changeAmount(4, 1);
			}
			if (animals[i]->fertilityIndex > 0)
				animals[i]->fertilityIndex--;
			animals[i]->drinkIndex = -1;
			animals[i]->ifBack = 0;
			animals[i]->hideIndex = -1;
			if (animals[i]->pos_x >= 9 || animals[i]->pos_y <= 50)//若不在家,则返回
			{
				animal->updatePos(animals[i]->pos_x, animals[i]->pos_y, 0);
				animals[i]->createPos(animal);
			}
			continue;
		}
		//狼
		if (animals[i]->type == 5 || animals[i]->type == 6)
		{
			feeds = animals[i]->feed(animal);
			if (feeds >= 0)//若附近有猎物
			{
				if (feeds == 1)
				{
					events->changeFeed(2);
					if (executeFeed(i) < i)
						i--;
				}
			}
			if (animals[i]->physicalStrength < 60)
				animals[i]->energy -= 2;
			else
			{
				if (animals[i]->physicalStrength >= 90 && animals[i]->energy < 8)
					animals[i]->energy++;
			}
			animals[i]->physicalStrength -= 10;
			if (animals[i]->physicalStrength < 0)
				animals[i]->physicalStrength = 0;
			animals[i]->m_age++;
			death = animals[i]->die();
			if (death > 0)
			{
				if (death == 1)
					events->changeStarve(3);
				else
					events->changeNaturalDeath(3);
				animal->updatePos(animals[i]->pos_x, animals[i]->pos_y, 0);
				animal->changeAmount(animals[i]->type, -1);
				delete animals[i];
				animals.erase(animals.begin() + i);
				i--;
				continue;
			}
			if (animals[i]->m_age == 9)
			{
				animals[i]->type = 6;
				animals[i]->energy += 3;
				animal->updatePos(animals[i]->pos_x, animals[i]->pos_y, 6);
				animal->changeAmount(5, -1);
				animal->changeAmount(6, 1);
			}
			if (animals[i]->fertilityIndex > 0)
				animals[i]->fertilityIndex--;
			animals[i]->drinkIndex = -1;
			animals[i]->ifBack = 0;
			animals[i]->feedIndex = -1;
			animals[i]->feedGoal = -1;
			animals[i]->goal_x = -1;
			animals[i]->goal_y = -1;
			if (animals[i]->pos_x > 7 || animals[i]->pos_y > 21)//若不在家,则返回
			{
				animal->updatePos(animals[i]->pos_x, animals[i]->pos_y, 0);
				animals[i]->createPos(animal);
			}
			continue;
		}
		//虎
		if (animals[i]->type == 7 || animals[i]->type == 8)
		{
			feeds = animals[i]->feed(animal);
			if (feeds >= 0)//若附近有猎物
			{
				if (feeds == 1)
				{
					events->changeFeed(4);
					if (executeFeed(i) < i)
						i--;
				}
			}
			if (animals[i]->physicalStrength < 60)
				animals[i]->energy -= 2;
			else
			{
				if (animals[i]->physicalStrength >= 90 && animals[i]->energy < 14)
					animals[i]->energy++;
			}
			animals[i]->physicalStrength -= 10;
			if (animals[i]->physicalStrength < 0)
				animals[i]->physicalStrength = 0;
			animals[i]->m_age++;
			death = animals[i]->die();
			if (death > 0)
			{
				if (death == 1)
					events->changeStarve(4);
				else
					events->changeNaturalDeath(4);
				animal->updatePos(animals[i]->pos_x, animals[i]->pos_y, 0);
				animal->changeAmount(animals[i]->type, -1);
				delete animals[i];
				animals.erase(animals.begin() + i);
				i--;
				continue;
			}
			if (animals[i]->m_age == 10)
			{
				animals[i]->type = 8;
				animals[i]->energy += 4;
				animal->updatePos(animals[i]->pos_x, animals[i]->pos_y, 8);
				animal->changeAmount(7, -1);
				animal->changeAmount(8, 1);
			}
			if (animals[i]->fertilityIndex > 0)
				animals[i]->fertilityIndex--;
			animals[i]->drinkIndex = -1;
			animals[i]->ifBack = 0;
			animals[i]->feedIndex = -1;
			animals[i]->feedGoal = -1;
			animals[i]->goal_x = -1;
			animals[i]->goal_y = -1;
			if (animals[i]->pos_x < 18 || animals[i]->pos_y < 58)//若不在家,则返回
			{
				animal->updatePos(animals[i]->pos_x, animals[i]->pos_y, 0);
				animals[i]->createPos(animal);
			}
			continue;
		}
	}
}

void CManage::executePlantBreed()//执行植物繁殖
{
	//树
	int key = rand() % 100;
	if (key == 66 && plant->breed(1) == 1)
		addVector(1);
	//草
	int sum = 0;
	if (climate->weather == "晴")
		sum = 200 + rand() % 51;
	else
	{
		if (climate->weather == "阴")
			sum = 200 + rand() % 81;
		else
			sum = 200 + rand() % 101;
	}
	while (sum--)
	{
		if (plant->breed(2) == 1)
			addVector(2);
		else
			break;
	}
}

void CManage::executeAnimalBreed()//执行动物繁殖
{
	int i = 0, j = 0, k = 0, sum = 0, other = 0, key = 0, mark = 0;//sum幼崽数目 other生育对象性别 key动物种类 mark幼崽种类
	int judge[9] = {0};//判断动物是否可生育:0可生育 1不可生育
	int n = animals.size();
	for (i = 0; i < n - 1; i++)
	{
		if (judge[2] == 1 && judge[4] == 1 && judge[6] == 1 && judge[8] == 1)
			break;
		if (judge[animals[i]->type] == 1)
			continue;
		if (animals[i]->fertilityIndex == 0)
		{
			key = animals[i]->type;
			if (animals[i]->sex = 0)
				other = 1;
			else
				other = 0;
			for (j = i + 1; j < n; j++)
			{
				if (animals[j]->sex == other && animals[j]->fertilityIndex == 0 && animals[j]->type == key)
				{
					if (key == 2)
					{
						sum = rand() % 3 + 1;
						mark = 3;
						//重置羊的抑育指数
						animals[i]->fertilityIndex = 3;
						animals[j]->fertilityIndex = 3;
					}
					else
					{
						if (key == 4)
						{
							sum = rand() % 3 + 1;
							mark = 4;
							//重置鹿的抑育指数
							animals[i]->fertilityIndex = 3;
							animals[j]->fertilityIndex = 3;
						}
						else
						{
							if (key == 6)
							{
								sum = 1;
								mark = 5;
								//重置狼的抑育指数
								animals[i]->fertilityIndex = 16;
								animals[j]->fertilityIndex = 16;
							}
							else
							{
								sum = 1;
								mark = 6;
								//重置虎的抑育指数
								animals[i]->fertilityIndex = 16;
								animals[j]->fertilityIndex = 16;
							}
						}
					}
					for (k = 0; k < sum; k++)
					{
						if (animal->breed(mark - 2) == 1)
						{
							addVector(mark);
							events->changeBreed(mark - 2);
						}
					}
					break;
				}
			}
			if (j == n)
				judge[key] = 1;
		}
	}
}

void CManage::occurEvents()//发生灾难事件
{
	int key = events->createDisaster();
	if (key == 0)//无灾难发生
		return;

	int percent = 0;//死亡百分比（乘以100）
	int i = 0;
	if (key == 1)//发生疾病
	{
		percent = 30 + rand() % 20;
		for (i = 0; i <  animals.size(); i++)
		{
			if (rand() % 100 <= percent)
			{
				animal->changeAmount(animals[i]->type, -1);
				if (animals[i]->type == 1 || animals[i]->type == 2)
					events->changeDisasterDeath(3);
				else
				{
					if (animals[i]->type == 3 || animals[i]->type == 4)
						events->changeDisasterDeath(4);
					else
					{
						if (animals[i]->type == 5 || animals[i]->type == 6)
							events->changeDisasterDeath(5);
						else
							events->changeDisasterDeath(6);
					}
				}
				animal->updatePos(animals[i]->pos_x, animals[i]->pos_y, 0);
				delete animals[i];
				animals.erase(animals.begin() + i);
				i--;
			}
		}
	}
	else//其他灾难
	{
		if (key == 2 || key == 3)//发生水灾或者火灾
			percent = 50 + rand() % 20;
		else//发生旱灾或者寒灾
			percent = 40 + rand() % 20;
		for (i = 0; i < animals.size(); i++)
		{
			if (rand() % 100 <= percent)
			{
				animal->changeAmount(animals[i]->type, -1);
				if (animals[i]->type == 1 || animals[i]->type == 2)
					events->changeDisasterDeath(3);
				else
				{
					if (animals[i]->type == 3 || animals[i]->type == 4)
						events->changeDisasterDeath(4);
					else
					{
						if (animals[i]->type == 5 || animals[i]->type == 6)
							events->changeDisasterDeath(5);
						else
							events->changeDisasterDeath(6);
					}
				}
				animal->updatePos(animals[i]->pos_x, animals[i]->pos_y, 0);
				delete animals[i];
				animals.erase(animals.begin() + i);
				i--;
			}
		}

		for (i = 0; i < plants.size(); i++)
		{
			if (rand() % 100 <= percent)
			{
				plant->changeAmount(plants[i]->type, -1);
				if (plants[i]->type == 1 || plants[i]->type == 2)
					events->changeDisasterDeath(1);
				else
					events->changeDisasterDeath(2);
				plant->updatePos(plants[i]->pos_x, plants[i]->pos_y, 0);
				delete plants[i];
				plants.erase(plants.begin() + i);
				i--;
			}
		}
	}
}

void CManage::drawForest()//绘制森林
{
	int i = 0, j = 0;
	for (i = 0; i < 41; i++)
		cout << "＿";
	cout << endl;
	for (i = 0; i < 13; i++)
	{
		cout << '|';
		for (j = 0; j < 80; j++)
			animal->printPos(i, j);
		cout << '|';
		if (i == 0)
			cout << "      ≈ 溪  流";
		if (i == 2)
			cout << "      H  幼  羊    S  成年羊";
		if (i == 3)
			cout << "      R  幼  鹿    D  成年鹿";
		if (i == 4)
			cout << "      F  幼  狼    W  成年狼";
		if (i == 5)
			cout << "      G  幼  虎    T  成年虎";
		if (i == 7)
			cout << "  第" << setw(3) << date << "天:";
		if (i == 8)
			cout << "      天  气: " << climate->weather << "   季  节: " << climate->season;
		if (i == 10)
			cout << "  植物共" << setw(4) << plant->getInfo(7) << "棵";
		if (i == 11)
			cout << "      树共" << setw(4) << plant->getInfo(3) << "棵 " << "  小  树" << setw(4) << plant->getInfo(1) << "棵 ";
		if (i == 12)
			cout << "                   大  树" << setw(4) << plant->getInfo(2) << "棵";
		cout << endl;
	}
	for (i = 0; i < 2; i++)
	{
		cout << '|';
		for (j = 0; j < 40; j++)
			cout << "≈";
		cout << '|';
		if (i == 0)
			cout << "      草共" << setw(4) << plant->getInfo(6) << "棵 " << "  嫩  草" << setw(4) << plant->getInfo(4) << "棵 ";
		if (i == 1)
			cout << "                   小  草" << setw(4) << plant->getInfo(5) << "棵";
		cout << endl;
	}
	for (i = 13; i < 26; i++)
	{
		cout << '|';
		for (j = 0; j < 80; j++)
			animal->printPos(i, j);
		cout << '|';
		if (i == 14)
			cout << "  动物共" << setw(4) << animal->getInfo(13) << "只";
		if (i == 15)
			cout << "      羊共" << setw(4) << animal->getInfo(3) << "只 " << "  幼  羊" << setw(4) << animal->getInfo(1) << "只 ";
		if (i == 16)
			cout << "                   成年羊" << setw(4) << animal->getInfo(2) << "只";
		if (i == 17)
			cout << "      鹿共" << setw(4) << animal->getInfo(6) << "只 " << "  幼  鹿" << setw(4) << animal->getInfo(4) << "只 ";
		if (i == 18)
			cout << "                   成年鹿" << setw(4) << animal->getInfo(5) << "只";
		if (i == 19)
			cout << "      狼共" << setw(4) << animal->getInfo(9) << "只 " << "  幼  狼" << setw(4) << animal->getInfo(7) << "只 ";
		if (i == 20)
			cout << "                   成年狼" << setw(4) << animal->getInfo(8) << "只";
		if (i == 21)
			cout << "      虎共" << setw(4) << animal->getInfo(12) << "只 " << "  幼  虎" << setw(4) << animal->getInfo(10) << "只 ";
		if (i == 22)
			cout << "                   成年虎" << setw(4) << animal->getInfo(11) << "只";
		cout << endl;
	}
	for (i = 0; i < 41; i++)
		cout << "￣";
	cout << endl;
}

void CManage::save()//保存容器信息至文件
{
	plant->fTree.open("treeInfo.txt");
	plant->fTree << "树共" << setw(4) << plant->getInfo(3) << "棵:" << endl;
	plant->fTree << "           小树" << setw(3) << plant->getInfo(1) << "棵      大树" << setw(3) << plant->getInfo(2) << "棵" << endl;
	plant->fTree << endl;
	plant->fTree << "信息如下:" << endl;
	plant->fTree << endl;

	plant->fGrass.open("grassInfo.txt");
	plant->fGrass << "草共" << setw(4) << plant->getInfo(6) << "棵:" << endl;
	plant->fGrass << "           嫩草" << setw(4) << plant->getInfo(4) << "棵       小草" << setw(4) << plant->getInfo(5) << "棵" << endl;
	plant->fGrass << endl;
	plant->fGrass << "信息如下:" << endl;
	plant->fGrass << endl;

	animal->fSheep.open("sheepInfo.txt");
	animal->fSheep << "羊共" << setw(3) << animal->getInfo(3) << "只:" << endl;
	animal->fSheep << "          幼羊" << setw(3) << animal->getInfo(1) << "只     成年羊" << setw(3) << animal->getInfo(2) << "只" << endl;
	animal->fSheep << endl;
	animal->fSheep << "信息如下:" << endl;
	animal->fSheep << endl;

	animal->fDeer.open("deerInfo.txt");
	animal->fDeer << "鹿共" << setw(3) << animal->getInfo(6) << "只:" << endl;
	animal->fDeer << "          幼鹿" << setw(3) << animal->getInfo(4) << "只     成年鹿" << setw(3) << animal->getInfo(4) << "只" << endl;
	animal->fDeer << endl;
	animal->fDeer << "信息如下:" << endl;
	animal->fDeer << endl;

	animal->fWolf.open("wolfInfo.txt");
	animal->fWolf << "狼共" << setw(3) << animal->getInfo(9) << "只:" << endl;
	animal->fWolf << "          幼狼" << setw(3) << animal->getInfo(7) << "只     成年狼" << setw(3) << animal->getInfo(8) << "只" << endl;
	animal->fWolf << endl;
	animal->fWolf << "信息如下:" << endl;
	animal->fWolf << endl;

	animal->fTiger.open("tigerInfo.txt");
	animal->fTiger << "虎共" << setw(3) << animal->getInfo(12) << "只:" << endl;
	animal->fTiger << "          幼虎" << setw(3) << animal->getInfo(10) << "只     成年虎" << setw(3) << animal->getInfo(11) << "只" << endl;
	animal->fTiger << endl;
	animal->fTiger << "信息如下:" << endl;
	animal->fTiger << endl;

	int i = 0;
	for (i = 0; i < plants.size(); i++)
		plants[i]->saveData(plant);

	for (i = 0; i < animals.size(); i++)
		animals[i]->saveData(animal);

	plant->fTree.close();
	plant->fGrass.close();
	animal->fSheep.close();
	animal->fWolf.close();
}

void CManage::end()//结束(释放空间)
{
	for (vector<CAnimal *>::iterator s = animals.begin(), end = animals.end(); s != end; ++s)
		delete *s;
	for (vector<CPlant *>::iterator s = plants.begin(), end = plants.end(); s != end; ++s)
		delete *s;
	delete animal;
	delete plant;
	delete events;
	delete climate;
}

CManage::~CManage()
{
}
