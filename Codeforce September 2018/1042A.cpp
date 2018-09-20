//20180921 00:41 ~ 00:52
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
int minans, maxans;

int main() {
	cin >> n >> m;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	maxans = v[n-1] + m;
	for (int i = 0; i < m; i++) {
		v[0]++;
		sort(v.begin(), v.end());
	}
	minans = v[n-1];
	cout << minans << " " << maxans;
	system("pause");
}