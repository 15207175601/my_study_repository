#include <iostream>
#include "stock10.h"
using namespace std;

Stock::Stock()
{
	cout << "Default constructor called\n";
	company = "no name";
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}

Stock::Stock(const string &co, long n, double pr)
{
	cout << "constructor using " << co << " called\n";
	company = co;
	if (n < 0)
	{
		cout << "number of shares can't be negative; "
			<< company << " shares set to 0.";
		shares = 0;
	}
	else
		shares = n;
	share_val = pr;
	set_tot();
}

Stock::~Stock()
{
	cout << "bye, " << company << "!\n";
}

void Stock::buy(long num, double price)
{
	if (num < 0)
	{
		cout << "number of shares purchased can't be negative. "
			<< "transaction is aborted.\n";
	}
	else
	{
		shares += num;
		share_val = price;
		set_tot();
	}
}

void Stock::sell(long num, double price)
{
	if (num < 0)
	{
		cout << "number of shares sold can't be negative. "
			<< "transaction is aborted.\n";
	}
	else if (shares < num)
	{
		cout << "number of shares can't be negative. "
			<< "transaction is aborted.\n";
	}
	else
	{
		shares -= num;
		share_val = price;
		set_tot();
	}
}

void Stock::update(double price)
{
	share_val = price;
	set_tot();
}

void Stock::show() const
{
	ios_base::fmtflags orig =
		cout.setf(ios_base::fixed, ios_base::floatfield);
	streamsize prec = cout.precision(3);

	cout << "company: " << company
		<< "  shares: " << shares << "\n";
	cout << "  share price: $" << share_val;
	cout.precision(2);
	cout << "  total worth: $" << total_val << '\n';
	cout.setf(orig, ios_base::floatfield);
	cout.precision(prec);
}

const Stock &Stock::topval(const Stock &s)const
{
	if (s.total_val > total_val)
		return s;
	else
		return *this;
}