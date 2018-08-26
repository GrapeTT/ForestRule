#pragma once
#include<iostream>
#include<Windows.h>
#include <iomanip>
#include<string>
using namespace std;

class CEvents
{
public:
	CEvents();

	int createDisaster();//产生灾难

	void resetInfo();//重置信息

	void changeFeed(int key);//改变捕食次数:1、2狼 3、4虎

	void changeStarve(int key);//改变饿死数量:1羊 2鹿 3狼 4虎

	void changeNaturalDeath(int key);//改变自然死亡数量:1羊 2鹿 3狼 4虎

	void changeBreed(int key);//改变狼羊生育数量:1羊 2鹿 3狼 4虎

	void changeDisasterDeath(int key);//改变生物受灾害死亡数量:1草 2树 3羊 4鹿 5狼 6虎

	void print();//输出事件信息

	~CEvents();

private:
	int wolfFeed = 0;//狼共捕食次数
	int wolfFeedSuccess = 0;//狼捕食成功次数
	int tigerFeed = 0;//虎共捕食次数
	int tigerFeedSuccess = 0;//虎捕食成功次数

	int sheepStarve = 0;//羊饿死数量
	int deerStarve = 0;//鹿饿死数量
	int wolfStarve = 0;//狼饿死数量
	int tigerStarve = 0;//虎饿死数量

	int sheepNaturalDeath = 0;//羊自然死亡数量
	int deerNaturalDeath = 0;//鹿自然死亡数量
	int wolfNaturalDeath = 0;//狼自然死亡数量
	int tigerNaturalDeath = 0;//虎自然死亡数量

	int sheepBreed = 0;//羊生育数量
	int deerBreed = 0;//鹿生育数量
	int wolfBreed = 0;//狼生育数量
	int tigerBreed = 0;//虎生育数量

	int disease = 0;//疾病次数
	int flood = 0;//水灾次数
	int fire = 0;//火灾次数
	int drought = 0;//旱灾次数
	int cold = 0;//寒灾次数

	int grassDisasterDeath = 0;//草受灾害死亡数量
	int treeDisasterDeath = 0;//树受灾害死亡数量
	int sheepDisasterDeath = 0;//羊受灾害死亡数量
	int deerDisasterDeath = 0;//鹿受灾害死亡数量
	int wolfDisasterDeath = 0;//狼受灾害死亡数量
	int tigerDisasterDeath = 0;//虎受灾害死亡数量
};

