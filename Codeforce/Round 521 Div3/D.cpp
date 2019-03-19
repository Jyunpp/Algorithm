// 20190318 22:02 ~ 22:22
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
int arr[200001];
vector<P> v;

int main() {
    cin>>n>>k;
    rep(i, 1, n+1){
        int a; cin>>a;
        arr[a]++;
    }
    rep(i, 1, 200001) {
        if(!arr[i]) continue;
        v.push_back({i,arr[i]});
    }
    sort(v.begin(), v.end(), [](P a, P b){return a.yy>b.yy;});
    int r = 200000;
    int l = 1;
    queue<int> q;
    queue<int> ret;
    while(l<r) {
        int m = (l+r)>>1;
        int can = true;
        rep(i, 0, v.size()) {
            P curr = v[i];
            int currYY = curr.yy;
            while(currYY >= m) {
                q.push(curr.xx);
                currYY-=m;
            }
        }
        if((int)q.size()>=k) {
            can = true;
            ret = q;
            while(!q.empty()) q.pop();
        } else {
            can = false;
            while(!q.empty()) q.pop();
        }
        if(can) {
            l = m+1;
        } else {
            r = m;
        }
    }
    while(k--) {
        cout<<ret.front()<<" ";
        ret.pop();
    }
    return 0;
}