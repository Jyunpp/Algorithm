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
		//���� ������ ������ ¦���� ��. => ����
		
		//¦�� �´� ������ ���� r���� ¦������ŭ�� �ϳ����� ������ �ǰ� �������� ���ʴ� ������.
		//¦������ŭ => r-r%2 ���� ���ݾ��� l,r���ʿ� => r-r%2
		//������ r%2���� ���ʴ�						  => 2*(r%2)
		cout << t << ". " << (l - r) / 2 + r + r % 2 << endl;
	}
	//system("pause");
	return 0;
}