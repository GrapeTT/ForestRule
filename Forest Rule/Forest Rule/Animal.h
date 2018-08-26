#pragma once
#include "Biology.h"
#include <iostream>
using namespace std;
class CPlant;

class CAnimal :
	public CBiology
{
public:
	CAnimal();

	ofstream fSheep;
	ofstream fDeer;
	ofstream fWolf;
	ofstream fTiger;

	int type = 0;//1幼羊 2成年羊 3幼鹿 4成年鹿 5幼狼 6成年狼 7幼虎 8成年虎
	int sex = 1;//性别:0雌 1雄
	int fertilityIndex = 4;//抑育指数
	int physicalStrength = 60;//体力(0-100):60以下每天能量减少 90以上可无需捕食
	int ifBack = 0;//0不回 1回家
	int feedGoal = -1;//捕食目标(存储vector下标)
	int goal_x = -1;//目标X坐标
	int goal_y = -1;//目标Y坐标
	int feedIndex = -1;//捕食指数:-1未捕食 0在捕食 1捕食过
	int hideIndex = -1;//逃跑指数:-1未发现敌人 0逃跑中
	int drinkIndex = -1;//饮水指数:-1不想饮水 0要饮水 1饮过水

	void createAnimal();//生成动物(设置数量)

	virtual int operateNumber(int key);//操作(改变并获得)种群编号:1羊 2鹿 3狼 4虎

	void createPos(CAnimal *animal);//生成位置

	void updatePos(int &i, int &j, int key);//更新位置信息

	int getPos(int &i, int &j)const;//获得当前位置的信息

	int breed(int key);//繁殖规则:1羊 2鹿 3狼 4虎

	int die();//死亡规则

	virtual void freeMove(CAnimal *animal);//自由移动:0向上 1斜右上 2向右 3斜右下 4向下 5斜左下 6向左 7斜左上

	virtual void toDrinking(CAnimal *animal);//去饮水

	virtual void backHome(CAnimal *animal);//返家
	
	virtual int feed(CAnimal *animal);//捕食规则

	virtual int searchPrey(CAnimal *animal);//寻找猎物

	virtual void catchPrey(CAnimal *animal);//追赶猎物

	virtual int searchEnemy(CAnimal *animal);//搜索敌人
	
	virtual void hideEnemy(CAnimal *animal);//躲避敌人
	
	void changeAmount(int key, int value);//改变动物数量信息(key控制):1幼羊 2成年羊 3幼鹿 4成年鹿 5幼狼 6成年狼 7幼虎 8成年虎
	
	int getInfo(int key)const;//获得动物数量信息:1幼羊 2成年羊 3所有羊 4幼鹿 5成年鹿 6所有鹿 7幼狼 8成年狼 9所有狼 10幼虎 11成年虎 12所有虎 13所有动物
	
	void printPos(int &i, int &j)const;//输出动物
	
	virtual void saveData(CAnimal *animal);//保存动物信息至文件
	
	~CAnimal();
private:
	int sheepNumber = -1;//羊群编号
	int deerNumber = -1;//鹿群编号
	int wolfNumber = -1;//狼群编号
	int tigerNumber = -1;//虎群编号

	int m_allSheep = 0;//羊的总数
	int m_youngSheep = 0;//幼羊数量
	int m_adultSheep = 0;//成年羊数量

	int m_allDeer = 0;//鹿的总数
	int m_youngDeer = 0;//幼鹿数量
	int m_adultDeer = 0;//成年鹿数量

	int m_allWolf = 0;//狼的总数
	int m_youngWolf = 0;//幼狼数量
	int m_adultWolf = 0;//成年狼数量

	int m_allTiger = 0;//虎的总数
	int m_youngTiger = 0;//幼虎数量
	int m_adultTiger = 0;//成年虎数量

	int m_allAnimal = 0;//动物总数
	int m_pos[26][80] = { 0 };//标记动物位置:0无 1幼羊 2成年羊 3幼鹿 4成年鹿 5幼狼 6成年狼 7幼虎 8成年虎
};

