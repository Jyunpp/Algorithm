//20170812 19:00 ~ 20:02
//무한도전 보면서 풀었는데 한 번에!!
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int berry[10001];
int dp[10001]; 
vector<vector<int>> node;

void merge(int here, int parent, int amount) {
	//classified
}

int main() {
	scanf("%d", &n);
	node.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		scanf(" %d", &berry[i]);
		dp[i] = berry[i];
	}
	for (int i = 1, a,b; i < n; i++) {
		scanf(" %d %d", &a, &b);
		//classified
	}
	int ans = 0, ansIdx;

	for (int i = n; i >= 1; i--) {
		if (dp[i] >= ans) {
			ans = dp[i];
			ansIdx = i;
		}
	}
	printf("%d %d\n", ans, ansIdx);
	//system("pause");
	return 0;
}