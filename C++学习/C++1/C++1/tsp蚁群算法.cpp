/*//蚂蚁群算法TSP,33s
# include <bits/stdc++.h>
using namespace std;
const int N = 34;
const int M = 700;
double mp[N + 3][N + 3];
double phe[N + 3][N + 3];
double phe2[N + 3][N + 3];
double rate = 0.5;
double Q = 1000;
int path[M + 3][N + 3] = { 0 };
int alpha = 1;
int beta = 4;
int times = 700;
bool vis[N + 3];
struct node {
	double x, y;
}point[N + 3];
double dis(int u, int v) {
	double x = point[u].x - point[v].x;
	double y = point[u].y - point[v].y;
	return sqrt(x*x + y * y);
}
void init_map() {//初始化边的情况
	for (int i = 0; i < N; ++i) {
		scanf("%lf%lf", &point[i].x, &point[i].y);
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			mp[i][j] = dis(i, j);
		}
	}
}
double cal_distance(int a[]) {
	double tot = 0;
	for (int i = 0; i < N - 1; ++i) {
		tot += mp[a[i]][a[i + 1]];
	}
	tot += mp[a[0]][a[N - 1]];
	return tot;
}
int main() {
	//freopen("a.txt", "r", stdin);
	//freopen("4.txt", "w", stdout);
	srand(time(0));
	init_map();
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			phe[i][j] = 1.0;
	for (int T = 0; T < times; ++T) {
		for (int i = 0; i < M; ++i) {//遍历每个蚂蚁
			memset(vis, false, sizeof(vis));
			int cur = rand() % N;
			vis[cur] = true;
			path[i][0] = cur;
			for (int j = 1; j < N; ++j) {
				double pob[N + 3] = { 0 }, POB = 0;
				for (int k = 0; k < N; ++k) {
					if (!vis[k]) {
						pob[k] = pow(phe[cur][k], alpha)*pow(1.0 / mp[cur][k], beta);
						POB += pob[k];
					}
				}
				if (POB > 0) {
					double zhuan = rand()*1.0 / RAND_MAX * POB;
					for (int k = 0; k < N; ++k) {
						if (!vis[k]) {
							zhuan -= pob[k];
							if (zhuan <= 0 || k == N - 1) {
								cur = k;
								break;
							}
						}
					}
				}
				vis[cur] = true;
				path[i][j] = cur;
			}


		}
		memset(phe2, 0, sizeof(phe2));//更新信息素
		for (int i = 0; i < M; ++i) {
			double tot = 0;
			tot += cal_distance(path[i]);
			for (int j = 0; j < N - 1; ++j) {
				phe2[path[i][j]][path[i][j + 1]] += Q / tot;
				phe2[path[i][j + 1]][path[i][j]] = phe2[path[i][j]][path[i][j + 1]];
			}
			phe2[path[i][0]][path[i][N - 1]] += Q / tot;
			phe2[path[i][N - 1]][path[i][0]] = phe2[path[i][0]][path[i][N - 1]];
		}
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				phe[i][j] = phe[i][j] * rate + phe2[i][j];
			}
		}
	}
	double imin = 1e18;
	int id = 0;
	for (int i = 0; i < M; ++i) {
		double tmp = cal_distance(path[i]);
		if (tmp < imin) imin = tmp, id = i;
	}
	printf("%f\n", imin);
	for (int i = 0; i < N; ++i) printf("%d ", path[id][i]);
	return 0;
}*/
