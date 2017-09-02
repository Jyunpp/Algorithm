//20170901 15:56 ~ 16:01
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int n;
int parent[100001];
vector<int> adj[100001];

void bfs(int curr, int par) {
	for (auto &i : adj[curr]) {
		if (i != par) {
			parent[i] = curr;
			bfs(i, curr);
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1, a, b; i < n; i++) {
		scanf(" %d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	bfs(1, -1);
	for (int i = 2; i <= n; i++)
		printf("%d\n", parent[i]);
	//system("pause");
	return 0;
}