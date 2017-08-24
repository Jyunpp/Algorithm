//20170824 19:54 ~ 20:18
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, A[1001], B[1001];
int visited[1001];
vector<int> adj[1001];

bool dfs(int a) {
	visited[a] = 1;
	for (auto &i : adj[a]) {
		if (B[i] == -1 || (visited[B[i]] == -1 && dfs(B[i]))) {
			A[a] = i;
			B[i] = a;
			return true;
		}
	}
	return false;
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 1, a; i <= N; i++) {
		scanf(" %d", &a);
		for (int j = 1, b; j <= a; j++) {
			scanf(" %d", &b);
			adj[i].push_back(b);
		}
	}

	int match = 0;
	fill(A, A + 1001, -1);
	fill(B, B + 1001, -1);
	for (int i = 1; i <= N; i++) {
		if (A[i] == -1) {
			fill(visited, visited + N, -1);
			if (dfs(i)) match++;
		}
	}
	printf("%d\n", match);
	//system("pause");
	return 0;
}