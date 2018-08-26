#include "Events.h"



CEvents::CEvents()
{
}

int CEvents::createDisaster()//产生灾难
{
	int key = rand() % 10;

	if (key == 1)//疾病
	{
		disease++;
		return 1;
	}
	if (key == 3)//水灾
	{
		flood++;
		return 2;
	}
	if (key == 5)//火灾
	{
		fire++;
		return 3;
	}
	if (key == 7)//旱灾
	{
		drought++;
		return 4;
	}
	if (key == 9)//寒灾
	{
		cold++;
		return 5;
	}
	return 0;//无灾难产生
}

void CEvents::resetInfo()//重置信息
{
	if (wolfFeed != 0)
		wolfFeed = 0;
	if (wolfFeedSuccess != 0)
		wolfFeedSuccess = 0;
	if (tigerFeed != 0)
		tigerFeed = 0;
	if (tigerFeedSuccess != 0)
		tigerFeedSuccess = 0;
	if (sheepStarve != 0)
		sheepStarve = 0;
	if (deerStarve != 0)
		deerStarve = 0;
	if (wolfStarve != 0)
		wolfStarve = 0;
	if (tigerStarve != 0)
		tigerStarve = 0;
	if (sheepNaturalDeath != 0)
		sheepNaturalDeath = 0;
	if (deerNaturalDeath != 0)
		deerNaturalDeath = 0;
	if (wolfNaturalDeath != 0)
		wolfNaturalDeath = 0;
	if (tigerNaturalDeath != 0)
		tigerNaturalDeath = 0;
	if (sheepBreed != 0)
		sheepBreed = 0;
	if (deerBreed != 0)
		deerBreed = 0;
	if (wolfBreed != 0)
		wolfBreed = 0;
	if (tigerBreed != 0)
		tigerBreed = 0;
	if (disease != 0)
		disease = 0;
	if (flood != 0)
		flood = 0;
	if (fire != 0)
		fire = 0;
	if (drought != 0)
		drought = 0;
	if (cold != 0)
		cold = 0;
	if (grassDisasterDeath != 0)
		grassDisasterDeath = 0;
	if (treeDisasterDeath != 0)
		treeDisasterDeath = 0;
	if (sheepDisasterDeath != 0)
		sheepDisasterDeath = 0;
	if (deerDisasterDeath != 0)
		deerDisasterDeath = 0;
	if (wolfDisasterDeath != 0)
		wolfDisasterDeath = 0;
	if (tigerDisasterDeath != 0)
		tigerDisasterDeath = 0;
}

void CEvents::changeFeed(int key)//改变捕食次数:1、2狼 3、4虎
{
	if (key == 1)
	{
		wolfFeed++;
		return;
	}
	if (key == 2)
	{
		wolfFeedSuccess++;
		return;
	}
	if (key == 3)
	{
		tigerFeed++;
		return;
	}
	if (key == 4)
		tigerFeedSuccess++;
}

void CEvents::changeStarve(int key)//改变饿死数量:1羊 2鹿 3狼 4虎
{
	if (key == 1)
	{
		sheepStarve++;
		return;
	}
	if (key == 2)
	{
		deerStarve++;
		return;
	}
	if (key == 3)
	{
		wolfStarve++;
		return;
	}
	if (key == 4)
		tigerStarve++;
}

void CEvents::changeNaturalDeath(int key)//改变狼羊自然死亡数量:1羊 2鹿 3狼 4虎
{
	if (key == 1)
	{
		sheepNaturalDeath++;
		return;
	}
	if (key == 2)
	{
		deerNaturalDeath++;
		return;
	}
	if (key == 3)
	{
		wolfNaturalDeath++;
		return;
	}
	if (key == 4)
		tigerNaturalDeath++;
}

void CEvents::changeBreed(int key)//改变生育数量:1羊 2鹿 3狼 4虎
{
	if (key == 1)
	{
		sheepBreed++;
		return;
	}
	if (key == 2)
	{
		deerBreed++;
		return;
	}
	if (key == 3)
	{
		wolfBreed++;
		return;
	}
	if (key == 4)
		tigerBreed++;
}

void CEvents::changeDisasterDeath(int key)//改变生物受灾害死亡数量:1草 2树 3羊 4鹿 5狼 6虎
{
	if (key == 1)
	{
		grassDisasterDeath++;
		return;
	}
	if (key == 2)
	{
		treeDisasterDeath++;
		return;
	}
	if (key == 3)
	{
		sheepDisasterDeath++;
		return;
	}
	if (key == 4)
	{
		deerDisasterDeath++;
		return;
	}
	if (key == 5)
	{
		wolfDisasterDeath++;
		return;
	}
	if (key == 6)
		tigerDisasterDeath++;
}

void CEvents::print()//输出事件信息
{
	cout << "  狼共捕食    " << setw(2) << wolfFeed << "次        " << "成功        " << setw(2) << wolfFeedSuccess << "次" << endl;
	cout << "  虎共捕食    " << setw(2) << tigerFeed << "次        " << "成功        " << setw(2) << tigerFeedSuccess << "次" << endl;
	cout << "  羊共饿死    " << setw(2) << sheepStarve << "只        " << "鹿共饿死    " << setw(2) << deerStarve << "只" << endl;
	cout << "  狼共饿死    " << setw(2) << wolfStarve << "只        " << "虎共饿死    " << setw(2) << tigerStarve << "只" << endl;
	cout << "  羊共自然死亡" << setw(2) << sheepNaturalDeath << "只        " << "鹿共自然死亡" << setw(2) << deerNaturalDeath << "只" << endl;
	cout << "  狼共自然死亡" << setw(2) << wolfNaturalDeath << "只        " << "虎共自然死亡" << setw(2) << tigerNaturalDeath << "只" << endl;
	cout << "  羊共生育    " << setw(2) << sheepBreed << "只        " << "鹿共生育    " << setw(2) << deerBreed << "只" << endl;
	cout << "  狼共生育    " << setw(2) << wolfBreed << "只        " << "虎共生育    " << setw(2) << tigerBreed << "只" << endl;
	string s;
	if (disease > 0)
		s = "疾病";
	else
	{
		if (flood > 0)
			s = "水灾";
		else
		{
			if (fire > 0)
				s = "火灾";
			else
			{
				if (drought > 0)
					s = "旱灾";
				else
				{
					if (cold > 0)
						s = "寒灾";
					else
					{
						resetInfo();
						return;
					}
				}
			}
		}
	}
	cout << "发生一次" << s << ",给森林造成如下伤害:" << endl;
	cout << "  草共死亡    " << setw(2) << grassDisasterDeath << "棵        " << "树共死亡    " << setw(2) << treeDisasterDeath << "棵" << endl;
	cout << "  羊共死亡    " << setw(2) << sheepDisasterDeath << "只        " << "鹿共死亡    " << setw(2) << deerDisasterDeath << "只" << endl;
	cout << "  狼共死亡    " << setw(2) << wolfDisasterDeath << "只        " << "虎共死亡    " << setw(2) << tigerDisasterDeath << "只" << endl;
	resetInfo();
}

CEvents::~CEvents()
{
}
