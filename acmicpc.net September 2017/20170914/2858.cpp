//20170914 22:27 ~ 22:31
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;

int R, B;

int main() {
	scanf("%d %d", &R, &B);
	int total = R + B;
	int ans1, ans2;
	for (int i = 3; i <= sqrt(total); i++) {
		if (total%i != 0) continue;
		int L = total / i;
		if (2 * (L + i) - 4 == R) {
			ans1 = L;
			ans2 = i;
			break;
		}
	}
	cout << ans1 << " " << ans2 << endl;
	//system("pause");
	return 0;
}