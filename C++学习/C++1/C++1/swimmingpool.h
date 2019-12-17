#pragma once
#ifndef SWIM_H_
#define SWIM_H_
#define WIDTH 3		 //过道宽度
#define P_PRICE 20.0	 //过道造价
#define Z_PRICE 35.0  //栅栏造价
#define PI 3.1415926

class swimmingpool 
{
private:
	double radio;
	double width;
	double Radio;
	double circumference;
	double Circumference;
	void set_Radio() { Radio=radio + width; }
	void set_c() { circumference = PI * radio*radio; }
	void set_C() { Circumference = PI * Radio*Radio; }
public:
	swimmingpool();
	swimmingpool(double r, double w=WIDTH)
	{
		radio = r;
	}
	~swimmingpool();
	double c();
	double C();
};
#endif // !SWIM
