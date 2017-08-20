//20170820 23:14 ~ 
/*
	�� ���� �� �߰��� �ִ� ���Ҹ� �������� ����,
	���� ���� ���� �� ū ���� ����
	�ʰ� ���� ���� �� ���� ���� ����
	�� ������ ���� ���� �߰� ���Ұ� 2~n-1��° ������ �� ���� ���ؼ� ��� ���� ��.
	
	�� ��, ���� or �ʰ� ���� ���� ó�����ֱ� ���ؼ� ������� or �ݴ������ Ʈ���� �����鼭 ������ ���Ѵ�.
	(�� ���� ���ļ�..)
	��, 1~10�� ������ �ε��� ���� ���ڸ� �ǹ��ϸ� ���� ������ �ǹ�.
	�������� ������ �ش��ϴ� ������ ����.
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