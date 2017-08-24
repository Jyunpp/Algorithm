//20170824 20:23 ~ 20:32
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, A[2001], B[1001];
bool visited[2001];
vector<int> adj[2001];

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
	scanf("%d %d", &N, &M);
	for (int i = 1, a; i <= N; i++) {
		scanf(" %d", &a);
		for (int j = 1, b; j <= a; j++) {
			scanf(" %d", &b);
			adj[i].push_back(b);
			adj[i + N].push_back(b);
		}
	}

	int match = 0;
	fill(A, A + 2001, -1);
	fill(B, B + 1001, -1);
	for (int i = 1; i <= 2 * N; i++) {
		if (A[i] == -1) {
			fill(visited, visited + 2001, false);
			if (dfs(i)) match++;
		}
	}
	printf("%d\n", match);
	//system("pause");
	return 0;
}