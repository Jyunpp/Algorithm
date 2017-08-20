//20170820 23:14 ~ 
/*
	세 원소 중 중간에 있는 원소를 기준으로 생각,
	먼저 들어온 원소 중 큰 원소 개수
	늦게 들어온 원소 중 작은 원소 개수
	두 개수를 곱한 값을 중간 원소가 2~n-1번째 원소일 때 각각 구해서 모두 더한 값.
	
	이 때, 먼저 or 늦게 들어온 것을 처리해주기 위해서 순서대로 or 반대순으로 트리에 넣으면서 개수를 구한다.
	(두 번에 걸쳐서..)
	또, 1~10만 까지의 인덱스 값은 숫자를 의미하며 값은 갯수를 의미.
	나머지는 범위에 해당하는 숫자의 개수.
*/

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define MAX_N 100000
using namespace std;
int n, q[MAX_N + 1], seg[4 * MAX_N + 1], a[MAX_N + 1], b[MAX_N + 1];
long long ans;

int update(int pos, int val, int node, int ns, int ne) {
	if (pos < ns || ne < pos)
		return seg[node];
	if (ns == ne)
		return seg[node] += val;
	int mid = (ns + ne) / 2;
	return seg[node] = update(pos, val, node * 2, ns, mid) + update(pos, val, node * 2 + 1, mid + 1, ne);
}

int sum(int s, int e, int node, int ns, int ne) {
	if (e < ns || ne < s)
		return 0;
	if (s <= ns && ne <= e)
		return seg[node];
	int mid = (ns + ne) / 2;
	return sum(s, e, node * 2, ns, mid) + sum(s, e, node * 2 + 1, mid + 1, ne);
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &q[i]);
	for (int i = 1; i <= n; i++) {
		a[i] = sum(q[i] + 1, MAX_N, 1, 1, MAX_N);
		update(q[i], 1, 1, 1, MAX_N);
	}
	memset(seg, 0, sizeof(seg));
	for (int i = n; i>0; i--) {
		b[i] = sum(1, q[i] - 1, 1, 1, MAX_N);
		update(q[i], 1, 1, 1, MAX_N);
	}
	for (int i = 1; i <= n; i++)
		ans += 1LL * a[i] * b[i];
	printf("%lld", ans);
	//system("pause");
	return 0;
}