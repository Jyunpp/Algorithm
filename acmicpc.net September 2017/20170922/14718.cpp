//20170922 22:01 ~ 22:37
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#define xx first
#define yy second
#define MAX_Y 100000

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

struct knight {
	int a, b, c;
}; 

knight s[101];
int n, K;
int ans = 987654321;
vector<int> va, vb, vc;

int main() {
	cin >> n >> K;
	for (int i = 1; i <= n; i++) {
		scanf(" %d %d %d", &s[i].a, &s[i].b, &s[i].c);
		va.push_back(s[i].a);
		vb.push_back(s[i].b);
		vc.push_back(s[i].c);
	}
	sort(va.begin(), va.end());
	sort(vb.begin(), vb.end());
	sort(vc.begin(), vc.end());
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				int ca = va[i];
				int cb = vb[j];
				int cc = vc[k];
				int temp = ca + cb + cc;
				int cnt = 0;
				bool canStop = false;
				for (int l = 1; l <= n; l++) {
					if (s[l].a <= ca && s[l].b <= cb && s[l].c <= cc) {
						cnt++;
						if (cnt >= K) {
							ans = min(ans, temp);
							canStop = true;
							break;
						}
					}
				}
				if(canStop) break;
			}
		}
	}
	cout << ans << endl;
	//system("pause");
	return 0;
}