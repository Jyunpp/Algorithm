//20170915 09:48 ~ 10:27
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <stdio.h>
#include <string>
#include <memory.h>
#include <algorithm>
using namespace std;

//s2에서 s1을 같은 간격을 가지는 형태로 찾을 수 있는가.
bool canFind(string s1, string s2) {
	int sz1 = s1.size();
	int sz2 = s2.size();
	bool ret = false;
	//s2의 각 i에서 찾음.
	for (int i = 0; i < sz2; i++) {
		//첫 번째 글자를 찾으면 시작.
		if (s2[i] == s1[0]) {
			//각 간격별 조사.
			for (int gap = 0; ++gap;) {		//이렇게 해야 gap : 1부터 시작			★
											//gap = 1; gap++ 로하면 2부터 시작		★
											//gap = 0; gap++ 로하면 0이라 안돌음.	★
				//가지치기
				if (i + gap*(sz1 - 1) > sz2) { break; }
				bool currRet = true;
				for (int j = 1; j < sz1; j++) {
					if (s2[i + j*gap] != s1[j]) {
						currRet = false;
						break;
					}
				}
				//찾았으면 간격별 조사 종료
				if (currRet) {
					ret = true;
					break;
				}
			}
		}
		//찾았으면 종료
		if (ret) break;
	}
	return ret;
}

int main() {
	int t;
	cin >> t;
	string name, s;
	cin >> name;
	int ans = 0;
	for (; t--;) {
		cin >> s;
		if (canFind(name, s)) ans++;
	}
	cout << ans << endl;
	//system("pause");
	return 0;
}
