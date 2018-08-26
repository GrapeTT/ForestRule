#pragma once
#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<vector>
#include<iomanip>//�ɿ��������ʽ
#include<fstream>
#include"Climate.h"
#include"Events.h"
#include"Animal.h"
#include"Plant.h"
#include"Grass.h"
#include"Tree.h"
#include"Sheep.h"
#include"Deer.h"
#include"Wolf.h"
#include"Tiger.h"
using namespace std;

class CManage
{
public:
	CManage();

	int date = 0;//����

	CPlant *plant = new CPlant;
	CAnimal *animal = new CAnimal;
	CEvents *events = new CEvents;
	CClimate *climate = new CClimate;
	vector<CPlant *> plants;//���ֲ��
	vector<CAnimal *> animals;//��Ŷ���

	int start();//��̬ϵͳ��ʼ����

	void travelAnimals(int time);//������������:timeΪһ���е����д���

	void lockGoal(int i);//����Ŀ��

	void noticeOthers(int type);//���ֵ��ˣ�֪ͨ����ͬ��

	int executeFeed(int i);//ִ�ж��ﲶʳ

	int cleanVector(int key, int j);//���Ҳ����ĳ��vector�е�ĳ��Ԫ��(key�������):1ֲ�� 2����

	void addVector(int key);//��������:1�� 2�� 3�� 4¹ 5�� 6��

	void updatePlantVector();//����ֲ������

	void updateAnimalVector();//���¶�������

	void executePlantBreed();//ִ��ֲ�ﷱֳ

	void executeAnimalBreed();//ִ�ж��ﷱֳ

	void occurEvents();//���������¼�

	void drawForest();//����ɭ��

	void save();//����������Ϣ���ļ�

	void end();//����(�ͷſռ�)

	~CManage();
};

