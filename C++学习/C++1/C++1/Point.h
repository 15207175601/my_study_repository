/*#ifndef POINT_H_
#define POINT_H_
class Point { //类的定义
public: //外部接口
	Point(int x = 0, int y = 0) : x(x), y(y) { }
	Point(const Point& p);
	~Point() { count--; }
	int getX() const { return x; }
	int getY() const { return y; }
	static void showCount(); //静态函数成员
private: //私有数据成员
	int x, y;
	static int count; //静态数据成员
};
#endif // !POINT_H_

*/
#ifndef _POINT_H
#define _POINT_H
class Point { //基类Point类的定义
public: //公有函数成员
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
private: //私有数据成员
	int x, y;
};
#endif //_POINT_H
