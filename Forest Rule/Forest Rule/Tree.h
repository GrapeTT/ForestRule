#pragma once
#include "Plant.h"
class CTree :
	public CPlant
{
public:
	CTree(int key, CPlant *plant);//key控制生成类型

	virtual void saveData(CPlant *plant);//保存树信息至文件

	~CTree();
};

