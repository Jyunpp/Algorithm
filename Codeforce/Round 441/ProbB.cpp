//20171016 대회시간 20:05 ~ 22:05
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

int arr[100001];
vector<int> dp[100001];
int n, k, m;


int main() {
	cin >> n >> k >> m;
	for (int i = 1; i <= n; i++) {
		scanf(" %d", &arr[i]);
		int currRem = arr[i] % m;
		dp[currRem].push_back(arr[i]);
	}
	for (int i = 0; i <= n; i++) {
		if (dp[i].size() >= k) {
			cout << "YES" << endl;
			for (int j = 0; j < k-1; j++) {
				printf("%d ", dp[i][j]);
			}
			printf("%d", dp[i][k - 1]);
			//system("pause");
			return 0;
		}
	}
	cout << "NO" << endl;
	//system("pause");
	return 0;
}