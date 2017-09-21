//20170920 ¥Î»∏ 19:00 ~ 21:00

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
int arr[501][501];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x1, y1, x2, y2;
		scanf(" %d %d %d %d", &x1, &y1, &x2, &y2);
		for (int x = x1 + 1; x <= x2; x++) {
			for (int y = y1 + 1; y <= y2; y++) {
				arr[x][y]++;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= 500; i++) {
		for (int j = 1; j <= 500; j++) {
			if (arr[i][j]) ans++;
		}
	}
	cout << ans << endl;
	//system("pause");
	return 0;
}