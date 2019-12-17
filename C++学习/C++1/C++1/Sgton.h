#pragma once
#ifndef _Sgton_H_
#define _Sgton_H_
#define MODE 0
#include<iostream>
using namespace std;
class Sgton
{
private:
	Sgton()
	{
		x = 0;
		cout << "RUN CUNSTRUCTOR" << endl;
	}//构造函数，疑问：未定义形参，是否能够给x赋值？
	Sgton(const Sgton& formalTarget) :x(formalTarget.x)
	{
		cout << "RUN COPY CONSTRUCTOR" << endl;
	}
	int x;
#if MODE == 1
	friend Sgton s1();//理解为方程的返回值类型是一个类，此处建立的是指针方程，指针函数
										 //友元可以为成员，一般是函数，也可以是对象
										 //直接把唯一指定对象定义为友元
										 //这里还是要理解为函数，返回值为Sgton类的函数
#else
	friend Sgton* s1();
#endif
public:
	void print() const { cout << "x=" << x << endl; }
	void setX(int formalParameter_x) { x = formalParameter_x; }
};
#endif