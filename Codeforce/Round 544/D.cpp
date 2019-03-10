// 20190310 02:00 ~ 
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
#include <map>
using namespace std;

#define sd(x) scanf(" %d", &x);
#define slld(x) scanf(" %lld", &x);
#define pb push_back
#define xx first
#define yy second
#define rep(i, l, r) for(int i=l; i<r; i++)
#define sortV(v, lambda) sort(v.begin(), v.end(), lambda)
#define powll(a, b) (ll) pow(a, b)

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;

int a[200001];
int b[200001];
int n, ans, cnt0;
map<pair<int, int>, int> m;

int gcd(int a, int b) { return a ? gcd(b%a, a) : b; }
void norm(pair<int, int>& p) {
	if(p.xx < 0) {
		p.xx *= -1;
		p.yy *= -1;
	}
	else if (p.xx == 0 && p.yy < 0) {
		p.yy *= -1;
	}
	int d = gcd(abs(p.xx), abs(p.yy));
	p.xx /= d;
	p.yy /= d;
}

int main() {
	cin>>n;
    rep(i, 0, n) cin>>a[i];
    rep(i, 0, n) cin>>b[i];
	rep(i, 0, n){
		if(a[i] == 0) {
			if(b[i] == 0) cnt0++;
		}
		else {
			pair<int, int> p = {-b[i], a[i]};
			norm(p);
			m[p]++;
			ans = max(ans, m[p]);
		}
	}
	cout << cnt0 + ans << endl;
    return 0;
}