//20170908 17:57 ~ 18:15 (거의 다 구현..) ~ 20:26 (고침..)
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

#define xx first
#define yy second
#define pb push_back
#define mp make_pair
using namespace std;

int visited[300001];
vector<pair<pair<int, int>, int> > v;
int n;

int main()
{
	scanf("%d", &n);
	for (int i = 1, a, b; i <= n; i++) {
		scanf(" %d %d", &a, &b);
		v.pb(mp(mp(a, 0), i));
		v.pb(mp(mp(b, 1), i));
	}
	sort(v.begin(), v.end(), [](pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {return (a.xx.xx != b.xx.xx ? a.xx.xx<b.xx.xx : a.xx.yy <= b.xx.yy); });
	int ans = 0;
	int temp = 0;
	int lastidx = 0;
	int idx = -1;
	for (auto &i : v) {
		idx++;
		if (i.xx.yy == 0) {
			temp++;
			if (temp>ans) {
				lastidx = idx;
				ans = temp;
			}
		}
		else {
			temp--;
		}
	}
	printf("%d\n", ans);
	int cnt = 0;
	for (int i = lastidx; i >= 0; i--) {
		if (v[i].xx.yy == 0 && visited[v[i].yy] != 1) {
			printf("%d ", v[i].yy);
			cnt++;
			if (cnt == ans) { break; }
		}
		else if(v[i].xx.yy==1){
			visited[v[i].yy] = 1;
		}
	}
	//system("pause");
	return 0;
}
