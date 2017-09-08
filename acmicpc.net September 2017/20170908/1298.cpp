//20170908 10:53 ~ 11:05
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;


int n, m;
int A[101], B[101];
bool visited[101];
vector<int> adj[101];

bool dfs(int a) {
	visited[a] = true;
	for (auto &i : adj[a]) {
		if (B[i] == -1 || (!visited[B[i]]) && dfs(B[i])) {
			B[i] = a;
			A[a] = i;
			return true;
		}
	}
	return false;
}

int main() {
	scanf(" %d %d", &n, &m);
	for (int i = 1, a, b; i <= m; i++) {
		scanf(" %d %d", &a, &b);
		adj[a].push_back(b);
	}
	//binary matching
	int match = 0;
	fill(A, A + 101, -1);
	fill(B, B + 101, -1);
	for (int i = 1; i <= n; i++) {
		if (A[i] == -1) {
			fill(visited, visited + 101, false);
			if (dfs(i)) match++;
		}
	}
	printf("%d\n", match);
	//system("pause");
	return 0;
}