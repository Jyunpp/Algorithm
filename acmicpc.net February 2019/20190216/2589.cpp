// 20190216 02:10 ~ 02:26
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

int h, w;
char arr[51][51];
int visited[51][51];
int ans;
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void clear() {
    rep(y, 1, h+1) rep(x, 1, w+1) visited[y][x] = 0;
}

int main() {
    cin>>h>>w;
    rep(y, 1, h+1) rep(x, 1, w+1) cin>>arr[y][x];
    
    rep(y, 1, h+1) {
        rep(x, 1, w+1) {
            if(arr[y][x] =='W') continue;
            clear();
            queue<P> q; 
            q.push({y, x});
            visited[y][x] = 1;
            int currRet = 0;
            while(!q.empty()) {
                int sz = q.size();
                currRet++;
                while(sz--){
                    P curr = q.front(); q.pop();
                    rep(i, 0, 4) {
                        int ny = dy[i] + curr.xx;
                        int nx = dx[i] + curr.yy;
                        if(nx*ny!=0 && ny <= h && nx <= w && !visited[ny][nx] && arr[ny][nx] != 'W') {
                            q.push({ny, nx});
                            visited[ny][nx] = 1;
                        }
                    }
                }
            }
            ans = max(ans, currRet);
        }
    }
    if(ans>0) ans--;
    cout<<ans<<endl;
    return 0;
}