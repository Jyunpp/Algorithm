//20170623 다시.. 00:43 ~ 02:10
//드디어 시험기간 때문에 오랫동안 못 푼 문제를.. 풀었다..
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, k, m;
vector<int> arr[101001];
int visited[101001];

int main() {
	cin >> n >> k >> m;
	for (int i = n + 1; i <= n + m; i++) {//★
		for (int j = 1; j <= k; j++) {
			int c; cin >> c;
			arr[i].push_back(c); arr[c].push_back(i);//=> ★나누기2로출력
		}
	}
	queue<int>q;
	q.push(1); visited[1] = 1;
	while (!q.empty()) {
		int here = q.front(); q.pop();
		int len = arr[here].size();
		for (int i = 0; i < len; i++) /*for (auto it : arr[here])*/ {
			if (!visited[arr[here][i]]) {
				visited[arr[here][i]] = visited[here] + 1;
				q.push(arr[here][i]);
				if (visited[n]) { cout << (visited[n] + 1) / 2 << endl; /*cin >> n;*/ return 0; }
			}
		}
	}
	cout << "-1" << endl;
	/*cin >> n;*/
	return 0;
}