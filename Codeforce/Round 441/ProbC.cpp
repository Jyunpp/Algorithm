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

int n, k;
vector<int> v;

int main() {
	cin >> n;
	int i = 1;
	int temp = 0;
	while (n / i) {
		i *= 10;
		temp++;
	}
	i /= 10;
	int c = n - (temp * 9);

	for (int i = c; i <= n; i++) {
		int curr = i;
		int sumOfDigits = curr % 10;
		while (curr / 10) {
			sumOfDigits += (curr / 10) % 10;
			curr /= 10;
		}
		sumOfDigits += i;
		if (sumOfDigits == n) {
			v.push_back(i);
		}
	}
	cout << v.size() << endl;
	for (auto &i : v) {
		cout << i << endl;
	}
	//system("pause");
	return 0;
}