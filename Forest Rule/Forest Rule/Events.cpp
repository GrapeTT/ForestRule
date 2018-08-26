#include "Events.h"



CEvents::CEvents()
{
}

int CEvents::createDisaster()//��������
{
	int key = rand() % 10;

	if (key == 1)//����
	{
		disease++;
		return 1;
	}
	if (key == 3)//ˮ��
	{
		flood++;
		return 2;
	}
	if (key == 5)//����
	{
		fire++;
		return 3;
	}
	if (key == 7)//����
	{
		drought++;
		return 4;
	}
	if (key == 9)//����
	{
		cold++;
		return 5;
	}
	return 0;//�����Ѳ���
}

void CEvents::resetInfo()//������Ϣ
{
	if (wolfFeed != 0)
		wolfFeed = 0;
	if (wolfFeedSuccess != 0)
		wolfFeedSuccess = 0;
	if (tigerFeed != 0)
		tigerFeed = 0;
	if (tigerFeedSuccess != 0)
		tigerFeedSuccess = 0;
	if (sheepStarve != 0)
		sheepStarve = 0;
	if (deerStarve != 0)
		deerStarve = 0;
	if (wolfStarve != 0)
		wolfStarve = 0;
	if (tigerStarve != 0)
		tigerStarve = 0;
	if (sheepNaturalDeath != 0)
		sheepNaturalDeath = 0;
	if (deerNaturalDeath != 0)
		deerNaturalDeath = 0;
	if (wolfNaturalDeath != 0)
		wolfNaturalDeath = 0;
	if (tigerNaturalDeath != 0)
		tigerNaturalDeath = 0;
	if (sheepBreed != 0)
		sheepBreed = 0;
	if (deerBreed != 0)
		deerBreed = 0;
	if (wolfBreed != 0)
		wolfBreed = 0;
	if (tigerBreed != 0)
		tigerBreed = 0;
	if (disease != 0)
		disease = 0;
	if (flood != 0)
		flood = 0;
	if (fire != 0)
		fire = 0;
	if (drought != 0)
		drought = 0;
	if (cold != 0)
		cold = 0;
	if (grassDisasterDeath != 0)
		grassDisasterDeath = 0;
	if (treeDisasterDeath != 0)
		treeDisasterDeath = 0;
	if (sheepDisasterDeath != 0)
		sheepDisasterDeath = 0;
	if (deerDisasterDeath != 0)
		deerDisasterDeath = 0;
	if (wolfDisasterDeath != 0)
		wolfDisasterDeath = 0;
	if (tigerDisasterDeath != 0)
		tigerDisasterDeath = 0;
}

void CEvents::changeFeed(int key)//�ı䲶ʳ����:1��2�� 3��4��
{
	if (key == 1)
	{
		wolfFeed++;
		return;
	}
	if (key == 2)
	{
		wolfFeedSuccess++;
		return;
	}
	if (key == 3)
	{
		tigerFeed++;
		return;
	}
	if (key == 4)
		tigerFeedSuccess++;
}

void CEvents::changeStarve(int key)//�ı��������:1�� 2¹ 3�� 4��
{
	if (key == 1)
	{
		sheepStarve++;
		return;
	}
	if (key == 2)
	{
		deerStarve++;
		return;
	}
	if (key == 3)
	{
		wolfStarve++;
		return;
	}
	if (key == 4)
		tigerStarve++;
}

void CEvents::changeNaturalDeath(int key)//�ı�������Ȼ��������:1�� 2¹ 3�� 4��
{
	if (key == 1)
	{
		sheepNaturalDeath++;
		return;
	}
	if (key == 2)
	{
		deerNaturalDeath++;
		return;
	}
	if (key == 3)
	{
		wolfNaturalDeath++;
		return;
	}
	if (key == 4)
		tigerNaturalDeath++;
}

void CEvents::changeBreed(int key)//�ı���������:1�� 2¹ 3�� 4��
{
	if (key == 1)
	{
		sheepBreed++;
		return;
	}
	if (key == 2)
	{
		deerBreed++;
		return;
	}
	if (key == 3)
	{
		wolfBreed++;
		return;
	}
	if (key == 4)
		tigerBreed++;
}

void CEvents::changeDisasterDeath(int key)//�ı��������ֺ���������:1�� 2�� 3�� 4¹ 5�� 6��
{
	if (key == 1)
	{
		grassDisasterDeath++;
		return;
	}
	if (key == 2)
	{
		treeDisasterDeath++;
		return;
	}
	if (key == 3)
	{
		sheepDisasterDeath++;
		return;
	}
	if (key == 4)
	{
		deerDisasterDeath++;
		return;
	}
	if (key == 5)
	{
		wolfDisasterDeath++;
		return;
	}
	if (key == 6)
		tigerDisasterDeath++;
}

void CEvents::print()//����¼���Ϣ
{
	cout << "  �ǹ���ʳ    " << setw(2) << wolfFeed << "��        " << "�ɹ�        " << setw(2) << wolfFeedSuccess << "��" << endl;
	cout << "  ������ʳ    " << setw(2) << tigerFeed << "��        " << "�ɹ�        " << setw(2) << tigerFeedSuccess << "��" << endl;
	cout << "  �򹲶���    " << setw(2) << sheepStarve << "ֻ        " << "¹������    " << setw(2) << deerStarve << "ֻ" << endl;
	cout << "  �ǹ�����    " << setw(2) << wolfStarve << "ֻ        " << "��������    " << setw(2) << tigerStarve << "ֻ" << endl;
	cout << "  ����Ȼ����" << setw(2) << sheepNaturalDeath << "ֻ        " << "¹����Ȼ����" << setw(2) << deerNaturalDeath << "ֻ" << endl;
	cout << "  �ǹ���Ȼ����" << setw(2) << wolfNaturalDeath << "ֻ        " << "������Ȼ����" << setw(2) << tigerNaturalDeath << "ֻ" << endl;
	cout << "  ������    " << setw(2) << sheepBreed << "ֻ        " << "¹������    " << setw(2) << deerBreed << "ֻ" << endl;
	cout << "  �ǹ�����    " << setw(2) << wolfBreed << "ֻ        " << "��������    " << setw(2) << tigerBreed << "ֻ" << endl;
	string s;
	if (disease > 0)
		s = "����";
	else
	{
		if (flood > 0)
			s = "ˮ��";
		else
		{
			if (fire > 0)
				s = "����";
			else
			{
				if (drought > 0)
					s = "����";
				else
				{
					if (cold > 0)
						s = "����";
					else
					{
						resetInfo();
						return;
					}
				}
			}
		}
	}
	cout << "����һ��" << s << ",��ɭ����������˺�:" << endl;
	cout << "  �ݹ�����    " << setw(2) << grassDisasterDeath << "��        " << "��������    " << setw(2) << treeDisasterDeath << "��" << endl;
	cout << "  ������    " << setw(2) << sheepDisasterDeath << "ֻ        " << "¹������    " << setw(2) << deerDisasterDeath << "ֻ" << endl;
	cout << "  �ǹ�����    " << setw(2) << wolfDisasterDeath << "ֻ        " << "��������    " << setw(2) << tigerDisasterDeath << "ֻ" << endl;
	resetInfo();
}

CEvents::~CEvents()
{
}
