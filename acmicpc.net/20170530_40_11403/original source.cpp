//20170530
//대표적인 플로이드 와샬 알고리즘 문제래서 그 방법을 이용.

//★부분에 대한 설명 및 이해.

//처음에는 for문 i->j->k 순일 떄,
//i,j 연결 && j,k 연결이면 i,k 연결하는 방식으로 했다.
//그렇게 하면 새로 생긴 간선을 이용해서 추가 간선을 연결할 수 없음.

//for문 i->j->k 순일 떄,
//j,i 연결 && i,k 연결이면 j, k연결하는 방식으로 해야함.
//connection vertex 를 i로 하고, i를 제일 큰 for문, 즉 i를 중심으로 돌아야
//새로 생긴 간선을 다음 연결에 반영할 수 있음.
#include <iostream>
#include <queue>
using namespace std;

int n;
int arr[101][101];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (arr[j][i] && arr[i][k]) {//★
					arr[j][k] = 1;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	/*cin >> n;*/
	return 0;
}