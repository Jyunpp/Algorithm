//20170925 대회시간 19:35 ~ 21:35
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
int arr[101];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		arr[a]++;
	}
	int cnt = 0;
	vector<int> v;
	for (int i = 1; i <= 100; i++) {
		if (arr[i]) {
			cnt++;
			v.push_back(i);
		}
	}
	if (cnt != 2) {
		cout << "NO" << endl;
	}
	else {
		if (arr[v[0]] == arr[v[1]]) {
			cout << "YES" << endl;
			cout << v[0] << " " << v[1] << endl;
		}
		else { cout << "NO" << endl; }
	}
	//system("pause");
	return 0;
}