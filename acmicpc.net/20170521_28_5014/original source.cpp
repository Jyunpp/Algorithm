#include <iostream>
#include <queue>
using namespace std;

#define MAX 1000001

int dp[MAX];
int f, s, g, u, d;

int main() {
	cin >> f >> s >> g >> u >> d;
	
	queue<int> q;
	q.push(s);
	//good
	dp[s] = 1;//방문 안했을 시 0 이용하려고 1로 함. 마지막에 answer 출력할 때 1빼고 출력!!!!!!!!!!
	//애초에 목적지에서 시작할 시.. 실수하기 쉬운 부분!! ★
	if (g == s) { cout << 0 << endl; return 0; }//추가한 부분.
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		//위로 이동할 수 있고, 더 빠른 값이라면 이동한다.
		if (here + u <= f) {
			//방문을 안했거나, 방문 했던 것 보다 더 빠르다면.. 애초에 방문을 했으면 그 때가 더 빠르겠구나. 뒷 조건은 필요가 없네.★
			//==> 방문을 안했다면.
			if (dp[here + u] == 0 /*|| dp[here + u]*/) {
				if (here + u == g) { dp[g] = dp[here] + 1; break; }
				dp[here + u] = dp[here] + 1;
				q.push(here + u);
			}
		}
		//아래로 이동 시.. 조건 합쳐서 써도 되네!
		if (here - d >= 1 && dp[here - d] == 0) {
			if (here - d == g) { dp[g] = dp[here] + 1; break; }
			dp[here - d] = dp[here] + 1;
			q.push(here - d);
		}
	}
	//test 후, 발견 시 바로 멈추기 추가해보자!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!했다.!good!★
	if (dp[g] == 0) { cout << "use the stairs" << endl; /*cin >> g;*/ return 0; }
	cout << dp[g] - 1 << endl;
	/*cin >> g;*/
	return 0;
}