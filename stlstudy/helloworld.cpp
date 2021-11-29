#include<iostream>
#include"myadapter.hpp"
int main(){
	using namespace MySTL;
	using std::cout;
	using std::endl;
	plus<int> plusobj;
	minus<int> minusobj;
	multiplies<int> multipliesobj;
	divides<int> dividesobj;
	modulus<int> modulusobj;
	negate<int> negateobj;

	cout<<plusobj(3,5)<<endl;
	cout<<minusobj(3,5)<<endl;
	cout<<multipliesobj(3,5)<<endl;
	cout<<dividesobj(3,5)<<endl;
	cout<<modulusobj(3,5)<<endl;
	cout<<negateobj(3)<<endl;

	cout<<equal_to<int>()(3,5)<<endl;
	cout<<not_equal_to<int>()(3,5)<<endl;
	cout<<greater<int>()(3,5)<<endl;
	cout<<less<int>()(3,5)<<endl;
	cout<<greater_equal<int>()(3,5)<<endl;
	cout<<less_equal<int>()(3,5)<<endl;
	return 0;
}

//my_helloworld