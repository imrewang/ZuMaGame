#include"Process.h"

// ��Balls�����iλ����Ѱ����ǰ����û�к�����ɫһ�����Ҷ����������������
// ����еĻ�����ɾ����,���صĽ����ɾ������С��ĸ���
// ���һ��û��ɾ�����ͷ���0
int eraseSameColorBalls(int i, Ball fireball, Path& path, vector <Ball>& balls)
{
	// ��¼��ǰ��Ͳ����С����ɫһ������ţ�����ȥ�ظ����õ���Ӧ��Ҫɾ�������
	//vector<int> sameColorIndexes;
	
	//sameColorIndexes.push_back(i); // ���Ȱ�i��ӵ�vector��
	int first = i;
	int end = i;

	// ��Path�յ㷽��Ѱ�ң�Ҳ�������ʼ���������Ѱ��
	for (int forward = i; forward >= 0 && balls[forward].colorId == fireball.colorId; forward--) {
		first = forward;
		if (forward == 0) {	
			break;
		}
		if (balls[forward - 1].indexInPath - balls[forward].indexInPath > 2 * Radius / path.sampleInterval) {
			break; // ǰ��һ�������������������ѭ��
		}
	}

	// ��Path��㷽��Ѱ�ң�Ҳ�������������ķ���Ѱ��
	for (int backward = i; backward <= balls.size() - 1 && balls[backward].colorId == fireball.colorId; backward++) {
		end = backward;
		if (backward == balls.size() - 1) {	
			break;
		}
		if (balls[backward].indexInPath - balls[backward + 1].indexInPath > 2 * Radius / path.sampleInterval) {
			break; // ǰ��һ�������������������ѭ��
		}
	}

	// ȥ��ͬ����ɫС�����ظ������
	/*sort(sameColorIndexes.begin(), sameColorIndexes.end());
	vector<int>::iterator ite = unique(sameColorIndexes.begin(), sameColorIndexes.end());
	sameColorIndexes.erase(ite, sameColorIndexes.end());*/

	//int NumSameColors = sameColorIndexes.size();
	int NumSameColors = end - first + 1;
	if (NumSameColors >= 3) // ��ͬ��ɫ����ﵽ3��������
	{
		//int minIndex = sameColorIndexes[0];
		//int maxIndex = sameColorIndexes[NumSameColors - 1];
		// ����Щ���ɾ��						
		balls.erase(balls.begin() + first, balls.begin() + end + 1);
		return NumSameColors; // �����ˣ���������С����Ŀ
	}
	return 0; // û������������0
}


// ���¶���һЩȫ�ֱ���
Path path; // ����켣����
vector <Ball> balls; // ��¼���С��
IMAGE im_role, im_house, im_bk; // һЩͼƬ
Cannon cannon;  // ������̨����
int gameStatus = 0;  // ��Ϸ״̬��-1ʧ�ܣ�0������1ʤ��


void startup()  // ��ʼ������
{
	mciSendString(_T("open game_music.mp3 alias bkmusic"), NULL, 0, NULL);//�򿪱�������
	mciSendString(_T("play bkmusic repeat"), NULL, 0, NULL);  // ѭ������

	srand(time(0)); // �����ʼ������
	initgraph(WIDTH, HEIGHT); // �¿�һ������
	cleardevice(); // ����

	loadimage(&im_bk, _T("bk1.jpg")); // ���뱳��ͼƬ
	loadimage(&im_role, _T("role.jpg")); // �����ɫͼƬ
	loadimage(&im_house, _T("house.jpg")); // �����ͼƬ


	//#define  WIDTH 1000 // ���ڿ��
	//#define  HEIGHT 700 // ���ڸ߶�
	// Ϊ�켣�����һЩ�ؼ���
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

	path.sampleInterval = Radius / 5; // ���ù켣�ߵĲ���������豻С��뾶Radius�����Ա㴦��
	//����ֱ����10������ÿ10���һ����ÿһ��Ųn����λ��10��Ų10n����λ
	//�����n���򣬳�10n����λ��ÿ�β�඼����
	path.getAllPoints();    // ��ù켣�ϵ����в�����

	// ��̨��һЩ��ʼ��
	cannon.im = im_role; // ��̨��ɫͼƬ
	cannon.angle = 0; // ��ʼ�Ƕ�
	cannon.x = 500;  // ��������
	cannon.y = 350;
	cannon.ball.radius = Radius; // ��̨����С��İ뾶
	cannon.ball.colorId = rand() % ColorNum; // ��̨С����ɫ
	cannon.setBallPosition(); // ������̨С�������

	// �����һЩС��
	for (int i = 0; i < 3; i++)
	{
		Ball ball;  // ����һ��С�����
		ball.initiate(path); // ��ʼ��С��path�ʼ��λ����	
		balls.push_back(ball); // ��С��ball��ӵ�balls��
	}

	BeginBatchDraw(); // ��ʼ��������
}

void show()  // ���ƺ���
{
	putimage(0, 0, &im_bk); // ��ʾ����ͼƬ
	putimage(30, 10, &im_house); // ��ʾ����ͼƬ
	//path.draw();  // �����켣
	cannon.draw(); // ������̨	
	for (int i = 0; i < balls.size(); i++) {
		balls[i].draw();  // ��������С��
	}

	// ����������ʾ����
	setbkmode(TRANSPARENT);
	settextcolor(RGB(255, 0, 0));
	settextstyle(60, 0, _T("����"));
	if (gameStatus == 1) {// �����Ϸʤ��
		outtextxy(WIDTH * 0.35, HEIGHT * 0.35, _T("��Ϸʤ�� :)"));
	}
	else if (gameStatus == -1) { // �����Ϸʧ��
		outtextxy(WIDTH * 0.35, HEIGHT * 0.35, _T("��Ϸʧ�� :("));
	}
	///////////////////////////////////////////////////////////////////////////////////
	TCHAR s[20];
	setbkmode(TRANSPARENT); // ��������͸��
	_stprintf_s(s, _T("%d��"), balls.size());
	settextcolor(WHITE); // �趨������ɫ
	settextstyle(40, 0, _T("����"));//  �趨���ִ�С����ʽ
	outtextxy(WIDTH * 0.02, 20, s); //  �����������
	////////////////////////////////////////////////////////

	FlushBatchDraw(); // ��������
}


void updateWithoutInput() // �������޹صĸ���
{
	
	static clock_t start = clock(); // ��¼��һ������ʱ��
	clock_t now = clock(); // ��õ�ǰʱ��
	// �������Ŀǰһ�������˶�����
	int nowSecond = (int(now - start) / CLOCKS_PER_SEC);
	// 100���ڣ�ʱ��ÿ��10���ӣ�����һ��С��
	if (nowSecond % 10 == 0 && nowSecond <= 100 && gameStatus == 0)
	{
		Ball ball;  // ����һ��С�����
		ball.initiate(path); // ��ʼ��С��path�ʼ��λ����
		balls.push_back(ball); // ��С��ball��ӵ�balls��
	}
	
	/*
	//�̶���������
	static int count = 0;
	static int lastSecond = 0; // ��¼ǰһ�γ��������˶�����
	static int nowSecond = 0; // ��¼��ǰ���������˶�����
	static clock_t start = clock(); // ��¼��һ������ʱ��
	clock_t now = clock(); // ��õ�ǰʱ��
	// �������Ŀǰһ�������˶�����
	nowSecond = (int(now - start) / CLOCKS_PER_SEC);
	if (nowSecond % 20 == 0&& nowSecond != lastSecond) {
		lastSecond = nowSecond; // ������lastSecond����
		count = 0;
	}
	if (count < 10 && nowSecond <= 100 && gameStatus == 0)
	{
		count++;
		Ball ball;  // ����һ��С�����
		ball.initiate(path); // ��ʼ��С��path�ʼ��λ����	
		balls.push_back(ball); // ��С��ball��ӵ�balls��
	}
	*/


	if (balls.size() == 0) // С���������
	{
		if (nowSecond > 100) { // ʱ�䵽�ˣ���Ϸʤ��
			gameStatus = 1; // ��Ϸʤ��
		}
		return; // û�е���ֹʱ�䣬С������ˣ��ȵ���ʱ�������µ�С��
	}
	// ��һ�����ܵ��յ��ˣ���Ϸʧ��
	if (balls[0].indexInPath >= path.allPoints.size() - 1)
	{
		gameStatus = -1; // ��Ϸʧ��
		return;
	}

	int i;
	for (i = 0; i < balls.size(); i++) {
		balls[i].direction = 0; // ��������С����ٶ���Ϊ0
	}

	//balls��ǰ�ƶ���Դ�������������һ��С�����һ��С��direction=1
	//����յ㷽��ǰ��һ��С������С���������У�����directionҲΪ1������directionΪ0
	i = balls.size() - 1; // ���һ��С��
	balls[i].direction = 1; // ���һ��С����ǰ�˶�

	while (i > 0)  // һֱ��ǰ�жϣ���û�б�������ǰ��һ��С��
	{
		// ���ǰ������С����������
		if (balls[i - 1].indexInPath - balls[i].indexInPath <= 2 * Radius / path.sampleInterval)
		{
			balls[i - 1].direction = 1; // ǰһ��С��ķ���Ҳ����ǰ
			// ��ǰһ��С���indexInPath���й��򻯣�ȷ����������
			balls[i - 1].indexInPath = balls[i].indexInPath + 2 * Radius / path.sampleInterval;

			int count = eraseSameColorBalls(i, balls[i], path, balls);

			if (count >= 3) {
				PlayMusicOnce(_T("coin.mp3"));  // ����һ�ν����Ч
				break;
			}

			i--;

		}
		else { // ��һ��С��ֱ�ӽӴ�����ֹͣ��ǰ�ٶȵĴ���
			break; // ����ѭ��
		}
	}


	for (int i = 0; i < balls.size(); i++)  // ÿһ��С�������direction��������λ��
	{
		balls[i].movetoIndexInPath(path);
		balls[i].changeIndexbyDirection(path);
	}

	sleep(40); // ��ͣ���ɺ���
}


void updateWithInput()  // ��������صĸ���
{
	if (gameStatus != 0) { // ��Ϸʤ����ʧ�ܣ�����Ҫ�û������룬����ֱ�ӷ���
		return;
	}

	int i, j;
	MOUSEMSG m;		// ���������Ϣ
	while (MouseHit())  // ��⵱ǰ�Ƿ��������Ϣ
	{
		m = GetMouseMsg();
		if (m.uMsg == WM_MOUSEMOVE)  // ����ƶ�ʱ			
		{
			cannon.updateWithMouseMOVE(m.x, m.y); // ��̨��ת��С��Ҳ�ƶ�����Ӧλ����
		}
		else if (m.uMsg == WM_RBUTTONDOWN)  // ����Ҽ����ʱ��������̨Ҫ�����С�����ɫ		
		{
			cannon.updateWithRButtonDown();
		}
		else if (m.uMsg == WM_LBUTTONDOWN)  // ���������ʱ			
		{
			cannon.updateWithMouseMOVE(m.x, m.y); //  �ȸ�������̨��ת�Ƕȡ���̨С�������
			float vx = (cannon.ball.center.x - cannon.x) / 5; // ��̨С���ƶ��ٶ�
			float vy = (cannon.ball.center.y - cannon.y) / 5;
			int isCollider = 0; // ����balls��û��С�����̨С����ײ
			// ���ŷ���ķ�����̨С�����ƶ����ж���balls��û��С�����̨С����ײ
			while (isCollider == 0 && cannon.ball.center.y > 0 && cannon.ball.center.y < HEIGHT
				&& cannon.ball.center.x>0 && cannon.ball.center.x < WIDTH) // ��̨С�򳬳��߽�Ͳ��ô�����
			{
				cannon.ball.center.x += vx; // ���·���С���λ��
				cannon.ball.center.y += vy;
				show(); // ��ʾ����̨С����˶��켣

				// balls������С�����̨С�������жϣ������Ƿ����ཻ��
				for (i = 0; i < balls.size(); i++)
				{
					float distance = Distance(balls[i].center.x, balls[i].center.y, cannon.ball.center.x, cannon.ball.center.y);
					if (distance < Radius) // �ҵ�����̨С����ײ��С��
					{
						isCollider = 1; // ��Ϊ�ҵ���ײС����						
						cannon.updateWithMouseMOVE(m.x, m.y); // ����̨С���λ���ƶ���ȥ

						// ���渴��һ��С�򣬲��뵽����ط�
						Ball fireball = balls[i];
						fireball.colorId = cannon.ball.colorId; // ������С������̨С�����ɫ
						balls.insert(balls.begin() + i, fireball); // ����һ��С�򣬲��뵽vector��//��С��λ��ԭС���ǰ��

						// ��Balls�����iλ����Ѱ����ǰ����û�к�����ɫһ�����Ҷ���3��������������
						// ����ǵĻ�����ɾ����,���صĽ����ɾ������С��ĸ���
						// ���һ��û��ɾ�����ͷ���0
						int count = eraseSameColorBalls(i, fireball, path, balls);
						
						if (count >= 3) {
							PlayMusicOnce(_T("coin.mp3"));  // ����һ�ν����Ч
						}
						if (count == 0)// ���û�������Ļ�
						{
							for (j = i; j >= 0; j--) // �ƶ�ǰ���С�������ռ�����²����С��//ǰ��ǰ������
							{
								if (balls[j].indexInPath - balls[j + 1].indexInPath <= 0) {
									balls[j].indexInPath = balls[j + 1].indexInPath + 2 * Radius / path.sampleInterval;
								}
								else {
									break; // ǰ��С����п�϶�������ٴ�����
								}
							}
						}
						return; // �ҵ�һ������̨��ײ��С���ˣ�����Ĳ���������
					}//����� if (distance < Radius)������ // �ҵ�����̨С����ײ��С��
				}  // �����for (i=0;i<balls.size();i++)������
			} // �����while�����ţ���̨С�����ƶ�����balls����������С������ж�
			cannon.updateWithMouseMOVE(m.x, m.y); // ��̨��ת��С��Ҳ�ƶ�����Ӧλ����
			//��ֹ�����߽磬�����ÿ�,��ֹ��겻�ƶ���С���ڱ߽�
		} // ���������ʱ	
	}
}

void gameover() // ��Ϸ����ʱ�Ĵ���
{
	balls.clear(); // ���vector���ڴ�ռ�
}

