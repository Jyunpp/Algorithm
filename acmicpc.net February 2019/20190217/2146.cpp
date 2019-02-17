// 20190217 14:35 ~ 14:39
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

int n;
int arr[101][101];
int team[101][101];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int visited[101][101];
int ret = 987654321;

int main() {
    cin>>n;
    rep(i, 1, n+1) rep (j, 1, n+1) cin>>arr[i][j];

    int currTeam = 0;
    rep(y, 1, n+1) {
        rep(x, 1, n+1) {
            if(team[y][x] || !arr[y][x]) continue;
            currTeam++;
            queue<P> q;
            q.push({y, x}); team[y][x] = currTeam;
            while(!q.empty()){
                int yy = q.front().xx;
                int xx = q.front().yy;
                q.pop();
                rep(i, 0, 4) {
                    int ny = yy+dy[i];
                    int nx = xx+dx[i];
                    if(ny*nx!=0 && ny <=n && nx <=n && !team[ny][nx] && arr[ny][nx]) {
                        team[ny][nx] = currTeam;
                        q.push({ny, nx});
                    }
                }
            }
        }
    }

    rep(t, 1, currTeam+1) {
        queue<P> q;
        rep(y, 1, n+1) {
            rep(x, 1, n+1) {
                visited[y][x] = 0;
                if(team[y][x] != t) continue;
                q.push({y,x});
            }
        }
        
        int currRet = 0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--){
                int yy = q.front().xx;
                int xx = q.front().yy;
                q.pop();
                if(ret < currRet) break;
                rep(i, 0, 4) {
                    int ny = yy+dy[i];
                    int nx = xx+dx[i];
                    if(ny*nx!=0 && ny<=n && nx<=n && team[ny][nx]!=t && !visited[ny][nx]) {
                        if(team[ny][nx]) ret = min(ret,currRet);
                        q.push({ny, nx});
                        visited[ny][nx]=1;
                    }
                }
            }
            currRet++;
        }
    }
    cout<<ret<<endl;
    return 0;
}