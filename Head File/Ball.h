#ifndef BALL_H
#define BALL_H

#include"Path.h"

class Ball // ����С����
{
public:
	Point center; // Բ������
	float radius; // �뾶
	int colorId;  // С�����ɫ��ţ�������ɫ��colors������ȡ
	int indexInPath; // С��λ����Path��allPoints�еĶ�Ӧ���
	int direction; // С���ƶ�����1���յ㣬-1����㣬0��ͣ

	void draw(); // ����С��

	void movetoIndexInPath(Path path);// ��С���ƶ��� Path��allPoints�е�indexInPath���λ��

	void initiate(Path path); // ��ʼ��С��path�ʼ��λ����

	// ��С�����Ź켣Path�ƶ�,ע�ⲻҪԽ��
	// directionΪ0��ʱ����,directionΪ1�����յ��ƶ���directionΪ-1��������ƶ�
	void changeIndexbyDirection(Path path);
};

#endif // !BALL_H

