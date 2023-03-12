#ifndef PATH_H
#define PATH_H


#include"Point.h"
#include"func.h"
#include <vector>

using namespace std;

class Path  // 定义轨迹类
{
public:
	vector<Point> keyPoints; //  记录轨迹上的一些关键点，关键点之间以直线相连
	float sampleInterval; // 对特征点连成的轨迹线，进行均匀采样的间隔
	vector<Point> allPoints; //  所有以采样间隔得到的采样点

	void getAllPoints(); // 以采样间隔进行采样，得到所有的采样点

	void draw(); // 画出轨迹

	~Path();  // 析构函数
};

#endif // !PATH_H
