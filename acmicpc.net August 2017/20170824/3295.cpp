//20170824 21:05 ~ 21:39
/*
	classified
*/
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, T, A[1000], B[1000];
bool visited[1000];
vector<int> adj[1000];

int dfs(int a) {
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
	//classified
//	system("pause");
	return 0;
}