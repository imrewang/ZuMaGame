#include"Ball.h"

void Ball::draw() // ����С��
{
	setlinecolor(colors[colorId]);
	setfillcolor(colors[colorId]);
	fillcircle(center.x, center.y, radius);
}

void Ball::movetoIndexInPath(Path path)
{
	// ��С���ƶ��� Path��allPoints�е�indexInPath���λ��
	center = path.allPoints[indexInPath];
}

void Ball::initiate(Path path) // ��ʼ��С��path�ʼ��λ����
{
	radius = Radius; //  �뾶
	indexInPath = 0; // ��ʼ�����
	direction = 0; // ��ʼ��ֹ
	movetoIndexInPath(path); // �ƶ���Path����Ķ�Ӧ��Ų�����λ��		
	colorId = rand() % ColorNum; // �����ɫ���
}

// ��С�����Ź켣Path�ƶ�,ע�ⲻҪԽ��
// directionΪ0��ʱ����,directionΪ1�����յ��ƶ���directionΪ-1��������ƶ�
void Ball::changeIndexbyDirection(Path path)
{
	if (direction == 1 && indexInPath + 1 < path.allPoints.size()) {
		indexInPath++;
	}
	else if (direction == -1 && indexInPath - 1 >= 0) {
		indexInPath--;
	}
}