/*#include<iostream>
void simple();
void cheers(int n);

int main()
{
	using namespace std;
	cout << "main() will call the simple() function:\n";
	simple();
	cout << "main() is finished with the simple() function.\n";
	cheers(10);
	// cin.get();
	return 0;
}

void simple()
{
	using namespace std;
	cout << "i'm but a simple function.\n";
}

void cheers(int n)
{
	for (int i = 0; i < n; i++)
		std::cout << "cheers! ";
	std::cout << std::endl;
}*/

/*#include<iostream>
int fact(int val);
int main()
{
	using namespace std;
	int j = fact(5);
	cout << "5! is " << j << endl;
	return 0;
}
int fact(int val)
{
	int ret = 1;
	while (val > 1)
		ret *= val--;
	return ret;
}
int bigger(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}*/
/*#include<iostream>
void cheers(int);
double cube(double x);
int main()
{
	using namespace std;
	cheers(5);
	cout << "give me a number: ";
	double side;
	cin >> side;
	double volume = cube(side);
	cout << "A" << side << "-foot cube has a volume of ";
	cout << volume << " cubic feet.\n";
	cheers(cube(2));
	return 0;
}
void cheers(int n)
{
	for (int i = 0; i < n; i++)
		std::cout << "cheers! ";
	std::cout << std::endl;
}

double cube(double x)
{
	return x * x*x;
}*/
#include<iostream>
using namespace std;
/*void n_chars(char, int);
int main()
{
	int times;
	char ch;
	
	cout << "enter a character: ";
	cin >> ch;
	while (ch != 'q')
	{
		cout << "enter an integer: ";
		cin >> times;
		n_chars(ch, times);
		cout << "\nEnter another character or press the"
			" q-key to quit: ";
		cin >> ch;
	}
	cout << "the value of times is " << times << ".\n";
	cout << "bye\n";
	return 0;
}

void n_chars(char c, int n)
{
	while (n-- > 0)
		cout << c;
}*/
/*long double cr(int, int);
int main()
{
	int numbers, picks;
	cout << "enter numbers: ";
	cin >> numbers;
	cout << "enter picks: ";
	cin >> picks;
	cout << "the answer is :" << cr(numbers, picks) << endl;
	return 0;
}*/
/*const int ArSize = 8;
int sum_arr(int arr[], int n);
int main()
{
	int cookies[ArSize] = { 1,2,4,8,16,32,64,128 };

	int sum = sum_arr(cookies, ArSize);
	cout << "Total cookies eaten: " << sum << "\n";
	return 0;
}
int sum_arr(int arr[], int n)
{
	int total = 0;
	for (int i = 0; i < n; i++)
		total = total + arr[i];
	return total;
}*/
/*const int ArSize = 8;
int sum_arr(int arr[], int n);
int main()
{
	int cookies[ArSize] = { 1,2,4,8,16,32,64,128 };
	cout << cookies << " = array address, ";
	cout << sizeof cookies << " = sizeof cookies\n";
	int sum = sum_arr(cookies, ArSize);
	cout << "total cookies eaten: " << sum << endl;
	sum = sum_arr(cookies, 3);
	cout << "first three eaters ate " << sum << " cookies.\n";
	sum = sum_arr(cookies + 4, 4);
	cout << "last four eaters ate " << sum << " cookies.\n";
	return 0;
}

int sum_arr(int arr[], int n)
{
	int total = 0;
	cout << arr << " = arr, ";
	for (int i = 0; i < n; i++)
		total = total + arr[i];
	return total;
}*/
/*const int Max = 5;
int fill_array(double ar[], int limit);
void show_array(const double ar[], int n);
void revalue(double r, double ar[], int n);

int main()
{
	using namespace std;
	double properties[Max];

	int size = fill_array(properties, Max);
	show_array(properties, size);
	if (size > 0)
	{
		cout << "enter revaluation factor: ";
		double factor;
		while (!(cin >> factor))
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "bad input;please enter a number: ";
		}
		revalue(factor, properties, size);
		show_array(properties, size);
	}
	cout << "done.\n";
	cin.get();
	cin.get();
	return 0;
}*/
/*const int ArSize = 8;
int sum_arr(const int * begin, const int * end);
int main()
{
	using namespace std;
	int cookies[ArSize] = { 1,2,4,8,16,32,64,128 };

	int sum = sum_arr(cookies, cookies + ArSize);
	cout << "total cookies eaten: " << sum << endl;
	sum= sum_arr(cookies, cookies + 3);
	cout << "first three eaters ate " << sum << " cookies.\n";
	sum = sum_arr(cookies + 4, cookies + 8);
	cout << "last four eaters ate " << sum << " cookies.\n";
	return 0;
}

int sum_arr(const int * begin,const int * end)
{
	const int * pt;
	int total = 0;


	for (pt=begin; pt!=end; pt++)
		total = total + *pt;
	return total;
}*/
//类
/*#include "stock10.h"
int main()
{
	{
		cout << "using constrctors to create new objects\n";
		Stock stock1("nanosmart", 12, 20.0);
		stock1.show();
		Stock stock2 = Stock("Boffo Objects", 2, 2.0);
		stock2.show();

		cout << "assigning stock1 to stock2:\n";
		stock2 = stock1;
		cout << "listing stock1 and stock2:\n";
		stock1.show();
		stock2.show();

		cout << "using s constuctor to reset an object\n";
		stock1 = Stock("Nifty Foods", 10, 50.0);
		cout << "revised stock1:\n";
		stock1.show();
		cout << "done\n";
	}
	return 0;
}*/
/*#include "stock10.h"

const int STKS = 4;
int main()
{
	Stock stocks[STKS] = {
		Stock("nanosmart",12,20.0),
		Stock("boffo objects",200,2.0),
		Stock("monolithic objects",130,3.25),
		Stock("fleep enterprises",60,6.5)
	};
	cout << "Stock holdings:\n";
	int st;
	for (st = 0; st < STKS; st++)
		stocks[st].show();
	const Stock * top = &stocks[0];
	for (st = 1; st < STKS; st++)
		top = &top->topval(stocks[st]);
	cout << "\nmost valuable holding:\n";
	top->show();
	return 0;
}
*/
/*int* f()
{
	int i = 0;
	return &i;
}
int* g()
{
	int i = 1;
	return &i;
}
int main()
{
	int *p = f();
	int *q = g();
	int x;
	x = *p + *q;
	cout << x;
	
}*/
/*#include <cctype>
#include"stack.h"


int main()
{
	Stack st;
	char ch;
	unsigned long po;
	cout << "please enter A to add a purchase order.\n"
		<< "P to process a PO, or Q to quit.\n";
	while (cin >> ch && toupper(ch) != 'Q')
	{
		while (cin.get() != '\n')
			continue;
		if (!isalpha(ch))
		{
			cout << '\a';
			continue;
		}
		switch (ch)
		{
		case'A':
		case'a':cout << "enter a PO number to add: ";
			cin >> po;
			if (st.isfull())
				cout << "stack already full\n";
			else
				st.push(po);
			break;
		case'P':
		case'p':
			if (st.isempty())
				cout << "stack already empty\n";
			else
			{
				st.pop(po);
				cout << "PO #" << po << "poped\n";
			}
			break;
		}
		cout << "please enter A to add a purchase order,\n"
			<< "P to process a PO, or Q to quit.\n";
	}
	cout << "bye\n";
	return 0;
}*/
/*//#include"mytime0.h"
#include "mytime1.h"

int main()
{
	Time planning;
	Time coding(2, 40);
	Time fixing(5, 55);
	Time total;

	cout << "planning time= ";
	planning.show();
	cout << endl;

	cout << "coding time= ";
	coding.show();
	cout << endl;

	cout << "fixing time= ";
	fixing.show();
	cout << endl;

	//total = coding.Sum(fixing);
	total = coding + fixing;
	cout << "coding + fixing = ";
	total.show();
	cout << endl;

	Time morefixing(3, 28);
	cout << "more fixing time = ";
	morefixing.show();
	cout << endl;
	total = morefixing.operator+(total);
	cout << "morefixing.operator+(total) = ";
	total.show();
	cout << endl;

	return 0;
}*/
/*#include "mytime2.h"

int main()
{
	Time weeding(4, 35);
	Time waxing(2, 47);
	Time total;
	Time diff;
	Time adjusted;

	cout << "weeding time = ";
	weeding.show();
	cout << endl;

	cout << "waxing time = ";
	waxing.show();
	cout << endl;

	cout << "total work time = ";
	total = weeding + waxing;
	total.show();
	cout << endl;

	diff = weeding - waxing;
	cout << "weeding time - waxing time = ";
	diff.show();
	cout << endl;

	adjusted = total * 1.5;
	cout << "adjusted work time = ";
	adjusted.show();
	cout << endl;
	return 0;
}*/
/*#include "mytime3.h"

int main()
{
	Time aida(3, 35);
	Time tosca(2, 48);
	Time temp;

	cout << "Aida and Tosca:\n";
	cout << aida << "; " << tosca << endl;
	temp = aida + tosca;
	cout << "aida + tosca: " << temp << endl;
	temp = aida * 1.17;
	cout << "aida * 1.17: " << temp << endl;
	cout << "10.0 * tosca: " << 10.0*tosca << endl;

	return 0;
}*/
/*#include<cstdlib>
#include<ctime>
#include"vector.h"
using VECTOR::Vector;
int main()
{
	srand(time(0));
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;
	cout << "enter target distance (q to quit): ";
	while (cin >> target)
	{
		cout << "enter step length:";
		if (!(cin >> dstep))
			break;
		while(result.magval() < target)
		{
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			steps++;
		}
		cout << "After " << steps << " steps, the subject has the following lacation:" << endl;
		cout << result << endl;
		result.polar_mode();
		cout << " or\n" << result << endl;
		cout << "average outward distance per step= " << result.magval() / steps << endl;
		steps = 0;
		result.reset(0.0, 0.0);
		cout << "enter target distance (q to quit):";
	}
	cout << "bye!\n";
	cin.clear();
	while (cin.get() != '\n')
		continue;

	system("pause");

}*/
/*#include "stonewt.h"
void display(const Stonewt &st, int n);
int main()
{
	Stonewt incognito = 275;
	Stonewt wolfe(285.7);
	Stonewt taft(21, 8);

	cout << "the celebrity weighed ";
	incognito.show_stn();
	cout << "the detective weighed ";
	wolfe.show_stn();
	cout << "the president weighed ";
	taft.show_lbs();
	incognito = 276.8;
	taft = 325;
	cout << "after dinner,the celebrity weighed ";
	incognito.show_stn();
	cout<< "after dinner,the president weighed ";
	taft.show_lbs();
	display(taft, 2);
	cout << "the wrestler weighed even more.\n";
	display(422, 2);
	cout << "no stone left unearned\n";
	return 0;
}

void display(const Stonewt & st, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "wow! ";
		st.show_stn();
	}
}*/
/*int func1(int x)
{
	return x * x;
}
int func2(int x, int y)
{
	return func1(x) + func1(y);
}

int main()
{
	int a, b;
	cout << "please enter two integer: ";
	cin >> a >> b;
	cout << "the sum of the two number square is:" << func2(a, b);
	return 0;
}*/
/*int jiecheng(int n)
{
	int a, i;
	a = 1;
	if (0 == n)
		return 1;
	else
		for (i = 0; i < n+i; i++)
		{
			a *= n;
			n--;
		}
		return a;
}

int fac(int n)
{
	if (n == 0)
		return 1;
	else
	{
		int f = fac(n - 1)*n;
		return  f;
	}
}

int main()
{
	int n;
	cout << "please enter a interger ( not negative.): ";
	cin >> n;
	cout << "the jiecheng of " << n << " is " << jiecheng(n) << endl;
	cout << "the jiecheng of " << n << " is " << fac(n) << endl;
	return 0;
}*/
/*int C(int n,int k)
{
	if (1==k)
		return n;
	else if (0==k || n == k)
		return 1;
	return C(n - 1, k) + C(n - 1, k - 1);
}

int main()
{
	int n, k;
	cout << "please enter two integer: ";
	cin >> n >> k;
	cout << "the answer is : " << C(n, k) << endl;
	return 0;
}*/
/*void han(char A, char B, char C,int n)
{
	if(1==n)
	{
		cout << A << " -> " << C << endl;
		return;
	}
	han(A, C, B, n - 1);
	cout << A << " -> " << C << endl;
	han(B, A, C, n - 1);
}

int main()
{
	int n;
	cout << "enter a number:";
	cin >> n;
	han('A', 'B', 'C', n);
	return 0;
}*/



/*#include <opencv2/opencv.hpp>
#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace std;
using namespace cv;*/

/*int main()
{
	Mat image = imread("D:\\1.png");  //存放自己图像的路径 
	namedWindow("saa");
	imshow("显示图像", image);
	waitKey(0);
	return 0;
}*/

/*#include "swimmingpool.h"

int main()
{
	double r,c,C;
	cout << "enter the radio of the pool: ";
	cin >> r;
	swimmingpool pool;
	swimmingpool::swimmingpool(r);
	c = pool.c();
	C = pool.C();
	cout << "it cost $ " << P_PRICE *c + Z_PRICE * C << endl;
	return 0;

}*/