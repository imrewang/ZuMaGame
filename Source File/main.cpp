#include"Process.h"
#include <conio.h>
#pragma comment(lib,"Winmm.lib")


int main() // ������
{
	startup();  // ��ʼ��	
	while (1)  // ѭ��
	{
		show(); // ��ʾ
		updateWithoutInput();  // �������޹صĸ���
		updateWithInput();  // ��������صĸ���
	}
	gameover(); // ��Ϸ����ʱ�Ĵ���
	return 0;
}

