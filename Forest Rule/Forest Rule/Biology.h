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

	int m_age = 0;//����
	int number = 0;//���
	int energy = 0;//����ֵ
	int pos_x = 0;//������
	int pos_y = 0;//������

	virtual int operateNumber(int key);//�������

	~CBiology();
};

