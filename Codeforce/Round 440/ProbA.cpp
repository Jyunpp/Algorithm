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

int n, m;
vector<int> arr[3];
int dp[10];

int main() {
	cin >> n >> m;
	for (int i = 1, a; i <= n; i++) {
		cin >> a;
		arr[1].push_back(a);
	}
	for (int i = 1, a; i <= m; i++) {
		cin >> a;
		arr[2].push_back(a);
	}
	sort(arr[1].begin(), arr[1].end());
	sort(arr[2].begin(), arr[2].end());
	int ans = 0;
	for (int i = 0; i < n; i++) {
		dp[arr[1][i]]++;
	}
	for (int i = 0; i < m; i++) {
		dp[arr[2][i]]++;
	}
	for (int i = 1; i <= 9; i++) {
		if (dp[i] == 2) {
			ans = i;
			break;
		}
	}
	if (ans) {

	}
	else {
		ans = min(arr[1][0] * 10 + arr[2][0], arr[1][0] + arr[2][0] * 10);
	}
	cout << ans << endl;
	//system("pause");
	return 0;
}