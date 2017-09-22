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
	//범위 밖 return;
	if (e < ns || ne < s) return;
	//범위 안 update하기
	if (s <= ns && ne <= e) cnt[node] += val;
	else {
		int mid = (ns + ne) >> 1;
		update(s, e, val, node * 2, ns, mid);
		update(s, e, val, node * 2 + 1, mid + 1, ne);
	}
	//위는, cnt 업데이트 과정.					(cnt[node] : node에 해당하는 범위 전체가 y에 속하는지)
	//cnt 업데이트가 끝난 후, seg값을 구해줌.	(seg : 포함되는 y좌표의 개수)
	if (cnt[node]) seg[node] = ne - ns + 1;					//전체가 속한다면 seg[node]값은, 맆노드의 갯수. 즉, 아우르는 범위
	else {
		if (ns == ne) seg[node] = 0;						//속하지 않는데 맆노드 => seg값 0
		else seg[node] = seg[node * 2] + seg[node * 2 + 1]; //이외는 바로밑 자녀노드 합
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1, a, b, c, d; i <= n; i++) {
		scanf(" %d %d %d %d", &a, &b, &c, &d);
		v.push_back(p{ a, b, d - 1, 1 });		//d-1인 이유 => 넓이 계산을 위해서
		v.push_back(p{ c, b, d - 1, -1 });		//dx * 포함된 y좌표의 갯수로 넓이를 구하는데, 높이2 한덩이 => y좌표는 세 개가 됨.
	}
	sort(v.begin(), v.end(), [](p a, p b) {return a.x < b.x; });
	
	//넓이구하기 시작.
	update(v[0].y1, v[0].y2, v[0].z, 1, 0, MAX_Y);
	last = v[0].x;
	for (int i = 1; i < 2 * n; i++) {
		int dx = v[i].x - last;
		ans += dx*seg[1];						//seg[1] : node1이 포함하는 범위(전체)에서 포함된 y좌표의 개수
		update(v[i].y1, v[i].y2, v[i].z, 1, 0, MAX_Y);
		last = v[i].x;
	}

	cout << ans << endl;
	//system("pause");
	return 0;
}