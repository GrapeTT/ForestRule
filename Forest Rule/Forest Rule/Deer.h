#pragma once
#include "Animal.h"
class CDeer :
	public CAnimal
{
public:
	CDeer(int key, CAnimal *animal);//key������������

	virtual void freeMove(CAnimal *animal);//�����ƶ�:0���� 1б���� 2���� 3б���� 4���� 5б���� 6���� 7б����

	virtual void toDrinking(CAnimal *animal);//ȥ��ˮ

	virtual void backHome(CAnimal *animal);//����

	virtual int searchEnemy(CAnimal *animal);//��������

	virtual void hideEnemy(CAnimal *animal);//��ܵ���

	virtual int feed(CAnimal *animal);//��ʳ

	virtual void saveData(CAnimal *animal);//����¹��Ϣ���ļ�

	~CDeer();
};

