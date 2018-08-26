#pragma once
#include "Animal.h"
class CTiger :
	public CAnimal
{
public:
	CTiger(int key, CAnimal *animal);//key控制生成类型

	virtual void freeMove(CAnimal *animal);//自由移动:0向上 1斜右上 2向右 3斜右下 4向下 5斜左下 6向左 7斜左上

	virtual void toDrinking(CAnimal *animal);//去饮水

	virtual void backHome(CAnimal *animal);//返家

	virtual int searchPrey(CAnimal *animal);//寻找猎物

	virtual void catchPrey(CAnimal *animal);//追赶猎物

	virtual int feed(CAnimal *animal);//捕食

	virtual void saveData(CAnimal *animal);//保存虎信息至文件

	~CTiger();
};

