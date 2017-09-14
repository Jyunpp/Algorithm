//20170913 14:37 ~ 14:40
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
using namespace std;

int n, ans;

int cal(int n, int jin) {
	int ret = 0;
	int curr = n;
	for (int i = 1; i <= 4; i++) {
		ret += curr%jin;
		curr /= jin;
	}
	return ret;
}

int main() {
	for (int n = 1000; n <= 9999; n++) {
		int a, b, c;
		a = cal(n, 10);
		b = cal(n, 12);
		c = cal(n, 16);
		if (a == b && b == c)
			cout << n << endl;
	}
	system("pause");
	return 0;
}