//20170812 15:42 ~ 18:50
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
/*
	classified
*/
#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int arr[33000], n, maxN;

void preOrder(int idx) {
	printf("%d ", arr[idx]);
	if (idx * 2 <= maxN) {
		preOrder(idx * 2);
		preOrder(idx * 2 + 1);
	}
}

int main() {
	cin >> n;
	maxN = pow(2, n) - 1;
	arr[1] = 1;
	for (int i = 1; i < n; i++) {
		//classified
	}
	preOrder(1);
	system("pause");
	return 0;
}
