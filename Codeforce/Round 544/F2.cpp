// 20190310 
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

int n, m, D, cntD;
int visited[200001];
vector<P> ans;

int main() {
    cin>>n>>m>>D;
    vector<vector<int>> v(n+1, vector<int>(0));
    rep(i, 1, m+1) {
        int a, b; cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    rep(i, 2, n+1) {
        if(visited[i]) continue;
        cntD++;
        queue<int> q;
        q.push(i);
        visited[i] = cntD;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(auto j: v[curr]) {
                if(visited[j] || j==1) continue;
                visited[j] = cntD;
                q.push(j);
            }
        }
    }
    if(cntD>D || (int)v[1].size()<D){
        cout<<"NO"<<endl;
        return 0;
    }
    vector<int> temp(cntD+1, 0);
    queue<int> q;
    visited[1] = -1;
    for(auto i: v[1]){
        if(!temp[visited[i]]){
            ans.pb({1, i});
            temp[visited[i]]++;
            visited[i] = -1;
            q.push(i);
        }
    }
    for(auto i:v[1]){
        if((int)q.size()==D) break;
        if(visited[i]==-1) continue;
        ans.pb({1, i});
        q.push(i);
        visited[i] = -1;
    }
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(auto i:v[curr]) {
            if(visited[i]!=-1){
                ans.pb({curr, i});
                visited[i] = -1;
                q.push(i);
            }
        }
    }
    cout<<"YES"<<endl;
    for(auto i: ans) {
        cout<<i.xx<<" "<<i.yy<<endl;
    }
    return 0;
}