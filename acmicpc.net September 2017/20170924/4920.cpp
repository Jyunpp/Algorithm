//20170924 12:56 ~ 13:18 ~13:47 (실수..)
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

int n, ans;
int arr[110][110];

int main() {
	int t = 0;
	while (++t) {
		cin >> n;
		if (n == 0) break;
		ans = -987654321;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				scanf(" %d", &arr[i][j]);
			}
		}
		for (int i = 1; i <= n; i++) {		//i가 y
			for (int j = 1; j <= n; j++) {	//j가 x
				//shape 1
				if (j + 3 <= n)
					ans = max(ans, arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i][j + 3]);
				if (i + 3 <= n)
					ans = max(ans, arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 3][j]);
				//shape 2, shape 3, shpae 4
				if (i + 1 <= n && j + 2 <= n) {
					ans = max(ans, arr[i][j] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 1][j + 2]);
					ans = max(ans, arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 2]);
					ans = max(ans, arr[i][j] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 1][j + 2]);
					ans = max(ans, arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 1]);
					ans = max(ans, arr[i][j + 1] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 1][j + 2]);
				}
				if (i + 2 <= n && j + 1 <= n) {
					ans = max(ans, arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 1][j] + arr[i + 2][j]);
					ans = max(ans, arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 2][j + 1] + arr[i + 2][j]);
					ans = max(ans, arr[i][j] + arr[i][j + 1] + arr[i + 1][j] + arr[i + 2][j]);
					ans = max(ans, arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 1][j + 1]);
					ans = max(ans, arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 2][j + 1] + arr[i + 1][j]);
				}
				//shape 5
				if (i + 1 <= n && j + 1 <= n)
					ans = max(ans, arr[i][j] + arr[i + 1][j] + arr[i][j + 1] + arr[i + 1][j + 1]);
			}
		}
		cout << t << ". " << ans << endl;
	}
	//system("pause");
	return 0;
}