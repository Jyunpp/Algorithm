//20170811 3:05 ~ 3:10 기분전환..
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <algorithm>
#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

int n;
vector<int> v;

int main() {
	scanf("%d", &n);
	v.resize(n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &v[i-1]);
	sort(v.begin(), v.end());
	for (auto &i : v) {
		printf("%d\n", i);
	}
	//system("pause");
	return 0;
}