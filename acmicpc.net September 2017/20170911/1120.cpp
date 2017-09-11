//20170911 22:02 ~ 22:07
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	string a, b;
	cin >> a >> b;
	int szA = a.size();
	int szB = b.size();
	int ans = 987654321;
	for (int i = 0; i <= szB - szA; i++) {
		int temp = 0;
		for (int j = 0; j < szA; j++) {
			if (a[j] != b[i + j]) temp++;
		}
		ans = min(ans, temp);
	}
	cout << ans << endl;
	//system("pause");
	return 0;
}