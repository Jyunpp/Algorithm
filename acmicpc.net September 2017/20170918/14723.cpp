//20170918 02:30 ~ 02:36
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#define xx first
#define yy second

#include <iostream>
#include <stdio.h>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <math.h>
#include <queue>
using namespace std;

int main() {
	int n;
	cin >> n;
	int goon = 0;
	int sum = 0;
	for (int i = 1; i <= 50; i++) {
		if (sum + i >= n) { break; }
		goon++;
		sum += i;
	}
	int num = n - sum - 1;
	int a = goon + 1 - num;
	int b = 1 + num;
	cout << a << " " << b << endl;
	//system("pause");
	return 0;
}