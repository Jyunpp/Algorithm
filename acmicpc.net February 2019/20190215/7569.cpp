// 20190215 22:43 ~ 23:07
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

int m,n,h;
int arr[101][101][101]; // z, y, x
int visited[101][101][101];
queue<pair<int,P>> q; //z, {y, x}

int dz[6] = {0, 0, 0, 0, -1, 1};
int dy[6] = {1, -1, 0, 0, 0, 0};
int dx[6] = {0, 0, -1, 1, 0, 0};

int main() {
    cin>>m>>n>>h;
    bool finished = true;
    int remain = 0;
    rep(z, 1, h+1) {
        rep(y, 1, n+1) {
            rep(x, 1, m+1) {
                cin>>arr[z][y][x];
                if(arr[z][y][x] == 1) {
                    q.push({z,{y,x}});
                } 
                if(arr[z][y][x] == 1 || arr[z][y][x] == -1){
                    visited[z][y][x] = 1;
                } else {
                    finished = false;
                    remain++;
                }
            }
        }
    }
    if(finished) {
        cout<<0<<endl;
        return 0;
    }

    int ret = 0;
    while(!q.empty()) {
        ret++;
        int sz = q.size();
        while(sz--) {
            int z = q.front().xx;
            int y = q.front().yy.xx;
            int x = q.front().yy.yy;
            q.pop();
            rep(i, 0, 6) {
                int nz = z + dz[i];
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(nz*ny*nx != 0 && nz <=h && ny <= n && nx <= m && visited[nz][ny][nx] != 1) {
                    remain--;
                    q.push({nz,{ny,nx}});
                    visited[nz][ny][nx] = 1;
                }
            }
        }
        if(!remain) {
            break;
        }
    }
    if(remain) ret = -1;
    cout<<ret<<endl;
    return 0;
}