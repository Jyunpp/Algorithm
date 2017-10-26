//20171026 대회시간 23:35 ~ 01:35
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#define sd(x) scanf(" %d", &x);
#define slld(x) scanf(" %lld", &x);
#define sc(x) scanf(" %c", &x);
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
int arr[1001][2];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf(" %d %d", &arr[i][0], &arr[i][1]);
	}
	int ans = arr[1][0];
	for (int i = 2; i <= n; i++ ) {
		if (ans < arr[i][0]) {
			ans = arr[i][0];
		}
		else {
			int temp = arr[i][0];
			while (ans >= temp) {
				temp += arr[i][1];
			}
			ans = temp;
		}
	}
	cout << ans << endl;
//	system("pause");
	return 0;
}