#include "Climate.h"



CClimate::CClimate()
{
	srand(time(NULL));
	weather = "��";
	season = "��";
	seasonKey = rand() % 4 - 1;
	if (seasonKey == 0)
		season = "��";
	else
	{
		if (seasonKey == 1)
			season = "��";
		else
		{
			if (seasonKey == 2)
				season = "��";
			else
				season = "��";
		}
	}
}

void CClimate::controlSeason()//���Ƽ���
{
	seasonKey++;
	if (seasonKey > 3)
		seasonKey = 0;
	if (seasonKey == 0)
		season = "��";
	else
	{
		if (seasonKey == 1)
			season = "��";
		else
		{
			if (seasonKey == 2)
				season = "��";
			else
				season = "��";
		}
	}
}

void CClimate::controlWeather()//��������
{
	int a = 0, b = 0;
	if (season == "��")
	{
		a = 2;
		b = 5;
	}
	else
	{
		if (season == "��")
		{
			a = 4;
			b = 7;
		}
		else
		{
			if (season == "��")
			{
				a = 1;
				b = 4;
			}
			else
			{
				a = 2;
				b = 6;
			}
		}
	}

	int key = rand() % 10;
	if (key >= 0 && key <= a)
		weather = "��";
	else
	{
		if (key > a && key <= b)
			weather = "��";
		else
			weather = "��";
	}
}

CClimate::~CClimate()
{
}
