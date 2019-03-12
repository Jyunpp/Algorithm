// 20190311 21:15 ~ 22:40 +11
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
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
ll arr[200002];
map<ll, ll> m;

int main() {
    cin>>n;
    rep(i, 0, n) {
        cin>>arr[i];
        m[arr[i]]=i;
    }
    ll ret = 1;
    ll last = m[arr[0]];
    rep(i, 1, n) {
        if(last<i) {
            ret *=2;
            ret %=998244353;
        }
        last = max(last, m[arr[i]]);
    }
    cout<<ret<<endl;
    return 0;
}