//20170922 대회시간 00:05 ~ 02:05

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

int main() {
	int n;
	scanf("%d", &n);
	while (n % 10 == 0) {
		n /= 10;
	}
	int a = 0;
	int temp = n;
	while (temp) {
		a *= 10;
		a += temp % 10;
		temp /= 10;
	}
	if (a == n) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	//system("pause");
	return 0;
}