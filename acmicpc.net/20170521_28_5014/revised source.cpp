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
	dp[s] = 1;//�湮 ������ �� 0 �̿��Ϸ��� 1�� ��. �������� answer ����� �� 1���� ���!!!!!!!!!!
	//���ʿ� ���������� ������ ��.. �Ǽ��ϱ� ���� �κ�!! ��
	if (g == s) { cout << 0 << endl; return 0; }//�߰��� �κ�.
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		//���� �̵��� �� �ְ�, �� ���� ���̶�� �̵��Ѵ�.
		//�� ��, �湮�� ���ߴٸ� �� �������̴�. �湮�� �ߴٴ� �� ��ü�� �̹� �� ���� ���� �ߴ� ��.
		if (here + u <= f && dp[here +u] ==0) {
			if (here + u == g) { dp[g] = dp[here] + 1; break; }
			dp[here + u] = dp[here] + 1;
			q.push(here + u);
		}
		//�Ʒ��� �̵� ��.. ���� ���ļ� �ᵵ �ǳ�!
		if (here - d >= 1 && dp[here - d] == 0) {
			if (here - d == g) { dp[g] = dp[here] + 1; break; }
			dp[here - d] = dp[here] + 1;
			q.push(here - d);
		}
	}
	if (dp[g] == 0) { cout << "use the stairs" << endl; /*cin >> g;*/ return 0; }
	cout << dp[g] - 1 << endl;
	/*cin >> g;*/
	return 0;
}