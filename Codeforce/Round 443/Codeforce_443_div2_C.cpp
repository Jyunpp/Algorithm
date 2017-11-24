//20171125 02:00 ~ 02:32
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
	int n;
	cin >> n;
	int x = 1023;
	int y = 0;
	for (int i = 1; i <= n; i++) {
		char op;
		int num;
		cin >> op >> num;
		if (op == '|') {
			x |= num;
			y |= num;
		}
		else if (op == '^') {
			x ^= num;
			y ^= num;
		}
		else {
			x &= num;
			y &= num;
		}
	}
	int xor = ~x; xor &= 1023;
	int or = ~(x^y); or &= 1023;

	cout << 2 << endl;
	cout << "| " << or << endl;
	cout << "^ " << xor;
	system("pause");
	return 0;
}