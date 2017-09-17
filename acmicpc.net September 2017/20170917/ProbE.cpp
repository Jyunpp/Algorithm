//20170917 03:56 ~ 03:59
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <stdio.h>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	int curr = 0;
	int ans = 0;
	for (int i = 1, a; i <= n; i++) {
		cin >> a;
		if (a == curr) {
			ans++;
			curr++;
			curr %= 3;
		}
	}
	cout << ans << endl;
	//system("pause");
	return 0;
}