//20170914 10:46 ~ 20:07
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;

int n;
long long ans[10];

int main() {
	scanf("%d", &n);
	int curr = 1;		//현재 자릿수
	int prev = 0;		//현재 자릿수의 숫자가 나올 횟수를 구하기 위해 저장.
	while (n) {
		int currNum = n % 10;	//현재 자릿수의 숫자 
		int nOverTen = n / 10;	//현재 자릿수 이상 부분의 숫자. A

		//각각의 숫자에 대해서 현재 자릿수 위치에서 몇 번 나올지 계산.

		//currNum보다 큰 숫자는 (A * 현재 자릿수) 만큼 나옴.
		for (int i = currNum + 1; i <= 9; i++) {
			ans[i] += nOverTen*curr;
		}
		//currNum은 (A * 현재 자릿수 만큼) 나오며
		//prev 부분 동안은 currNum이므로 prev + 1만큼 추가로 나온다.
		ans[currNum] += nOverTen*curr + prev + 1;
		//currNum보다 작은 숫자는 ((A+1) * 현재 자릿수) 만큼 나옴.
		for (int i = 0; i < currNum; i++) {
			ans[i] += (nOverTen + 1) *curr;
		}
		//이 때, 0이 제일 앞자리 숫자일 수 없으므로, curr만큼 빼준다.
		ans[0] -= curr;
		prev += currNum*curr;
		curr *= 10;
		n /= 10;
	}
	for (int i = 0; i <= 9; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	//system("pause");
	return 0;
}