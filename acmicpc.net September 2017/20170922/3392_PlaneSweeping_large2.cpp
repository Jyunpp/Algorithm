//20170922 16:23 ~ 17:30
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#define xx first
#define yy second
#define MAX_N 10000
#define MAX_Y 30000

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

struct p {
	int x, y1, y2, z;
};
vector<p> v;
int n, ans, last;
int seg[4 * MAX_Y], cnt[4 * MAX_Y];

void update(int s, int e, int val, int node, int ns, int ne) {
	//���� �� return;
	if (e < ns || ne < s) return;
	//���� �� update�ϱ�
	if (s <= ns && ne <= e) cnt[node] += val;
	else {
		int mid = (ns + ne) >> 1;
		update(s, e, val, node * 2, ns, mid);
		update(s, e, val, node * 2 + 1, mid + 1, ne);
	}
	//����, cnt ������Ʈ ����.					(cnt[node] : node�� �ش��ϴ� ���� ��ü�� y�� ���ϴ���)
	//cnt ������Ʈ�� ���� ��, seg���� ������.	(seg : ���ԵǴ� y��ǥ�� ����)
	if (cnt[node]) seg[node] = ne - ns + 1;					//��ü�� ���Ѵٸ� seg[node]����, ������� ����. ��, �ƿ츣�� ����
	else {
		if (ns == ne) seg[node] = 0;						//������ �ʴµ� ����� => seg�� 0
		else seg[node] = seg[node * 2] + seg[node * 2 + 1]; //�ܴ̿� �ٷι� �ڳ��� ��
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1, a, b, c, d; i <= n; i++) {
		scanf(" %d %d %d %d", &a, &b, &c, &d);
		v.push_back(p{ a, b, d - 1, 1 });		//d-1�� ���� => ���� ����� ���ؼ�
		v.push_back(p{ c, b, d - 1, -1 });		//dx * ���Ե� y��ǥ�� ������ ���̸� ���ϴµ�, ����2 �ѵ��� => y��ǥ�� �� ���� ��.
	}
	sort(v.begin(), v.end(), [](p a, p b) {return a.x < b.x; });
	
	//���̱��ϱ� ����.
	update(v[0].y1, v[0].y2, v[0].z, 1, 0, MAX_Y);
	last = v[0].x;
	for (int i = 1; i < 2 * n; i++) {
		int dx = v[i].x - last;
		ans += dx*seg[1];						//seg[1] : node1�� �����ϴ� ����(��ü)���� ���Ե� y��ǥ�� ����
		update(v[i].y1, v[i].y2, v[i].z, 1, 0, MAX_Y);
		last = v[i].x;
	}

	cout << ans << endl;
	//system("pause");
	return 0;
}