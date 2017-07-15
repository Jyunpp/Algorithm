//20170716
#include <iostream>
#include <algorithm>
using namespace std;

#define sz 300001

int h[sz], moveL[sz], moveR[sz];
char t[sz];
int n, k;

int main() {
	cin >> n >> k; k--;
	for (int i = 0; i < n; i++)
		cin >> h[i];
	cin >> t;
	//왼쪽으로 이동 할 수 있는 경우,
	//왼쪽으로 이동 가능 길이를 늘려가며 저장,
	//왼쪽이 T라면(T인 상태 : T이거나 왼쪽 방향에 T인 곳으로 갈 수 있다.) 이번도 T인 상태로.
	for (int i = 1; i < n; i++) {
		if (h[i] < h[i - 1]) continue;
		if (t[i - 1] == 'T') t[i] = 'T';
		moveL[i] = 1 + moveL[i - 1];
	}
	//오른쪽도 같다.
	for (int i = n - 2; i >= 0; i--) {
		if (h[i] < h[i + 1]) continue;
		if (t[i + 1] == 'T') t[i] = 'T';
		moveR[i] = 1 + moveR[i + 1];
	}
	//T의 갯수와, T가 없는 라인 중 최대 길이를 구한다.
	int T = 0, best = 0;
	for (int i = 0; i < n; i++) {
		if (t[i] == 'T') T++;
		else best = max(best, 1 + max(moveL[i], moveR[i]));
	}
	//시작 점이 T라는 것은, 시작점을 포함한 이어진 라인은 모두 갈 수 있으며
	//점프를 통해 모든 T가 이어진 각각의 라인들을 갈 수 있다.
	//=> T의 갯수 + T가 없는 라인의 최대 길이 출력
	if (t[k] == 'T')
		cout << T + best << endl;
	//시작 점이 T가 아니라면, 시작점과 같은 높이의 양 끝 중 최대 이동 가능 + 같은높이 출력
	else {
		int l = k, r = k;
		//좌우측으로 평행한 높이 까지는 갈 수 있으므로 계산해줌.
		while (l > 0 && h[l - 1] == h[k]) l--;
		while (r < n - 1 && h[r + 1] == h[k]) r++;
		cout << r - l + 1 + max(moveL[l], moveR[r]) << endl;
	}
	system("pause");
	return 0;
}