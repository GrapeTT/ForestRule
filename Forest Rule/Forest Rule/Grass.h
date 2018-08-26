#pragma once
#include"Plant.h"
class CGrass :
	public CPlant
{
public:
	CGrass(int key, CPlant *plant);//key控制生成类型

	virtual void saveData(CPlant *plant);//保存草信息至文件

	~CGrass();
};

