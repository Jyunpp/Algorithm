//20170921 16:17 ~ 16:33
//20170922 14:22 ~ 16:07
/*
	dp�� ��� ������ ������ �������� ���� ��.
	�� ����ó��.. �̰� ���� ���ɱ�? �ʹ���
	dp[101][10001] ����� 10,000,000 => �ִ� õ���� ���ۿ� ���Ѵ� => TLE����
	������� �����غ���..
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
int dp[101][10001];			//dp[i][j] : j�� cost�� i�� ������ ���ʰ� �Ǿ��� �� �ִ�.

int recur(int idx, int cost) {
	//��������
	if (cost > t) return -987654321;
	if (idx > n) return 0;	//idx 1~n�̶� n+1�� °�� ������ �� ����.

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

	int ans = max(recur(2, 0), recur(2, arr[1].xx) + arr[1].yy);	//����X, ����O
	cout << ans << endl;
	//system("pause");
	return 0;
}