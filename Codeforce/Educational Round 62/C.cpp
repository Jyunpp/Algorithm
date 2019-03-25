// 20190325 10:17 ~ 10:30 retry
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

int n, k;
vector<P> v;
ll ret;

int main() {
    cin>>n>>k;
    rep(i, 1, n+1){
        int t, b; sd(t); sd(b);
        v.pb({t,b});
    }
    sort(v.begin(), v.end(), [](P a, P b){return a.yy>b.yy;});
    priority_queue<ll, vector<ll>, greater<ll> > pq;
    ll sum = 0;
    for(auto i : v) {
        pq.push(i.xx);
        sum += i.xx;
        if(pq.size()>k) {
            sum -= pq.top();
            pq.pop();
        }
        if(ret < sum * i.yy) ret = sum * i.yy;
    }
    cout<<ret<<endl;
    return 0;
}