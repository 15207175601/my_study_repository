#pragma once
/*#ifndef _RECTANGLE_H
#define _RECTANGLE_H
#include "Point.h"
class Rectangle : public Point { //派生类定义部分
public: //新增公有函数成员
	void initRectangle(int x, int y, int w, int h) {
		initPoint(x, y); //调用基类公有成员函数
		this-> w = w;
		this-> h = h;
	}
	int getH() const { return h; }
	int getW() const { return w; }
private: //新增私有数据成员
	int w, h;
};
#endif //_RECTANGLE_H*/
#ifndef _RECTANGLE_H
#define _RECTANGLE_H
#include "Point.h"
class Rectangle : private Point { //派生类定义部分
public: //新增公有函数成员
	void initRectangle(int x, int y, int w, int h) {
		initPoint(x, y); //调用基类公有成员函数
		this-> w = w;
		this-> h = h;
	}
	void move(int offX, int offY) {
		Point::move(offX, offY);
	}
	int getX() const { return Point::getX(); }
	int getY() const { return Point::getY(); }
	int getH() const { return h; }
	int getW() const { return w; }
private: //新增私有数据成员
	int w, h;
};
#endif //_RECTANGLE_H