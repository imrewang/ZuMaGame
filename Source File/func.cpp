#include"func.h"

extern COLORREF  colors[ColorNum] = { RED,BLUE,GREEN,YELLOW,MAGENTA }; // �������鱣�����е���ɫ

// ������֮��ľ��뺯��
float Distance(float x1, float y1, float x2, float y2)
{
	float xd = x1 - x2;
	float yd = y1 - y2;
	float length = sqrt(xd * xd + yd * yd);
	return length;
}

void sleep(DWORD ms)  // ��ȷ��ʱ����
{
	static DWORD oldtime = GetTickCount();
	while (GetTickCount() - oldtime < ms)
		Sleep(1);
	oldtime = GetTickCount();
}

void PlayMusicOnce(const TCHAR fileName[80]) // ����һ�����ֺ���
{
	TCHAR cmdString1[50];
	_stprintf_s(cmdString1, _T("open %s alias tmpmusic"), fileName); // ���������ַ���
	mciSendString(_T("close tmpmusic"), NULL, 0, NULL); // �Ȱ�ǰ��һ�ε����ֹر�
	mciSendString(cmdString1, NULL, 0, NULL); // ������
	mciSendString(_T("play tmpmusic"), NULL, 0, NULL); // ������һ��
}
