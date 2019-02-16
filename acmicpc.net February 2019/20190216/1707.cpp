// 20190216 12:57 ~ 13:10
// 20190216 16:40 ~ 17:24
// 5*200,000 => brute force
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

int t, v, e;
vector<int> arr[20001];
int team[20001];

int main() {
    cin>>t;
    while(t--) {
        cin>>v>>e;
        rep(i, 1, v+1) {
            arr[i].clear();
            team[i] = 0;
        }
        int a, b;
        rep(i, 1, e+1) {
            cin>>a>>b;
            arr[a].pb(b); arr[b].pb(a);
        }
        
        string ret = "YES";
        int currTeam = 1;
        rep(i, 1, v+1) {
            if(team[i]) continue;
            
            queue<P> q; //prev, curr;
            q.push({-1, i});
            team[i] = currTeam;
            while(!q.empty()){
                currTeam = 3-currTeam;
                int sz = q.size();
                while(sz--){
                    int prev = q.front().xx;
                    int curr = q.front().yy;
                    q.pop();
                    rep(nextIdx, 0, arr[curr].size()) {
                        int next = arr[curr][nextIdx];
                        if(next == prev || team[next]) continue;
                        team[next] = currTeam;
                        q.push({curr, next}); 
                    }
                }
            }
        }
        rep(i, 1, v+1) {
            rep(j, 0, arr[i].size()) {
                if(team[i] == team[arr[i][j]]) ret = "NO";
            }
        }
        cout<<ret<<endl;
    }
    return 0;
}