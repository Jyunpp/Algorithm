//20171005 대회시간 16:05 ~ 19:05 
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

string arr[101];

int main() {
	string need;
	int n;
	cin >> need;
	cin >> n;
	bool canBark = false;
	bool haveF = false;
	bool haveS = false;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		if (arr[i] == need) {
			canBark = true;
		}
	}
	if (canBark) {
		cout << "YES" << endl;
	}
	else {
		for (int i = 1; i <= n; i++) {
			if (arr[i][1] == need[0]) {
				haveF = true;
			}
			if (arr[i][0] == need[1]) {
				haveS = true;
			}
		}
		if (haveF && haveS) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	//system("pause");
	return 0;
}