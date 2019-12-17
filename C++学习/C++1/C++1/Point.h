/*#ifndef POINT_H_
#define POINT_H_
class Point { //��Ķ���
public: //�ⲿ�ӿ�
	Point(int x = 0, int y = 0) : x(x), y(y) { }
	Point(const Point& p);
	~Point() { count--; }
	int getX() const { return x; }
	int getY() const { return y; }
	static void showCount(); //��̬������Ա
private: //˽�����ݳ�Ա
	int x, y;
	static int count; //��̬���ݳ�Ա
};
#endif // !POINT_H_

*/
#ifndef _POINT_H
#define _POINT_H
class Point { //����Point��Ķ���
public: //���к�����Ա
	void initPoint(int x = 0, int y = 0)
	{
		this-> x = x; this-> y = y;
	}
	void move(int offX, int offY)
	{
		x += offX; y += offY;
	}
	int getX() const { return x; }
	int getY() const { return y; }
private: //˽�����ݳ�Ա
	int x, y;
};
#endif //_POINT_H
