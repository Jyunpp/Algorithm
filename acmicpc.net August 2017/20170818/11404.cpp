//20170818 19:51 ~ 20:55
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, dp[101][101];

int main() {
	scanf(" %d", &n);
	scanf(" %d", &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			dp[i][j] = 987654321;
	}
	for (int i = 1; i <= n; i++)
		dp[i][i] = 0;
	for (int i = 1, a, b, c; i <= m; i++) {
		scanf(" %d %d %d", &a, &b, &c);
		dp[a][b] = min(dp[a][b], c);
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++)
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++){
			if (dp[i][j] < 987654321)
				printf("%d ", dp[i][j]);
			else
				printf("0 ");
		}
		printf("\n");
	}
	//system("pause");
	return 0;
}