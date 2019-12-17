#include<iostream>
#include<vector>
using namespace std;

/*struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}

};*/
/*class Solution {
public:
	void swap(ListNode* head)
	{
		ListNode* temp;
		if (head->next != NULL)
		{
			temp = head;
			head->next = head->next->next;
			head = head->next;
			head->next = temp;
		}
		if (head->next != NULL)
			swap(head);
	}
	ListNode* swapPairs(ListNode* head) {
		swap(head);
		return head;
	}
};*/

/*int main()
{
	ListNode* head = new ListNode*;
	head->val = 0;
	head->next->val = 1;
	head->next->next->val = 2;
	head->next->next->next->val = 3;
	Solution A;
	A.swapPairs(head);
	cout << &head;
	return 0;
}*/

class MyCircularQueue {
public:
	int* p, * q;
	int *start;
	int size;
	/** Initialize your data structure here. Set the size of the queue to be k. */
	MyCircularQueue(int k) {
		size = k;
		start = new int[size];
		for (int i = 0; i < size; i++)
		{
			start[i] = -1;
		}
		p = q = start;
	}

	/** Insert an element into the circular queue. Return true if the operation is successful. */
	bool enQueue(int value) {
		if (!isFull())
		{
			*q = value;
			if (q - start == size - 1)
				q = start;
			else
				q++;
			return true;
		}
		return false;
	}

	/** Delete an element from the circular queue. Return true if the operation is successful. */
	bool deQueue() {
		if (!isEmpty())
		{
			*p = -1;
			if (p - start == size - 1)
				p = start;
			else
				p++;
			return true;
		}
		return false;
	}

	/** Get the front item from the queue. */
	int Front() {
		if (isEmpty())
			return -1;
		return *p;
	}

	/** Get the last item from the queue. */
	int Rear() {
		if (isEmpty())
			return -1;
		if (q == start)
			return *(start + size - 1);
		return *(q-1);
	}

	/** Checks whether the circular queue is empty or not. */
	bool isEmpty() {
		if (*p != -1)
			return false;
		return true;
	}

	/** Checks whether the circular queue is full or not. */
	bool isFull() {
		if (p == q && *p != -1)
			return true;
		return false;
	}
};
/*int main()
{
	MyCircularQueue* obj = new MyCircularQueue(3);
	bool param_1 = obj->enQueue(1);
	bool param_2 = obj->enQueue(2);
	bool param_3 = obj->enQueue(3);
	bool param_4 = obj->enQueue(4);
	int param_5 = obj->Rear();
	int param_6 = obj->isFull();
	bool param_7 = obj->deQueue();
	bool param_8 = obj->enQueue(5);
	int param_9 = obj->Rear();
	return 0;
}*/


#include <queue>
/*class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		int size = grid.size();
		if (size == 0)
			return 0;
		queue<int> q1;
		vector<char>v1;
		v1 = grid[0];
		int sizev = v1.size();
		int i, j;
		int num = 0;
		bool flag = false;
		if (sizev == 0)
			return 0;
		for (i = 0, j = 0; i < size&& j < sizev; num++)
		{
			i = 0, j = 0;
			while (grid[i][j] != '1')
			{
				if (j < sizev-1)
				{
					j++;
				}
				else
				{
					j = 0;
					i++;
				}
				if (i == size)
				{
					flag = true;
					break;
				}
			}
			if (flag)
				break;
			q1.push(i);
			q1.push(j);
			grid[i][j] = '2';
			do
			{
				i = q1.front();
				q1.pop();
				j = q1.front();
				q1.pop();
				if (i < size && j < sizev - 1 && grid[i][j + 1] == '1')
				{
					q1.push(i);
					q1.push(j+1);
					grid[i][j+1] = '2';
				}
				if (i < size - 1 && j < sizev && grid[i + 1][j] == '1')
				{
					q1.push(i+1);
					q1.push(j);
					grid[i+1][j] = '2';
				}
				if (i > 0 && j >= 0 && grid[i - 1][j] == '1')
				{
					//i--;
					//q1.push(grid[i][j]);
					q1.push(i-1);
					q1.push(j);
					grid[i-1][j] = '2';
				}
				if (i >= 0 && j > 0 && grid[i][j - 1] == '1')
				{
					//j--;
					//q1.push(grid[i][j]);
					q1.push(i);
					q1.push(j-1);
					grid[i][j-1] = '2';
				}
			
			} while (q1.size() != 0);
		}
		return num;
	}
};
int main()
{
	Solution A;
	//vector <char> a[4] = { {'1', '1', '1', '1', '0' },{'1', '1', '0', '1', '0'} ,
	//{'1', '1', '0', '0', '0'},{'0', '0', '0', '0', '0'} };
	//vector <char> a[3] = { {'1', '1', '1' } ,{'1', '0', '1'},{'1', '1', '1' } };
	vector <char> a[20] = { {'1','1','1','1','1','0','1','1','1','1','1','1','1','1','1','0','1','0','1','1'},
{'0','1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','0'},
{'1','0','1','1','1','0','0','1','1','0','1','1','1','1','1','1','1','1','1','1'},
{'1','1','1','1','0','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},
{'1','0','0','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},
{'1','0','1','1','1','1','1','1','0','1','1','1','0','1','1','1','0','1','1','1'},
{'0','1','1','1','1','1','1','1','1','1','1','1','0','1','1','0','1','1','1','1'},
{'1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','0','1','1'},
{'1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','1','1','1','1'},
{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},
{'0','1','1','1','1','1','1','1','0','1','1','1','1','1','1','1','1','1','1','1'},
{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},
{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},
{'1','1','1','1','1','0','1','1','1','1','1','1','1','0','1','1','1','1','1','1'},
{'1','0','1','1','1','1','1','0','1','1','1','0','1','1','1','1','0','1','1','1'},
{'1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','1','0'},
{'1','1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','0','0'},
{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},
{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},
{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'} };
	vector<vector<char>> qestion(a,a+20);
	int answer;
	answer = A.numIslands(qestion);
	return 0;
}*/
/*void heapsort(int nums[], int size)
{
	int i = 1;
	int left = 2 * i;
	int right = 2 * i - 1;
	int parent = i / 2;
	while (nums[left] < nums[i])
	{
		swap(nums[left], nums[i]);
		if(nums[i]<nums[parent])
			swap(nums[parent], nums[i]);
		if(nums[left]>nums[right])
			swap(nums[left], nums[right]);
	}
	while(nums[right]<nums[i])

}*/
/*#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	double a, b, c, x1, x2, m;
	x1 = 0;
	x2 = 0;
	cout << "方程ax^2+bx+c=0的a,b,c: " << endl;
	cin >> a >> b >> c;
	m = b * b - 4 * a * c;
	if (a == 0)
		cout << "这是一个一元一次方程" << endl;
	else
	{
		if (m > 0)
		{
			x1 = (-b - sqrt(m)) / (2 * a);
			x2 = (-b + sqrt(m)) / (2 * a);
			cout << "方程的解x1=" << x1 << "		x2=" << x2 << endl;
		}
		else if (m == 0)
		{
			x1 = x2 = -b / (2 * a);
			cout << "方程有两个相等的实根x1=x2=" << x1 << endl;
		}
		else
		{
			double s, t;
			s = -b / (2 * a);
			t = sqrt(-m) / (2 * a);
			cout << "方程有两个复数根:" << endl<< "x1=" << s << "-" << t << "i" << endl;
			cout << "x2=" << s << "+" << t << "i";
		}
	}
	return 0;
}
*/
/*class Solution {
public:
	int getMoneyAmount(int n) {
		int count = 1;
		int num = n - 1;
		int money = 0;
		if (n == 1)
			return 0;
		else if (n == 2)
			return 1;
		else {
			while ((num - 2 + num % 2) * (num / 2) >= n - 1)
			{
				money += num;
				count++;
				num -= count;
			}
			while (count < 3)
			{
				money += num;
				count++;
				num -= count;
			}
		}
		return money;
	}
};
int main()
{
	Solution a;
	int b=a.getMoneyAmount(1);
	cout << b << endl;
	b = a.getMoneyAmount(2);
	cout << b << endl;
	b = a.getMoneyAmount(3);
	cout << b << endl;
	b = a.getMoneyAmount(4);
	cout << b << endl;
	b = a.getMoneyAmount(7);
	cout << b << endl;
	b = a.getMoneyAmount(14);
	cout << b << endl;
	return 0;
}*/
/*class Solution {
public:
	//查重
	bool repeat(vector<string>& deadends, string& target)
	{
		for (int i = 0; i < deadends.size(); i++)
		{
			if (deadends[i] == target)
				return true;
		}
		return false;
	}
	//减法移动
	void move1(string& target, int j)
	{
		if (target[j] > '0')
		{
			target[j]--;
		}
		else
		{
			target[j] = '9';
		}

	}
	//加法移动
	void move2(string& target, int j)
	{
		if (target[j] < '9')
		{
			target[j]++;
		}
		else
		{
			target[j] = '0';
		}
	}
	int openLock(vector<string>& deadends, string target) {

		int size = deadends.size();
		int num = 0;
		int i = 0;
		bool flag[4] = { false,false,false,false };
		while (i < 4)
		{
			if (target[i] == '0')
			{
				flag[i] = true;
				i++;
			}
			else if (target[i] < '5')
			{
				int j = i;
				while (flag[i] == false)
				{
					if (target[i] == '0')
						flag[i] = true;
					else {
						move1(target, j);
						num++;
						if (repeat(deadends, target))
						{
							move2(target, j);
							num--;
							j++;
						}
						if (j > 3)
							j = i;
					}
				}
				i++;
			}
			else
				break;
		}
		if (target == "0000")
			return num;
		i = 0;
		num = -num;
		while (i < 4)
		{
			if (target[i] == '0')
				i++;
			move2(target, i);
			num++;
			if (repeat(deadends, target))
			{
				move1(target, i);
				num--;
				i++;
			}
		}
		if (target == "0000")
			return num;
		return -1;
	}
};*/
/*#include <xhash>
#include <string>
class Solution {
public:
	//查重
	bool hash[10000] = { 0 };
	bool repeat(string target)
	{
		if (hash[stoi(target, 0, 10)] == 1)
			return true;
		return false;
	}
	//减法移动
	string change1(string target, int j)
	{
		if (target[j] > '0')
		{
			target[j]--;
		}
		else
		{
			target[j] = '9';
		}
		return target;
	}
	//加法移动
	string change2(string target, int j)
	{
		if (target[j] < '9')
		{
			target[j]++;
		}
		else
		{
			target[j] = '0';
		}
		return target;
	}
	int openLock(vector<string>& deadends, string target) {
		for (int i = 0; i < deadends.size(); i++)
		{
			hash[stoi(deadends[i], 0, 10)] = 1;
		}
		int num = 0;
		int i = 0;
		string init = "0000";
		queue<string> a;
		queue<int> cur;
		a.push(target);
		cur.push(0);
		if (init == target)
			return num;
		else if (repeat(init))
			return -1;
		//deadends.push_back(a.front());
		hash[stoi(a.front(), 0, 10)] = 1;
		while (a.front() != "0000")
		{
			num=cur.front()+1;
			for (i = 0; i < 4; i++)
			{
				string temp = a.front();
				string temp1 = change1(temp, i);
				string temp2 = change2(temp, i);
				if (!repeat(temp1))
				{
					a.push(temp1);
					hash[stoi(a.front(), 0, 10)] = 1;
					//deadends.push_back(temp1);
					cur.push(num);
				}
				if (!repeat(temp2))
				{
					a.push(temp2);
					hash[stoi(a.front(), 0, 10)] = 1;
					//deadends.push_back(temp2);
					cur.push(num);
				}
			}
			a.pop();
			cur.pop();
			if (a.empty())
				return -1;
			if (cur.front() > 36)
				return -1;
		}
		return cur.front();
	}
};
int main()
{
	//string a[5] = { "0201", "0101", "0102", "1212", "2002" };
	string a[10] = { "1131", "1303", "3113", "0132", "1301", "1303", "2200", "0232", "0020", "2223" };
	vector<string> deadends(a, a+10);
	Solution A;
	//string target = "0202";
	string target = "3312";
	cout << A.openLock(deadends, target);
	return 0;
}*/
//水仙花数
/*#include <cmath>	
bool find(int n)
{
	int i, j, k;
	i = n / 100;
	j = (n % 100) / 10;
	k = n % 10;
	if (pow(i, 3) + pow(j, 3) + pow(k, 3) == n)
		return true;
	return false;
}

int main()
{
	int i = 100;
	int count = 0;
	for (i; i < 1000; i++)
	{
		if (find(i))
		{
			count++;
			cout << count<<" : "<<i << endl;
		}	
	}
	return 0;
}*/