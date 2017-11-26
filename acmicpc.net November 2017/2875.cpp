//20171127 03:21~03:34 ¸Ó¸®½ÄÈú°â..
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#define sd(x) scanf(" %d", &x);
#define slld(x) scanf(" %lld", &x);
#define sc(x) scanf(" %c", &x);
#define ll long long
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
	int n, m, k, temp, ret;
	cin >> n >> m >> k;
	if (n / m >= 2) {
		temp = n - m * 2;
		ret = m;
	}
	else {
		temp = m - (n / 2) + n % 2;
		ret = n / 2;
	}
	if (temp < k) {
		while (1) {
			temp += 3;
			ret--;
			if (temp >= k) break;
		}
	}
	cout << ret << endl;
	system("pause");
}