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

//s2���� s1�� ���� ������ ������ ���·� ã�� �� �ִ°�.
bool canFind(string s1, string s2) {
	int sz1 = s1.size();
	int sz2 = s2.size();
	bool ret = false;
	//s2�� �� i���� ã��.
	for (int i = 0; i < sz2; i++) {
		//ù ��° ���ڸ� ã���� ����.
		if (s2[i] == s1[0]) {
			//�� ���ݺ� ����.
			for (int gap = 0; ++gap;) {		//�̷��� �ؾ� gap : 1���� ����			��
											//gap = 1; gap++ ���ϸ� 2���� ����		��
											//gap = 0; gap++ ���ϸ� 0�̶� �ȵ���.	��
				//����ġ��
				if (i + gap*(sz1 - 1) > sz2) { break; }
				bool currRet = true;
				for (int j = 1; j < sz1; j++) {
					if (s2[i + j*gap] != s1[j]) {
						currRet = false;
						break;
					}
				}
				//ã������ ���ݺ� ���� ����
				if (currRet) {
					ret = true;
					break;
				}
			}
		}
		//ã������ ����
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
