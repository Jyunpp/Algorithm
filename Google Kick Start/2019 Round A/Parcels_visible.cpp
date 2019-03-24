// 20190324 13:00 ~ 
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

int t, r, c;
bool arr[251][251];
int md[251][251];
int ans;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool visited[251][251];
queue<P> q;
int no;

int main() {
    cin>>t;
    rep(T, 1, t+1) {
        int maxMd = -1;
        cin>>r>>c;
        no = 0;
        rep(i, 1, r+1){
            rep(j, 1, c+1) {
                char ch; cin>>ch;
                arr[i][j] = (ch=='1');
                no |=arr[i][j];
            }
        }
        if(!no){
            arr[r/2 + r%2][c/2 + c%2] = 1;
            rep(i, 1, r+1) {
                rep(j, 1, c+1){
                    if(arr[i][j]) md[i][j] = 0;
                    else {
                        memset(visited, 0, sizeof(visited));
                        q.push({i, j}); // y, x;
                        visited[i][j] = 1;
                        int currMd = 0;
                        while(!q.empty()) {
                            int sz = q.size();
                            currMd++;
                            while(sz-- && !q.empty()) {
                                P curr = q.front();
                                q.pop();
                                rep(k, 0, 4){
                                    int ny = curr.xx + dy[k];
                                    int nx = curr.yy + dx[k];
                                    if(ny*nx!=0 && ny <=r && nx <=c &&!visited[ny][nx]) {
                                        if(arr[ny][nx]) {
                                            md[i][j] = currMd;
                                            while(!q.empty()) {
                                                q.pop();
                                            }
                                            break;
                                        }
                                        else {
                                            visited[ny][nx] = 1;
                                            q.push({ny, nx});
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            rep(i, 1, r+1) {
                rep(j, 1, c+1) {
                    if(maxMd<md[i][j]){
                        maxMd = md[i][j];
                    }
                }
            }
        } else {
            maxMd = 987654321;
            rep(ii, 1, r+1){
                rep(jj, 1, c+1){
                    bool temp = arr[ii][jj];
                    arr[ii][jj] = 1;
                    rep(i, 1, r+1) {
                        rep(j, 1, c+1){
                            if(arr[i][j]) md[i][j] = 0;
                            else {
                                memset(visited, 0, sizeof(visited));
                                q.push({i, j}); // y, x;
                                visited[i][j] = 1;
                                int currMd = 0;
                                while(!q.empty()) {
                                    int sz = q.size();
                                    currMd++;
                                    while(sz-- && !q.empty()) {
                                        P curr = q.front();
                                        q.pop();
                                        rep(k, 0, 4){
                                            int ny = curr.xx + dy[k];
                                            int nx = curr.yy + dx[k];
                                            if(ny*nx!=0 && ny <=r && nx <=c &&!visited[ny][nx]) {
                                                if(arr[ny][nx]) {
                                                    md[i][j] = currMd;
                                                    while(!q.empty()) {
                                                        q.pop();
                                                    }
                                                    break;
                                                }
                                                else {
                                                    visited[ny][nx] = 1;
                                                    q.push({ny, nx});
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    int currMaxMd = -1;
                    rep(i, 1, r+1) {
                        rep(j, 1, c+1) {
                            if(currMaxMd<md[i][j]){
                                currMaxMd = md[i][j];
                            }
                        }
                    }
                    maxMd = min(maxMd, currMaxMd);
                    arr[ii][jj] = temp;
                }
            }
        }
        cout<<"Case #"<<T<<": "<<maxMd<<endl;
    }
    return 0;
}