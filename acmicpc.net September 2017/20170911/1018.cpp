//20170911 21:34 ~ 21:59
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int n, m;
char arr[51][51];
int dp[51][51];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int check = i % 2;	// È¦¼ö¸é 1
		for (int j = 1; j <= m; j++) {
			check ^= 1;	// 0, 1 ¹Ù²ñ => È¦¼ö¸é 0À¸·Î ½ÃÀÛ.
			scanf(" %c", &arr[i][j]);
			char checkCh= (check ? 'W' : 'B');
			if (arr[i][j] == checkCh) {
				dp[i][j] = 0;
			}
			else {
				dp[i][j] = 1;
			}
		}
	}
	int ans = 987654321;
	for (int i = 1; i + 7 <= n; i++) {
		for (int j = 1; j + 7 <= m; j++) {
			int sum = 0;
			for (int k = i; k <= i + 7; k++) {
				for (int o = j; o <= j + 7; o++) {
					sum += dp[k][o];
				}
			}
			ans = min(ans, sum);
			ans = min(ans, 64 - sum);
		}
	}
	printf("%d", ans);
	//system("pause");
	return 0;
}