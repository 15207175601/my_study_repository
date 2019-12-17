#include<iostream>
//#include "mytime0.h"
//#include "mytime1.h"
//#include "mytime2.h"
#include "mytime3.h"

Time::Time()
{
	hours = 0;
	minutes = 0;
}

Time::Time(int h, int m)
{
	hours = h;
	minutes = m;
}

void Time::AddMin(int m)
{
	minutes += m;
	hours += minutes / 60;			//*******
	minutes %= 60;
}

void Time::AddHr(int h)
{
	hours += h;
}

void Time::Reset(int h , int m )
{
	hours = h;
	minutes = m;
}

//Time Time::Sum(const Time &t)const
Time Time::operator+(const Time &t)const
{
	Time sum;
	sum.minutes = minutes + t.minutes;
	sum.hours = hours + t.hours + sum.minutes / 60;
	sum.minutes %= 60;
	return sum;
}

Time Time::operator-(const Time &t)const
{
	Time dec;
	int tot1, tot2;
	tot1 = t.minutes + 60 * t.hours;
	tot2 = minutes + 60 * hours;
	dec.minutes = (tot2 - tot1) % 60;
	dec.hours = (tot2-tot1) / 60;
	return dec;
}

Time Time::operator*(double mult)const
{
	Time mul;
	long int temp;
	temp = minutes*mult + 60 * hours*mult;
	mul.minutes = temp % 60;
	mul.hours = temp / 60;
	return mul;
}


/*void Time::show() const
{
	std::cout << hours << "hours, " << minutes << " minutes";
}*/

std::ostream & operator<<(std::ostream &os, const Time & t)
{
	os << t.hours << " hours," << t.minutes << " minutes";
	return os;
}