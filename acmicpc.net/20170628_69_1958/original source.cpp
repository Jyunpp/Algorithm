//20170628 
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string str[3];
int len[3];
int dp[101][101][101];
int main() {
	for (int i = 0; i < 3; i++) {
		cin >> str[i];
		len[i] = str[i].size();
	}
	for (int k = 1; k <= len[2]; k++) {
		for (int i = 1; i <= len[0]; i++) {
			for (int j = 1; j <= len[1]; j++) {
				if (str[0][i - 1] == str[1][j - 1] && str[0][i - 1] == str[2][k - 1])
					dp[i][j][k] = 1 + dp[i - 1][j - 1][k - 1];
				else
					dp[i][j][k] = max(max(dp[i - 1][j][k], dp[i][j - 1][k]), dp[i][j][k - 1]);
			}
		}
	}
	cout << dp[len[0]][len[1]][len[2]] << endl;
	/*system("pause");*/
	return 0;
}