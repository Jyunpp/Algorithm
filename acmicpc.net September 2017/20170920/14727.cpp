//20170920 ¥Î»∏ 19:00 ~ 21:00

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

vector<int> h;
int solve(int left, int right);

int main() {
	int n;
	cin >> n;
	for (int i = 1, a; i <= n; i++) {
		scanf(" %d", &a);
		h.push_back(a);
	}
	int ans = solve(0, n - 1);
	cout << ans << endl;
	//system("pause");
	return 0;
}

int solve(int left, int right) {
	if (left == right) return h[left];
	int mid = (left + right) / 2;

	int ret = max(solve(left, mid), solve(mid + 1, right));
	int lo = mid, hi = mid + 1;
	int heght = min(h[lo], h[hi]);
	ret = max(ret, heght * 2);
	while (left < lo || hi < right) {
		if (hi < right && (lo == left || h[lo - 1] < h[hi + 1])) {
			++hi;
			heght = min(heght, h[hi]);
		}
		else {
			--lo;
			heght = min(heght, h[lo]);
		}
		ret = max(ret, heght * (hi - lo + 1));
	}
	return ret;
}