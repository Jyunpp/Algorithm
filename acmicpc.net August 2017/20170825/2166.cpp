//20170825 01:36 ~ 01:58
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef long long ll;

int n;
ll x[10001], y[10001];

ll ccw(ll vx1, ll vy1, ll vx2, ll vy2) {
	return vx1*vy2 - vx2*vy1;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf(" %lld %lld", &x[i], &y[i]);
	}
	ll ans = 0;
	for (int i = 2; i <= n - 1; i++)
		ans += ccw(x[i] - x[1], y[i] - y[1], x[i + 1] - x[i], y[i + 1] - y[i]);
	if (ans < 0) ans *= -1;
	printf("%.1Lf", (long double)ans/2);
	//system("pause");
	return 0;
}