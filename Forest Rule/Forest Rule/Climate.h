#pragma once
#include<iostream>
#include<string>
#include<iomanip>
#include<Windows.h>
using namespace std;
class CClimate
{
public:
	CClimate();

	int seasonKey = 0;//��ʾ����:0�� 1�� 2�� 3��
	string season;//����:�� �� �� ��
	string weather;//����:�� �� ��

	void controlSeason();//���Ƽ���

	void controlWeather();//��������

	~CClimate();
};

