//20171006 대회시간 22:35 ~ 00:35
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

int n;
int A[2001];
int B[2001];
int dp[2000001];
int cnt = 0;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		dp[A[i]]++;
	}
	for (int i = 1; i <= n; i++) {
		cin >> B[i];
		dp[B[i]]++;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int curr = (int)(A[i] ^ B[j]);
			if (curr > 2000000) {
				continue;
			}
			if (dp[curr]) {//짝수 세기
				cnt++;
			}
		}
	}
	cout << cnt << endl;
	if (!(cnt % 2)) {
		cout << "Karen" << endl;
	}
	else {
		cout << "Koyomi" << endl;
	}
	system("pause");
	return 0;
}