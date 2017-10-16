//20171016 대회시간 20:05 ~ 22:05
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#define sd(x) scanf(" %d", &x);
#define slld(x) scanf(" %lld", &x);
#define sc(x) scanf(" %c", &x);
#define ll long long
#define pb push_back
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

int n, a, b, c;

int main() {
	cin >> n >> a >> b >> c;
	int ans = 0;
	if (n == 1) {
		cout << 0 << endl;
		return 0;
	}
	else {
		n--;
		int MIN = min(min(a, b), c);
		if (n == 1) {
			cout << min(a, b) << endl;
			return 0;
		}
		if (MIN == c) {
			cout << min(a, b) + c*(n - 1) << endl;
			//system("pause");
			return 0;
		}
		else {
			cout << MIN*n << endl;
			return 0;
		}

	}
	return 0;
}
