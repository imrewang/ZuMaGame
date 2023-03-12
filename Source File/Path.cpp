#include "Path.h"

void Path::getAllPoints()// 以采样间隔进行采样，得到所有的采样点
{
	int i;
	// 对关键点依次连接形成的多条线段进行遍历
	for (i = 0; i < keyPoints.size() - 1; i++)
	{
		float xd = keyPoints[i + 1].x - keyPoints[i].x;
		float yd = keyPoints[i + 1].y - keyPoints[i].y;
		float length = sqrt(xd * xd + yd * yd); // 这一段直线段的长度

		int num = length / sampleInterval; // 这一段直线段要被采样的个数
		for (int j = 0; j < num; j++)
		{
			float x_sample = keyPoints[i].x + j * xd / num;
			float y_sample = keyPoints[i].y + j * yd / num;
			allPoints.push_back(Point(x_sample, y_sample)); // 添加进去所有的采样点
		}
	}
	// 还有最后一个关键点
	allPoints.push_back(Point(keyPoints[i].x, keyPoints[i].y));
}

void Path::draw() // 画出轨迹
{
	setlinecolor(RGB(0, 0, 100)); // 设置线条颜色
	setfillcolor(RGB(16, 211, 255)); // 设置填充颜色

	// 画出关键点依次连接形成的多条线段
	for (int i = 0; i < keyPoints.size() - 1; i++) {
		line(keyPoints[i].x, keyPoints[i].y, keyPoints[i + 1].x, keyPoints[i + 1].y);
	}
	// 所有采样点处，分别画一个小圆点
	for (int i = 0; i < allPoints.size(); i++) {
		fillcircle(allPoints[i].x, allPoints[i].y, 2);
	}
}

Path::~Path()// 析构函数
{
	keyPoints.clear(); // 清除vector的内存空间
	allPoints.clear();
}
