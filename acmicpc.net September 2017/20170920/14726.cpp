//20170920 대회 19:00 ~ 21:00

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
	int T;
	cin >> T;
	int val;
	for (int i = 1; i <= T; i++) {
		val = 0;
		string s;
		cin >> s;
		for (int j = 15; j >= 0; j--) {
			if (j % 2 == 1) {//이게 홀수
				val += (s[j] - '0');
			}
			else {
				int num = s[j] - '0';
				num *= 2;
				val += (num % 10);
				val += (num / 10);
			}
		}
		if (val % 10 == 0) {
			cout << "T" << endl;
		}
		else
			cout << "F" << endl;
	}
	//system("pause");
	return 0;
}
