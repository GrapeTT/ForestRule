#pragma once
#include "Biology.h"
#include <iostream>
using namespace std;
class CAnimal;

class CPlant :
	public CBiology
{
public:
	CPlant();

	ofstream fTree;
	ofstream fGrass;

	int type = 0;//1С�� 2���� 3�۲� 4С�� 

	void createPlant();//����ֲ��

	void createPos(CPlant *plant);//����λ��

	virtual int operateNumber(int key);//����(�ı䲢���)��Ⱥ���:1�� 2��

	void updatePos(int &i, int &j, int key);//����λ����Ϣ

	int getPos(int &i, int &j)const;//��õ�ǰλ�õ���Ϣ

	int getTreeRegion(int i);//���ɭ��ĳ����������Ŀ

	void changeTreeRegion(int x, int y, int value);//�ı�ɭ��ÿ����������Ŀ

	int breed(int key);//��ֳ����:1�� 2��

	int die();//��������

	void changeAmount(int key, int value);//�ı�ֲ��������Ϣ(key����):1С�� 2���� 3�۲� 4С��

	int getInfo(int key)const;//���ֲ��������Ϣ:1С�� 2���� 3������  4�۲� 5С�� 6���в� 7����ֲ��

	virtual void saveData(CPlant *plant);//����ֲ����Ϣ���ļ�

	~CPlant();
private:
	int treeNumber = -1;//�ݴԱ��
	int grassNumber = -1;//���Ա��

	int m_allGrass = 0;//�ݵ��ܿ���
	int m_youngGrass = 0;//�۲ݿ���
	int m_adultGrass = 0;//С�ݿ���

	int m_allTree = 0;//�����ܿ���
	int m_youngTree = 0;//С������
	int m_adultTree = 0;//��������

	int m_allPlant = 0;//ֲ������
	int treeRegion[4] = { 0 };//��ʾɭ�־���Ϊ�ĸ�����ÿ����������Ŀ:0������ 1������ 2������ 3������
	int m_pos[26][80] = { 0 };//���ֲ��λ��:0�� 1С�� 2���� 3�۲� 4С��
};

