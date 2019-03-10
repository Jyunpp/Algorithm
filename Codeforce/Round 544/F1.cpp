// 20190310 20:40 ~ 21:20
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
int visited[200001];

int main() {
    cin>>n>>m;
    vector<vector<int>> v(n+1, vector<int>(0));
    rep(i, 1, m+1) {
        int a, b;
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    int idx = 1;
    int maxDegree = v[1].size();
    rep(i, 2, n+1) {
        if(maxDegree < v[i].size()){
            maxDegree = v[i].size();
            idx = i;
        }
    }
    vector<P> ans;
    queue<int> q;
    visited[idx]++;
    q.push(idx);
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        for(auto i: v[curr]) {
            if(visited[i]) continue;
            visited[i]++;
            ans.pb({curr, i});
            q.push(i);
        }
    }
    for(auto i: ans) {
        cout<<i.xx<<" "<<i.yy<<endl;
    }
    return 0;
}