#pragma once
#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<vector>
#include<iomanip>//可控制输出格式
#include<fstream>
#include"Climate.h"
#include"Events.h"
#include"Animal.h"
#include"Plant.h"
#include"Grass.h"
#include"Tree.h"
#include"Sheep.h"
#include"Deer.h"
#include"Wolf.h"
#include"Tiger.h"
using namespace std;

class CManage
{
public:
	CManage();

	int date = 0;//日期

	CPlant *plant = new CPlant;
	CAnimal *animal = new CAnimal;
	CEvents *events = new CEvents;
	CClimate *climate = new CClimate;
	vector<CPlant *> plants;//存放植物
	vector<CAnimal *> animals;//存放动物

	int start();//生态系统开始运行

	void travelAnimals(int time);//遍历动物容器:time为一天中的运行次数

	void lockGoal(int i);//锁定目标

	void noticeOthers(int type);//发现敌人，通知其他同伴

	int executeFeed(int i);//执行动物捕食

	int cleanVector(int key, int j);//查找并清除某个vector中的某个元素(key区分类别):1植物 2动物

	void addVector(int key);//扩充容器:1树 2草 3羊 4鹿 5狼 6虎

	void updatePlantVector();//更新植物容器

	void updateAnimalVector();//更新动物容器

	void executePlantBreed();//执行植物繁殖

	void executeAnimalBreed();//执行动物繁殖

	void occurEvents();//发生灾难事件

	void drawForest();//绘制森林

	void save();//保存容器信息至文件

	void end();//结束(释放空间)

	~CManage();
};

