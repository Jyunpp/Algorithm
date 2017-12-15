//20171215 18:46 ~ 18:53
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
	int a, b, c;
	int cnt = 0;
	bool finded = false;
	cin >> a >> b >> c;
	while (cnt++ < 100000){
		a *= 10;
		int check = a / b;
		a %= b;
		if (check == c) {
			finded = true;
			break;
		}
	}
	if (!finded) cnt = -1;
	cout << cnt << endl;
	system("pause");
	return 0;
}