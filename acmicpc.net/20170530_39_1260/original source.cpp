//20170529~20170530 넘어가는 새벽..
//stack을 처음 ..써봄.. 
//DFS를 항상 재귀호출로 구현하다가 stack을 처음 씀..
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int n, m, v;
int arr[1001][1001];
int visited[2][1001];
int main() {
	cin >> n >> m >> v;
	int input1, input2;
	for (int i = 0; i < m; i++) {
		cin >> input1 >> input2;
		arr[input1][input2] = 1;
		arr[input2][input1] = 1;
	}
	queue<int> q;
	stack<int> s;
	//DFS
	s.push(v);
	//너무 오래걸리면 vector로 push해서 입력받고, sorting 후 돌자..
	cout << v << " ";
	while (!s.empty()) {
		bool isThereConnection = false;
		int here = s.top();
		visited[0][here] = 1;
		for (int i = 1; i <= 1000; i++) {
			if ((arr[here][i] == 1) && visited[0][i] == 0) {
				cout << i << " ";
				s.push(i);
				isThereConnection = true;
				break;
			}
		}
		if (isThereConnection == false) { s.pop(); }
	}
	cout << endl;
	
	//BFS
	q.push(v);
	while (!q.empty()) {
		int here = q.front();
		visited[1][here] = 1;
		cout << here << " ";
		q.pop();
		for (int i = 1; i <= 1000; i++) {
			if ((arr[here][i] == 1) && visited[1][i] == 0) {
				visited[1][i] = 1;
				q.push(i);
			}
		}
	}

	//cin >> n;
	return 0;
}