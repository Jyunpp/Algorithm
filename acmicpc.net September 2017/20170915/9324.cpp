//20170915 09:14 ~ 09:38
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <stdio.h>
#include <string>
#include <memory.h>
#include <algorithm>
using namespace std;

const int SIZE = 'Z' - 'A' + 1;

int arr[SIZE];

int main() {
	string s;
	int t;
	for (scanf("%d", &t); t--;) {
		memset(arr, 0, sizeof(int) * SIZE);
		cin >> s;
		int sz = s.length();
		bool isReal = true;
		for (int i = 0; i < sz; i++) {
			int curr = s[i] - 'A';
			arr[curr]++;
			if (arr[curr] == 3) {
				if (i + 1 == sz || s[i + 1] != s[i]) {
					isReal = false;
					break;
				}
				else {
					arr[curr] = 0;
					i++;
				}
			}
		}
		if (isReal) cout << "OK" << endl;
		else cout << "FAKE" << endl;
	}
	//system("pause");
	return 0;
}
