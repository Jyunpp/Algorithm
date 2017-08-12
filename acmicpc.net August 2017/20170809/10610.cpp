//20170809 21:53 ~ 22:05
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

string str;
int frequency[10];//각 숫자의 빈도

int main() {
	cin >> str;
	int len = str.size();
	int sum = 0;
	for (int i = 0; i < len; i++) {
		frequency[str[i] - '0']++;
		sum += str[i] - '0';
	}
	//0이 없거나 합이 3의 배수가 아니라면 불가능.
	if (!frequency[0] || sum % 3 != 0) {
		cout << -1 << endl;
		return 0;
	}
	for (int i = 9; i >= 0; i--) {
		while (frequency[i]--)
			printf("%d", i);
	}
	system("pause");
	return 0;
}