#pragma once
#include "Animal.h"
class CDeer :
	public CAnimal
{
public:
	CDeer(int key, CAnimal *animal);//key控制生成类型

	virtual void freeMove(CAnimal *animal);//自由移动:0向上 1斜右上 2向右 3斜右下 4向下 5斜左下 6向左 7斜左上

	virtual void toDrinking(CAnimal *animal);//去饮水

	virtual void backHome(CAnimal *animal);//返家

	virtual int searchEnemy(CAnimal *animal);//搜索敌人

	virtual void hideEnemy(CAnimal *animal);//躲避敌人

	virtual int feed(CAnimal *animal);//捕食

	virtual void saveData(CAnimal *animal);//保存鹿信息至文件

	~CDeer();
};

