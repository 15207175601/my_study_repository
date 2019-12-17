#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


/*struct Queen {
	int n;
	int sum;
	int *x;
	void Backtrack(int n);
	bool Place(int k);
};

int intnQueen(int n)
{
	Queen X;//初始化X    
	X.n = n;//皇后个数
	X.sum = 0;	//解的个数
	int* p = new int[n + 1];
	for (int i = 0;i <= n;i++)
		p[i] = 0;
	X.x = p;
	X.Backtrack(1);
	delete []p;
	return X.sum;
}
bool Queen::Place(int k)
{
	for (int j = 1; j < k; j++)
		if ((abs(k - j) == abs(x[j] - x[k]))
			|| (x[j] == x[k])) return false;
	return true;
}

void Queen::Backtrack(int t)
{
	if (t > n)
	{
		sum++;
		printf("end.\n",n);
	}

	else
	{
		for (int i = 1; i <= n; i++) {
			int z = 0;
			x[t] = i;
			if (Place(t))
			{
				printf("%d:%i, ", t,i);
				Backtrack(t + 1);
			}
		}
	}
}

int main(void)
{
	int n = 5;
	int q;
	printf("if 'end' is shown, forback %d array is the ansewer.(if missing number,select missing number from prior array array)\n", n);
	q=intnQueen(n);
	printf("\nthe total ways to position queen: %d", q);
	return 0;
}
*/
//n queens problem.


/*void IterativeBacktrack(void)
{
	int t = 1;
	while (t > 0) {
		if (f(n, t) <= g(n, t))  //对剩下子树处理
			for (int i = f(n, t); i <= g(n, t); i++)
			{
				x[t] = h(i);
				if (Constraint(t) && Bound(t)) {
					if (Solution(t)) Output(x);
					else t++;
				}
			} //i=f(n,t)-1,进入下一结点
		else t--; //所有剩下子树处理完毕
	}
}
const int n = 3;
int W[n] = { 20,15,15 };
int P[n] = { 40,25,25 };
int C = 30;
bool x[n + 1];
bool a[n];
int value = 0;
int valueup = 0;
bool Constraint(int t)
{
	int sum=0;
	for (int i = 1; i <= t; i++)
		sum += W[i-1]*x[i];
	if (sum <= C)
		return 1;
	else
		return 0;
}
bool Bound(int t)
{
	int sum=0;
	for (int i = 1; i <= t; i++)
		sum += P[i-1] * x[i];
	value = sum;
	return 1;
}
int f(int n,int t)
{
	return 2*t;//
}
int g(int n, int t)
{
	return 2 * t + 1;//
}
bool h(int i)
{
	if (i % 2 == 0)
		return 1;
	else
		return 0;
}
void Output(bool p[])
{
	if (value > valueup)
	{
		valueup = value;
		for (int i = 0; i < n; i++)
		{
			a[i] = x[i + 1];
		}
	}
}
void Backtrack(int t)
{
	if (t > n) Output(x);
	else   // f(n,t): leftChild; g(n,t): rightChild
		for (int i = f(n, t); i <= g(n, t); i++)
		{
			x[t] = h(i);   //Value for current child
			if (Constraint(t) && Bound(t))
				Backtrack(t + 1);
		}
}

int main()
{
	Backtrack(1);
	for (int i = 0; i < n; i++)
	{
		printf("%d\t", a[i]);
	}
	printf("value = %d", valueup);
	return 0;
}*/
//0-1backpack

/*class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> subs;
		for (int i = 0; i < nums.size(); i++)
		{
			subs.push_back(target - nums[i]);
		}
		for (int i = 0; i < nums.size(); i++)
			for (int j = nums.size() - 1; j > i; j--)
			{
				if (nums[i] == subs[j])
					return { i,j };
			}
		return { 0 };
	}
};*/
/*class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> subs;
		for (int i = 0; i < nums.size(); i++)
		{
			subs.push_back(target - nums[i]);
			for (int j = nums.size() - 1; j > i; j--)
			{
				if (nums[j] == subs[i])
					return { i,j };
			}
		}
		return { 0 };
	}
};*/
/*class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		for (int i = 0; i < nums.size(); i++)
		{
			int a = target - nums[i];
			for (int j = nums.size() - 1; j > i; j--)
			{
				if (nums[j] == a)
					return { i,j };
			}

		}
		return { 0 };
	}
};*/
/*class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> a = {};
		for (int i = 0; i < nums.size(); i++)
		{
			for (int j = i + 1; j < nums.size(); j++)
			{
				for (int k = j + 1; k < nums.size(); k++)
				{
					if (nums[i] + nums[j] + nums[k] == 0)
					{
						a.push_back({ nums[i],nums[j],nums[k] });
					}
				}
			}
		}
		return a;
	}
};
int main(void)
{
	vector<int> nums = { -1, 0, 1, 2, -1, -4 };
	Solution a1;
	vector <vector<int>> a2;
	a2=a1.threeSum(nums);
	for (int i = 0; i < a2.size(); i++)
	{
		for (int j=0;j<3;j++)
		std::cout <<a2[i][j] << endl;
	}
	return 0;
}*/
//二元数组
#include<queue>
/*int main()
{
	priority_queue <int> i;
	i.push(1);
	i.push(3);
	i.push(2);
	while (!i.empty())
	{
		printf("%d", i.top());
		i.pop();
	}

	return 0;

}*/

/*#include <queue>
struct node
{
	int x, y;
	bool operator < (const node& a) const
	{
		return x < a.x;
	}
}k;

priority_queue <node> q;
int main()
{
	k.x = 10, k.y = 100; q.push(k);
	k.x = 12, k.y = 60; q.push(k);
	k.x = 14, k.y = 40; q.push(k);
	k.x = 6, k.y = 80; q.push(k);
	k.x = 8, k.y = 20; q.push(k);
	while (!q.empty())
	{
		node m = q.top(); q.pop();
		printf("(%d,%d) ", m.x, m.y);
	}
}*/



 //* Definition for singly-linked list.
  /*struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* ans;
		static int b = 0;
		int a = b + l1->val + l2->val;
		b = a / 10;
		if (b == 1)
		{
			ans->next->val = a / 10;
		}
		if(ans!=NULL)
		ans->val=a % 10;
		while (l1->next != NULL)
		{
			addTwoNumbers(l1->next, l2->next);
		}
		return ans;
	}
};

class Solution {
public:
	int reverse(int x) {
		vector <int> p;
		bool flag;
		flag = x > 0 ? 1 : 0;
		while (x != 0)
		{
			int b;
			b = x % 10;
			x /= 10;
			p.push_back(b);
		}
		for (int i = 0; i < p.size(); i++)
		{
			int a = p[i];
			if (2147483647 / 10 > x)
				x = x * 10 + a;
			else
				exit;
		}
		return flag == 1 ? x : -x;
	}
};

class Solution {
public:
	int game(vector<int>& guess, vector<int>& answer) {
		int num = 0;
		for (int i = 0; i < 3; i++)
		{
			if (guess[i] == answer[i])
				num++;
		}
		return num;
	}
};

class Solution {
public:
	vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
		vector <int>ans;
		int temp,sumA,sumB,sub;
		sumA = sumB = 0;
		for (int i = 0; i < A.size(); i++)
			sumA += A[i];
		for (int j = 0; j < B.size(); j++)
			sumB += B[j];
		sub = sumA - sumB;
		for(int i=0;i<A.size();i++)
			for (int j = 0; j < B.size(); j++)
			{
				if (A[i] - B[j] == sub / 2)
				{
					ans.push_back(A[i]);
					ans.push_back(B[j]);
					return ans;
				}
			}
	}
};
*/
/*class Solution {
public:
	int findUnsortedSubarray(vector<int>& nums) {
		vector <int> a(nums);
		int min, num=0;
		min = a.back();
		a.pop_back();
		if (a.size() > 0 && min > a.back())
			num++;
		else if (a.size() == 0)
			return 0;
		while (a.size() > 0 && min > a.back())
		{
			min = a.back();
			a.pop_back();
			num++;
		}
		return nums.size() - num;
	}
};
int main()
{
	vector <int> nums = { 1,2,3,3,3 };
	Solution A;
	cout << A.findUnsortedSubarray(nums);
	return 0;
}*/