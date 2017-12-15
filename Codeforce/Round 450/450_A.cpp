//20171215 18:38 ~ 18:43
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
#include <functional>
using namespace std;

int main() {
	int n;
	int left = 0, right = 0;
	cin >> n;
	for (int i = 1, x, y; i <= n; i++) {
		cin >> x >> y;
		if (x < 0) left++;
		else right++;
	}
	if (right == n || right == 1 || left == n || left == 1) {
		cout << "Yes" << endl;
	}
	else cout << "No" << endl;
	system("pause");
	return 0;
}