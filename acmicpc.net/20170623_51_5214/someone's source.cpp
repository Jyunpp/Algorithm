#include<stdio.h>
#include<iostream>
#include<vector>rkxd
using namespace std;
const int MAX_S = 1e5 + 1e3;
int n, k, m, ck[MAX_S + 1], q[MAX_S], t;
vector<int> adj[MAX_S + 1];
int main() {
	scanf_s("%d %d %d", &n, &k, &m);
	for (int i = n + 1; i <= n + m; i++)
		for (int j = 0, c; j < k; j++)
			scanf_s("%d", &c), adj[c].push_back(i), adj[i].push_back(c);
	q[t++] = ck[1] = 1;
	for (int h = 0; h < t; h++) {
		cout << "h : " << h << ", t : " << t << endl;
		cout << "q[h] : " << q[h] << endl;
		for (auto it : adj[q[h]]) {
			cout << "it : " << it << endl;
			if (!ck[it]) ck[q[t++] = it] = ck[q[h]] + 1;
		}
	}
	printf("%d", ck[n] ? ck[n] / 2 + 1 : -1);
	cin >> n;
	return 0;
}
