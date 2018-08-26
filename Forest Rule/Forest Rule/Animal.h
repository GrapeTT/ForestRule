#pragma once
#include "Biology.h"
#include <iostream>
using namespace std;
class CPlant;

class CAnimal :
	public CBiology
{
public:
	CAnimal();

	ofstream fSheep;
	ofstream fDeer;
	ofstream fWolf;
	ofstream fTiger;

	int type = 0;//1���� 2������ 3��¹ 4����¹ 5���� 6������ 7�׻� 8���껢
	int sex = 1;//�Ա�:0�� 1��
	int fertilityIndex = 4;//����ָ��
	int physicalStrength = 60;//����(0-100):60����ÿ���������� 90���Ͽ����貶ʳ
	int ifBack = 0;//0���� 1�ؼ�
	int feedGoal = -1;//��ʳĿ��(�洢vector�±�)
	int goal_x = -1;//Ŀ��X����
	int goal_y = -1;//Ŀ��Y����
	int feedIndex = -1;//��ʳָ��:-1δ��ʳ 0�ڲ�ʳ 1��ʳ��
	int hideIndex = -1;//����ָ��:-1δ���ֵ��� 0������
	int drinkIndex = -1;//��ˮָ��:-1������ˮ 0Ҫ��ˮ 1����ˮ

	void createAnimal();//���ɶ���(��������)

	virtual int operateNumber(int key);//����(�ı䲢���)��Ⱥ���:1�� 2¹ 3�� 4��

	void createPos(CAnimal *animal);//����λ��

	void updatePos(int &i, int &j, int key);//����λ����Ϣ

	int getPos(int &i, int &j)const;//��õ�ǰλ�õ���Ϣ

	int breed(int key);//��ֳ����:1�� 2¹ 3�� 4��

	int die();//��������

	virtual void freeMove(CAnimal *animal);//�����ƶ�:0���� 1б���� 2���� 3б���� 4���� 5б���� 6���� 7б����

	virtual void toDrinking(CAnimal *animal);//ȥ��ˮ

	virtual void backHome(CAnimal *animal);//����
	
	virtual int feed(CAnimal *animal);//��ʳ����

	virtual int searchPrey(CAnimal *animal);//Ѱ������

	virtual void catchPrey(CAnimal *animal);//׷������

	virtual int searchEnemy(CAnimal *animal);//��������
	
	virtual void hideEnemy(CAnimal *animal);//��ܵ���
	
	void changeAmount(int key, int value);//�ı䶯��������Ϣ(key����):1���� 2������ 3��¹ 4����¹ 5���� 6������ 7�׻� 8���껢
	
	int getInfo(int key)const;//��ö���������Ϣ:1���� 2������ 3������ 4��¹ 5����¹ 6����¹ 7���� 8������ 9������ 10�׻� 11���껢 12���л� 13���ж���
	
	void printPos(int &i, int &j)const;//�������
	
	virtual void saveData(CAnimal *animal);//���涯����Ϣ���ļ�
	
	~CAnimal();
private:
	int sheepNumber = -1;//��Ⱥ���
	int deerNumber = -1;//¹Ⱥ���
	int wolfNumber = -1;//��Ⱥ���
	int tigerNumber = -1;//��Ⱥ���

	int m_allSheep = 0;//�������
	int m_youngSheep = 0;//��������
	int m_adultSheep = 0;//����������

	int m_allDeer = 0;//¹������
	int m_youngDeer = 0;//��¹����
	int m_adultDeer = 0;//����¹����

	int m_allWolf = 0;//�ǵ�����
	int m_youngWolf = 0;//��������
	int m_adultWolf = 0;//����������

	int m_allTiger = 0;//��������
	int m_youngTiger = 0;//�׻�����
	int m_adultTiger = 0;//���껢����

	int m_allAnimal = 0;//��������
	int m_pos[26][80] = { 0 };//��Ƕ���λ��:0�� 1���� 2������ 3��¹ 4����¹ 5���� 6������ 7�׻� 8���껢
};

