#pragma once
#include "Biology.h"
#include <iostream>
using namespace std;
class CAnimal;

class CPlant :
	public CBiology
{
public:
	CPlant();

	ofstream fTree;
	ofstream fGrass;

	int type = 0;//1小树 2大树 3嫩草 4小草 

	void createPlant();//生成植物

	void createPos(CPlant *plant);//生成位置

	virtual int operateNumber(int key);//操作(改变并获得)种群编号:1树 2草

	void updatePos(int &i, int &j, int key);//更新位置信息

	int getPos(int &i, int &j)const;//获得当前位置的信息

	int getTreeRegion(int i);//获得森林某个区树的数目

	void changeTreeRegion(int x, int y, int value);//改变森林每个区树的数目

	int breed(int key);//繁殖规则:1树 2草

	int die();//死亡规则

	void changeAmount(int key, int value);//改变植物数量信息(key控制):1小树 2大树 3嫩草 4小草

	int getInfo(int key)const;//获得植物数量信息:1小树 2大树 3所有树  4嫩草 5小草 6所有草 7所有植物

	virtual void saveData(CPlant *plant);//保存植物信息至文件

	~CPlant();
private:
	int treeNumber = -1;//草丛编号
	int grassNumber = -1;//树丛编号

	int m_allGrass = 0;//草的总棵数
	int m_youngGrass = 0;//嫩草棵数
	int m_adultGrass = 0;//小草棵数

	int m_allTree = 0;//树的总棵树
	int m_youngTree = 0;//小树棵数
	int m_adultTree = 0;//大树棵数

	int m_allPlant = 0;//植物总数
	int treeRegion[4] = { 0 };//表示森林均分为四个区后，每个区树的数目:0右上区 1右下区 2左下区 3左上区
	int m_pos[26][80] = { 0 };//标记植物位置:0无 1小树 2大树 3嫩草 4小草
};

