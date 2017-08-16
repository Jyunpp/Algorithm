//20170816 02:28 ~ 

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int V, E, discovered[10001];
int cnt = 0;
vector<vector<int>>graph;
bool cutPoint[100000];

int dfs(int curr, int parent, bool isRoot) {
	discovered[curr] = ++cnt;
	int ret = discovered[curr];
	
	int child = 0;
	for (auto &i : graph[curr]) {
		if (i == parent) continue;
		if (!discovered[i]) {
			child++;
			int low = dfs(i, curr, false);
			if (!isRoot && low >= discovered[curr])	//선과는 다르게 늦거나"같다면". 선에서 정의할 때 선이지만 종착점을 기준으로 생각해서.
				cutPoint[curr] = true;
			ret = min(ret, low);
		}
		else
			ret = min(ret, discovered[i]);
	}
	if (isRoot)
		cutPoint[curr] = (child >= 2);
	return ret;
}

int main() {
	scanf("%d %d ", &V, &E);
	graph.resize(V);
	for (int i = 1, a, b; i <= E; i++) {
		scanf(" %d %d", &a, &b); a--; b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	//연결 그래프가 아닐 수 있어서 세그먼트들에 대해서 다 해줘야.
	for (int i = 0; i < V; i++) {
		if (!discovered[i])
			dfs(i, -1, true);
	}

	int ans = 0;
	for (int i = 0; i < V; i++) {
		if (cutPoint[i])
			ans++;
	}
	printf("%d\n", ans);
	for (int i = 0; i < V; i++) {
		if (cutPoint[i])
			printf("%d ", i + 1);
	}
	//system("pause");
	return 0;
}