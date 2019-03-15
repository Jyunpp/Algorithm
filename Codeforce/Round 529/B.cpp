// 20190315 07:24 ~ 07:26
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

int n;
vector<int> v;

int main() {
    cin>>n;
    rep(i, 1, n+1) {
        int a; cin>>a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    int ret = 987654321;
    ret = min(v[n-2]-v[0],v[n-1]-v[1]);
    cout<<ret<<endl;
    return 0;
}