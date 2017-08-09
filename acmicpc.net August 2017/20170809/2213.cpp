//20170809 1:23 ~ 20:00
#ifdef _msc_ver
#define _crt_secure_no_warnings
#endif

#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct vertex {
	int num;
	vector<int> edge;
};

vector<vertex> ver;
vector<vertex> tree;
int n, ans = 0;
vector<int>ansvec;
int visited[10001];
int dp[10001][2];

void dfs(int here, int parent) {
	visited[here] = 1;
	if (here != 1)tree[parent].edge.push_back(here);
	for (auto &i : ver[here].edge) {
		if (visited[i] != 1)
			dfs(i, here);
	}
}

int solve(int idx, int opt) {
	int &ret = dp[idx][opt];
	if (ret != -1)return ret;
	if (opt) {//이번에 선택을 한 것. opt를 끄고 재귀.
		ret = ver[idx].num;
		for (auto &i : tree[idx].edge) {
			ret += solve(i, 0);
		}
	}
	else {
		ret = 0;
		for (auto &i : tree[idx].edge) {
			ret += max(solve(i, 0), solve(i, 1));
		}
	}
	return ret;
}

void trace(int idx, int opt) {
	if (opt) {
		ansvec.push_back(idx);
		for (auto &i : tree[idx].edge) {
			trace(i, 0);
		}
	}
	else {
		for (auto &i : tree[idx].edge) {
			if (dp[i][1] >= dp[i][0])
				trace(i, 1);
			else
				trace(i, 0);
		}
	}
}

int main() {
	cin >> n;
	ver.resize(n + 1);
	tree.resize(n + 1);
	for (int i = 1, input; i <= n; i++) {
		scanf("%d", &ver[i].num);
		visited[i] = -1;
		dp[i][0] = dp[i][1] = -1;
	}
	int a, b;
	//while(scanf("%d %d", &a, &b)!=eof){
	for(int i=2; i<=n; i++){
		scanf("%d %d", &a, &b);
		ver[a].edge.push_back(b);
		ver[b].edge.push_back(a);
	}
	//dfs로 tree 만들기.
	dfs(1, 0);
	//
	int x = solve(1, 0);
	int y = solve(1, 1);
	ans = y;
	if (x >= y) {
		ans = x;
		trace(1, 0);
	}
	else
		trace(1, 1);
	cout << ans << endl;
	sort(ansvec.begin(), ansvec.end());
	for (auto &i : ansvec)
		printf("%d ", i);
	//system("pause");
	return 0;
}