//20170925 대회시간 19:35 ~ 21:35
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

vector<int> v;
int cnt[30];

int main() {
	int n;
	string s;
	cin >> n;
	cin >> s;
	v.push_back(-1);
	for (int i = 0; i < n; i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') v.push_back(i);
	}
	v.push_back(n);
	int ans = 0;
	int sz = v.size();
	for (int i = 0; i < sz - 1; i++) {
		int curr = v[i];
		int next = v[i + 1];

		for (int A = 0; A < 30; A++) cnt[A] = 0;
		int temp = 0;
		for (int j = curr + 1; j < next; j++) {
			if (cnt[s[j] - 'a'] == 0) {
				temp++;
				cnt[s[j] - 'a']++;
			}
		}
		ans = max(temp, ans);
	}
	cout << ans << endl;
	//system("pause");
	return 0;
}