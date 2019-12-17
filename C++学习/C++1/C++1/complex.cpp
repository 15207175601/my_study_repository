#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*#include <iostream>
using namespace std;
class Complex { //复数类定义
public: //外部接口
	Complex(double r = 0.0, double i = 0.0) :
		real(r), imag(i) { } //构造函数
	Complex operator + (const Complex& c2) const;
	//运算符+重载成员函数
	Complex operator - (const Complex& c2) const;
	//运算符‐重载成员函数
	void display() const; //输出复数
private: //私有数据成员
	double real; //复数实部
	double imag; //复数虚部
};
Complex Complex::operator + (const Complex& c2)
const { //重载运算符函数实现
	return Complex(real + c2.real, imag +c2.imag); //创建一个临时无名对象作为返回值
}
Complex Complex::operator - (const Complex& c2)
const { //重载运算符函数实现
	return Complex(real - c2.real, imag -c2.imag); //创建一个临时无名对象作为返回值
}
void Complex::display() const {
	cout << "(" << real << ", " << imag << ")" <<endl;
}
int main() { //主函数
	Complex c1(5, 4), c2(2, 10), c3; //定义复数类的对象
		cout << "c1 = "; c1.display();
	cout << "c2 = "; c2.display();
	c3 = c1 - c2; //使用重载运算符完成复数减法
	cout << "c3 = c1 - c2 = "; c3.display();
	c3 = c1 + c2; //使用重载运算符完成复数加法
	cout << "c3 = c1 + c2 = "; c3.display();
	return 0;
}*/
/*#include <iostream>
using namespace std;
class Clock { //时钟类定义
public: //外部接口
	Clock(int hour = 0, int minute = 0, int second = 0);
	void showTime() const;
	Clock& operator ++ (); //前置单目运算符重载
	Clock operator ++ (int); //后置单目运算符重载
private: //私有数据成员
	int hour, minute, second;
};
Clock::Clock(int hour, int minute, int second) {
	if (0 <= hour && hour < 24 && 0 <= minute && minute < 60
		&& 0 <= second && second < 60) {
		this-> hour = hour;
		this-> minute = minute;
		this-> second = second;
	}
	else
		cout << "Time error!" << endl;
}
void Clock::showTime() const { //显示时间函数
	cout << hour << ":" << minute << ":" << second << endl;
}
Clock& Clock::operator ++ () { //前置单目运算符重载函数
	second++;
	if (second >= 60) {
		second -= 60;
		minute++;
		if (minute >= 60) {
			minute -= 60;
			hour = (hour + 1) % 24;
		}
	}
	return *this;
}
Clock Clock::operator ++ (int) { //后置单目运算符重载
//注意形参表中的整型参数
	Clock old = *this;
	++(*this); //调用前置“++”运算符
	return old;
}
int main() {
	Clock myClock(23, 59, 59);
	cout << "First time output: ";
	myClock.showTime();
	cout << "Show myClock++: ";
	(myClock++).showTime();
	cout << "Show ++myClock: ";
	(++myClock).showTime();
	return 0;
}*/
/*#include <iostream>
using namespace std;
class Complex { //复数类定义
public: //外部接口
	Complex(double r = 0.0, double i = 0.0) : real(r),
		imag(i) { } //构造函数
	friend Complex operator + (const Complex& c1, const
		Complex& c2); //运算符+重载
	friend Complex operator - (const Complex& c1, const
		Complex& c2); //运算符‐重载
	friend ostream& operator << (ostream& out, const
		Complex& c); //运算符<<重载
private: //私有数据成员
	double real; //复数实部
	double imag; //复数虚部
};
Complex operator + (const Complex& c1, const Complex& c2)
{ //重载运算符函数实现
	return Complex(c1.real + c2.real, c1.imag + c2.imag);
}
Complex operator - (const Complex& c1, const Complex& c2)
{ //重载运算符函数实现
	return Complex(c1.real - c2.real, c1.imag - c2.imag);
}
ostream& operator << (ostream& out, const Complex& c) {
	//重载运算符函数实现
	out << "(" << c.real << ", " << c.imag << ")";
	return out;
}
int main() {//主函数
	Complex c1(5, 4), c2(2, 10), c3; //定义复数类的对象
	cout << "c1 = " << c1 << endl;
	cout << "c2 = " << c2 << endl;
	c3 = c1 - c2; //使用重载运算符完成复数减法
	cout << "c3 = c1 - c2 = " << c3 << endl;
	c3 = c1 + c2; //使用重载运算符完成复数加法
	cout << "c3 = c1 + c2 = " << c3 << endl;
	return 0;
}*/
/*#include <iostream>
using namespace std;
int divide(int x, int y) {
	if (y == 0)
		throw x;
	return x / y;
}
int main() {
	try {
		cout << "5 / 2 = " << divide(5, 2) << endl;
		cout << "8 / 0 = " << divide(8, 0) << endl;
		cout << "7 / 1 = " << divide(7, 1) << endl;
	}
	catch (int e) {
		cout << e << " is divided by zero!" << endl;
	}
	cout << "That is ok." << endl;
	return 0;
}*/
/*#include <iostream>
#include <string>
using namespace std;
class MyException {
public:
	MyException(const string& message) : message(message) {}
	~MyException() {}
	const string& getMessage() const { return message; }
private:
	string message;
};
class Demo {
public:
	Demo() { cout << "Constructor of Demo" << endl; }
	~Demo() { cout << "Destructor of Demo" << endl; }
};
void func() throw (MyException) {
	Demo d;
	cout << "Throw MyException in func()" << endl;
	throw MyException("exception thrown by func()");
}
int main() {
	cout << "In main function" << endl;
	try {
		func();
	}
	catch (MyException & e) {
		cout << "Caught an exception: " <<
			e.getMessage() << endl;
	}
	cout << "Resume the execution of main()" << endl;
}*/
/*#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;
//给出三角形三边长，计算三角形面积
double area(double a, double b, double c) throw
(invalid_argument) {
	//判断三角形边长是否为正
	if (a <= 0 || b <= 0 || c <= 0)
		throw invalid_argument("the side length should be positive");
			//判断三边长是否满足三角不等式
			if (a + b <= c || b + c <= a || c + a <= b)
				throw invalid_argument("the side length should fit the triangle inequation");
					//由Heron公式计算三角形面积
					double s = (a + b + c) / 2;
	return sqrt(s * (s - a) * (s - b) * (s - c));
}
int main() {
	double a, b, c; //三角形三边长
	cout << "Please input the side lengths of a triangle: ";
		cin >> a >> b >> c;
	try {
		double s = area(a, b, c); //尝试计算三角形面积
			cout << "Area: " << s << endl;
	}
	catch (exception & e) {
		cout << "Error: " << e.what() << endl;
	}
	return 0;
}*/
//输出指定的整型顺序容器的元素
#include<iostream>
#include<queue>
#include <list>
#include <iterator>
#include <stack>
#include <time.h>
#include <set>
#include <map>
using namespace std;
/*template <class T>
void printContainer(const char* msg, const T& s) {
	cout << msg << ": ";
	copy(s.begin(), s.end(), ostream_iterator <int>(cout, " "));
	cout << endl;
}
int main() {
	//从标准输入读入10个整数，将它们分别从s的头部加入
	deque<int> s;
	for (int i = 0; i < 10; i++) {
		int x;
		cin >> x;
		s.push_front(x);
	}
	printContainer("deque at first", s);
	//用s容器的内容的逆序构造列表容器l
	list<int> l(s.rbegin(), s.rend());
	printContainer("list at first", l);
	//将列表容器l的每相邻两个元素顺序颠倒
	list<int>::iterator iter = l.begin();
	while (iter != l.end()) {
		int v = *iter;
		iter = l.erase(iter);
		l.insert(++iter, v);
	}
	printContainer("list at last", l);
	//用列表容器l的内容给s赋值，将s输出
	s.assign(l.begin(), l.end());
	printContainer("deque at last", s);
	return 0;
}*/
/*int main() {
	istream_iterator<int> i1(cin), i2; //建立一对儿输入流迭代器
	vector<int> s1(i1, i2); //通过输入流迭代器从标准输入流中输入数据
	sort(s1.begin(), s1.end()); //将输入的整数排序
	deque<int> s2;
	//以下循环遍历s1
	for (vector<int>::iterator iter = s1.begin(); iter != s1.end(); ++iter)
	{
		if (*iter % 2 == 0) //偶数放到s2尾部
			s2.push_back(*iter);
		else //奇数放到s2首部
			s2.push_front(*iter);
	}
	//将s2的结果输出
	copy(s2.begin(), s2.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	return 0;
}*/
/*int main() {
	string names1[] = { "Alice", "Helen", "Lucy", "Susan" };
	string names2[] = { "Bob", "David", "Levin", "Mike" };
	list<string> s1(names1, names1 + 4); //用names1数组的内容构造列表s1
		list<string> s2(names2, names2 + 4); //用names2数组的内容构造列表s2
		//将s1的第一个元素放到s2的最后
		s2.splice(s2.end(), s1, s1.begin());
	list<string>::iterator iter1 = s1.begin(); //iter1指向s1首
	advance(iter1, 2); //iter1前进2个元素，它将指向s1第3个元素
	list<string>::iterator iter2 = s2.begin(); //iter2指向s2首
	++iter2; //iter2前进1个元素，它将指向s2第2个元素
	list<string>::iterator iter3 = iter2; //用iter2初始化iter3
	advance(iter3, 2); //iter3前进2个元素，它将指向s2第4个元素
	//将[iter2, iter3)范围内的结点接到s1中iter1指向的结点前
	s1.splice(iter1, s2, iter2, iter3);
	//分别将s1和s2输出
	copy(s1.begin(), s1.end(), ostream_iterator<string>(cout, " "));
	cout << endl;
	copy(s2.begin(), s2.end(), ostream_iterator<string>(cout, " "));
	cout << endl;
	return 0;
}*/
/*int main() {
	stack<char> s;
	string str;
	cin >> str; //从键盘输入一个字符串
	//将字符串的每个元素顺序压入栈中
	for (string::iterator iter = str.begin(); iter !=
		str.end(); ++iter)
		s.push(*iter);
	//将栈中的元素顺序弹出并输出
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
	cout << endl;
	return 0;
}*/
/*const int SPLIT_TIME_MIN = 500; //细胞分裂最短时间
const int SPLIT_TIME_MAX = 2000; //细胞分裂最长时间
class Cell;
priority_queue<Cell> cellQueue;
class Cell { //细胞类
private:
	static int count; //细胞总数
	int id; //当前细胞编号
	int time; //细胞分裂时间
public:
	Cell(int birth) : id(count++) { //birth为细胞诞生时间
	//初始化，确定细胞分裂时间
		time = birth + (rand() % (SPLIT_TIME_MAX - SPLIT_TIME_MIN)) +
			SPLIT_TIME_MIN;
	}
	int getId() const { return id; } //得到细胞编号
	int getSplitTime() const { return time; } //得到细胞分裂时间
	bool operator < (const Cell& s) const { return time > s.time; } //定义“<”
	//细胞分裂
	void split() const {
		Cell child1(time), child2(time); //建立两个子细胞
		cout << time << "s: Cell #" << id << " splits to #"
			<< child1.getId() << " and #" << child2.getId() << endl;
		cellQueue.push(child1); //将第一个子细胞压入优先级队列
		cellQueue.push(child2); //将第二个子细胞压入优先级队列
	}
};
int Cell::count = 0;
int main() {
	srand(static_cast<unsigned>(time(0)));
	int t; //模拟时间长度
	cout << "Simulation time: ";
	cin >> t;
	cellQueue.push(Cell(0)); //将第一个细胞压入优先级队列
	while (cellQueue.top().getSplitTime() <= t) {
		cellQueue.top().split(); //模拟下一个细胞的分裂
		cellQueue.pop(); //将刚刚分裂的细胞弹出
	}
	return 0;
}*/
/*int main() {
	set<double> s;
	while (true) {
		double v;
		cin >> v;
		if (v == 0) break; //输入0表示结束
		pair<set<double>::iterator, bool> r = s.insert(v); //尝试将v插入
		if (!r.second) //如果v已存在，输出提示信息
			cout << v << " is duplicated" << endl;
	}
	set<double>::iterator iter1 = s.begin(); //得到第一个元素的迭代器
	set<double>::iterator iter2 = s.end(); //得到末尾的迭代器
	double medium = (*iter1 + *(--iter2)) / 2; //得到最小和最大元素的中值
	//输出小于或等于中值的元素
	cout << "<= medium: ";
	copy(s.begin(), s.upper_bound(medium), ostream_iterator<double>(cout, " "));
	cout << endl;
	//输出大于或等于中值的元素
	cout << ">= medium: ";
	copy(s.lower_bound(medium), s.end(), ostream_iterator<double>(cout, " "));
	cout << endl;
	return 0;
}*/
/*int main() {
	map<string, int> courses;
	//将课程信息插入courses映射中
	courses.insert(make_pair("CSAPP", 3));
	courses.insert(make_pair("C++", 2));
	courses.insert(make_pair("CSARCH", 4));
	courses.insert(make_pair("COMPILER", 4));
	courses.insert(make_pair("OS", 5));
	int n = 3; //剩下的可选次数
	int sum = 0; //学分总和
	while (n > 0) {
		string name;
		cin >> name; //输入课程名称
		map<string, int>::iterator iter = courses.find(name);//查找课程
		if (iter == courses.end()) { //判断是否找到
			cout << name << " is not available" << endl;
		}
		else {
			sum += iter-> second; //累加学分
			courses.erase(iter); //将刚选过的课程从映射中删除
			n--;
		}
	}
	cout << "Total credit: " << sum << endl; //输出总学分
	return 0;
}*/
/*int main() {
	map<char, int> s;//用来存储字母出现次数的映射
	char c; //存储输入字符
	do {
		cin >> c; //输入下一个字符
		if (isalpha(c)) { //判断是否是字母
			c = tolower(c); //将字母转换为小写
			s[c]++; //将该字母的出现频率加1
		}
	} while (c != '.'); //碰到“.”则结束输入
	//输出每个字母出现次数
	for (map<char, int>::iterator iter = s.begin(); iter !=
		s.end(); ++iter)
		cout << iter-> first << " " << iter-> second << " ";
	cout << endl;
	return 0;
}*/
/*#include <iostream>
#include <map>
#include <utility>
#include <string>
using namespace std;
int main() {
	multimap<string, string> courses;
	typedef multimap<string, string>::iterator CourseIter;
	//将课程上课时间插入courses映射中
	courses.insert(make_pair("C++", "2‐6"));
	courses.insert(make_pair("COMPILER", "3‐1"));
	courses.insert(make_pair("COMPILER", "5‐2"));
	courses.insert(make_pair("OS", "1‐2"));
	courses.insert(make_pair("OS", "4‐1"));
	courses.insert(make_pair("OS", "5‐5"));
	//输入一个课程名，直到找到该课程为止，记下每周上课次数
	string name;
	int count;
	do {
		cin >> name;
		count = courses.count(name);
		if (count == 0)
			cout << "Cannot find this course!" << endl;
	} while (count == 0);
	//输出每周上课次数和上课时间
	cout << count << " lesson(s) per week: ";
	pair<CourseIter, CourseIter> range = courses.equal_range(name);
	for (CourseIter iter = range.first; iter != range.second; ++iter)
		cout << iter-> second << " ";
	cout << endl;
	return 0;
}*/
/*#include <iostream>
using namespace std;
int main() {
	double values[] = { 1.23, 35.36, 653.7,
	4358.24 };
	for (int i = 0; i < 4; i++) {
		cout.width(10);
		cout << values[i] << endl;
	}
	return 0;
}*/
/*#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main() {
	double values[] = { 1.23, 35.36, 653.7, 4358.24 };
	string names[] = { "Zoot", "Jimmy", "Al",
	"Stan" };
	for (int i = 0; i < 4; i++)
		cout << setw(6) << names[i]
		<< setw(10) << values[i] << endl;
	return 0;
}*/
/*#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main() {
	double values[] = { 1.23, 35.36, 653.7, 4358.24 };
	string names[] = { "Zoot", "Jimmy", "Al", "Stan" };
	for (int i = 0; i < 4; i++)
		cout << setiosflags(ios_base::left)
		<< setw(6) << names[i]
		<< resetiosflags(ios_base::left)
		<< setw(10) << values[i] << endl;
	return 0;
}*/
/*#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main() {
	double values[] = { 1.23, 35.36, 653.7, 4358.24 };
	string names[] = { "Zoot", "Jimmy", "Al", "Stan" };
	for (int i = 0; i < 4; i++)
		cout << setiosflags(ios_base::left)
		<< setw(6) << names[i]
		<< resetiosflags(ios_base::left)
		<< setw(10) << setprecision(1) << values[i]
		<< endl;
	return 0;
}*/
/*#include <fstream>
using namespace std;
int main() {
	ofstream file("date.dat", ios_base::binary);
	file.write("Hello,", 6);
	file << "World!";
	file.close();
	return 0;
}*/
/*#include <iostream>
#include <sstream>
#include <string>
using namespace std;
template <class T>
inline string toString(const T& v) {
	ostringstream os; //创建字符串输出流
	os << v; //将变量v的值写入字符串流
	return os.str(); //返回输出流生成的字符串
}
int main() {
	string str1 = toString(5);
	cout << str1 << endl;
	string str2 = toString(1.2);
	cout << str2 << endl;
	return 0;
}*/
/*#include <iostream>
using namespace std;
int main() {
	char ch;
	while ((ch = cin.get()) != EOF)
		cout.put(ch);
	return 0;
}*/
/*#include <iostream>
#include <string>
using namespace std;
int main() {
	string line;
	cout << "Type a line terminated by 't'" << endl;
	getline(cin, line, 't');
	cout << line << endl;
	return 0;
}*/
/*template <class T>
inline T fromString(const string& str) {
	istringstream is(str); //创建字符串输入流
	T v;
	is >> v; //从字符串输入流中读取变量v
	return v; //返回变量v
}
int main() {
	int v1 = fromString<int>("5");
	cout << v1 << endl;
	double v2 = fromString<double>("1.2");
	cout << v2 << endl;
	return 0;
}*/

/*#include<string.h>
#include<stdio.h>

class Base
{
private:
	char* name;
public:
	Base(char* className)
	{
		name = new char[strlen(className) + 1];
		strcpy_s(name, strlen(className) + 1, className);
		//strcpy(name, className);
	}
	~Base() {
		delete name;
	}
	char newname[256];
	char* copyName()
	{
		strcpy_s(newname, strlen(name) + 1, name);
		//strcpy_s(newname, name);
		return newname;
	}
	char* getName() { return name; }
	static void print(Base base)
	{
		printf("name:%s\n", base.name);
	}
	void show()
	{
		printf("%c\n", *(name + 4));
	}
};

class Subclass :public Base
{
public:
	Subclass(char* className) :Base(className) {}
};

int main()
{
	char p[5] = "test";
	Base* pBase = new Subclass(p);
	//Base* pBase = new Subclass("test");
	printf("new name:%s\n", pBase->copyName());
	printf("name:%s\n", pBase->getName());
	Base::print(*pBase);
	return 0;
	getchar();
}*/

/*#include"Sgton.h"
//mode1:fake if double define not consistent
#if MODE==1
Sgton s1();
int main()
{
	enum { correct, fake } mode;
	mode = fake;
	if (mode == fake)
	{
		Sgton* si1 = &s1();//建立类的指针不需要用到构造函数，此处声明的指针不能与类指针函数重名
		Sgton* si2 = &s1();//这里取得s1()函数的地址不一定一样，所以导致后面更改值的时候出现了不一致，应该定义该函数时就取到特定指针
		si2->setX(2);
		si1->print();
		si2->print();
	}
}
Sgton s1()//相当于手动定义了一遍指针，因为主函数中不能调用构造，所以改调用友元成员
{                //显然改函数不能暴露给操作者，同时，无论调用几次只能生成一个对象s1
	static Sgton s1;//因为是友元函数，所以能够构造
			   //此处的static必须有，不加会产生警告，动态数据会自动释放导致数据流失，如果想避免自动释放，则需要使用new函数，但是这里又涉及要加delete手动释放空间，操作不当导致内存泄露的问题。
	return s1;//如果此处不是返回地址，此处需要调用拷贝构造函数，将s1赋到函数s1()上，此时s1随地址不变，但是拷构函生成的s1()地址会发生变化
}
//mode2:correct if double consistent
#else
Sgton* s1();
int main()
{
	enum { correct, fake } mode;
	mode = correct;
	if (mode == correct)
	{
		Sgton* si1 = s1();//建立类的指针不需要用到构造函数，此处声明的指针不能与类指针函数重名
		Sgton* si2 = s1();
		si2->setX(2);
		si1->print();
		si2->print();
	}
}
Sgton* s1()//相当于手动定义了一遍指针，因为主函数中不能调用构造，所以改调用友元成员
{                //显然改函数不能暴露给操作者，同时，无论调用几次只能生成一个对象s1
	static Sgton s1;//因为是友元函数，所以能够构造
	return &s1;//如果此处不是返回地址，此处不会调用拷贝构造函数
}
#endif*/