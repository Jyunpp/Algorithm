//20170901 08:59 ~ 11:14 (수업듣느라)
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int T, W;
int dp[31][1001][3];	//dp[i][j][k] : 남은 횟수가 i번, 현재 j초, k번 아래 일 때 최대 먹는 갯수
int arr[1001];

int main() {
	scanf("%d %d", &T, &W);
	for (int i = 1; i <= T; i++)
		scanf(" %d", &arr[i]);
	dp[W][1][1] = (arr[1] == 1);
	dp[W][1][2] = 0;
	dp[W - 1][1][2] = (arr[1] == 2);
	//i초 일 때
	for (int i = 2; i <= T; i++) {
		int curr = arr[i];
		int other = 3 - curr;
		//j번 남았을 때를 채우기 위해서
		for (int j = W; j >= 0; j--) {
			//이동하지 않은 경우와
			dp[j][i][curr] = max(dp[j][i][curr], dp[j][i - 1][curr] + 1);
			dp[j][i][other] = max(dp[j][i][other], dp[j][i - 1][other]);
			//이동한 경우를 고려.
			if (j + 1 <= W) {
				dp[j][i][curr] = max(dp[j][i][curr], dp[j + 1][i - 1][other] + 1);
				dp[j][i][other] = max(dp[j][i][other], dp[j + 1][i - 1][curr]);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= W; i++)
		ans = max(max(ans, dp[i][T][1]), dp[i][T][2]);
	printf("%d\n", ans);
	//system("pause");
	return 0;
}