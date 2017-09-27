//20170927 16:23 ~
/*
	Ʈ������ dp�����ϰ� ����ϱ� ��
	childNode �� ������ ���� �����ϱ� ��
	��� �� leaf�� ã�� ���.
	sd, sdll ����ϴ� ��(?)

	���� ��Ҵ� dp��, "���� ���k����, ���ѹ�, ���� k����"����
	dp������� ���������, �̷��� ��´ٸ� child���� ������ ������ �����ϱⰡ ��ƴ�.
	  ex) ���� x�� 5�� �� ��, child1�� 2�� child2�� 3�� child3�� 0�� .. �ٵ� "����" ���� �̹Ƿ�
	      ��� ��� ���� ��� .. ��ġ������

	�信��, "���ѹ�, �������k���� + k���� ū�� ������, �� ��� ��Ʈ������ ����Ʈ���� "����" k����
	k���� ���� ��츦 ���� ���ִ� �͵� �� ����
	���� ������ �ű��ϴ�.
*/
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#define sd(x) scanf(" %d", &x);
#define slld(x) scanf(" %lld", &x);
#define ll long long
#define pb push_back
#define xx first
#define yy second
#define mod 1000000007

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>
using namespace std;

int dp[100001][3][11];		//nodeNumOfRootOfSubtree, ==k?1:<k?0:2, numOfkWithinSubtree
int x, k, m;
int a[3][12], b[3][12];
vector<int> edge[100001];

void dfs(int curr, int par) {
	bool leaf = true;
	int temp;
	//child���⸸ ���.
	for (auto &i : edge[curr]) {
		if (i == par) continue;
		leaf = false;
		dfs(i, curr);
	}
	//leaf ����� dp Base ä���
	if (leaf) {
		dp[curr][0][0] = k - 1;
		dp[curr][1][1] = 1;
		dp[curr][2][0] = m - k;
		return;
	}
	//a�� b�� ���տ� ���Ǵ� dp �ʱ�ȭ
	//currNode�� "<k, ==k, >k" ������ ��쿡 ���ؼ�					=> b[i][j] �� i��
	//child���� ��ȸ�ϸ鼭, �̹� child���� "k�� ����� ����"�� ����	=> b[i][j] �� j��
	//������ ����� ���� �����Ѵ�. �� ��, ���� child������ ���� ������ a[i][j]���� �����´�.
	//=> ó�� a[i][0]�� 1�� ���� & ���� child�� �Ѿ������ b���� a�� ����.
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j <= x; j++)
			a[i][j] = b[i][j] = 0;
	}

	//ó���� �ƹ� child ���� �� ���� �� ���� k���� ����. 0�� �ʱ�ȭ.
	for (int i = 0; i < 3; i++) a[i][0] = 1;

	//child���� Ȯ��.
	for (auto &i : edge[curr]) {
		//currNode�� (<k, ==k, >k)�� ���ؼ�
		for (int j = 0; j < 3; j++) {
			//���� child���� ����� k����(last) ���� ����� ���� �̿��ؼ� (a[j][last])
			for (int last = 0; last <= x; last++) {
				//�̹� child�� k��� ����(here) ���� ����� ���� ����. (b[j][here]);
				for (int here = 0; here <= x; here++) {
					if (last + here > x) continue;
					if (j == 0) {		//j==0 : RootOfSubTree < k
						temp = dp[i][0][here];
						temp += dp[i][1][here]; temp %= mod;
						temp += dp[i][2][here]; temp %= mod;
						b[j][last + here] += (1ll * a[j][last] * temp) % mod;
						b[j][last + here] %= mod;
					}
					else if (j == 1) {	//j==1 : RootOfSubTree == k 
						b[j][last + here] += (1ll * a[j][last] * (dp[i][0][last])) % mod;
						b[j][last + here] %= mod;
					}
					else {				//j==2 : RootOfSubTree > k 
						temp = dp[i][0][here];
						temp += dp[i][2][here]; temp %= mod;
						b[j][last + here] += (1ll * a[j][last] * temp) % mod;
						b[j][last + here] %= mod;
					}
				}
			}
		}
		//���� child�� ���� ���� a ����.
		for (int j = 0; j < 3; j++) {
			for (int last = 0; last <= x; last++) {
				a[j][last] = b[j][last];
				b[j][last] = 0;
			}
		}
	}
	//child�� ������ curr�� ����
	for (int last = 0; last <= x; last++) {
		dp[curr][0][last] = (1ll * a[0][last] * (k - 1)) % mod;
		if (last >= 1) dp[curr][1][last] = a[1][last - 1];
		dp[curr][2][last] = (1ll * a[2][last] * (m - k)) % mod;
	}
}

int main() {
	int n, ans;
	sd(n);
	sd(m);
	for (int i = 1, j; i < n; i++) {
		sd(j); sd(k);
		edge[j].pb(k);
		edge[k].pb(j);
	}
	sd(k);
	sd(x);
	dfs(1, 0);
	ans = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j <= x; j++) {
			ans += dp[1][i][j];
			ans %= mod;
		}
	}
	printf("%d\n", ans);
	system("pause");
	return 0;
}