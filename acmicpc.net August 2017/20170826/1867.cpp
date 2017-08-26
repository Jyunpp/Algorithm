//20170826 23:11 ~ 01:09
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int n, k, A[501], B[501];
bool visited[501];
vector<int> adj[501];

bool dfs(int a) {
	visited[a] = true;
	for (auto &i : adj[a]) {
		if (B[i] == -1 || (!visited[B[i]] && dfs(B[i]))) {
			B[i] = a;
			A[a] = i;
			return true;
		}
	}
	return false;
}

int main() {
	scanf(" %d %d", &n, &k);
	for (int i = 1, a, b; i <= k; i++) {
		scanf(" %d %d", &a, &b);
		adj[a].push_back(b);
	}
	int match = 0;
	fill(A, A + 501, -1);
	fill(B, B + 501, -1);
	for (int i = 1; i <= n; i++) {
		if (A[i] == -1) {
			fill(visited, visited + 501, false);
			if (dfs(i))
				match++;
		}
	}
	printf("%d\n", match);
	//system("pause");
	return 0;
}
