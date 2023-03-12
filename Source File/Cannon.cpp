#include"Cannon.h"

void Cannon::draw() // һЩ���ƺ���
{
	rotateimage(&im_rotate, &im, angle, RGB(160, 211, 255), false, false);//��ת��ɫͼƬ
	putimage(x - im.getwidth() / 2, y - im.getheight() / 2, &im_rotate); // ��ʾ��ת���ɫͼƬ
	ball.draw(); // ��������������С��
}

void Cannon::setBallPosition() // ������̨С�������
{
	ball.center.x = x + 100 * cos(angle);
	ball.center.y = y + 100 * sin(angle);
}

void Cannon::updateWithMouseMOVE(int mx, int my) // ���������ƶ�λ��������
{
	// �����̨�����ĽǶ�
	float xs = mx - x;
	float ys = my - y;
	float length = sqrt(xs * xs + ys * ys);
	if (length > 4) // ����������λ�ù�����������
	{
		angle = atan2(-ys, xs); // �����̨��ת�Ƕ�

		// Ҳ˳�������̨���������λ��
		ball.center.x = x + 100 * xs / length;//cos(angle);
		ball.center.y = y + 100 * ys / length;//sin(angle);
	}
}

void Cannon::updateWithRButtonDown() // ������Ҽ����ʱ���ı�С�����ɫ
{
	// ������̨Ҫ�����С�����ɫ
	ball.colorId += 1;
	if (ball.colorId == ColorNum) {
		ball.colorId = 0;
	}
}