#ifndef CANNON_H
#define CANNON_H

#include"BALL.h"

class Cannon // 炮台类，包括角色图片，还有一个小球
{
public:
	IMAGE im; // 角色图片
	IMAGE im_rotate; // 角色旋转后的图片
	float x, y; // 中心坐标
	Ball ball;  // 一个可以绕着中心旋转，变颜色的小球
	float angle; // 旋转角度

	void draw();// 一些绘制函数

	void setBallPosition(); // 生成炮台小球的坐标

	void updateWithMouseMOVE(int mx, int my);// 根据鼠标的移动位置来更新

	void updateWithRButtonDown(); // 当鼠标右键点击时，改变小球的颜色
};

#endif // !CANNON_H
