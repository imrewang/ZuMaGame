#ifndef BALL_H
#define BALL_H

#include"Path.h"

class Ball // 定义小球类
{
public:
	Point center; // 圆心坐标
	float radius; // 半径
	int colorId;  // 小球的颜色序号，具体颜色在colors数组中取
	int indexInPath; // 小球位置在Path的allPoints中的对应序号
	int direction; // 小球移动方向，1向终点，-1向起点，0暂停

	void draw(); // 画出小球

	void movetoIndexInPath(Path path);// 让小球移动到 Path的allPoints中的indexInPath序号位置

	void initiate(Path path); // 初始化小球到path最开始的位置上

	// 让小球沿着轨迹Path移动,注意不要越界
	// direction为0暂时不动,direction为1向着终点移动，direction为-1向着起点移动
	void changeIndexbyDirection(Path path);
};

#endif // !BALL_H

