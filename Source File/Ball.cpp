#include"Ball.h"

void Ball::draw() // 画出小球
{
	setlinecolor(colors[colorId]);
	setfillcolor(colors[colorId]);
	fillcircle(center.x, center.y, radius);
}

void Ball::movetoIndexInPath(Path path)
{
	// 让小球移动到 Path的allPoints中的indexInPath序号位置
	center = path.allPoints[indexInPath];
}

void Ball::initiate(Path path) // 初始化小球到path最开始的位置上
{
	radius = Radius; //  半径
	indexInPath = 0; // 初始化序号
	direction = 0; // 初始静止
	movetoIndexInPath(path); // 移动到Path上面的对应序号采样点位置		
	colorId = rand() % ColorNum; // 随机颜色序号
}

// 让小球沿着轨迹Path移动,注意不要越界
// direction为0暂时不动,direction为1向着终点移动，direction为-1向着起点移动
void Ball::changeIndexbyDirection(Path path)
{
	if (direction == 1 && indexInPath + 1 < path.allPoints.size()) {
		indexInPath++;
	}
	else if (direction == -1 && indexInPath - 1 >= 0) {
		indexInPath--;
	}
}