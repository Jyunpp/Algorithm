//20170910 14:14 ~ 14:20
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int n;
int arr[2][51];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &arr[0][i], &arr[1][i]);
	}
	for (int i = 1; i <= n; i++) {
		int ans = 1;
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			if (arr[0][i] < arr[0][j] && arr[1][i] < arr[1][j])
				ans++;
		}
		cout << ans << " ";
	}
	system("pause");
	return 0;
}