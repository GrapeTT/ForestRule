#pragma once
#include"Plant.h"
class CGrass :
	public CPlant
{
public:
	CGrass(int key, CPlant *plant);//key������������

	virtual void saveData(CPlant *plant);//�������Ϣ���ļ�

	~CGrass();
};

