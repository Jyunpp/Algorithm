//20170811 06:00 ~
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, depth[100001];
int maxD;
int parent[100001][20];
vector<vector<int>> edge;

void dfs(int currIdx, int parentIdx, int d) {
	parent[currIdx][0] = parentIdx;
	depth[currIdx] = d;
	int len = edge[currIdx].size();
	int i = 0;
	while (len--) {
		if (edge[currIdx][i] == parentIdx) {
			edge[currIdx].erase(edge[currIdx].begin() + i);
		}
		else {
			dfs(edge[currIdx][i], currIdx, d + 1);
			i++;
		}
	}
}

void fillParent() {
	for (int i = 0; i <= maxD; i++) {
		for (int j = 1; j <= n; j++)
			parent[j][i + 1] = parent[parent[j][i]][i];
	}
}

int lca(int a, int b) {
	if (depth[a] != depth[b]) {
		if (depth[a] > depth[b])
			swap(a, b);
		for (int i = maxD; i >= 0; i--) {
			if (depth[parent[b][i]] >= depth[a])
				b = parent[b][i];
		}
	}
	int lca = a;
	if (a != b) {
		for (int i = maxD; i >= 0; i--) {
			if (parent[a][i] != parent[b][i]) {
				a = parent[a][i];
				b = parent[b][i];
			}
			lca = parent[a][i];
		}
	}
	return lca;
}

int main() {
	scanf("%d", &n);
	edge.resize(n + 1);
	maxD = (int)floor(log2(n));
	for (int i = 1, a, b; i < n; i++) {
		scanf("%d %d", &a, &b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	//tree拳, depth 傈贸府
	dfs(1, 0, 1);
	//parent 傈贸府
	fillParent();
	//孽府
	scanf("%d", &m);
	for (int i = 1, a, b; i <= m; i++) {
		scanf("%d %d", &a, &b);
		printf("%d\n", lca(a, b));
	}
//	system("pause");
	return 0;
}