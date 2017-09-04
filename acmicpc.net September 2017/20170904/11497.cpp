//20170904 08:32 ~ 08:45
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int t, n, h[100000];

int main() {
	for (scanf("%d", &t); t--;) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) 
			scanf(" %d", &h[i]);
		sort(h, h + n);
		int ans = h[1] - h[0];
		for (int i = 2; i < n; i++)
			ans = max(ans, max(h[i] - h[i - 1], h[i] - h[i - 2]));
		printf("%d\n", ans);
	}
	//system("pause");
	return 0;
}