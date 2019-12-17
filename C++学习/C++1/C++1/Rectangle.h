#pragma once
/*#ifndef _RECTANGLE_H
#define _RECTANGLE_H
#include "Point.h"
class Rectangle : public Point { //�����ඨ�岿��
public: //�������к�����Ա
	void initRectangle(int x, int y, int w, int h) {
		initPoint(x, y); //���û��๫�г�Ա����
		this-> w = w;
		this-> h = h;
	}
	int getH() const { return h; }
	int getW() const { return w; }
private: //����˽�����ݳ�Ա
	int w, h;
};
#endif //_RECTANGLE_H*/
#ifndef _RECTANGLE_H
#define _RECTANGLE_H
#include "Point.h"
class Rectangle : private Point { //�����ඨ�岿��
public: //�������к�����Ա
	void initRectangle(int x, int y, int w, int h) {
		initPoint(x, y); //���û��๫�г�Ա����
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
private: //����˽�����ݳ�Ա
	int w, h;
};
#endif //_RECTANGLE_H