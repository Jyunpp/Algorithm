//20181001 22:02 ~ 23:30
// TLE 및 중복코드 제거할 필요.. 다시 하기로..
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
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

int n, h;
pair<int, int> arr[200001]; //{x1, x2}

int main() {
	cin >> n >> h;
	for (int i = 1; i <= n; i++) {
		sd(arr[i].xx);
		sd(arr[i].yy);
	}
	int ans = arr[1].yy - arr[1].xx;
	int rest = 0;
	int currH = h;
	int i = 2; // i 갈 차례
	while (currH > 0) {
		if (i > n) break;
		int dis = arr[i].xx - arr[i - 1].yy;
		if (currH >= dis) {
			ans += dis; rest = 0;
			currH -= dis;
			if (currH > 0) {
				ans += arr[i].yy - arr[i].xx;
				i++;
			}
		}
		else {
			rest = currH;
			currH = 0;
		}
	}
	int Ans = ans + rest + currH;
	int j = 1;
	while (i <= n) {
		if (i - 1 != j) {
			currH += arr[j + 1].xx - arr[j].yy;
			ans -= arr[j + 1].xx - arr[j].xx;
			rest = 0;
			j++;
			while (currH > 0) {
				if (i > n) break;
				int dis = arr[i].xx - arr[i - 1].yy;
				if (currH >= dis) {
					ans += dis; rest = 0;
					currH -= dis;
					if (currH > 0) {
						ans += arr[i].yy - arr[i].xx;
						i++;
					}
				}
				else {
					rest = currH;
					currH = 0;
				}
			}
			Ans = max(Ans, ans + rest + currH);
		}
		else {
			ans = arr[j].yy - arr[j].xx;
			rest = 0;
			currH = h;
			Ans = max(Ans, ans + currH);
			while (currH > 0) {
				if (i > n) break;
				int dis = arr[i].xx - arr[i - 1].yy;
				if (currH >= dis) {
					ans += dis; rest = 0;
					currH -= dis;
					if (currH > 0) {
						ans += arr[i].yy - arr[i].xx;
						i++;
					}
				}
				else {
					rest = currH;
					currH = 0;
				}
			}
			Ans = max(Ans, ans + rest + currH);
		}
	}
	Ans = max(Ans, ans + rest + currH);
	cout << Ans << endl;
	//cin >> n;
	return 0;
}