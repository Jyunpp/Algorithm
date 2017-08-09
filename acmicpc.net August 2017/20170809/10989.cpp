//20170809 20: 18 ~ 20:23
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <iostream>
using namespace std;

int arr[10001], n, i;

int main() {
	for (scanf("%d", &n); n--;) {
		scanf("%d", &i);
		arr[i]++;
	}
	for (i = 1; i <= 10000; i++) {
		while (arr[i]--) {
			printf("%d\n", i);
		}
	}
	system("pause");
	return 0;
}