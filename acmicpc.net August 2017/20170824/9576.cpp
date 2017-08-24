//20170824 19:04 ~ 19:50
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, t, visited[1001];
int A[1001], B[1001];

bool dfs(int b, vector<int> *adj) {
	visited[b] = true;
	for (int &i : adj[b]) {
		if (A[i] == -1 || (!visited[A[i]] && dfs(A[i], adj))) {
			B[b] = i;
			A[i] = b;
			return true;
		}
	}
	return false;
}

int main() {
	for (scanf("%d", &t);t--;) {
		vector<int> adj[1001];
		scanf(" %d %d", &N, &M);
		for (int i = 1, a, b; i <= M; i++) {
			scanf(" %d %d", &a, &b);
			for (int j = a; j <= b; j++)
				adj[i].push_back(j);
		}

		int match = 0;
		fill(A, A + 1001, -1);
		fill(B, B + 1001, -1);
		for (int i = 1; i <= M; i++) {
			if (B[i] == -1) {
				fill(visited, visited + M, false);
				if (dfs(i, adj)) match++;
			}
		}
		printf("%d\n", match);
	}
	//system("pause");
	return 0;
}