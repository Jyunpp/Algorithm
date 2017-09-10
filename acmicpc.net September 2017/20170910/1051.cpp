//20170910 15:09 ~ 15:30
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

char arr[51][51];
int n, m;

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %c", &arr[i][j]);
		}
	}
	int ans = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char curr = arr[i][j];
			for (int k = i+1; k <= n; k++) {
				if (arr[k][j] != curr) continue;
				int o = j + (k - i);
				if (o > m) continue;
				if (arr[i][o] == curr && arr[k][o] == curr)
					ans = max(ans, (k - i + 1) * (o - j + 1));
			}
		}
	}
	cout << ans << endl;
	//system("pause");
	return 0;
}