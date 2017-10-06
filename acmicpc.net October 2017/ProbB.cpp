//20171006 대회시간 22:35 ~ 00:35
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#define sd(x) scanf(" %d", &x);
#define slld(x) scanf(" %lld", &x);
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

int main() {
	long long a, b;
	cin >> a >> b;
	long long temp = 1;
	if (a > b) {
		cout << 0 << endl;
		//system("pause");
		return 0;
	}
	if (a == b) {
		cout << 1 << endl;
		//system("pause");
		return 0;
	}
	
	if ((b - a) < 10) {
		for (long long i = a + 1; i <= b; i++) {
			temp *= i;
			temp %= 10;
		}
		cout << temp << endl;
		//system("pause");
		return 0;
	}
	else {
		cout << 0 << endl;
		//system("pause");
		return 0;
	}
	//system("pause");
	return 0;
}