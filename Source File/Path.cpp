#include "Path.h"

void Path::getAllPoints()// �Բ���������в������õ����еĲ�����
{
	int i;
	// �Թؼ������������γɵĶ����߶ν��б���
	for (i = 0; i < keyPoints.size() - 1; i++)
	{
		float xd = keyPoints[i + 1].x - keyPoints[i].x;
		float yd = keyPoints[i + 1].y - keyPoints[i].y;
		float length = sqrt(xd * xd + yd * yd); // ��һ��ֱ�߶εĳ���

		int num = length / sampleInterval; // ��һ��ֱ�߶�Ҫ�������ĸ���
		for (int j = 0; j < num; j++)
		{
			float x_sample = keyPoints[i].x + j * xd / num;
			float y_sample = keyPoints[i].y + j * yd / num;
			allPoints.push_back(Point(x_sample, y_sample)); // ��ӽ�ȥ���еĲ�����
		}
	}
	// �������һ���ؼ���
	allPoints.push_back(Point(keyPoints[i].x, keyPoints[i].y));
}

void Path::draw() // �����켣
{
	setlinecolor(RGB(0, 0, 100)); // ����������ɫ
	setfillcolor(RGB(16, 211, 255)); // ���������ɫ

	// �����ؼ������������γɵĶ����߶�
	for (int i = 0; i < keyPoints.size() - 1; i++) {
		line(keyPoints[i].x, keyPoints[i].y, keyPoints[i + 1].x, keyPoints[i + 1].y);
	}
	// ���в����㴦���ֱ�һ��СԲ��
	for (int i = 0; i < allPoints.size(); i++) {
		fillcircle(allPoints[i].x, allPoints[i].y, 2);
	}
}

Path::~Path()// ��������
{
	keyPoints.clear(); // ���vector���ڴ�ռ�
	allPoints.clear();
}
