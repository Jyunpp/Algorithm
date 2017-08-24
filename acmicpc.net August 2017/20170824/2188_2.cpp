//20170824 18:38 ~ 
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, A[200], B[200];
vector<int> adj[200];
bool visited[200];

bool dfs(int a) {
	visited[a] = true;
	for (auto &i : adj[a]) {
		if (B[i] == -1 || (!visited[B[i]] && dfs(B[i]))) {
			A[a] = i;
			B[i] = a;
			return true;
		}
	}
	return false;
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0, s; i < N; i++) {
		scanf(" %d ", &s);
		for (int j = 0, k; j < s; j++) {
			scanf(" %d", &k);
			adj[i].push_back(k - 1);
		}
	}
	
	int match = 0;
	fill(A, A + N, -1);
	fill(B, B + M, -1);
	for (int i = 0; i < N; i++) {
		if (A[i] == -1) {
			fill(visited, visited + N, false);
			if (dfs(i)) match++;
		}
	}
	printf("%d\n", match);
	//system("pause");
	return 0;
}