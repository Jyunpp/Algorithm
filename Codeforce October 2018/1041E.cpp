// 20181004 23:25 ~ 23:42
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

#define sd(x) scanf(" %d", &x);
#define slld(x) scanf(" %lld", &x);
#define pb push_back
#define xx first
#define yy second

typedef long long ll;
typedef pair<int, int> P;

int n;

int main() {
	cin >> n;
	vector<int> ans(n+1);
	vector<int> arr(n);
	int ret = 1;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		if (max(a, b) != n) {
			ret = 0;
		}
		if (min(a, b) == n) {
			ret = 0;
		}
		arr[min(a, b)]++;
	}
	if (!ret) {
		cout << "NO" << endl;
	}
	else {
		ans[1] = n;
		int currIdx = 1;
		for (int i = n - 1; i >= 1; i--) {
			if (!arr[i]) {
				int find = 0;
				for (int j = 1; j <= currIdx; j++) {
					if (ans[j] == 0) {
						ans[j] = i;
						find = 1;
						break;
					}
				}
				if (!find) {
					ret = 0;
					break;
				}
			}
			else {
				currIdx += arr[i];
				ans[currIdx] = i;
			}
		}
		if (!ret) cout << "NO";
		else {
			cout << "YES" << endl;
			for (int i = 1; i < n; i++) {
				cout << ans[i] << " " << ans[i + 1] << endl;
			}
		}
	}
	return 0;
}