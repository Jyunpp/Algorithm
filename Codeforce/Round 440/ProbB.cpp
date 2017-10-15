//20171015 대회시간 17:05 ~ 19:05
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#define xx first
#define yy second

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>
using namespace std;

int n, k;
int arr[100001];
int temp = 1987654321;
int TEMP = -temp;
int dp[2][100001];

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		scanf(" %d", &arr[i]);
		temp = min(temp, arr[i]);
		TEMP = max(TEMP, arr[i]);
	}
	int ans = -1987654321;
	if (k == 1) {
		ans = temp;
	}
	else if (k >=3) {
		ans = TEMP;
	}
	else {
		dp[0][1] = arr[1];
		for (int i = 2; i <= n; i++) {
			dp[0][i] = min(dp[0][i - 1], arr[i]);
		}
		dp[1][1] = arr[n];
		for (int i = 2; i <= n; i++) {
			dp[1][i] = min(dp[0][i - 1], arr[n - (i - 1)]);
		}
		for (int i = 1; i <= n; i++) {
			ans = max(ans, max(dp[0][i], dp[1][i]));
		}
	}
	cout << ans << endl;
	//system("pause");
	return 0;
}