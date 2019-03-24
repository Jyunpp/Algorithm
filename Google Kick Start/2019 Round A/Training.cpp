// 20190324 13:40 ~  13:44
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

int t, n, p;
int ps[100001];

int main() {
    cin>>t;
    rep(T, 1, t+1) {
        cin>>n>>p;
        vector<int> v;
        rep(i, 1, n+1) {
            int skill; cin>>skill;
            v.pb(skill);
        }
        sort(v.begin(), v.end());
        ps[0] = v[0];
        rep(i, 1, n) {
            ps[i] = ps[i-1] + v[i];
        }
        int ans = 1987654321;
        rep(i, p-1, n) {
            ans = min(ans, (v[i]*p - (ps[i] - ps[i-p])));
        }
        cout<<"Case #"<<T<<": "<<ans<<endl;
    }
    return 0;
}