//20170924 대회시간 23:35 ~ 02:00
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#define xx first
#define yy second
#define MAX_Y 100000

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

int n;
string arr[101];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		bool Y = false;
		for (int j = 1; j < i; j++) {
			if (arr[i] == arr[j]) {
				Y = true;
				break;
			}
		}
		if (Y) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	//system("pause");
	return 0;
}