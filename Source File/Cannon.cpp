#include"Cannon.h"

void Cannon::draw() // 一些绘制函数
{
	rotateimage(&im_rotate, &im, angle, RGB(160, 211, 255), false, false);//旋转角色图片
	putimage(x - im.getwidth() / 2, y - im.getheight() / 2, &im_rotate); // 显示旋转后角色图片
	ball.draw(); // 绘制这个待发射的小球
}

void Cannon::setBallPosition() // 生成炮台小球的坐标
{
	ball.center.x = x + 100 * cos(angle);
	ball.center.y = y + 100 * sin(angle);
}

void Cannon::updateWithMouseMOVE(int mx, int my) // 根据鼠标的移动位置来更新
{
	// 求出炮台到鼠标的角度
	float xs = mx - x;
	float ys = my - y;
	float length = sqrt(xs * xs + ys * ys);
	if (length > 4) // 鼠标距离中心位置过近，不处理
	{
		angle = atan2(-ys, xs); // 求出炮台旋转角度

		// 也顺便求出炮台附带的球的位置
		ball.center.x = x + 100 * xs / length;//cos(angle);
		ball.center.y = y + 100 * ys / length;//sin(angle);
	}
}

void Cannon::updateWithRButtonDown() // 当鼠标右键点击时，改变小球的颜色
{
	// 更改炮台要发射的小球的颜色
	ball.colorId += 1;
	if (ball.colorId == ColorNum) {
		ball.colorId = 0;
	}
}