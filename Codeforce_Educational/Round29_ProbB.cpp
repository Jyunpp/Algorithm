//20170922 대회시간 00:05 ~ 02:05

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

int n;
int w[100];

int main() {
	cin >> n;
	int N = 2 * n;
	for (int i = 0; i < 100; i++) {
		w[i] = 987654321;
	}
	for (int i = 0; i < N; i++) {
		scanf(" %d", &w[i]);
	}
	sort(w, w + 100);
	int ans = 987654321;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			//i, j를 제외 후, 나머지 친구들로 짝지어보기.
			int temp = 0;
			int idx = 0;
			int cnt = 0;
			while (cnt < n - 1) {
				if (idx == i || idx == j) {
					idx++; continue;
				}
				int next = idx + 1;
				while (next == i || next == j) {
					next++;
				}

				int differ = w[idx] - w[next];
				if (differ < 0) differ *= -1;

				temp += differ;
				idx = next + 1;
				cnt++;
			}
			ans = min(ans, temp);
		}
	}
	cout << ans << endl;
	//system("pause");
	return 0;
}