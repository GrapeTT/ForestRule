#pragma once
#include<iostream>
#include<Windows.h>
#include <iomanip>
#include<string>
using namespace std;

class CEvents
{
public:
	CEvents();

	int createDisaster();//��������

	void resetInfo();//������Ϣ

	void changeFeed(int key);//�ı䲶ʳ����:1��2�� 3��4��

	void changeStarve(int key);//�ı��������:1�� 2¹ 3�� 4��

	void changeNaturalDeath(int key);//�ı���Ȼ��������:1�� 2¹ 3�� 4��

	void changeBreed(int key);//�ı�������������:1�� 2¹ 3�� 4��

	void changeDisasterDeath(int key);//�ı��������ֺ���������:1�� 2�� 3�� 4¹ 5�� 6��

	void print();//����¼���Ϣ

	~CEvents();

private:
	int wolfFeed = 0;//�ǹ���ʳ����
	int wolfFeedSuccess = 0;//�ǲ�ʳ�ɹ�����
	int tigerFeed = 0;//������ʳ����
	int tigerFeedSuccess = 0;//����ʳ�ɹ�����

	int sheepStarve = 0;//���������
	int deerStarve = 0;//¹��������
	int wolfStarve = 0;//�Ƕ�������
	int tigerStarve = 0;//����������

	int sheepNaturalDeath = 0;//����Ȼ��������
	int deerNaturalDeath = 0;//¹��Ȼ��������
	int wolfNaturalDeath = 0;//����Ȼ��������
	int tigerNaturalDeath = 0;//����Ȼ��������

	int sheepBreed = 0;//����������
	int deerBreed = 0;//¹��������
	int wolfBreed = 0;//����������
	int tigerBreed = 0;//����������

	int disease = 0;//��������
	int flood = 0;//ˮ�ִ���
	int fire = 0;//���ִ���
	int drought = 0;//���ִ���
	int cold = 0;//���ִ���

	int grassDisasterDeath = 0;//�����ֺ���������
	int treeDisasterDeath = 0;//�����ֺ���������
	int sheepDisasterDeath = 0;//�����ֺ���������
	int deerDisasterDeath = 0;//¹���ֺ���������
	int wolfDisasterDeath = 0;//�����ֺ���������
	int tigerDisasterDeath = 0;//�����ֺ���������
};

