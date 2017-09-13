//20170913 14:14 ~ 14:18
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
using namespace std;

int n, ans;

int main() {
	cin >> n;
	string s;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		int sz = s.size();
		if (sz == 1) {
			ans++; continue;
		}
		else {
			bool win = true;
			for (int j = 1; j < sz; j++) {
				int prev = s[j - 1];
				int curr = s[j];
				if (prev == 'C' && curr == 'D') {
					win = false;
					break;
				}
			}
			if (win) ans++;
		}
	}
	cout << ans << endl;
	system("pause");
	return 0;
}