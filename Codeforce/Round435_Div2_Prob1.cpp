//20170920 대회 시간 : 00:05 ~ 02:05

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

int n, x;
int arr[101];

int main() {
	cin >> n >> x;
	for (int i = 0, a; i < n; i++) {
		cin >> a;
		arr[a] = 1;
	}
	int ans = 0;
	for (int i = 0; i < x; i++) {
		if (arr[i] == 0) {
			ans++;
		}
	}
	if (arr[x] == 1) {
		ans++;
	}
	cout << ans << endl;
	//system("pause");
	return 0;
}