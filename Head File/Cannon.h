#ifndef CANNON_H
#define CANNON_H

#include"BALL.h"

class Cannon // ��̨�࣬������ɫͼƬ������һ��С��
{
public:
	IMAGE im; // ��ɫͼƬ
	IMAGE im_rotate; // ��ɫ��ת���ͼƬ
	float x, y; // ��������
	Ball ball;  // һ����������������ת������ɫ��С��
	float angle; // ��ת�Ƕ�

	void draw();// һЩ���ƺ���

	void setBallPosition(); // ������̨С�������

	void updateWithMouseMOVE(int mx, int my);// ���������ƶ�λ��������

	void updateWithRButtonDown(); // ������Ҽ����ʱ���ı�С�����ɫ
};

#endif // !CANNON_H
