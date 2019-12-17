
//遗传算法解决TSP问题,35s
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include<vector>
#include<algorithm>

using namespace std;
typedef long long LL;
const int times = 3000;//遗传代数
const int chrom = 34; //染色体长度
const int num = 380; //染色体数量
int pc = 80, pm = 6;
int tmp[num + 3];
double mp[chrom + 3][chrom + 3] = { 0 }; //图
int vis[chrom + 3], cur;
double fitness[num + 3], INF = 1e13;
vector<int>g[num + 3], neb[chrom + 3], nb[chrom + 3];
vector<int>debug[times + 3];
double debug2[times + 3];

struct node {
	double x, y;
}point[chrom + 3];
double dis(int u, int v) {
	double x = point[u].x - point[v].x;
	double y = point[u].y - point[v].y;
	return sqrt(x * x + y * y);
}
void init_map() {//初始化边的情况
	for (int i = 0; i < num; ++i) {
		//scanf_s("%lf%lf", &point[i].x, &point[i].y);
		//srand(time(0));
		//point[i].x = rand()%200;
		//srand(i);
		//point[i].y = rand()%200;
		static int j = 1;
		srand(i + j);
		point[i].x = rand() % 200;
		j++;
		srand(i + j);
		point[i].y = rand() % 200;
		j = j + i;
	}
	for (int i = 0; i < num; ++i) {
		for (int j = 0; j < num; ++j) {
			mp[i][j] = dis(i, j);
		}
	}
}
void encoding() {//对染色体编码
	vector<int>id;
	for (int i = 0; i < chrom; ++i) id.push_back(i);
	for (int i = 0; i < num; ++i) {
		random_shuffle(id.begin(), id.end());
		g[i] = id;
	}

}
double cal_distance(vector<int>x) {//计算染色体的距离
	double res = mp[x[0]][x[chrom - 1]];
	for (int i = 0; i < chrom - 1; ++i)
		res += mp[x[i]][x[i + 1]];
	return res;
}
void get_fitness() {//计算染色体的适应度
	for (int i = 0; i < num; ++i) {
		fitness[i] = INF / cal_distance(g[i]);
	}
}
bool cmp(int x, int y) {
	return fitness[x] > fitness[y];
}
void selection() {//选自算子
	for (int i = 0; i < num; ++i) tmp[i] = i;
	sort(tmp, tmp + num, cmp);//按适应度排序
	int L = (int)(num * 0.3);
	for (int i = L * 9 / 10; i; --i) {
		int x = rand() % L + L;
		int y = rand() % L;
		g[tmp[x]] = g[tmp[y]];
	}
}
vector<int> core(int flag, vector<int>neb[]) {
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < chrom; ++i) nb[i] = neb[i];
	vector<int>ans;
	vector<pair<double, int> >best;
	ans.push_back(g[flag][0]);
	for (int i = 0; i < chrom - 1; ++i) {
		int x = ans[i];
		best.clear();
		vis[x] = 1;
		for (int j = 0; j < nb[x].size(); ++j) {
			int y = nb[x][j];
			best.push_back({ mp[x][y], y });
			auto it = find(nb[y].begin(), nb[y].end(), x);
			if (it != nb[y].end()) {
				nb[y].erase(it);
			}
		}
		if (!best.empty()) {
			sort(best.begin(), best.end());
			ans.push_back(best[0].second);
		}
		else {
			double min_dis = 1e9;
			int min_id = 0;
			for (int j = 0; j < chrom; ++j) {
				if (!vis[j] && mp[x][j] < min_dis) {
					min_dis = mp[x][j];
					min_id = j;
				}
			}
			ans.push_back(min_id);
		}
	}
	return ans;
}
pair<double, int> get_best() {
	double min_dis = 1e9;
	int min_id = 0;
	for (int i = 0; i < num; ++i) {
		double x = cal_distance(g[i]);
		if (min_dis > x) {
			min_dis = x;
			min_id = i;
		}
	}
	return { min_dis,min_id };
}
void crosscover() {
	for (int i = 0; i < num / 2; ++i) {
		if ((rand() % 100 + 1) <= pc) {
			for (int j = 0; j < chrom; ++j) neb[j].clear();
			for (int j = 0; j < chrom; ++j) {
				neb[g[i][j]].push_back(g[i][(j + 1) % chrom]);
				neb[g[i][j]].push_back(g[i][(j - 1 + chrom) % chrom]);
				neb[g[num - i - 1][j]].push_back(g[num - i - 1][(j + 1) % chrom]);
				neb[g[num - i - 1][j]].push_back(g[num - i - 1][(j - 1 + chrom) % chrom]);
			}
			for (int j = 0; j < chrom; ++j) {
				sort(neb[j].begin(), neb[j].end());
				neb[j].erase(unique(neb[j].begin(), neb[j].end()), neb[j].end());
			}
			vector<int>tmp1 = core(i, neb);
			vector<int>tmp2 = core(num - i - 1, neb);
			vector<pair<double, vector<int> > >best;
			best.push_back({ cal_distance(g[i]), g[i] });
			best.push_back({ cal_distance(g[num - i - 1]), g[num - i - 1] });
			best.push_back({ cal_distance(tmp1), tmp1 });
			best.push_back({ cal_distance(tmp2), tmp2 });
			sort(best.begin(), best.end());
			g[i] = best[0].second;
			g[num - i - 1] = best[1].second;
		}
	}
}
void mutation() {
	int gai = pm;
	if (cur >= times * 3 / 4) gai = pm * 5;
	for (int i = 0; i < num; ++i) {
		if ((rand() % 100 + 1) <= gai) {
			int x = rand() % chrom, y = rand() % chrom;
			if (x > y) swap(x, y);
			for (int j = 0; x + j <= (x + y >> 1); ++j) {
				swap(g[i][x + j], g[i][y - j]);
			}
		}
	}
}
int main() {
	//freopen("a.txt", "r", stdin);
	//freopen("2.txt", "w", stdout);
	srand(time(0));
	init_map();
	encoding();
	for (int i = 0; i < times; ++i) {
		cur = i;
		get_fitness();
		selection();
		pair<double, int>it = get_best();
		debug[i] = g[it.second];
		debug2[i] = it.first;
		crosscover();
		mutation();
	}
	printf("%f\n", debug2[times - 1]);
	return 0;
}

/*class Solution {
public:
	int numJewelsInStones(string J, string S) {
		int nums=0;
		for (int i = 0; i < J.length(); i++)
		{
			char a = J[0];
			for (int j = 0; j < S.length(); j++)
			{
				if (a == S[j])
					nums++;
			}
		}
		return nums;
	}
};*/
class Solution {
public:
	bool isAnagram(string s, string t) {
		int a[26] = { 0 };
		int sl = s.length();
		int tl = t.length();
		if (sl != tl)
			return false;
		for (int i = 0; i < sl; i++)
		{
			if (s[i] >= 97 && s[i] <= 122)
			{
				int j = s[i] % 97;
				a[j]++;
			}
			else
			{
				return false;
			}
		}
		for (int i = 0; i < tl; i++)
		{
			if (t[i] >= 97 && t[i] <= 122)
			{
				int j = t[i] % 97;
				a[j]--;
				if (a[j] < 0)
					return false;
			}
			else
			{
				return false;
			}
		}
		return true;
	}
};

class Solution {
public:
	void reverseString(vector<char>& s) {
		if (s.size() > 0)
		{
			vector <char>::iterator p;
			vector <char>::iterator q;
			p = s.begin();
			q = s.end() - 1;
			while (p < q)
			{
				char temp = *p;
				*p = *q;
				*q = temp;
				p++;
				q--;
			}
		}
		
	}
};
class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		vector<int>::iterator p;
		vector<int>::iterator q;
		p = nums.begin();
		q = nums.end() - 1;
		while (p < q)
		{
			if (*q == 0)
			{
				q--;
			}
			if (*p == 0)
			{
				for (int i = 0; p + i < q; i++)
				{
					*(p + i) = *(p + 1 + i);
				}
				*q = 0;
				q--;
			}
			else
			{
				p++;
			}
		}
	}
};

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int f1, f2;
		f1 = 0;
		f2 = nums.size();
		while (f1 < f2)
		{
			if (nums[f2] == 0)
			{
				f2--;
			}
			if (nums[f1] == 0)
			{
				for (int i = 0; f1 + i < f2; i++)
				{
					nums[f1 + i] = nums[f1+1+i];
				}
				nums[f2] = 0;
				f2--;
			}
			else
			{
				f1++;
			}
		}
	}
};

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int min = 0;
		int max = nums.size() - 1;
		int flag = max / 2;
		while (nums[flag] != target&&flag!=min)
		{
			
		}
		return nums[flag] == target ? target : -1;
	}
};

class Solution {
public:
	int arrangeCoins(int n) {
		int sum = 0;
		int num = 0;
		for (int i = 1; i <= n - sum; i++)
		{
			sum += i;
			num++;
		}
		return num;
	}
};

class Solution {
public:

	// Encodes a URL to a shortened URL.
	string encode(string longUrl) {
		string ans;
		
	}

	// Decodes a shortened URL to its original URL.
	string decode(string shortUrl) {

	}
};

class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> a;
		vector<int> b;
		vector<int> c;
		a.push_back({});
		int size = nums.size();
		for (int i = 0; i < size; i++)
		{
			c[i] = 1;
			if (c[i] == 1)
			{
				
			}
		}

		
		
	}
};

class Solution {
public:
	void reverseString(vector<char>& s) {
		if (s.size() > 0)
		{
			auto p1 = s.begin();
			auto a = *p1;
			s.erase(p1);
			reverseString(s);
			s.push_back(a);
		}
	}
};
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
	
};
class Solution {
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
};

class Solution {
public:
	bool checkPossibility(vector<int>& nums) {
		int len = nums.size();
		int count = 0;
		if (len < 3)
		{
			return true;
		}
		if (nums[0] > nums[1])
		{
			nums[0] = nums[1];
			count++;
		}
		for (int i = 1; i < len - 1; i++)
		{
			if (nums[i] > nums[i + 1])
			{
				if (nums[i + 1] >= nums[i - 1])
				{
					nums[i] = nums[i + 1];
					count++;
				}
				else
				{
					nums[i + 1] = nums[i];
					count++;
				}
			}
		}
		if(count<2)
			return true;
		return false;
	}
};
#include <stdlib.h>
#include <queue>
/*class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		int size = grid.size();
		queue<char> q1;
		vector<char>v1;
		v1 = grid[0];
		int sizev = v1.size();
		int i, j;
		i = j = 0;
		int num = 0;
		while (grid[i][j] == '1')
		{
			if (j < sizev)
			{
				j++;
				break;
			}
			else
			{
				j = 0;
				i++;
				break;
			}
		}
		for(i=0,j=0;i<size,j<sizev;)
		q1.push(grid[i][j]);
		grid[i][j] = '2';
		do
		{
			if (i < size && j < sizev-1 && grid[i][j+1]=='1')
			{
				j++;
				q1.push(grid[i][j]);
				grid[i][j] = '2';
			}
			if (i < size-1 && j < sizev && grid[i+1][j] == '1')
			{
				i++;
				q1.push(grid[i][j]);
				grid[i][j] = '2';
			}
			q1.pop();
		} while (true);
	}
};*/
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
		for (i = 0, j = 0; i < size && j < sizev; num++)
		{
			i = 0, j = 0;
			while (grid[i][j] != '1')
			{
				if (j < sizev - 1)
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
					q1.push(j + 1);
					grid[i][j + 1] = '2';
				}
				if (i < size - 1 && j < sizev && grid[i + 1][j] == '1')
				{
					q1.push(i + 1);
					q1.push(j);
					grid[i + 1][j] = '2';
				}
				if (i > 0 && j >= 0 && grid[i - 1][j] == '1')
				{
					//i--;
					//q1.push(grid[i][j]);
					q1.push(i - 1);
					q1.push(j);
					grid[i - 1][j] = '2';
				}
				if (i >= 0 && j > 0 && grid[i][j - 1] == '1')
				{
					//j--;
					//q1.push(grid[i][j]);
					q1.push(i);
					q1.push(j - 1);
					grid[i][j - 1] = '2';
				}

			} while (q1.size() != 0);
		}
		return num;
	}
};*/
int guess(int num);

class Solution {
public:
	int guessNumber(int n) {
		int big = n;
		int small = 1;
		int num = (small + big) / 2;
		int i;
		bool flag = false;
		while (!flag)
		{
			i = guess(num);
			switch (i)
			{
			case 1:
				small = num;
				num = (small + big) / 2+1;
				break;
			case -1:
				big = num;
				num = (small + big) / 2;
				break;
			case 0:
				flag = true;
				break;
			}
		}
		return num;
	}
};

class Solution {
public:
	int getMoneyAmount(int n) {
		int big = n;
		int small = 1;
		int num = (small + big) / 2;
		int money = 0;
		if (n % 2 == 0)
		{
			while (num != small)
			{
				money += small;
				small = num;
				num = (small + big) / 2;
			}
		}
		else
		{

		}
			
				while (!flag)
				{
					i = guess(num);
					switch (i)
					{
					case 1:
						money += num;
						small = num;
						num = (small + big) / 2;
						break;
					case -1:
						money += num;
						big = num;
						num = (small + big) / 2;
						break;
					case 0:
						flag = true;
						break;
					}
				}
		return;
	}
};

class Solution {
public:
	//查重
	bool repeat(vector<string>& deadends, string &target)
	{
		for (int i = 0; i < deadends.size(); i++)
		{
			if (deadends[i] == target)
				return true;
		}
		return false;
	}
	//减法移动
	void move1(string &target,int j)
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
		while (i < 4 && target[i] != '0')
		{
			if (target[i] < '5')
			{
				move1(target, i);
				num++;
				if (repeat(deadends, target))
				{
					move2(target, i);
					num--;
					i++;
				}
			}
			else
				break;
		}
		if (target == "0000")
			return num;
		i = 0;
		num = -num;
		while (i < 4 && target[i] != '0')
		{
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
};

#include<queue>
class Solution {
public:
	//查重
	bool repeat(vector<string>& deadends, string target)
	{
		for (int i = 0; i < deadends.size(); i++)
		{
			if (deadends[i] == target)
				return true;
		}
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

		int size = deadends.size();
		int num = 0;
		int i = 0;
		string init = "0000";
		queue<string> a;
		queue<int> cur;
		a.push(init);
		cur.push(0);
		if (init == target)
			return num;
		num++;
		for (i = 0; i < 4; i++)
		{
			string temp = a.front();
			if (!repeat(deadends, change1(temp, i)))
			{
				a.push(temp);
				cur.push(num);
			}
			if (!repeat(deadends, change2(temp, i)))
			{
				a.push(temp);
				cur.push(-num);
			}
		}
		num++;
		a.pop();
		cur.pop();
		while (a.front() != target)
		{
			if (a.empty())
				return -1;
			for (i = 0; i < 4; i++)
			{
				string temp = a.front();
				if (cur.front() > 0)
				{
					if (!repeat(deadends, change1(temp, i)))
					{
						a.push(temp);
						cur.push(num);
					}
				}
				else
				{
					if (!repeat(deadends, change2(temp, i)))
					{
						a.push(temp);
						cur.push(-num);
					}
				}
				
			}
			a.pop();
			cur.pop();
			num++;
		}
		return num;
	}
};
int main()
{
	string a[5] = { "0201", "0101", "0102", "1212", "2002" };
	vector<string> deadends(a, a + 5);
	Solution A;
	string target = "0202";
	return A.openLock(deadends, target);
}