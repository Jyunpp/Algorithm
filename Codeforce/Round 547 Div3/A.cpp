// 20190319 23:35 ~ 23:39
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

int main() {
    ll n, m;
    cin>>n>>m;
    if(m%n) {
        cout<<-1<<endl;
        return 0;
    }
    ll a = m/n;
    ll ret = 0;
    while(!(a%2)) {
        a/=2;
        ret++;
    }
    while(!(a%3)) {
        a/=3;
        ret++;
    }
    if(a!=1) {
        cout<<-1<<endl;
        return 0;
    }
    cout<<ret<<endl;
    return 0;
}