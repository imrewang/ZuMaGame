#include <graphics.h>  
#include <conio.h>
#include <vector>
using namespace std;
#define  WIDTH 1000 // 窗口宽度
#define  HEIGHT 700 // 窗口高度
#define  Radius 25//  小球半径

class Point // 定义顶点类
{
public:
	float x, y; // 记录(x,y)坐标
	Point() // 无参数的构造函数
	{
	}
	Point(float ix, float iy) // 有参数的构造函数
	{
		x = ix;
		y = iy;
	}
};

class Path  // 定义轨迹类
{
public:
	vector<Point> keyPoints; //  记录轨迹上的一些关键点，关键点之间以直线相连
	float sampleInterval; // 对特征点连成的轨迹线，进行均匀采样的间隔
	vector<Point> allPoints; //  所有以采样间隔得到的采样点

	void getAllPoints() // 以采样间隔进行采样，得到所有的采样点
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
};

class Ball // 定义小球类
{
public:
	Point center; // 圆心坐标
	float radius; // 半径
	int indexInPath; // 小球位置在Path的allPoints中的对应序号
	int direction; // 小球移动方向，1向前，-1向后，0暂停
	COLORREF color; // 小球颜色
	void draw() // 画出小球
	{
		setlinecolor(color);
		setfillcolor(color);
		fillcircle(center.x, center.y, radius);
	}

	void movetoIndexInPath(Path path)
	{
		// 让小球移动到 Path的allPoints中的indexInPath序号位置
		center = path.allPoints[indexInPath];
	}

	// 让小球沿着轨迹Path移动,注意不要越界
	// direction为0暂时不动,direction为1向着终点移动，direction为-1向着起点移动
	void changeIndexbyDirection(Path path)
	{
		if (direction == 1 && indexInPath + 1 < path.allPoints.size())
			indexInPath++;
		else if (direction == -1 && indexInPath - 1 >= 0)
			indexInPath--;
	}

	void initiate(Path path) // 初始化小球到path最开始的位置上
	{
		radius = Radius; //  半径
		indexInPath = 0; // 初始化序号
		direction = 0;
		movetoIndexInPath(path); // 移动到Path上面的对应序号采样点位置		
	}
};

// 以下定义一些全局变量
Path path; // 定义轨迹对象
Ball ball1, ball2;  // 定义两个小球对象

void startup()  // 初始化函数
{
	initgraph(WIDTH, HEIGHT); // 新开一个画面
	setbkcolor(RGB(160, 211, 255)); // 设置背景颜色
	cleardevice(); // 清屏

	// 为轨迹类添加一些关键点
	path.keyPoints.push_back(Point(50, 300));
	path.keyPoints.push_back(Point(50, 600));
	path.keyPoints.push_back(Point(100, 650));
	path.keyPoints.push_back(Point(700, 650));
	path.keyPoints.push_back(Point(700, 550));
	path.keyPoints.push_back(Point(250, 550));
	path.keyPoints.push_back(Point(200, 500));
	path.keyPoints.push_back(Point(200, 200));
	path.keyPoints.push_back(Point(250, 150));
	path.keyPoints.push_back(Point(800, 150));
	path.keyPoints.push_back(Point(850, 200));
	path.keyPoints.push_back(Point(850, 650));
	path.keyPoints.push_back(Point(950, 650));
	path.keyPoints.push_back(Point(950, 100));
	path.keyPoints.push_back(Point(900, 50));
	path.keyPoints.push_back(Point(150, 50));

	path.sampleInterval = Radius / 5; // 设置轨迹线的采样间隔，需要被Radius整除，便于后面处理
	path.getAllPoints();    // 获得轨迹上的所有采样点

	ball1.initiate(path); // 初始化大球到path最开始的位置上
	ball1.direction = 1; // 大球向前移动
	ball1.color = RGB(200, 30, 190); // 设置大球1颜色
	ball1.radius = Radius + 3; // 设置大球1半径

	ball2.initiate(path); // 初始化小球到path最开始的位置上
	ball2.direction = 1; // 小球向前移动
	ball2.color = RGB(250, 170, 200); // 设置小球2颜色
	ball2.radius = Radius; // 设置小球2半径

	BeginBatchDraw(); // 开始批量绘制
}

void show()  // 绘制函数
{
	// 先画第一个大球，第一个大球到达终点后开始画第二个小球
	if (ball1.indexInPath < path.allPoints.size() - 1)
		ball1.draw();  // 画出小球1
	else
		ball2.draw();  // 画出小球2		
	FlushBatchDraw(); // 批量绘制
}

void update() // 更新
{
	// 先移动第一个大球，第一个大球到达终点后开始移动第二个小球
	if (ball1.indexInPath < path.allPoints.size() - 1)
	{
		ball1.movetoIndexInPath(path);
		ball1.changeIndexbyDirection(path);
	}
	else if (ball2.indexInPath < path.allPoints.size() - 2)
	{
		ball2.movetoIndexInPath(path);
		ball2.changeIndexbyDirection(path);
	}
	if (_kbhit()) // 当按键时
	{
		char input = _getch(); // 获得输入字符
		if (input == ' ') { // 当按下空格键时
			saveimage(_T("bk.jpg")); // 保存绘制的图像
		}
	}
}

int main() // 主函数
{
	startup();
	while (1)
	{
		show();
		update();
	}
	return 0;
}