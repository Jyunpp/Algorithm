// 20181008 02:05 ~ 02:20
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
#define rep(i, s, e) for(int i=s; i<=e; i++)

typedef long long ll;
typedef pair<int, int> P;

int n;
int arr[1001][1001];
int visited[1001][1001];
int ax, ay, bx, by, cx, cy;

int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};
int dx[8] = {0, 0, -1, 1, 1, -1, -1, 1};

int main() {
    cin>>n;
    cin>>ax>>ay>>bx>>by>>cx>>cy;
    for(int i=1; i<=n; i++){
        arr[ay][i] = 1;
        arr[i][ax] = 1;
    }
    arr[ay][ax] = 1;
    for(int i=1; i<=1000; i++){
        int ny, nx;
        ny = ay+i;
        nx = ax+i;
        if(ny<=n&&nx<=n&&ny>=1&&nx>=1){
            arr[ny][nx] = 1;
        }
        ny = ay+i;
        nx = ax-i;
        if(ny<=n&&nx<=n&&ny>=1&&nx>=1){
            arr[ny][nx] = 1;
        }
        ny = ay-i;
        nx = ax+i;
        if(ny<=n&&nx<=n&&ny>=1&&nx>=1){
            arr[ny][nx] = 1;
        }
        ny = ay-i;
        nx = ax-i;
        if(ny<=n&&nx<=n&&ny>=1&&nx>=1){
            arr[ny][nx] = 1;
        }
    }
    queue<P> q;
    q.push({by, bx});
    visited[by][bx] = 1;
    int ans = 0;
    while(!q.empty()){
        int y = q.front().xx;
        int x = q.front().yy;
        q.pop();
        if(y==cy&&x==cx){
            ans = 1;
            break;
        }
        for(int i=0; i<=7; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny<=n && nx<=n && ny>=1 && nx>=1 && arr[ny][nx] !=1 && visited[ny][nx] !=1){
                visited[ny][nx] = 1;
                q.push({ny,nx});
            }
        }
    }
    if(ans) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}