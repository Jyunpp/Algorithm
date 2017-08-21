//20170821 06:31 ~ 10:10 ~ 01:11 ~ 02:57
//한 번에 맞은 거에 만족한다!!
/*
	classified
*/
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m, t, ans = 0;
int S = 0, T = 5001;
int c[5002][5002], f[5002][5002];								//classified
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

inline int makeIdx(int n, int m) { return 50 * (n-1) + m; }

int main() {
	for (scanf(" %d", &t); t--;) {
		scanf(" %d %d", &n, &m);
		ans = 0;
		memset(c, 0, sizeof(0));
		memset(f, 0, sizeof(f));
		vector<int> adj[5002];
		//classified
	}
	system("pause");
	return 0;
}