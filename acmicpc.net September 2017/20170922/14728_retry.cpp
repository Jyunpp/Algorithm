//20170921 16:17 ~ 16:33
//20170922 14:22 ~ 16:07
/*
	dp를 어떻게 잡으면 좋을지 떠오르지 않을 때.
	이 문제처럼.. 이게 과연 사용될까? 싶더라도
	dp[101][10001] 사이즈가 10,000,000 => 최대 천만번 계산밖에 안한다 => TLE면함
	사이즈로 접근해보기..
*/
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

int n, t;
pair<int, int> arr[101];
int dp[101][10001];			//dp[i][j] : j의 cost로 i를 선택할 차례가 되었을 때 최댓값.

int recur(int idx, int cost) {
	//종료조건
	if (cost > t) return -987654321;
	if (idx > n) return 0;	//idx 1~n이라 n+1번 째는 선택할 게 없다.

	int &ret = dp[idx][cost];
	if (ret != -1) return ret;

	ret = max(recur(idx + 1, cost), recur(idx + 1, cost + arr[idx].xx) + arr[idx].yy);
	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	cin >> n >> t;
	for (int i = 1; i <= n; i++)
		scanf(" %d %d", &arr[i].xx, &arr[i].yy);

	int ans = max(recur(2, 0), recur(2, arr[1].xx) + arr[1].yy);	//선택X, 선택O
	cout << ans << endl;
	//system("pause");
	return 0;
}