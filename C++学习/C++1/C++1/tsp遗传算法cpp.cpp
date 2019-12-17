/*
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
	return sqrt(x*x + y * y);
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
	int L = (int)(num*0.3);
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

*/