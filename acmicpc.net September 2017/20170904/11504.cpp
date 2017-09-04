//20170904 09:12 ~ 09:27
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int t, n, m, xArr[101], yArr[101], arr[101];

int main() {
	for (scanf("%d", &t); t--;) {
		int ans = 0;
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= m; i++)
			scanf(" %d", &xArr[i]);
		for (int i = 1; i <= m; i++)
			scanf(" %d", &yArr[i]);
		for (int i = 1; i <= n; i++)
			scanf(" %d", &arr[i]);
		for (int i = 1; i <= n; i++) {
			int x = 0, y = 0;
			int curr = 0;
			bool canGet = true;
			for (int j = 0; j < m; j++) {
				int curridx = i + j;
				if (curridx > n) curridx -= n;
				curr *= 10; curr += arr[curridx];
				x *= 10; x += xArr[j + 1];
				y *= 10; y += yArr[j + 1];
				if (x > curr || curr > y) {
					canGet = false;
					break;
				}
			}
			ans += canGet;
		}
		printf("%d\n", ans);
	}
	//system("pause");
	return 0;
}