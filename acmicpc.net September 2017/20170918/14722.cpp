//20170917 04:26 ~ 04:58 ~ 05:19 다 오후얘기. ~ 다음날 새벽 02:23
/*
	처음에 bfs로 했는데
	시간초과.
	=> dp[3][1001][1001]에 1000*1000*3 3중 포문으로 돌림..
	예외처리가 어렵더라..
*/
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#define xx first
#define yy second

#include <iostream>
#include <stdio.h>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <math.h>
#include <queue>
using namespace std;

int n;
int arr[1001][1001];
int dp[3][1001][1001];	//dp[curr][i][j] : 마지막으로 먹은게 curr일 때 i, j에서 최대먹은개수
						//-1이면 방문한 적 없음.

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf(" %d", &arr[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		arr[0][i] = arr[i][0] = -1;
	}
	dp[0][1][1] = (arr[1][1] == 0 ? 1 : -1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == 1 && j == 1) continue;
			for (int curr = 0; curr < 3; curr++) {
				int prev = (curr == 0 ? 2 : curr - 1);
				int up, left;
				//up
				if (arr[i - 1][j] == -1) up = -1;
				else {
					if (arr[i][j] == curr){
						if (curr != 0 && dp[prev][i - 1][j] == 0)	//방문한 적이 없다면 prev불가능
							up = dp[curr][i - 1][j];
						else
							up = max(dp[prev][i - 1][j] + 1, dp[curr][i - 1][j]);
					}
					else {
						up = dp[curr][i - 1][j];
					}
				}
				//left
				if (arr[i][j - 1] == -1) left = -1;
				else {
					if (arr[i][j] == curr){
						if (curr != 0 && dp[prev][i][j - 1] == 0)	//방문한 적이 없다면 prev불가능
							left = dp[curr][i][j - 1];
						else
							left = max(dp[prev][i][j - 1] + 1, dp[curr][i][j - 1]); 
					}
					else {
						left = dp[curr][i][j - 1];
					}
				}
				dp[curr][i][j] = max(up, left);
			}
		}
	}
	////test
	//cout << endl;
	//for (int k = 0; k < 3; k++) {
	//	cout << "k : " << k << endl;
	//	for (int i = 1; i <= n; i++) {
	//		for (int j = 1; j <= n; j++) {
	//			cout << dp[k][i][j] << " ";
	//		}
	//		cout << endl;
	//	}
	//	cout << endl;
	//}
	////testEnd
	int ans = max( max(dp[0][n][n], dp[1][n][n]), dp[2][n][n]);
	cout << ans << endl;
	//system("pause");
	return 0;
}