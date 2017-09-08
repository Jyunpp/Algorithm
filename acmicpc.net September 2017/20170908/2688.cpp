//20170908 11:18 ~ 11:31
#include <iostream>
#include <stdio.h>

using namespace std;

int t;
long long dp[10][65];

int main() {
	//fill dp
	for (int i = 0; i<10; i++) {
		dp[i][1] = 1;
	}
	for (int i = 2; i <= 64; i++) {
		for (int j = 0; j<10; j++) {
			//fill dp[j][i]
			for (int k = 0; k <= j; k++) {
				dp[j][i] += dp[k][i - 1];
			}
		}
	}
	for (scanf("%d", &t); t--; ) {
		int n;
		scanf("%d", &n);
		long long ans = 0;
		for (int i = 0; i<10; i++) {
			ans += dp[i][n];
		}
		printf("%lld\n", ans);
	}
	return 0;
}
