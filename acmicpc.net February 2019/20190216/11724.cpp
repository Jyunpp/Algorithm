// 20190216 00:36 ~ 00:45
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

int n, m, ret;
vector<int> arr[1001];
int visited[1001];


int main() {
    cin>>n>>m;
    int a, b;
    rep(i, 0, m) {
        cin>>a>>b;
        arr[a].pb(b);
        arr[b].pb(a);
    }
    rep(i, 1, n+1) {
        if(visited[i]) continue;
        queue<int> q;
        q.push(i); visited[i] = 1;
        ret++;
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            rep(j, 0, arr[curr].size()){
                if(!visited[arr[curr][j]]) {
                    q.push(arr[curr][j]);
                    visited[arr[curr][j]] = 1;
                }
            }
        }
    }
    cout<<ret<<endl;
    return 0;
}