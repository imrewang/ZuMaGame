#ifndef FUNC_H
#define FUNC_H

#include <algorithm>
#include <graphics.h> 

#define  WIDTH 1000 // ���ڿ��
#define  HEIGHT 700 // ���ڸ߶�
#define  Radius 25 //  С��뾶
#define  ColorNum 5 //  С����ɫ������Ŀ

extern COLORREF  colors[ColorNum]; // �������鱣�����е���ɫ

// ������֮��ľ��뺯��
float Distance(float x1, float y1, float x2, float y2);

void sleep(DWORD ms); // ��ȷ��ʱ����

void PlayMusicOnce(const TCHAR fileName[80]); // ����һ�����ֺ���

#endif // !FUNC_H
