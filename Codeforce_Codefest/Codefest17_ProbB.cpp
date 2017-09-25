//20170924 대회시간 23:35 ~ 02:00
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#define xx first
#define yy second
#define max_y 100000

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
int p, q, r;
long long arr[100001];
long long ans = -9223372036854775800;
long long min1toi[100001];
long long max1toi[100001];
long long miniton[100001];
long long maxiton[100001];

int main() {
	cin >> n >> p >> q >> r;
	for(int i=1; i<=n; i++){
		scanf(" %lld", &arr[i]);
	}
	//전처리
	long long currMin = arr[1];
	long long currMax = arr[1];
	min1toi[1] = max1toi[1] = arr[1];
	for (int i = 2; i <= n; i++) {
		currMin = min(currMin, arr[i]); min1toi[i] = currMin;
		currMax = max(currMax, arr[i]); max1toi[i] = currMax;
	}
	currMin = arr[n];
	currMax = arr[n];
	miniton[n] = maxiton[n] = arr[n];
	for (int i = n - 1; i >= 1; i--) {
		currMin = min(currMin, arr[i]); miniton[i] = currMin;
		currMax = max(currMax, arr[i]); maxiton[i] = currMax;
	}

	long long a, b, c;
	for (int i = 1; i <= n; i++) {
		b = q*arr[i];
		//p가 음수면 그 앞에 제일 작은 숫자로 p를 곱하고 양수면 제일 큰수로 p를 곱함.
		if (p < 0) a = min1toi[i] * p;
		else a = max1toi[i] * p;
		//r이 음수면 그 뒤에 제일 작은 숫자로 r을 곱하고 양수면 제일 큰수로 r를 곱함.
		if (r < 0) c = miniton[i] * r;
		else c = maxiton[i] * r;
		ans = max(ans, a + b + c);
	}
	cout << ans << endl;
	//system("pause");
	return 0;
}