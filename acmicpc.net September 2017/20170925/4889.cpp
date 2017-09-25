//20170925 08:49 ~ 09:12
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

string s;

int main() {
	int t = 0;
	while (++t) {
		cin >> s;
		int l = 0, r = 0;
		for (auto &i : s) {
			if (i == '-') return 0;
			if (i == '{')l++;
			else { if (l)l--; else r++; }
		}
		if (l < r) swap(l, r);
		//차이 갯수는 무조건 짝수일 것. => 절반
		
		//짝이 맞는 나머지 갯수 r개는 짝수개만큼은 하나씩만 돌리면 되고 나머지는 양쪽다 돌려야.
		//짝수개만큼 => r-r%2 개중 절반씩이 l,r양쪽에 => r-r%2
		//나머지 r%2개는 양쪽다						  => 2*(r%2)
		cout << t << ". " << (l - r) / 2 + r + r % 2 << endl;
	}
	//system("pause");
	return 0;
}