//20171011
/*
	그래프에서 한 개의 cycle만 존재할 때.
	Codeforces Roudn #427 - F 의 부분.
*/
#define N 100001
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int n;
vector<pair<int, int>> g[N];
vector<int> cycle;
int color[N];

int dfs(int v, int from = -1) {
	static int cycle_start = -1;
	color[v] = 1;
	for (auto &e : g[v]) {
		int u = e.first;
		if (u == from) {
			continue;
		}

		if (color[u] == 1) {
			cycle.push_back(v);
			cycle_start = u;
			return 1;
		}
		else if (color[u] == 0) {
			int res = dfs(u, v);
			if (res == -1) {
				return -1;
			}
			if (res == 1) {
				cycle.push_back(v);
				if (v == cycle_start) {
					return -1;
				}
				return 1;
			}
		}
	}
	color[v] = 2;
	return 0;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int u, v, l;
		scanf("%d%d%d", &u, &v, &l);
		g[u].push_back({ v, l });
		g[v].push_back({ u, l });
	}

	dfs(1);
}