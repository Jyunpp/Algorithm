//20170920 13:39 ~ 13:58

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

int t;
string s;

int main() {
	cin >> t;
	vector<int> v;
	for (int i = 1; i <= t; i++) {
		cin >> s;
		v.clear();
		if (s == "6174") { cout << 0 << endl; continue; }
		v.push_back(s[0] - '0');
		v.push_back(s[1] - '0');
		v.push_back(s[2] - '0');
		v.push_back(s[3] - '0');
		int cnt = 0;
		while (++cnt) {
			sort(v.begin(), v.end());
			int big = 1000 * v[3] + 100 * v[2] + 10 * v[1] + v[0];
			int small = 1000 * v[0] + 100 * v[1] + 10 * v[2] + v[3];
			int curr = big - small;
			if (curr == 6174) { cout << cnt << endl; break; }
			v.clear();
			v.push_back(curr / 1000); curr %= 1000;
			v.push_back(curr / 100); curr %= 100;
			v.push_back(curr / 10); curr %= 10;
			v.push_back(curr);
		}
	}
	//system("pause");
	return 0;
}