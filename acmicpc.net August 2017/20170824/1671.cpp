//20170824 21:57 ~ 22:25
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

struct Shark {
	int a, b, c;
}s[1001];
int A[2001], B[1001], N;
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
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf(" %d %d %d", &s[i].a, &s[i].b, &s[i].c);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) continue;
			//같은 능력치를 가질 시, 서로 잡아먹는 예외를 없애주기 위해서 하나만 연결.
			if (s[i].a == s[j].a && s[i].b == s[j].b && s[i].c == s[j].c && i > j) continue;
			if (s[i].a >= s[j].a && s[i].b >= s[j].b&&s[i].c >= s[j].c) {
				adj[i].push_back(j);
				adj[i + N].push_back(j);
			}
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
	printf("%d\n", N - match);
	//system("pause");
	return 0;
}