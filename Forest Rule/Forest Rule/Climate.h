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

	int seasonKey = 0;//表示季节:0春 1夏 2秋 3冬
	string season;//季节:春 夏 秋 冬
	string weather;//天气:晴 阴 雨

	void controlSeason();//控制季节

	void controlWeather();//控制天气

	~CClimate();
};

