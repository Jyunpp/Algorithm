//20170925 ��ȸ�ð� 19:35 ~ 21:35
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
	//��������
	long long MAXDIS = max(a - f, f);
	if (k >= 2 && (a - f) * 2 > B) {
		cout << "-1" << endl;
		//system("pause");			//�ϱ�
		return 0;
	}
	if (k > 2 && f * 2 > B) {
		cout << "-1" << endl;
		//system("pause");			//�ϱ�
		return 0;
	}
	if (k == 1 && MAXDIS > B) {
		cout << "-1" << endl;
		return 0;
	}
	b -= f;	//f�� �ϴ� ������
	if (b < 0) { cout << "-1" << endl; return 0; }
	int right = 0;		//%2 ==1 => right
	if (k == 1) {
		cout << (a - f > b) << endl;
		return 0;
	}
	for (int i = 1; i<k; i++) {	//�������� ���ΰ�� k-1���� �ϴ�.
		right++;
		//����
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
		//����
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
	//¦Ȧ�γ�����
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