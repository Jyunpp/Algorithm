//20171015 대회시간 17:05 ~ 19:05
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

int q, n;

int solve(int n) {
	if (n % 2 && n<=8) return -1;
	if (n <= 3)return -1;
	if (n ==11) {
		return -1;
	}
	if (n % 2) {
		return 1 + (n - 9) / 4;
	}
	int temp = n / 4;
	return temp;
}

int main() {
	cin >> q;
	for (int i = 1; i <= q; i++) {
		scanf(" %d", &n);
		printf("%d\n", solve(n));
	}
	//system("pause");
	return 0;
}