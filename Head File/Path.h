#ifndef PATH_H
#define PATH_H


#include"Point.h"
#include"func.h"
#include <vector>

using namespace std;

class Path  // ����켣��
{
public:
	vector<Point> keyPoints; //  ��¼�켣�ϵ�һЩ�ؼ��㣬�ؼ���֮����ֱ������
	float sampleInterval; // �����������ɵĹ켣�ߣ����о��Ȳ����ļ��
	vector<Point> allPoints; //  �����Բ�������õ��Ĳ�����

	void getAllPoints(); // �Բ���������в������õ����еĲ�����

	void draw(); // �����켣

	~Path();  // ��������
};

#endif // !PATH_H
