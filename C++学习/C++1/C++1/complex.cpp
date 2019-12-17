#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*#include <iostream>
using namespace std;
class Complex { //�����ඨ��
public: //�ⲿ�ӿ�
	Complex(double r = 0.0, double i = 0.0) :
		real(r), imag(i) { } //���캯��
	Complex operator + (const Complex& c2) const;
	//�����+���س�Ա����
	Complex operator - (const Complex& c2) const;
	//������\���س�Ա����
	void display() const; //�������
private: //˽�����ݳ�Ա
	double real; //����ʵ��
	double imag; //�����鲿
};
Complex Complex::operator + (const Complex& c2)
const { //�������������ʵ��
	return Complex(real + c2.real, imag +c2.imag); //����һ����ʱ����������Ϊ����ֵ
}
Complex Complex::operator - (const Complex& c2)
const { //�������������ʵ��
	return Complex(real - c2.real, imag -c2.imag); //����һ����ʱ����������Ϊ����ֵ
}
void Complex::display() const {
	cout << "(" << real << ", " << imag << ")" <<endl;
}
int main() { //������
	Complex c1(5, 4), c2(2, 10), c3; //���帴����Ķ���
		cout << "c1 = "; c1.display();
	cout << "c2 = "; c2.display();
	c3 = c1 - c2; //ʹ�������������ɸ�������
	cout << "c3 = c1 - c2 = "; c3.display();
	c3 = c1 + c2; //ʹ�������������ɸ����ӷ�
	cout << "c3 = c1 + c2 = "; c3.display();
	return 0;
}*/
/*#include <iostream>
using namespace std;
class Clock { //ʱ���ඨ��
public: //�ⲿ�ӿ�
	Clock(int hour = 0, int minute = 0, int second = 0);
	void showTime() const;
	Clock& operator ++ (); //ǰ�õ�Ŀ���������
	Clock operator ++ (int); //���õ�Ŀ���������
private: //˽�����ݳ�Ա
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
void Clock::showTime() const { //��ʾʱ�亯��
	cout << hour << ":" << minute << ":" << second << endl;
}
Clock& Clock::operator ++ () { //ǰ�õ�Ŀ��������غ���
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
Clock Clock::operator ++ (int) { //���õ�Ŀ���������
//ע���βα��е����Ͳ���
	Clock old = *this;
	++(*this); //����ǰ�á�++�������
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
class Complex { //�����ඨ��
public: //�ⲿ�ӿ�
	Complex(double r = 0.0, double i = 0.0) : real(r),
		imag(i) { } //���캯��
	friend Complex operator + (const Complex& c1, const
		Complex& c2); //�����+����
	friend Complex operator - (const Complex& c1, const
		Complex& c2); //������\����
	friend ostream& operator << (ostream& out, const
		Complex& c); //�����<<����
private: //˽�����ݳ�Ա
	double real; //����ʵ��
	double imag; //�����鲿
};
Complex operator + (const Complex& c1, const Complex& c2)
{ //�������������ʵ��
	return Complex(c1.real + c2.real, c1.imag + c2.imag);
}
Complex operator - (const Complex& c1, const Complex& c2)
{ //�������������ʵ��
	return Complex(c1.real - c2.real, c1.imag - c2.imag);
}
ostream& operator << (ostream& out, const Complex& c) {
	//�������������ʵ��
	out << "(" << c.real << ", " << c.imag << ")";
	return out;
}
int main() {//������
	Complex c1(5, 4), c2(2, 10), c3; //���帴����Ķ���
	cout << "c1 = " << c1 << endl;
	cout << "c2 = " << c2 << endl;
	c3 = c1 - c2; //ʹ�������������ɸ�������
	cout << "c3 = c1 - c2 = " << c3 << endl;
	c3 = c1 + c2; //ʹ�������������ɸ����ӷ�
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
//�������������߳����������������
double area(double a, double b, double c) throw
(invalid_argument) {
	//�ж������α߳��Ƿ�Ϊ��
	if (a <= 0 || b <= 0 || c <= 0)
		throw invalid_argument("the side length should be positive");
			//�ж����߳��Ƿ��������ǲ���ʽ
			if (a + b <= c || b + c <= a || c + a <= b)
				throw invalid_argument("the side length should fit the triangle inequation");
					//��Heron��ʽ�������������
					double s = (a + b + c) / 2;
	return sqrt(s * (s - a) * (s - b) * (s - c));
}
int main() {
	double a, b, c; //���������߳�
	cout << "Please input the side lengths of a triangle: ";
		cin >> a >> b >> c;
	try {
		double s = area(a, b, c); //���Լ������������
			cout << "Area: " << s << endl;
	}
	catch (exception & e) {
		cout << "Error: " << e.what() << endl;
	}
	return 0;
}*/
//���ָ��������˳��������Ԫ��
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
	//�ӱ�׼�������10�������������Ƿֱ��s��ͷ������
	deque<int> s;
	for (int i = 0; i < 10; i++) {
		int x;
		cin >> x;
		s.push_front(x);
	}
	printContainer("deque at first", s);
	//��s���������ݵ��������б�����l
	list<int> l(s.rbegin(), s.rend());
	printContainer("list at first", l);
	//���б�����l��ÿ��������Ԫ��˳��ߵ�
	list<int>::iterator iter = l.begin();
	while (iter != l.end()) {
		int v = *iter;
		iter = l.erase(iter);
		l.insert(++iter, v);
	}
	printContainer("list at last", l);
	//���б�����l�����ݸ�s��ֵ����s���
	s.assign(l.begin(), l.end());
	printContainer("deque at last", s);
	return 0;
}*/
/*int main() {
	istream_iterator<int> i1(cin), i2; //����һ�Զ�������������
	vector<int> s1(i1, i2); //ͨ���������������ӱ�׼����������������
	sort(s1.begin(), s1.end()); //���������������
	deque<int> s2;
	//����ѭ������s1
	for (vector<int>::iterator iter = s1.begin(); iter != s1.end(); ++iter)
	{
		if (*iter % 2 == 0) //ż���ŵ�s2β��
			s2.push_back(*iter);
		else //�����ŵ�s2�ײ�
			s2.push_front(*iter);
	}
	//��s2�Ľ�����
	copy(s2.begin(), s2.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	return 0;
}*/
/*int main() {
	string names1[] = { "Alice", "Helen", "Lucy", "Susan" };
	string names2[] = { "Bob", "David", "Levin", "Mike" };
	list<string> s1(names1, names1 + 4); //��names1��������ݹ����б�s1
		list<string> s2(names2, names2 + 4); //��names2��������ݹ����б�s2
		//��s1�ĵ�һ��Ԫ�طŵ�s2�����
		s2.splice(s2.end(), s1, s1.begin());
	list<string>::iterator iter1 = s1.begin(); //iter1ָ��s1��
	advance(iter1, 2); //iter1ǰ��2��Ԫ�أ�����ָ��s1��3��Ԫ��
	list<string>::iterator iter2 = s2.begin(); //iter2ָ��s2��
	++iter2; //iter2ǰ��1��Ԫ�أ�����ָ��s2��2��Ԫ��
	list<string>::iterator iter3 = iter2; //��iter2��ʼ��iter3
	advance(iter3, 2); //iter3ǰ��2��Ԫ�أ�����ָ��s2��4��Ԫ��
	//��[iter2, iter3)��Χ�ڵĽ��ӵ�s1��iter1ָ��Ľ��ǰ
	s1.splice(iter1, s2, iter2, iter3);
	//�ֱ�s1��s2���
	copy(s1.begin(), s1.end(), ostream_iterator<string>(cout, " "));
	cout << endl;
	copy(s2.begin(), s2.end(), ostream_iterator<string>(cout, " "));
	cout << endl;
	return 0;
}*/
/*int main() {
	stack<char> s;
	string str;
	cin >> str; //�Ӽ�������һ���ַ���
	//���ַ�����ÿ��Ԫ��˳��ѹ��ջ��
	for (string::iterator iter = str.begin(); iter !=
		str.end(); ++iter)
		s.push(*iter);
	//��ջ�е�Ԫ��˳�򵯳������
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
	cout << endl;
	return 0;
}*/
/*const int SPLIT_TIME_MIN = 500; //ϸ���������ʱ��
const int SPLIT_TIME_MAX = 2000; //ϸ�������ʱ��
class Cell;
priority_queue<Cell> cellQueue;
class Cell { //ϸ����
private:
	static int count; //ϸ������
	int id; //��ǰϸ�����
	int time; //ϸ������ʱ��
public:
	Cell(int birth) : id(count++) { //birthΪϸ������ʱ��
	//��ʼ����ȷ��ϸ������ʱ��
		time = birth + (rand() % (SPLIT_TIME_MAX - SPLIT_TIME_MIN)) +
			SPLIT_TIME_MIN;
	}
	int getId() const { return id; } //�õ�ϸ�����
	int getSplitTime() const { return time; } //�õ�ϸ������ʱ��
	bool operator < (const Cell& s) const { return time > s.time; } //���塰<��
	//ϸ������
	void split() const {
		Cell child1(time), child2(time); //����������ϸ��
		cout << time << "s: Cell #" << id << " splits to #"
			<< child1.getId() << " and #" << child2.getId() << endl;
		cellQueue.push(child1); //����һ����ϸ��ѹ�����ȼ�����
		cellQueue.push(child2); //���ڶ�����ϸ��ѹ�����ȼ�����
	}
};
int Cell::count = 0;
int main() {
	srand(static_cast<unsigned>(time(0)));
	int t; //ģ��ʱ�䳤��
	cout << "Simulation time: ";
	cin >> t;
	cellQueue.push(Cell(0)); //����һ��ϸ��ѹ�����ȼ�����
	while (cellQueue.top().getSplitTime() <= t) {
		cellQueue.top().split(); //ģ����һ��ϸ���ķ���
		cellQueue.pop(); //���ոշ��ѵ�ϸ������
	}
	return 0;
}*/
/*int main() {
	set<double> s;
	while (true) {
		double v;
		cin >> v;
		if (v == 0) break; //����0��ʾ����
		pair<set<double>::iterator, bool> r = s.insert(v); //���Խ�v����
		if (!r.second) //���v�Ѵ��ڣ������ʾ��Ϣ
			cout << v << " is duplicated" << endl;
	}
	set<double>::iterator iter1 = s.begin(); //�õ���һ��Ԫ�صĵ�����
	set<double>::iterator iter2 = s.end(); //�õ�ĩβ�ĵ�����
	double medium = (*iter1 + *(--iter2)) / 2; //�õ���С�����Ԫ�ص���ֵ
	//���С�ڻ������ֵ��Ԫ��
	cout << "<= medium: ";
	copy(s.begin(), s.upper_bound(medium), ostream_iterator<double>(cout, " "));
	cout << endl;
	//������ڻ������ֵ��Ԫ��
	cout << ">= medium: ";
	copy(s.lower_bound(medium), s.end(), ostream_iterator<double>(cout, " "));
	cout << endl;
	return 0;
}*/
/*int main() {
	map<string, int> courses;
	//���γ���Ϣ����coursesӳ����
	courses.insert(make_pair("CSAPP", 3));
	courses.insert(make_pair("C++", 2));
	courses.insert(make_pair("CSARCH", 4));
	courses.insert(make_pair("COMPILER", 4));
	courses.insert(make_pair("OS", 5));
	int n = 3; //ʣ�µĿ�ѡ����
	int sum = 0; //ѧ���ܺ�
	while (n > 0) {
		string name;
		cin >> name; //����γ�����
		map<string, int>::iterator iter = courses.find(name);//���ҿγ�
		if (iter == courses.end()) { //�ж��Ƿ��ҵ�
			cout << name << " is not available" << endl;
		}
		else {
			sum += iter-> second; //�ۼ�ѧ��
			courses.erase(iter); //����ѡ���Ŀγ̴�ӳ����ɾ��
			n--;
		}
	}
	cout << "Total credit: " << sum << endl; //�����ѧ��
	return 0;
}*/
/*int main() {
	map<char, int> s;//�����洢��ĸ���ִ�����ӳ��
	char c; //�洢�����ַ�
	do {
		cin >> c; //������һ���ַ�
		if (isalpha(c)) { //�ж��Ƿ�����ĸ
			c = tolower(c); //����ĸת��ΪСд
			s[c]++; //������ĸ�ĳ���Ƶ�ʼ�1
		}
	} while (c != '.'); //������.�����������
	//���ÿ����ĸ���ִ���
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
	//���γ��Ͽ�ʱ�����coursesӳ����
	courses.insert(make_pair("C++", "2�\6"));
	courses.insert(make_pair("COMPILER", "3�\1"));
	courses.insert(make_pair("COMPILER", "5�\2"));
	courses.insert(make_pair("OS", "1�\2"));
	courses.insert(make_pair("OS", "4�\1"));
	courses.insert(make_pair("OS", "5�\5"));
	//����һ���γ�����ֱ���ҵ��ÿγ�Ϊֹ������ÿ���Ͽδ���
	string name;
	int count;
	do {
		cin >> name;
		count = courses.count(name);
		if (count == 0)
			cout << "Cannot find this course!" << endl;
	} while (count == 0);
	//���ÿ���Ͽδ������Ͽ�ʱ��
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
	ostringstream os; //�����ַ��������
	os << v; //������v��ֵд���ַ�����
	return os.str(); //������������ɵ��ַ���
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
	istringstream is(str); //�����ַ���������
	T v;
	is >> v; //���ַ����������ж�ȡ����v
	return v; //���ر���v
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
		Sgton* si1 = &s1();//�������ָ�벻��Ҫ�õ����캯�����˴�������ָ�벻������ָ�뺯������
		Sgton* si2 = &s1();//����ȡ��s1()�����ĵ�ַ��һ��һ�������Ե��º������ֵ��ʱ������˲�һ�£�Ӧ�ö���ú���ʱ��ȡ���ض�ָ��
		si2->setX(2);
		si1->print();
		si2->print();
	}
}
Sgton s1()//�൱���ֶ�������һ��ָ�룬��Ϊ�������в��ܵ��ù��죬���Ըĵ�����Ԫ��Ա
{                //��Ȼ�ĺ������ܱ�¶�������ߣ�ͬʱ�����۵��ü���ֻ������һ������s1
	static Sgton s1;//��Ϊ����Ԫ�����������ܹ�����
			   //�˴���static�����У����ӻ�������棬��̬���ݻ��Զ��ͷŵ���������ʧ�����������Զ��ͷţ�����Ҫʹ��new�����������������漰Ҫ��delete�ֶ��ͷſռ䣬�������������ڴ�й¶�����⡣
	return s1;//����˴����Ƿ��ص�ַ���˴���Ҫ���ÿ������캯������s1��������s1()�ϣ���ʱs1���ַ���䣬���ǿ��������ɵ�s1()��ַ�ᷢ���仯
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
		Sgton* si1 = s1();//�������ָ�벻��Ҫ�õ����캯�����˴�������ָ�벻������ָ�뺯������
		Sgton* si2 = s1();
		si2->setX(2);
		si1->print();
		si2->print();
	}
}
Sgton* s1()//�൱���ֶ�������һ��ָ�룬��Ϊ�������в��ܵ��ù��죬���Ըĵ�����Ԫ��Ա
{                //��Ȼ�ĺ������ܱ�¶�������ߣ�ͬʱ�����۵��ü���ֻ������һ������s1
	static Sgton s1;//��Ϊ����Ԫ�����������ܹ�����
	return &s1;//����˴����Ƿ��ص�ַ���˴�������ÿ������캯��
}
#endif*/