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
	}//���캯�������ʣ�δ�����βΣ��Ƿ��ܹ���x��ֵ��
	Sgton(const Sgton& formalTarget) :x(formalTarget.x)
	{
		cout << "RUN COPY CONSTRUCTOR" << endl;
	}
	int x;
#if MODE == 1
	friend Sgton s1();//���Ϊ���̵ķ���ֵ������һ���࣬�˴���������ָ�뷽�̣�ָ�뺯��
										 //��Ԫ����Ϊ��Ա��һ���Ǻ�����Ҳ�����Ƕ���
										 //ֱ�Ӱ�Ψһָ��������Ϊ��Ԫ
										 //���ﻹ��Ҫ���Ϊ����������ֵΪSgton��ĺ���
#else
	friend Sgton* s1();
#endif
public:
	void print() const { cout << "x=" << x << endl; }
	void setX(int formalParameter_x) { x = formalParameter_x; }
};
#endif