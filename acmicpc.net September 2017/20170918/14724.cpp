//20170918 04:48 ~ 04:54
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#define xx first
#define yy second

#include <iostream>
#include <stdio.h>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <math.h>
#include <queue>
using namespace std;

string name[9] = { "PROBRAIN", "GROW", "ARGOS", "ADMIN", "ANT", "MOTION", "SPG", "COMON", "ALMIGHTY" };

int main() {
	int n;
	cin >> n;
	int maxIdx = -1;
	int maxScore = -1;
	for (int i = 0; i < 9; i++) {
		int tempMax = 0;
		for (int j = 0, a; j < n; j++) {
			scanf(" %d", &a);
			tempMax = max(a, tempMax);
		}
		if (maxScore < tempMax) {
			maxScore = tempMax;
			maxIdx = i;
		}
	}
	cout << name[maxIdx] << endl;
//	system("pause");
	return 0;
}