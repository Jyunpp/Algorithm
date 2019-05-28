// 20190526 18:00 ~ 18:13
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
 
int t;
P ret;
int n, r, c, sr, sc;
vector<vector<bool>> visited;
int dy[128], dx[128];
 
int main() {
    dy['E'] = 0; dx['E'] = 1;
    dy['W'] = 0; dx['W'] = -1;
    dy['N'] = -1; dx['N'] = 0;
    dy['S'] = 1; dx['S'] = 0;
    
    cin>>t;
    rep(T, 1, t+1) {
        cin>>n>>r>>c>>sr>>sc;
        visited = vector<vector<bool>>(r+1, vector<bool>(c+1));
        visited[sr][sc] = true;
        
        rep(i, 1, n+1) {
            char ch; cin>>ch;
            sr += dy[ch];
            sc += dx[ch];
            while(visited[sr][sc] != false) {
                sr += dy[ch];
                sc += dx[ch];
            }
            // cout<<"debug sr: "<<sr<<", sc:"<<sc<<endl;
            visited[sr][sc] = true;
            if(i==n) ret = {sr, sc};
        }
        cout<<"Case #"<<T<<": "<<ret.xx<<" "<<ret.yy<<endl;
    }
    return 0;
}
