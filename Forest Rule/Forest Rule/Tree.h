#pragma once
#include "Plant.h"
class CTree :
	public CPlant
{
public:
	CTree(int key, CPlant *plant);//key������������

	virtual void saveData(CPlant *plant);//��������Ϣ���ļ�

	~CTree();
};

