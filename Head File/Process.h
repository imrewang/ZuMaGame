#ifndef PROCESS_H
#define PROCESS_H

#include"Cannon.h"
#include <time.h>

// ��Balls�����iλ����Ѱ����ǰ����û�к�����ɫһ�����Ҷ����������������
// ����еĻ�����ɾ����,���صĽ����ɾ������С��ĸ���
// ���һ��û��ɾ�����ͷ���0
int eraseSameColorBalls(int i, Ball fireball, Path& path, vector <Ball>& balls);

// ���¶���һЩȫ�ֱ���
extern Path path; // ����켣����
extern vector <Ball> balls; // ��¼���С��
extern IMAGE im_role, im_house, im_bk; // һЩͼƬ
extern Cannon cannon;  // ������̨����
extern int gameStatus;  // ��Ϸ״̬��-1ʧ�ܣ�0������1ʤ��

void startup();  // ��ʼ������

void show();  // ���ƺ���

void updateWithoutInput(); // �������޹صĸ���

void updateWithInput();  // ��������صĸ���

void gameover();// ��Ϸ����ʱ�Ĵ���

#endif // !PROCESS_H
