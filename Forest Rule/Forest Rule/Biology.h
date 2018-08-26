#pragma once
#include <iostream>
#include <cmath>
#include <cstdlib> 
#include<iomanip>
#include<fstream>
using namespace std;

class CBiology
{
public:
	CBiology();

	int m_age = 0;//年龄
	int number = 0;//编号
	int energy = 0;//能量值
	int pos_x = 0;//横坐标
	int pos_y = 0;//纵坐标

	virtual int operateNumber(int key);//操作编号

	~CBiology();
};

