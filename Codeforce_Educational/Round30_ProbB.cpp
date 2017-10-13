//20171013 13:14 ~ 14:20
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

int n, ans = 0;
string s;
int dp[300002];	//dp[i] : first idx+2 of when i = numOfOne - numOfZero + 100001.
				//        and, dp[100001] = 1;
int main() {
	cin >> n >> s;
	int curr = 100001;
	dp[curr] = 1;
	for (int i = 0; i < n; i++) {
		curr += (s[i]=='1' ? 1 : -1);
		if (!dp[curr]) dp[curr] = i + 2;
		else {
			ans = max(ans, i + 2 - dp[curr]);
		}
	}
	cout << ans << endl;
	//system("pause");
	return 0;
}