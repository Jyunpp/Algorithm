//20170815 05:18 ~ 05:52
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <stdio.h>
using namespace std;

int n, m;
int dp[101][101];	//dp[i][j] : 0 비교불가// 1 i기준 j는 가볍

int main() {
	//n, m 입력 및 dp 초기화
	cin >> n;
	cin >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) dp[i][j] = 3;
			else dp[i][j] = 0;
		}
	}
	//비교 입력 및 dp 갱신
	for (int i = 1, a, b; i <= m; i++) {
		scanf(" %d %d", &a, &b);	//weight : a>b
		dp[a][b] = 1;
	}
	//플로이드 와샬?로 dp채우기
	for (int k = 1; k <= n; k++) {	//플로이드 와샬 k를 중심으로 도는 것 중요★
									//그래야, 차례차례 완성, 갱신안되것 보고 갱신못시키는 경우가 없음.
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) continue;
				//dp[i][j]를 채운다.
				if (dp[i][k] == dp[k][j] && dp[i][k])
					dp[i][j] = dp[i][k];
			}
		}
	}
	//답 출력
	for (int i = 1; i <= n; i++) {
		int ans = 0;
		for (int j = 1; j <= n; j++)
			if (dp[i][j] || dp[j][i])ans++;
		printf("%d\n", n - ans);
	}
	//system("pause");
	return 0;
}