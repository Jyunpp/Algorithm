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

long long a, b, f, k;

int main() {
	long long ans = 0;
	cin >> a >> b >> f >> k;
	long long B = b;
	//종료조건
	long long MAXDIS = max(a - f, f);
	if (k >= 2 && (a - f) * 2 > B) {
		cout << "-1" << endl;
		//system("pause");			//하기
		return 0;
	}
	if (k > 2 && f * 2 > B) {
		cout << "-1" << endl;
		//system("pause");			//하기
		return 0;
	}
	if (k == 1 && MAXDIS > B) {
		cout << "-1" << endl;
		return 0;
	}
	b -= f;	//f로 일단 보내자
	if (b < 0) { cout << "-1" << endl; return 0; }
	int right = 0;		//%2 ==1 => right
	if (k == 1) {
		cout << (a - f > b) << endl;
		return 0;
	}
	for (int i = 1; i<k; i++) {	//마지막은 따로계산 k-1번만 일단.
		right++;
		//우측
		if (right % 2) {
			if ((a - f) * 2 > b) {
				ans++;
				b = B;
				b -= ((a - f) * 2);
			}
			else {
				b -= ((a - f) * 2);
			}
		}
		//좌측
		else {
			if (f * 2 > b) {
				ans++;
				b = B;
				b -= 2 * f;
			}
			else {
				b -= 2 * f;
			}
		}
	}
	//짝홀로나누기
	if (k % 2) {
		if (b < a - f) ans++;
	}
	else {
		if (b < f) ans++;
	}
	cout << ans << endl;
	//system("pause");
	return 0;
}