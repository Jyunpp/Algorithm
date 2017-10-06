//20171005 대회시간 16:05 ~ 19:05 
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#define sd(x) scanf(" %d", &x);
#define slld(x) scanf(" %lld", &x);
#define ll long long
#define pb push_back
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

struct P {
	int a, b, c, d;
};

int arr[100001][5];
int dp[2][2][2][2];
vector<P> v;

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			sd(arr[i][j]);
		}
		dp[arr[i][1]][arr[i][2]][arr[i][3]][arr[i][4]]++;
	}
	bool ans = false;
	if (k == 1) {
		if (dp[0][0][0][0]) ans = true;
		//if (dp[1][0][0][0] && dp[0][0][0][0]) ans = true;
	}
	else if (k == 2) {
		if (dp[0][0][0][0]) ans = true;
		//if (dp[0][0][0][0] && (dp[1][1][0][0]||dp[1][0][0][0]||dp[0][1][0][0]))ans = true;
		if (dp[1][0][0][0] && dp[0][1][0][0]) ans = true;
	}
	else if (k == 3) {
		if (dp[0][0][0][0]) ans = true;
		//if (dp[0][0][0][0] && (dp[1][1][1][0]||dp[0][0][1][0]||dp[0][1][0][0]||dp[0][1][1][0]||dp[1][0][0][0]||dp[1][0][1][0]||dp[1][1][0][0]))ans = true;
		if (dp[0][0][1][0] && (dp[1][1][0][0]||dp[0][0][0][0]||dp[1][0][0][0]||dp[0][1][0][0])) ans = true;
		if (dp[0][1][0][0] && (dp[1][0][1][0]||dp[0][0][0][0]||dp[0][0][1][0]||dp[1][0][0][0])) ans = true;
		if (dp[0][1][1][0] && (dp[1][0][0][0]||dp[0][0][0][0])) ans = true;
	}
	else {
		if (dp[0][0][0][0]) ans = true;
		//if (dp[0][0][0][0] && (dp[1][1][1][1]||dp[0][0][0][1]||dp[0][0][1][0]||dp[0][0][1][1]||dp[0][1][0][0]||dp[0][1][0][1]||dp[0][1][1][0]||dp[0][1][1][1]||dp[1][0][0][0]||dp[1][0][0][1]||dp[1][0][1][0]||dp[1][0][1][1]||dp[1][1][0][0]||dp[1][1][0][1]||dp[1][1][1][0]))ans = true;
		if (dp[0][0][0][1] && (dp[1][1][1][0]||dp[0][0][0][0]||dp[0][0][1][0]||dp[0][1][0][0]||dp[0][1][1][0]||dp[1][0][0][0]||dp[1][0][1][0]||dp[1][1][0][0])) ans = true;
		if (dp[0][0][1][0] && (dp[1][1][0][1]||dp[0][0][0][0]||dp[0][0][0][1]||dp[0][1][0][0]||dp[0][1][0][1]||dp[1][0][0][0]||dp[1][0][0][1]||dp[1][1][0][0])) ans = true;
		if (dp[0][0][1][1] && (dp[1][1][0][0]||dp[0][0][0][0]||dp[0][1][0][0]||dp[1][0][0][0])) ans = true;
		if (dp[0][1][0][0] && (dp[1][0][1][1]||dp[0][0][0][0]||dp[0][0][0][1]||dp[0][0][1][0]||dp[0][0][1][1]||dp[1][0][0][0]||dp[1][0][0][1]||dp[1][0][1][0]))ans = true;
		if (dp[0][1][0][1] && (dp[1][0][1][0]||dp[0][0][0][0]||dp[0][0][1][0]||dp[1][0][0][0])) ans = true;
		if (dp[0][1][1][0] && (dp[1][0][0][1]||dp[0][0][0][0]||dp[0][0][0][1]||dp[1][0][0][0])) ans = true;
		if (dp[0][1][1][1] && (dp[0][0][0][0]||dp[1][0][0][0])) ans = true;
	}
	if (ans)cout << "YES" << endl;
	else cout << "NO" << endl;
	//system("pause");
	return 0;
}