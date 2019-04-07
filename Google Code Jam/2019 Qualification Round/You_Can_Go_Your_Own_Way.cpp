// round : 20190406 08:00 ~ 20190407 11:00
// 20190406 09:26 ~ 09:32
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

int T;

int main() {
    cin>>T;
    rep(t, 1, T+1){
        int n; cin>>n;
        string s; cin>>s;
        cout<<"Case #"<<t<<": ";
        rep(i, 0, s.size()) {
            cout<<(char)('S' + 'E' - s[i]);
        }
        cout<<endl;
    }
    return 0;
}