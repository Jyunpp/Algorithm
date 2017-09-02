//20170901 15:37 ~ 15:42
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <iostream>
#include <stdio.h>
using namespace std;

int t, n;
int arr[1001];

int main() {
	for (scanf("%d", &t); t--; ) {
		scanf(" %d", &n);
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			scanf(" %d", &arr[i]);
		}
		for (int i = 1; i < n; i++) {
			for (int j = 1; j <= n - i; j++) {
				if (arr[j] > arr[j + 1]) {
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
					ans++;
				}
			}
		}
		printf("%d\n", ans);
	}
	//system("pause");
	return 0;
}