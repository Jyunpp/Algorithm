//20171026 대회시간 23:35 ~ 01:35
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#define sd(x) scanf(" %d", &x);
#define slld(x) scanf(" %lld", &x);
#define sc(x) scanf(" %c", &x);
#define ll long long
#define pb push_back
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
long long k;
int arr[501];
//output은 winner의 power
int temp = -987654321;
int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		scanf(" %d", &arr[i]);
		temp = max(temp, arr[i]);
	}
	if (k > n) {
		cout << temp << endl;
		//system("pause");
		return 0;
	}
	queue<pair<int, long long>> q;
	for (int i = 1; i <= n; i++) {
		q.push(make_pair(i, 0));
	}
	int ans = -1;
	int currIdx = q.front().xx;
	long long currTimes = q.front().yy;
	q.pop();
	while (1) {
		if (currTimes == k) {
			ans = arr[currIdx];
			break;
		}
		int nextIdx = q.front().xx;
		long long nextTimes = q.front().yy;
		int curr = arr[currIdx];
		int next = arr[nextIdx];
		if (curr < next) {
			currIdx = nextIdx;
			currTimes = nextTimes + 1;
			q.pop();
			q.push(make_pair(currIdx, currTimes));
		}
		else {
			currTimes++;
			q.pop();
			q.push(make_pair(nextIdx, nextTimes));
		}
	}
	cout << ans << endl;
	//system("pause");
	return 0;
}