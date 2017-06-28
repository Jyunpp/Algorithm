//20170627
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string str[2];
int len[2];
int dp[1001][1001];

int main() {
	for (int i = 0; i < 2; i++) {
		cin >> str[i];
		len[i] = str[i].size();
	}
	
	for (int i = 1; i <= len[0]; i++) {
		for (int j = 1; j <= len[1]; j++) {
			if (str[0][i - 1] == str[1][j - 1])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	
	cout << dp[len[0]][len[1]] << endl;
	/*
	for (int i = 0; i <= len[0]; i++) {
		for (int j = 0; j <= len[1]; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
*/
	return 0;
}