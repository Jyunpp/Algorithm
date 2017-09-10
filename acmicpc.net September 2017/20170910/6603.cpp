//20170910 14:41 ~ 15:00
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int arr[14];
vector<int> v;

void solve(int idx, int k) {
	if (v.size() == 6) {
		for (auto &i : v) printf("%d ", i);
		printf("\n");
		return;
	}
	if (idx > k) return;
	v.push_back(arr[idx]);
	solve(idx + 1, k);
	v.pop_back();
	solve(idx + 1, k);
}

int main() {
	int k;
	scanf("%d", &k);
	while (k) {
		for (int i = 1; i <= k; i++) {
			scanf(" %d", &arr[i]);
		}
		solve(1, k);
		scanf("%d", &k);
		cout << endl;
	}
	return 0;
}