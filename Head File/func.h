#ifndef FUNC_H
#define FUNC_H

#include <algorithm>
#include <graphics.h> 

#define  WIDTH 1000 // 窗口宽度
#define  HEIGHT 700 // 窗口高度
#define  Radius 25 //  小球半径
#define  ColorNum 5 //  小球颜色种类数目

extern COLORREF  colors[ColorNum]; // 定义数组保存所有的颜色

// 求两点之间的距离函数
float Distance(float x1, float y1, float x2, float y2);

void sleep(DWORD ms); // 精确延时函数

void PlayMusicOnce(const TCHAR fileName[80]); // 播放一次音乐函数

#endif // !FUNC_H
