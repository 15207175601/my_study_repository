/*#include<iostream>
double ans(double x);
int main()
{
	using namespace std;
	cout << "enter a number with symbol.\n";
	double value;
	cin >> value;
	cout << "the answer is: " << ans(value);
	return 0;
}

double ans(double x)
{
	if (x < 0)
		return -x;
	else
		return x;
}*/
/*#include <iostream>
using namespace std;
class Base1 { //基类Base1定义
public:
	void display() const {
		cout << "Base1::display()" << endl;
	}
};
class Base2 : public Base1 { //公有派生类Base2定义
public:
	void display() const {
		cout << "Base2::display()" << endl;
	}
};
class Derived : public Base2 { //公有派生类Derived定义
public:
	void display() const {
		cout << "Derived::display()" << endl;
	}
};
void fun(Base1* ptr) { //参数为指向基类对象的指针
	ptr-> display(); //"对象指针‐>成员名"
}
int main() { //主函数
	Base1 base1; //声明Base1类对象
	Base2 base2; //声明Base2类对象
	Derived derived; //声明Derived类对象
	fun(&base1); //用Base1对象的指针调用fun函数
	fun(&base2); //用Base2对象的指针调用fun函数
	fun(&derived); //用Derived对象的指针调用fun函数
	return 0;
}*/
/*#include <iostream>
using namespace std;
class Base1 { //基类Base1定义
public:
	virtual void display() const; //虚函数
};
void Base1::display() const {
	cout << "Base1::display()" << endl;
}
class Base2:public Base1 { //公有派生类Base2定义
public:
	virtual void display() const; //覆盖基类的虚函数
};
void Base2::display() const {
	cout << "Base2::display()" << endl;
}
class Derived : public Base2 { //公有派生类
public:
	virtual void display() const; //覆盖基类的虚函数
};
void Derived::display() const {
	cout << "Derived::display()" << endl;
}
void fun(Base1* ptr) { //参数为指向基类对象的指针
	ptr-> display(); //"对象指针‐>成员名"
}
int main() {//主函数
	Base1 base1; //定义Base1类对象
	Base2 base2; //定义Base2类对象
	Derived derived; //定义Derived类对象
	fun(&base1);//用Base1对象的指针调用fun函数
	fun(&base2);//用Base2对象的指针调用fun函数
	fun(&derived);//用Derived对象的指针调用fun函数
	return 0;
}*/
/*#include <iostream>
using namespace std;
class Base {
public:
	virtual ~Base();		//基类析构函数虚函数，基类指针释放派生类对象
};
Base::~Base() {
	cout << "Base destructor"
		<< endl;
}
class Derived1 : public Base {
public:
	Derived1();
	~Derived1();
private:
	int* p;
};
Derived1::Derived1() {
	p = new int(0);
}
Derived1::~Derived1() {
	cout << "Derived destructor" << endl;
		delete p;
}
void fun1(Base* b) {
	delete b;
}
int main() {
	Base* b = new Derived1();
	fun1(b);
	return 0;
}*/
/*#include <iostream>
using namespace std;
class Base1 { //基类Base1定义
public:
	virtual void display() const = 0; //纯虚函数，抽象作为基类，在派生类实现
};
class Base2 : public Base1 { //公有派生类Base2定义
public:
	void display() const; //覆盖基类的虚函数
};
void Base2::display() const {
	cout << "Base2::display()" << endl;
}
class Derived : public Base2 { //公有派生类Derived定义
public:
	void display() const; //覆盖基类的虚函数
};
void Derived::display() const {
	cout << "Derived::display()" << endl;
}
void fun(Base1* ptr) { //参数为指向基类对象的指针
	ptr-> display(); //"对象指针‐>成员名"
}
int main() { //主函数
	Base2 base2; //定义Base2类对象
	Derived derived; //定义Derived类对象
	fun(&base2); //用Base2对象的指针调用fun函数
	fun(&derived); //用Derived对象的指针调用fun函数
	return 0
}*/
/*#include <iostream>
#include <cmath>
#include "Rectangle.h"
using namespace std;
int main() {
	Rectangle rect; //定义Rectangle类的对象
	rect.initRectangle(2, 3, 20, 10);//设置矩形的数据
	rect.move(3, 2); //移动矩形位置
	cout << "The data of rect(x,y,w,h): " << endl;
	cout << rect.getX() << ", "	//输出矩形的特征参数
		<< rect.getY() << ", "
		<< rect.getW() << ", "
		<< rect.getH() << endl;
	return 0;
}*/
/*#include <iostream>
using namespace std;
template<typename T>
T abs(T x) {
	return x < 0 ? -x : x;
}
int main() {
	int n = -5;
	double d = -5.5;
	cout << abs(n) << endl;
	cout << abs(d) << endl;
	return 0;
}*/
/*#include <iostream>
using namespace std;
template <class T> //定义函数模板
void outputArray(const T* array, int count) {
	for (int i = 0; i < count; i++)
		cout << array[i] << " ";
	cout << endl;
}
int main() { //主函数
	const int A_COUNT = 8, B_COUNT = 8, C_COUNT = 20;
	int a[A_COUNT] = { 1, 2, 3, 4, 5, 6, 7, 8 }; //定义int数组
	double b[B_COUNT] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6,7.7, 8.8 };//定义double数组
	char c[C_COUNT] = "Welcome to see you!";//定义char数组
	cout << " a array contains:" << endl;
	outputArray(a, A_COUNT); //调用函数模板
	cout << " b array contains:" << endl;
	outputArray(b, B_COUNT); //调用函数模板
	cout << " c array contains:" << endl;
	outputArray(c, C_COUNT); //调用函数模板
	return 0;
}*/
//类模板
/*#include <iostream>
#include <cstdlib>
using namespace std;
// 结构体Student
struct Student {
	int id; //学号
	float gpa; //平均分
};
template <class T>
class Store {//类模板：实现对任意类型数据进行存取
private:
	T item; // item用于存放任意类型的数据
	bool haveValue; // haveValue标记item是否已被存入内容
public:
	Store(); // 缺省形式（无形参）的构造函数
	T& getElem(); //提取数据函数
	void putElem(const T& x); //存入数据函数
};
//以下实现各成员函数。
template <class T> //缺省构造函数的实现
Store<T>::Store() : haveValue(false) { }
template <class T> //提取数据函数的实现
T& Store<T>::getElem() {
	//如试图提取未初始化的数据，则终止程序
	if (!haveValue) {
		cout << "No item present!" << endl;
		exit(1); //使程序完全退出，返回到操作系统。
	}
	return item; // 返回item中存放的数据
}
template <class T> //存入数据函数的实现
void Store<T>::putElem(const T& x) {
	// 将haveValue 置为true，表示item中已存入数值
	haveValue = true;
	item = x; // 将x值存入item
}
int main() {
	Store<int> s1, s2;
	s1.putElem(3);
	s2.putElem(-7);
	cout << s1.getElem() << " " << s2.getElem() << endl;
	Student g = { 1000, 23 };
	Store<Student> s3;
	s3.putElem(g);
	cout << "The student id is " << s3.getElem().id <<
		endl;
	Store<double> d;
	cout << "Retrieving object D... ";
	cout << d.getElem() << endl;
		//由于d未经初始化,在执行函数D.getElement()过程中导致程序终止
	return 0;
}*/
/*class A {
protected:
	int x;
};
int main() {
	A a;
	a.x = 5; //错误
}
class A {
protected:
	int x;
};
class B : public A {
public:
	void function();
};
void B :: function() {
	x = 5; //正确
}*/
//基类：Shape类
/*#include <iostream>
#include <cstdlib>
#include <cmath>
#include "swimmingpool.h"
using namespace std;*/
/*class Shape
{
public:
	Shape() {}
	virtual ~Shape() { cout << "destuct base!" << endl; }
	virtual double Area() = 0;
};
//派生类：矩形类
class Rectangle : public Shape {
public:
	Rectangle(double x, double y)
	{
		width = x; height = y;
	}
	~Rectangle() { cout << "destuct Rectangle!" << endl; }
	double Area() {
		cout << width * height << endl;
		return (double)width * height;
	}
private:
	double width;
	double height;
};
//派生类：圆类
class Circle : public Shape {
public:
	Circle(double x) { radius = x; }
	~Circle() { cout << "destuct Circle!" << endl; }
	double Area() {
		cout << PI * pow(radius, 2) << endl;
		return (double)PI * pow(radius, 2);
	}
private:
	double radius;
};
//主程序
int main() {
	cout << "虚函数多态实例: " << endl;
		//定义基类对象
	Shape * shape;
	//使用基类指针调用派生类的实现函数
	shape = new Rectangle(2, 3);
	shape-> Area();
	delete shape;
	shape = new Circle(3);
	shape-> Area();
	delete shape;
	return 0;
}*/
//基类：Point类
/*class Point {
public:
	Point(double ix, double iy)
	{
		x = ix; y = iy;
	}
	~Point() {}
	double GetX() { return x; }
	double GetY() { return y; }
private:
	double x;
	double y;
};
class Rectangle {
public:
	Rectangle(double x, double y, double w, double h)
		: vertex(x, y)
	{
		width = w; height = h;
	}
	~Rectangle() {}
	double Area() {
		cout << width * height << endl;
		return (double)width * height;
	}
	double GetX() { return vertex.GetX(); }
	double GetY() { return vertex.GetY(); }
private:
	Point vertex;
	double width;
	double height;
};
class Circle {
public:
	Circle(double x, double y, double r)
		: vertex(x, y)
	{
		radius = r;
	}
	double Area() {
		cout << PI * pow(radius, 2) << endl;
		return (double)PI * pow(radius, 2);
	}
	double GetX() { return vertex.GetX(); }
	double GetY() { return vertex.GetY(); }
private:
	Point vertex;
	double radius;
};*/
/*//基类：Point类
class Point {
public:
	Point(double ix, double iy)
	{
		x = ix; y = iy;
	}
	virtual ~Point() {}
	double GetX() { return x; }
	double GetY() { return y; }
private:
	double x;
	double y;
};
//派生类：矩形类
class Rectangle : public Point {
public:
	Rectangle(double x, double y, double w, double h)
		: Point(x, y)
	{
		width = w; height = h;
	}
	~Rectangle() {}
	double Area() {
		cout << width * height << endl;
		return (double)width * height;
	}
private:
	double width;
	double height;
};
//派生类：圆类
class Circle : public Point {
public:
	Circle(double x, double y, double r)
		: Point(x, y)
	{
		radius = r;
	}
	~Circle() {}
	double Area() {
		cout << PI * pow(radius, 2) << endl;
		return (double)PI * pow(radius, 2);
	}
private:
	double radius;
};
int main() {
	cout << "虚函数多态实例" << endl;
	Rectangle* shape = new Rectangle(0, 0, 2, 3);
	shape-> Area();
	shape-> GetX();
	delete shape;
	Circle* shape1 = new Circle(0, 0, 3);
	shape1-> Area();
	shape1-> GetX();
	delete shape1;
	return 0;
}*/
/*#include <iostream>
using namespace std;
class Base {
public:
	virtual void fun1() { cout << "Base::fun1()" << endl; }
	virtual ~Base() { }
};
class Derived1 : public Base {
public:
	virtual void fun1() { cout << "Derived1::fun1()" << endl; }
	virtual void fun2() { cout << "Derived1::fun2()" << endl; }
};
class Derived2 : public Derived1 {
public:
	virtual void fun1() { cout << "Derived2::fun1()" << endl; }
	virtual void fun2() { cout << "Derived2::fun2()" << endl; }
};
void fun(Base* b) {
	b-> fun1();
	//尝试将b转换为Derived1指针
	Derived1* d = dynamic_cast<Derived1*>(b);
	//判断转换是否成功
	if (d != 0) d-> fun2();
}
int main() {
	Base b;
	fun(&b);
	Derived1 d1;
	fun(&d1);
	Derived2 d2;
	fun(&d2);
	return 0;
}*/
/*#include <iostream>
using namespace std;
class Singleton {
	Singleton() { x = 0; }
public:
	void print()
	{
		cout << "singleton print called. x=" << x << endl;
	}
	
private:
	friend Singleton Case();
	int x;
};

Singleton Case()
{
	Singleton s1;
	return s1;
}
int main()
{
	Case();
	return 0;
}
*/

/*#include <iostream>
#include <typeinfo>
using namespace std;
class Base {
public:
	virtual ~Base() { }
};
class Derived : public Base { };
void fun(Base* b) {
	//得到表示b和*b类型信息的对象
	const type_info& info1 =typeid(b);
	const type_info& info2 =typeid(*b);
	cout << "typeid(b): " << info1.name()<< endl;
	cout << "typeid(*b): " << info2.name()<< endl;
	//判断*b是否为Base类型
	if (info2 == typeid(Base))
		cout << "A base class!" << endl;
}
int main() {
	Base b;
	fun(&b);
	Derived d;
	fun(&d);
	return 0;
}*/
/*#include <iostream>
using namespace std;
class Base1 { //基类Base1，构造函数有参数
public:
	Base1(int i) { cout << "Constructing Base1 " << i << endl; }
	virtual ~Base1() { cout << "Destructing Base1" << endl; }
};
class Base2 { //基类Base2，构造函数有参数
public:
	Base2(int j) { cout << "Constructing Base2 " << j << endl; }
	virtual ~Base2() { cout << "Destructing Base2" << endl; }
};
class Base3 { //基类Base3，构造函数无参数
public:
	Base3() { cout << "Constructing Base3 *" << endl; }
	virtual ~Base3() { cout << "Destructing Base3" << endl; }
};
class Derived : public Base2, public Base1, public Base3 {
	//派生新类Derived，注意基类名的顺序
public: //派生类的公有成员
	Derived(int a, int b, int c, int d) : Base1(a), member2(d),
		member1(c), Base2(b)
	{
		cout << "Constructing Derived" << endl;
	}
	virtual ~Derived() { cout << "Destructing Derived" << endl; }
	//注意基类名的个数与顺序，//注意成员对象名的个数与顺序
private: //派生类的私有成员对象
	Base1 member1;
	Base2 member2;
	Base3 member3;
};
int main() {
	Derived obj(1, 2, 3, 4);

	return 0;
}*/
/*#include <iostream>
using namespace std;
class Base1 { //基类Base1，构造函数有参数
public:
	Base1(int i) { cout << "Constructing Base1 " << i << endl; }
	~Base1() { cout << "Destructing Base1" << endl; }
};
class Base2 { //基类Base2，构造函数有参数
public:
	Base2(int j) { cout << "Constructing Base2 " << j << endl; }
	~Base2() { cout << "Destructing Base2" << endl; }
};
class Base3 { //基类Base3，构造函数无参数
public:
	Base3() { cout << "Constructing Base3 *" << endl; }
	~Base3() { cout << "Destructing Base3" << endl; }
};
class Derived : public Base2, public Base1, public Base3 {
	//派生新类Derived，注意基类名的顺序
public: //派生类的公有成员
	Derived(int a, int b, int c, int d) : Base1(a), member1(d),
		member2(c), Base2(b) { }
	//注意基类名的个数与顺序，注意成员对象名的个数与顺序
private: //派生类的私有成员对象
	Base1 member1;
	Base2 member2;
	Base3 member3;
};
int main() {
	Derived obj(5, 2, 3, 4);
	return 0;
}*/
/*#include <iostream>
using namespace std;
class Base1 { //定义基类Base1
public:
	int var;
	void fun() { cout << "Member of Base1" << endl; }
};
class Base2 { //定义基类Base2
public:
	int var;
	void fun() { cout << "Member of Base2" << endl; }
};
class Derived : public Base1, public Base2 { //定义派生类Derived
public:
	int var; //同名数据成员
	void fun() { cout << "Member of Derived" << endl; } //同名函数成员
};
int main() {
	Derived d;
	Derived* p = &d;
	d.var = 1; //对象名.成员名标识
	d.fun(); //访问Derived类成员
	d.Base1::var = 2; //作用域分辨符标识
	d.Base1::fun(); //访问Base1基类成员
	p-> Base2::var = 3; //作用域分辨符标识
	p-> Base2::fun(); //访问Base2基类成员
	return 0;
}*/
/*#include <iostream>
using namespace std;
class Base0 { //定义基类Base0
public:
	int var0;
	void fun0() { cout << "Member of Base0" << endl; }
};
class Base1 : public Base0 { //定义派生类Base1
public: //新增外部接口
	int var1;
};
class Base2 : public Base0 { //定义派生类Base2
public: //新增外部接口
	int var2;
};
class Derived : public Base1, public Base2 {//定义派生类Derived
public: //新增外部接口
	int var;
	void fun() { cout << "Member of Derived" << endl; }
};
int main() {//程序主函数
	Derived d; //定义Derived类对象d
	d.Base1::var0 = 2; //使用直接基类
	d.Base1::fun0();
	d.Base2::var0 = 3; //使用直接基类
	d.Base2::fun0();
	return 0;
}*/
/*#include <iostream>
using namespace std;
class Base0 { //定义基类Base0
public:
	int var0;
	void fun0() { cout << "Member of Base0" << endl; }
};
class Base1 : virtual public Base0 { //定义派生类Base1
public: //新增外部接口
	int var1;
};
class Base2 : virtual public Base0 { //定义派生类Base2
public: //新增外部接口
	int var2;
};
class Derived : public Base1, public Base2 {
	//定义派生类Derived
public: //新增外部接口
	int var;
	void fun() {
		cout << "Member of Derived" << endl;
	}
};
int main() { //程序主函数
	Derived d; //定义Derived类对象d
	d.var0 = 2; //直接访问虚基类的数据成员
	d.fun0(); //直接访问虚基类的函数成员
	return 0;
}*/
/*#include <iostream>
using namespace std;
class Base0 { //定义基类Base0
public:
	Base0(int var) : var0(var) { }
	int var0;
	void fun0() { cout << "Member of Base0" << endl; }
};
class Base1 : virtual public Base0 { //定义派生类Base1
public: //新增外部接口
	Base1(int var) : Base0(var) { }
	int var1;
};
class Base2 : virtual public Base0 { //定义派生类Base2
public: //新增外部接口
	Base2(int var) : Base0(var) { }
	int var2;
};
class Derived : public Base1, public Base2 {
	//定义派生类Derived
public: //新增外部接口
	Derived(int var) : Base0(var), Base1(var), Base2(var)
	{ }
	int var;
	void fun() { cout << "Member of Derived" << endl; }
};
int main() {//程序主函数
	Derived d(1); //定义Derived类对象d
	d.var0 = 2; //直接访问虚基类的数据成员
	d.fun0(); //直接访问虚基类的函数成员
	return 0;
}*/

/*#include<iostream>
using namespace std;

class A{
public:
	virtual void print(void)
	{
		cout <<"A::print()"<<endl;
	}
};

class B:public A{
public:
	virtual void print(void)
	{
		cout << "B::print()" << endl;
	}
};

class C :public B {
public:
	virtual void print(void)
	{
		cout << "C::print()" << endl;
	}
};

void print(A a)
{
	a.print();
}

int main()
{
	A a, * pa, * pb, * pc;
	B b;
	C c;
	pa = &a;
	pb = &b;
	pc = &c;
	a.print();
	b.print();
	c.print();
	pa->print();
	pb->print();
	pc->print();
	print(a);
	print(b);
	print(c);
	return 0;
}*/

/*#include <iostream>
using namespace std;

class A {
public:
	virtual void Print(int a, int b = 4) const
	{
		cout << "a = " << a << " , b = " << b << endl;
	}
};
class B : public A {
public:
	virtual void Print(int a) const
	{
		cout << "a = " << a << endl;
	}
	void Print(int a, double d) const
	{
		cout << "a = " << a << " , d = " << d << endl;
	}
};
void Show(A* p)
{
	p->Print(2);
	p->Print(2, 6.9);
}
class Base1 { //基类Base1定义
public:
	virtual void display() const; //虚函数
};
void Base1::display() const {
	cout << "Base1::display()" << endl;
}
class Base2 :public Base1 { //公有派生类Base2定义
public:
	virtual void display() const; //覆盖基类的虚函数
};
void Base2::display() const {
	cout << "Base2::display()" << endl;
}
class Derived : public Base2 { //公有派生类
public:
	virtual void display() const; //覆盖基类的虚函数
};
void Derived::display() const {
	cout << "Derived::display()" << endl;
}
void fun(Base1* ptr) { //参数为指向基类对象的指针
	ptr->display(); //"对象指针‐>成员名"
}
int main() {//主函数
	Base1 base1; //定义Base1类对象
	Base2 base2; //定义Base2类对象
	Derived derived; //定义Derived类对象
	fun(&base1);//用Base1对象的指针调用fun函数
	fun(&base2);//用Base2对象的指针调用fun函数
	fun(&derived);//用Derived对象的指针调用fun函数
	A* pa = new A;
	B b;
	B* pb = new B;
	Show(pa);
	Show(&b);
	delete pa;
	delete pb;
	return 0;
}*/
/*#include<iostream>
using namespace std;
class Solution {
public:
	int count = 0;
	void pa(int x, int n)
	{
		if (x >= n)
			return;
		if (x + 1 == n)
		{
			count++;
			return;
		}
		if (x + 2 == n)
		{
			count += 2;
			return;
		}
		else
		{
			pa(x + 1, n);
			pa(x + 2, n);
		}
	}
	int climbStairs(int n) {
		int x = 0;
		pa(x, n);
		return count;
	}
};

int main()
{
	Solution A;
	cout << A.climbStairs(5) << endl;
	return 0;
}*/
#include<iostream>
#include<vector>
using namespace std;
/*class Solution {
public:
	int climbStairs(int n) {
		if (n == 1)
			return 1;
		if (n == 0)
			return 0;
		int a[2] = { 1,1};
		for (int i = 2; i <= n; i++)
		{
			int temp= a[1] + a[0];
			a[0] = a[1];
			a[1] = temp;
		}
		return a[1];
	}
};

int main()
{
	Solution A;
	cout << A.climbStairs(44) << endl;
	return 0;
}*/
/*class Solution {
public:
	int minCostClimbingStairs(vector<int>& cost) {
		int count = 0;
		//vector<int>::iterator pe = cost.end();
		//vector<int>::iterator ps = cost.begin();
		int num = cost.size();
		for (int i = 0; i + 1 <= num;)
		{
			//count += (cost[i] < cost[i + 1]) ? cost[i] : cost[i + 1];
			if (cost[i] < cost[i + 1])
			{
				count += cost[i];
				i++;
			}
			else
			{
				count += cost[i + 1];
				i += 2;
			}
		}
		return count;
		/*if (ps + 1 <= pe)
		{
			count += (*ps < *(ps + 1)) ? *ps : *(ps + 1);
			if (*ps < *(ps + 1))
			{
				count += *ps;
			}
			else
			{
				count += *(ps + 1);
			}
		}
		else if (ps + 1 == pe)
		{

		}
	}
};
/*int main()
{
	Solution A;
	int a[4] = { 0,0,1,1 };
	vector<int>p(a,a+4);
	cout<<A.minCostClimbingStairs(p);
	return 0;
}*/


 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode q(0);
		ListNode* l3 = &q;
		ListNode* l4=l3;
		int add = 0;
		while (l2 != NULL && l1!= NULL)
		{
			ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
			l3->val = l1->val + l2->val+add;
			add = (l3->val > 9);
			l3->val %= 10;
			l3->next = temp;
			l3 = l3->next;
			l3->next = NULL;
			l1 = l1->next;
			l2 = l2->next;
		}
		while (l1 != NULL)
		{
			ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
			l3->val = l1->val + add;
			add = (l3->val > 9);
			l3->val %= 10;
			l3->next = temp;
			l3 = l3->next;
			l3->next = NULL;
			l1 = l1->next;
		}
		while (l2 != NULL)
		{
			ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
			l3->val = l2->val + add;
			add = (l3->val > 9);
			l3->val %= 10;
			l3->next = temp;
			l3 = l3->next;
			l3->next = NULL;
			l2 = l2->next;
		}
		if (add == 1)
		{
			l3->val = add;
			l3->next = NULL;
		}
		else
		{
			l3 = NULL;
		}
		return l4;
	}
};

int main()
{
	Solution A;
	ListNode l1(6),l3(5);
	l1.next = &l3;
	ListNode l2(6),l4(2);
	l2.next = &l4;
	printf("%d",A.addTwoNumbers(&l1, &l2)->val);
	return 0;
}

/*class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

		ListNode* pre1, * pre2, * head = l1;
		int a = 0;
		int re = 0;
		bool flag = false;
		while (l1 != NULL && l2 != NULL)
		{

			re = (l1->val + l2->val + a) % 10;
			a = (l1->val + l2->val + a) / 10;
			l1->val = re;
			pre2 = l2;
			pre1 = l1;
			l1 = l1->next;
			l2 = l2->next;
		}
		if (l2 != NULL)
		{
			pre1->next = l2;
			pre2->next = NULL;
			flag = true;
		}
		while (l1 != NULL)
		{
			re = (a + l1->val) % 10;
			a = (a + l1->val) / 10;
			l1->val = re;
			pre1 = l1;
			l1 = l1->next;
		}
		while (l2 != NULL)
		{
			re = (a + l2->val) % 10;
			a = (a + l2->val) / 10;
			pre2 = l2;
			l2->val = re;
			l2 = l2->next;
		}
		if (a != 0)
		{
			ListNode* last = new ListNode(a);
			if (flag)
				pre2->next = last;
			else
				pre1->next = last;
		}

		return head;

	}
};*/