//20171216 13:45 ~ 14:11
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

int arr[100001], dp[100001];
int n;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		sd(arr[i]);
		dp[i] = 0;
	}
	int max = arr[1];
	int maxIdx = 1;
	dp[1]--;
	int second = 0;
	if (n == 1) {
		cout << 1 << endl;
		return 0;
	}
	for (int i = 2; i <= n; i++) {
		int curr = arr[i];
		if (curr > second && curr < max) {
			dp[maxIdx]++;
			second = curr;
		}
		else if (curr > max) {
			dp[i]--;
			maxIdx = i;
			second = max;
			max = curr;
		}
	}
	int ansNum = -123;
	for (int i = 1; i <= n; i++) {
		if (dp[i] > ansNum) {
			ansNum = dp[i];
		}
	}
	int ans = 123456789;
	for (int i = 1; i <= n; i++) {
		if (dp[i] == ansNum) {
			if (ans > arr[i]) ans = arr[i];
		}
	}
	/*for (int i = 1; i <= n; i++) {
		cout << dp[i] << " ";
	}cout << endl;*/
	cout << ans << endl;
	//system("pause");
	return 0;
}