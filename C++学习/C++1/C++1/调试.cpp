/*#include<iostream>
int main()
{
	std::cout << "Enter two numbers:" << std::endl;
	int v1 = 0, v2 = 0;
	std::cin >> v1 >> v2;
	std::cout << "The sum of " << v1 << "and " << v2 << "is " << v1 + v2 << std::endl;
	return 0;
}*/
/*#include <iostream>
#include <cmath>
using namespace std;
 
class Point
{
private:
	int x, y;
public:
	Point(int xx = 0, int yy = 0) { x = xx, y = yy; }
	Point(Point &p);
	int getX() { return x; }
	int getY() { return y; }
};
Point::Point(Point &p)
{
	x = p.x;
	y = p.y;
	cout << "calling the copy constructor " << endl;
}

//void fun1(Point p)
//{
//	cout << p.getX() << endl;
//}
//Point func2()
//{
//	Point a(1, 2);
//	return a;
//}

class Line
{
private:
	Point p1, p2;
	double len;
public:
	Line(Point xp1, Point xp2);
	Line(Line & l);
	double getLen() { return len; }
};

Line::Line(Point xp1, Point xp2) :p1(xp1), p2(xp2)
{
	cout << "calling constructor of Line" << endl;
	double x = static_cast<double>(p1.getX() - p2.getX());
	double y = static_cast<double>(p1.getY() - p2.getY());
	len = sqrt(x*x + y *y);
}

Line::Line(Line &l):p1(l.p1),p2(l.p2)
{
	cout << "calling the copy constructor of Line" << endl;
	len = l.len;
}

int main()
{
	//Point a(4, 5);
	//Point b = a;
	//cout << b.getX() << endl;
	//fun1(b);
	//b = func2();
	//cout << b.getX() << endl;
	//return 0;
	Point myp1(1, 1), myp2(4, 5);
	Line line(myp1, myp2);
	Line line2(line);
	cout << "the length of the line is: ";
	cout << line.getLen() << endl;
	cout << "the length of the line2 is:";
	cout << line2.getLen() << endl;
	return 0;
}*/

/*#include <string>
#include <iostream>
using namespace std;
class ExamInfo {
private:
	string name;
	enum {GRADE,PASS,PERCENTAGE}
	mode;
	union
	{
		char grade;
		bool pass;
		int percent;
	};
public:
	ExamInfo(string name, char grade)
		:name(name), mode(GRADE), grade(grade) {};
	ExamInfo(string name, bool pass)
		:name(name), mode(PASS), pass(pass) {};
	ExamInfo(string name, int percent)
		:name(name), mode(PERCENTAGE), percent(percent) {};
	void show();

};
void ExamInfo::show()
{
	cout << name << ": ";
	switch (mode)
	{
	case ExamInfo::GRADE:cout << grade ;
		break;
	case ExamInfo::PASS:cout << pass ;
		break;
	case ExamInfo::PERCENTAGE:cout << percent ;
		break;
	default:
		break;
	}
	cout << endl;
}
int main() {
	ExamInfo course1("English", 'B');
	ExamInfo course2("Calculus", true);
	ExamInfo course3("C++ Programming", 85);
	course1.show();
	course2.show();
	course3.show();
	return 0;
}*/

/*#include<iostream>
#include<cmath>
using namespace std;

class savingsAccount
{
private:
	int id;
	double balance;
	double rate;
	int lastDate;
	double accumulation;
	void record(int date, double amount);
	double accumulate(int date) { return accumulation + balance * (date - lastDate); }
public:
	savingsAccount(int date, int id, double rate);
	int getId() { return id; }
	double getBalance() { return balance; }
	double getRate(){return rate; }
	void deposit(int date, double amount);
	void withdraw(int date, double amount);
	void settle(int date);
	void show();
};
savingsAccount::savingsAccount(int date, int id, double rate)
	:id(id),balance(0),rate(rate),lastDate(date),accumulation(0)
{
	cout << date << "\t#" << id << " is created." << endl;
}

void savingsAccount::record(int date, double amount)
{
	accumulation = accumulate(date);
	lastDate = date;
	amount = floor(amount * 100 + 0.5)/100;
	balance += amount;
	cout<<date<<"\t#" << id << "\t" << amount << "\t" << balance << endl;
}
void savingsAccount::deposit(int date, double amount) {
	record(date, amount);
}
void savingsAccount::withdraw(int date, double amount) {
	if (amount > getBalance())
		cout << "Error: not enough money" << endl;
	else
		record(date, -amount);
}
void savingsAccount::settle(int date) {
	double interest = accumulate(date) * rate / 365;//������Ϣ
	if (interest != 0)
		record(date, interest);
	accumulation = 0;
}
void savingsAccount::show() {
	cout << "#" << id << "\tBalance: " << balance;
}
int main() {
	//���������˻�
	savingsAccount sa0(1, 21325302, 0.015);
	savingsAccount sa1(1, 58320212, 0.015);
	//������Ŀ
	sa0.deposit(5, 5000);
	sa1.deposit(25, 10000);
	sa0.deposit(45, 5500);
	sa1.withdraw(60, 4000);
	//�������90�쵽�����еļ�Ϣ�գ����������˻�����Ϣ
	sa0.settle(90);
	sa1.settle(90);
	//��������˻���Ϣ
	sa0.show(); cout << endl;
	sa1.show(); cout << endl;
	return 0;
}*/

/*int Flow(int** M, int n, int bestx[])
{
	int ub = 32767;
	Flowshop X;
	X.x = new int[n + 1]; //��ǰ����
	X.f2 = new int[n + l];
	X.M = M; //����ҵ���账��ʱ��
	X.n = n; //��ҵ�� 
	X.bestx = bestx; //��ǰ���ŵ���
	X.bestf = ub; //��ǰ���ŵ���ʱ��
	X.fl = 0; //����2��ɴ���ʱ��
	X.f = 0; //����1��ɴ���ʱ��
	for (int i = 0; i <= n; i++)
		X.f2[i] = 0, X.x[i] = i;
	X.Backtrack(1);
	delete[] X.x;
	delete[] X.f2;
	return X.bestf;
}
void Flowshop::Backtrack(int i)
{
	if (i > n) {
		for (int j = 1; j <= n; j++)
			bestx[j] = x[j];
		bestf = f;
	}
	else
		for (int j = i; j < = n; j++) {
			fl += M[x[j]][1];
			f2[i] = ((f2[i - 1] > fl) ? f2[i - 1] : fl)
				+ M[x[j]][2];
			f += f2[i];
			if (f < bestf) {
				Swap(x[i], x[j]);
				Backtrack(i + 1);
				Swap(x[i], x[j]);
			}
			fl - = M[x[j]][1];
			f - = f2[i];
		}
}
*/

/*#include "account.h"
#include <iostream>
using namespace std;
int main() {
	Date date(2008, 11, 1); //��ʼ����
	//���������˻�
	SavingsAccount sa1(date, "S3755217", 0.015);
	SavingsAccount sa2(date, "02342342", 0.015);
	CreditAccount ca(date, "C5392394", 10000, 0.0005, 50);
	Account* accounts[] = { &sa1, &sa2, &ca };
	const int n = sizeof(accounts) / sizeof(Account*);//�˻�����
	cout << "(d)deposit (w)withdraw (s)show (c)change day (n)nextmonth(e)exit" << endl;
		char cmd;
	do {
		//��ʾ���ں��ܽ��
		date.show();
		cout << "\tTotal: " << Account::getTotal() << "\tcommand> ";
		int index, day;
		double amount;
		string desc;
		cin >> cmd;
		switch (cmd) {
		case 'd': //�����ֽ�
			cin >> index >> amount;
			getline(cin, desc);
			accounts[index]-> deposit(date, amount, desc);
			break;
		case 'w': //ȡ���ֽ�
			cin >> index >> amount;
			getline(cin, desc);
			accounts[index]-> withdraw(date, amount, desc);
			break;
		case 's': //��ѯ���˻���Ϣ
			for (int i = 0; i < n; i++) {
				cout << "[" << i << "] ";
				accounts[i]-> show();
				cout << endl;
			}
			break;
		case 'c': //�ı�����
			cin >> day;
			if (day < date.getDay())
				cout << "You cannot specify a previous day";
			else if (day > date.getMaxDay())
				cout << "Invalid day";
			else
				date = Date(date.getYear(), date.getMonth(),
					day);
			break;
		case 'n': //�����¸���
			if (date.getMonth() == 12)
				date = Date(date.getYear() + 1, 1, 1);
			else
				date = Date(date.getYear(),
					date.getMonth() + 1, 1);
			for (int i = 0; i < n; i++)
				accounts[i] -> settle(date);
			break;
		}
	} while (cmd != 'e');
	return 0;
}*/