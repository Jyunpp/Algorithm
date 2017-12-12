//20171212 13:34 ~ 13:55
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#define sd(x) scanf(" %d", &x);
#define slld(x) scanf(" %lld", &x);
#define sc(x) scanf(" %c", &x);
#define ll long long
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
#include <functional>
using namespace std;
typedef pair<int, int> P;

int n;
int dp[6][100001];
P arr[100001];

int main() {
	sd(n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &arr[i].xx, &arr[i].yy);
		for (int j = 1; j <= 5; j++)
			dp[j][i] = 0;
	}
	dp[arr[1].xx][1] = 1;
	dp[arr[1].yy][1] = 1;
	int ansNum = 1;
	int ansGrade = min(arr[1].xx, arr[1].yy);
	for (int i = 2; i <= n; i++) {
		int currX = arr[i].xx;
		int currY = arr[i].yy;
		for (int j = 1; j <= 5; j++) {
			if (j == currX || j == currY) {
				dp[j][i] = dp[j][i - 1] + 1;
				if (dp[j][i] > ansNum) {
					ansNum = dp[j][i];
					ansGrade = j;
				}
				else if (dp[j][i] == ansNum)
					ansGrade = ansGrade > j ? j : ansGrade;
			}
			else dp[j][i] = 0;
		}
	}
	cout << ansNum << " " << ansGrade << endl;
//	system("pause");
}