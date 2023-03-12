#include"Process.h"
#include <conio.h>
#pragma comment(lib,"Winmm.lib")


int main() // 主函数
{
	startup();  // 初始化	
	while (1)  // 循环
	{
		show(); // 显示
		updateWithoutInput();  // 和输入无关的更新
		updateWithInput();  // 和输入相关的更新
	}
	gameover(); // 游戏结束时的处理
	return 0;
}

