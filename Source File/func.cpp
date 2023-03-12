#include"func.h"

extern COLORREF  colors[ColorNum] = { RED,BLUE,GREEN,YELLOW,MAGENTA }; // 定义数组保存所有的颜色

// 求两点之间的距离函数
float Distance(float x1, float y1, float x2, float y2)
{
	float xd = x1 - x2;
	float yd = y1 - y2;
	float length = sqrt(xd * xd + yd * yd);
	return length;
}

void sleep(DWORD ms)  // 精确延时函数
{
	static DWORD oldtime = GetTickCount();
	while (GetTickCount() - oldtime < ms)
		Sleep(1);
	oldtime = GetTickCount();
}

void PlayMusicOnce(const TCHAR fileName[80]) // 播放一次音乐函数
{
	TCHAR cmdString1[50];
	_stprintf_s(cmdString1, _T("open %s alias tmpmusic"), fileName); // 生成命令字符串
	mciSendString(_T("close tmpmusic"), NULL, 0, NULL); // 先把前面一次的音乐关闭
	mciSendString(cmdString1, NULL, 0, NULL); // 打开音乐
	mciSendString(_T("play tmpmusic"), NULL, 0, NULL); // 仅播放一次
}
