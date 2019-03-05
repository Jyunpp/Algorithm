// 20190306 00:13 ~ 00:26
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

int n, m;
vector<ll> v;
vector<ll> ps;
int q[300001];

int main() {
    cin>>n;
    rep(i, 1, n+1){
        ll curr;
        cin>>curr;
        v.push_back(curr);
    }
    cin>>m;
    rep(i, 1, m+1) cin>>q[i];
    sort(v.begin(), v.end(), [](ll a, ll b){return a>b;});
    ll partialSum = 0;
    rep(i, 0, n) {
        partialSum += v[i];
        ps.push_back(partialSum);
    }
    rep(i, 1, m+1) {
        ll ret = 0;
        int cq = q[i]-1;
        ret += ps[n-1];
        ret -= v[cq];
        cout<<ret<<endl;
    }
}