//20170927 16:23 ~
/*
	트리에서 dp정의하고 사용하기 ★
	childNode 들 가지고 조합 구현하기 ★
	재귀 시 leaf도 찾는 방법.
	sd, sdll 사용하는 팁(?)

	내가 잡았던 dp는, "이전 노드k여부, 노드넘버, 남은 k갯수"였다
	dp사이즈는 비슷하지만, 이렇게 잡는다면 child들을 가지고 조합을 구현하기가 어렵다.
	  ex) 남은 x가 5개 일 떄, child1쪽 2개 child2쪽 3개 child3쪽 0개 .. 근데 "남은" 개수 이므로
	      모두 사용 안한 경우 .. 골치아파짐

	답에선, "노드넘버, 이전노드k여부 + k보다 큰지 작은지, 이 노드 루트노드로한 서브트리에 "사용된" k갯수
	k보다 작은 경우를 따로 세주는 것도 더 좋고
	조합 구현도 신기하다.
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
	//child방향만 재귀.
	for (auto &i : edge[curr]) {
		if (i == par) continue;
		leaf = false;
		dfs(i, curr);
	}
	//leaf 노드라면 dp Base 채우기
	if (leaf) {
		dp[curr][0][0] = k - 1;
		dp[curr][1][1] = 1;
		dp[curr][2][0] = m - k;
		return;
	}
	//a와 b는 조합에 사용되는 dp 초기화
	//currNode가 "<k, ==k, >k" 각각의 경우에 대해서					=> b[i][j] 중 i값
	//child들을 순회하면서, 이번 child까지 "k를 사용한 갯수"에 따라	=> b[i][j] 중 j값
	//가능한 경우의 수를 저장한다. 이 떄, 이전 child까지에 대한 정보를 a[i][j]에서 가져온다.
	//=> 처음 a[i][0]은 1로 저장 & 다음 child로 넘어가기전에 b값을 a에 저장.
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j <= x; j++)
			a[i][j] = b[i][j] = 0;
	}

	//처음에 아무 child 만난 적 없을 땐 과거 k갯수 없음. 0만 초기화.
	for (int i = 0; i < 3; i++) a[i][0] = 1;

	//child별로 확인.
	for (auto &i : edge[curr]) {
		//currNode가 (<k, ==k, >k)에 대해서
		for (int j = 0; j < 3; j++) {
			//이전 child까지 사용한 k갯수(last) 별로 경우의 수를 이용해서 (a[j][last])
			for (int last = 0; last <= x; last++) {
				//이번 child의 k사용 갯수(here) 별로 경우의 수를 갱신. (b[j][here]);
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
		//다음 child로 가기 전에 a 갱신.
		for (int j = 0; j < 3; j++) {
			for (int last = 0; last <= x; last++) {
				a[j][last] = b[j][last];
				b[j][last] = 0;
			}
		}
	}
	//child를 가지고 curr를 갱신
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