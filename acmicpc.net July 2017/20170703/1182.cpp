//20170703
#include <iostream>
#include <queue>
using namespace std;

int n, s, ans;
int arr[20]; //인덱스 0~19 사용 
int visited[1 << 21];

int main() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
/* 같은 원소가 입력 됐을 시, 아예 배제하는 줄 알고 만든 부분.
		for (int j = 0; j < i; j++) {
			if (arr[j] == arr[i]) {
				n--;
				i--;
				break;
			}
		}
*/
	}
	queue<pair<int, int>> q; //first : sum,  second : bit status;
	for (int i = 0; i < n; i++) {
		q.push({ arr[i], 1 << i });
		visited[1 << i] = 1;
	}
	while (!q.empty()) {
		int now = q.front().first;
		int bit = q.front().second;
		q.pop();
		//cout << now << endl;
		if (now == s)
			ans++;
		for (int i = 0; i < n; i++) {
			if (!(bit & (1 << i)) && !visited[bit | (1 << i)]) {
				q.push({ now + arr[i], bit | (1 << i) });
				visited[bit | (1 << i)] = 1;
			}
		}
	}
	cout << ans << endl;
	/*system("pause");*/
	return 0;
}
