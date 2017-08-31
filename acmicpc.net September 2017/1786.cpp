//20170901 06:58 ~ 
/*
	KMP�⺻
	S���� W�� ã�Ƽ�
	S���� W�� ������, �� ������ġ�� ���.
*/
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

vector<int> getPi(string p) {
	int m = (int)p.size();
	vector<int> pi(m, 0);
	for (int i = 1, j = 0; i <= m; i++) {
		while (j > 0 && p[i] != p[j]) j = pi[j - 1];
		if (p[i] == p[j]) pi[i] = ++j;
	}
	return pi;
}

vector<int> kmp(string s, string p) {
	vector<int> ans;
	vector<int> pi = getPi(p);
	int n = (int)s.size(), m = (int)p.size();
	for (int i = 0, j = 0; i < n; i++) {
		while (j > 0 && s[i] != p[j]) j = pi[j - 1];
		if (s[i] == p[j]) {
			if (j == m - 1) {
				ans.push_back(i - m + 1);
				j = pi[j];
			}
			else
				j++;
		}
	}
	return ans;
}

int main() {
	string S, W;
	int M, N;
	getline(cin, S);		//���� ���� ���� �Է�
	getline(cin, W);

	vector<int> matched = kmp(S, W);
	printf("%d\n", (int)matched.size());
	for (auto i : matched)
		printf("%d ", i + 1);
	//system("pause");
	return 0;
}