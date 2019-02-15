// 20190216 01:30 ~ 01:51
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

int visited[101];
int n, m;
vector<int> arr[101];
int ret[101];

int main() {
    cin>>n>>m;
    int a, b;
    rep(i, 1, m+1) {
        cin>>a>>b;
        arr[a].pb(b);
        arr[b].pb(a);
    }

    rep(i, 1, n+1) {
        rep(j, 1, n+1) visited[j] = 0;
        int currRet = 0;
        queue<int> q;
        q.push(i); visited[i] = 1;
        while(!q.empty()){
            int sz = q.size();
            ret[i] +=(sz*currRet);
            currRet++;
            while(sz--){
                int curr = q.front(); q.pop();
                rep(nextIdx, 0, arr[curr].size()) {
                    int next = arr[curr][nextIdx];
                    if(!visited[next]) {
                        q.push(next);
                        visited[next] = 1;
                    }
                }
            }
        }
    }
    int result = 1;
    rep(i, 2, n+1) {
        if(ret[result] > ret[i]) result = i;
    }
    cout<<result<<endl;
    return 0;
}