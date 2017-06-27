//20170626 22:45 ~ 
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

char arr[2][1001];
int dp[1001][1001];

int main() {
	string inputS;
	int len1, len2;
	cin >> inputS;
	len1 = inputS.size();
	for (int j = 0; j < len1; j++)
		arr[0][j] = inputS[j];
	cin >> inputS;
	len2 = inputS.size();
	for (int j = 0; j < len2; j++)
		arr[1][j] = inputS[j];
	int longer = max(len1, len2);
	int shorter = min(len1, len2);
	int longIndex = (len1 > len2 ? 0 : 1);
	for (int i = 1; i <= shorter; i++) {
		for (int j = 1; j <= longer; j++) {
			if (arr[1- longIndex][i - 1] == arr[longIndex][j - 1]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	cout << dp[shorter][longer] << endl;
	/*
	for (int i = 0; i <= shorter; i++) {
		for (int j = 0; j <= longer; j++)
			cout << dp[i][j] << " ";
		cout << endl;
	}
	system("pause");
*/
	return 0;
}