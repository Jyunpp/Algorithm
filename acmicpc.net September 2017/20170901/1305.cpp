//20170901 06:27 ~ 06:32

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;
string s;
vector<int> pi;

void getpi() {
	for (int i = 1, j = 0; i < n; i++) {
		while (j > 0 && s[i] != s[j]) j = pi[j - 1];
		if (s[i] == s[j]) pi[i] = ++j;
	}
}

int main() {
	cin >> n;
	pi.resize(n + 1);
	cin >> s;
	getpi();
	cout << n - pi[n - 1] << endl;
	//system("pause");
	return 0;
}