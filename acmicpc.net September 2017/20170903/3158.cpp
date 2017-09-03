//20170903 14:40 ~ 15:15(구상) ~ 15:48(구현)
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

string s;
bool num[5];
int len;
int ansNum = 0;
int printedNum = 0;

int main() {
	cin >> s;
	num[1] = num[2] = num[3] = false;
	len = s.size();
	//끝이 4
	if (s[len - 1] == '4') {
		for (int i = 1; i <= 3; i++) {
			string ansS = s.substr(0, len - 1);
			ansS += ('0' + i);
			cout << ansS << endl;
		}
	}
	//끝이 1,2,3
	else {
		for (int i = 1; i < len; i++)
			num[s[i] - '0'] = true;
		ansNum = num[1] + num[2] + num[3];
		num[1] = num[2] = num[3] = false;
		int i = len - 1;
		string ansS = s.substr(0, i) + '4';
		cout << ansS << endl;
		printedNum++;
		while (printedNum != ansNum) {
			num[s[i] - '0'] = true;
			s = s.substr(0, i--);
			int curr = s[i] - '0';
			//이번 숫자를 4로 바꾼 삼각형이 기댄 삼각형 이려면, 이전에 존재했던 숫자들이
			//이번 숫자 이외의 숫자여야 한다.
			bool canPrint = !num[curr];
			if (canPrint) {
				ansS = s.substr(0, i) + '4';
				cout << ansS << endl;
				printedNum++;
			}
		}
	}
	system("pause");
	return 0;
}