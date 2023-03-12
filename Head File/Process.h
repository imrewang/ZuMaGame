#ifndef PROCESS_H
#define PROCESS_H

#include"Cannon.h"
#include <time.h>

// 在Balls中序号i位置球，寻找其前后有没有和他颜色一样，且多余个连续靠近的球
// 如果有的话，就删除掉,返回的结果是删除掉的小球的个数
// 如果一个没有删除，就返回0
int eraseSameColorBalls(int i, Ball fireball, Path& path, vector <Ball>& balls);

// 以下定义一些全局变量
extern Path path; // 定义轨迹对象
extern vector <Ball> balls; // 记录多个小球
extern IMAGE im_role, im_house, im_bk; // 一些图片
extern Cannon cannon;  // 定义炮台对象
extern int gameStatus;  // 游戏状态，-1失败，0正常，1胜利

void startup();  // 初始化函数

void show();  // 绘制函数

void updateWithoutInput(); // 和输入无关的更新

void updateWithInput();  // 和输入相关的更新

void gameover();// 游戏结束时的处理

#endif // !PROCESS_H
