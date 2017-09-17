//20170917 04:03 ~ 04:22
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <stdio.h>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

int n;
pair<int, int> arr[101];
int ansA, ansB;

long long calGap(int a, int b, int x, int y) {
	long long fx = a*x + b;
	return (fx - y)*(fx - y);
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf(" %d %d", &arr[i].first, &arr[i].second);
	}
	long long gap = 9223372036854775800;
	long long sum;
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			sum = 0;
			for (int k = 1; k <= n; k++) {
				sum += calGap(i, j, arr[k].first, arr[k].second);
				if (sum > gap) continue;
			}
			if (sum < gap) {
				gap = sum;
				ansA = i; ansB = j;
			}
		}
	}
	cout <<ansA<< " " <<ansB<<endl;
//	system("pause");
	return 0;
}