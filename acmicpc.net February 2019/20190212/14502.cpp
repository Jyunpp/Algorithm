// 20190212 18:45 ~ 20190212 19:18
// 맵크기 브루트 포스시, (8*8)^3 = 2^18 = 1024*256
// 최악의경우 대각선 끝방향 => 15번
// 1024*256*15 = 390만.
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

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;

int n, m;
int arrIn[9][9];
int arr[9][9];
int visited[9][9];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int ret;

int getY(int i) {
    return 1 + (i-1)/m;
}

int getX(int i) {
    return 1 + (i-1)%m;
}

int canNotWall(int i) {
    int y = getY(i);
    int x = getX(i);
    return arrIn[y][x] != 0;
}

void clear() {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            arr[i][j] = arrIn[i][j];
            visited[i][j] = 0;
        }
    }
}
void solve(int wallIndex1, int wallIndex2, int wallIndex3) {
    clear();
    arr[getY(wallIndex1)][getX(wallIndex1)] = 1;
    arr[getY(wallIndex2)][getX(wallIndex2)] = 1;
    arr[getY(wallIndex3)][getX(wallIndex3)] = 1;
    
    queue<P> q;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(arr[i][j] == 2) {
                q.push({i, j});
                visited[i][j] = 1;
            }
        }
    }
    while(!q.empty()) {
        int y = q.front().xx;
        int x = q.front().yy;
        q.pop();
        for(int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny*nx != 0 && ny <=n && nx <=m && !visited[ny][nx] && arr[ny][nx] == 0) {
                arr[ny][nx] = 2;
                q.push({ny, nx});
            }
        }
    }
    int currRet = 0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            currRet += arr[i][j] == 0;
        }
    }
    ret = max(ret, currRet);
}

int main() {
    cin>>n>>m;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin>>arrIn[i][j];
        }
    }
    clear();

    for(int i=1; i<=n*m; i++) {
        if(canNotWall(i)) continue;
        for(int j=1; j<=n*m; j++) {
            if(canNotWall(j) || i==j) continue;
            for(int k=1; k<=n*m; k++) {
                if(canNotWall(k) || k==i || k==j) continue;
                solve(i ,j, k);
            }
        }
    }

    cout<<ret<<endl;
    return 0;
}