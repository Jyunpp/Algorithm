// 20190306 00:05 ~ 00:11
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

ll a[4];

int main() {
    rep(i, 0, 4) cin>>a[i];
    int ret = 1;
    if(a[0]==0 && a[2] != 0) ret = 0;
    if(a[3]==0 && a[2] != 0) ret = 0;
    if(a[0] != a[3]) ret = 0;
    cout<<ret<<endl;
    return 0;
}