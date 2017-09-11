//20170911 22:11 ~ 22:18
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
using namespace std;

const int len = 'Z' - 'A' + 1;
int arr[len];

int main() {
	string s;
	cin >> s;
	int sz = s.size();
	for (int i = 0; i < sz; i++) {
		arr[s[i] - 'A']++;
	}
	bool odd = false;
	int oddIdx = -1;
	for (int i = 0; i < len; i++) {
		if (arr[i] % 2 == 1) {
			if (!odd) {
				odd = true;
				oddIdx = i;
			}
			else {
				cout << "I'm Sorry Hansoo" << endl;
				return 0;
			}
		}
	}
	for (int i = 0; i < len; i++) {
		int num = arr[i] / 2;
		for (int j = 1; j <= num; j++) {
			cout << char('A' + i);
		}
	}
	if (oddIdx != -1) {
		cout << char('A' + oddIdx);
	}
	for (int i = len - 1; i >= 0; i--) {
		int num = arr[i] / 2;
		for (int j = 1; j <= num; j++) {
			cout << char('A' + i);
		}
	}
	//system("pause");
	return 0;
}