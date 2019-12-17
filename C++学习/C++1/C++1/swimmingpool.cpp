#include <iostream>
#include "swimmingpool.h"
using namespace std;

swimmingpool::swimmingpool()
{
	radio = 0;
}

swimmingpool::~swimmingpool()
{
	cout << "bye!" << endl;
}

double swimmingpool::c()
{
	return circumference;
}

double swimmingpool::C()
{
	return Circumference;
}