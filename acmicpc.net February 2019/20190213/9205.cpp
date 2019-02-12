// 20190213 01:50 ~ 
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

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;

P arr[102];
int dist[102][102];
int visited[102];

int main() {
    int t; sd(t);
    while(t--) {
        int x, y, n; sd(n);
        rep(i, 0, n+2) {
            sd(x); sd(y);
            arr[i] = {x,y};
            visited[i] = 0;
        }

        rep(i, 0, n+2) {
            rep(j, i+1, n+2) {
                dist[i][j] = dist[j][i] = abs(arr[i].xx - arr[j].xx) + abs(arr[i].yy - arr[j].yy);
            }
        }

        queue<int> q;
        q.push(0); visited[0] = 1;
        while(!q.empty()) {
            int curr = q.front();
            if(curr == n+1) break;
            q.pop();
            rep(i, 1, n+2) {
                if(dist[curr][i] <= 1000 && !visited[i]) {
                    q.push(i); visited[i] = 1;
                }
            }
        }
        if(visited[n+1]) cout<<"happy"<<endl;
        else cout<<"sad"<<endl;
    }
    return 0;
}