#include "Climate.h"



CClimate::CClimate()
{
	srand(time(NULL));
	weather = "ÎŞ";
	season = "ÎŞ";
	seasonKey = rand() % 4 - 1;
	if (seasonKey == 0)
		season = "´º";
	else
	{
		if (seasonKey == 1)
			season = "ÏÄ";
		else
		{
			if (seasonKey == 2)
				season = "Çï";
			else
				season = "¶¬";
		}
	}
}

void CClimate::controlSeason()//¿ØÖÆ¼¾½Ú
{
	seasonKey++;
	if (seasonKey > 3)
		seasonKey = 0;
	if (seasonKey == 0)
		season = "´º";
	else
	{
		if (seasonKey == 1)
			season = "ÏÄ";
		else
		{
			if (seasonKey == 2)
				season = "Çï";
			else
				season = "¶¬";
		}
	}
}

void CClimate::controlWeather()//¿ØÖÆÌìÆø
{
	int a = 0, b = 0;
	if (season == "´º")
	{
		a = 2;
		b = 5;
	}
	else
	{
		if (season == "ÏÄ")
		{
			a = 4;
			b = 7;
		}
		else
		{
			if (season == "Çï")
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
		weather = "Çç";
	else
	{
		if (key > a && key <= b)
			weather = "Òõ";
		else
			weather = "Óê";
	}
}

CClimate::~CClimate()
{
}
