// 20190216 17:45 ~ 19:18
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

int n, m;
char arr[101][101];
// 우, 좌, 상, 하
int dy[4] = {0, 0, -1, 1};
int dx[4] = {1, -1, 0, 0};
P B, R;

int ans;

int main() {
    cin>>n>>m;
    rep(i, 1, n+1) {
        rep(j, 1, m+1) {
            cin>>arr[i][j];
            if(arr[i][j] == 'B') B = {i, j};
            if(arr[i][j] == 'R') R = {i, j};
        }
    }
    queue<pair<P, P>> q;
    q.push({B, R});
    int ret = 1;
    while(!q.empty() && ret <= 10 && !ans) {
        int sz = q.size();
        while(sz--){
            P currB = q.front().xx;
            P currR = q.front().yy;
            q.pop();
            rep(i, 0, 4) {
                int by = currB.xx;
                int bx = currB.yy;
                int ry = currR.xx;
                int rx = currR.yy;
                //우좌
                int nby = by;
                int nbx = bx;
                int nry = ry;
                int nrx = rx;
                bool finished = false;
                bool canRecur = true;
                if((i==0||i==1)&&by == ry) {
                    if(bx<rx) {
                        //좌
                        if(i==1) {
                            while(arr[by][nbx+dx[i]]!='#') {
                                nbx += dx[i];
                                if(arr[by][nbx] == 'O') canRecur = false;
                            }
                            while(arr[by][nrx+dx[i]]!='#' && nrx+dx[i] != nbx) {
                                nrx += dx[i];
                                if(arr[by][nrx] == 'O') {
                                    finished = true;
                                }
                            }
                            if(canRecur && finished) ans = ret;
                            if(canRecur) q.push({{nby, nbx}, {nry, nrx}});
                        }
                        //우
                        else {
                            while(arr[by][nrx+dx[i]]!='#') {
                                nrx += dx[i];
                                if(arr[by][nrx] == 'O') {
                                    finished = true;
                                    nrx = -1; break;
                                }
                            }
                            while(arr[by][nbx+dx[i]]!='#' && nbx+dx[i]!=nrx) {
                                nbx += dx[i];
                                if(arr[by][nbx] == 'O') canRecur = false;
                            }
                            if(canRecur && finished) ans = ret;
                            if(canRecur) q.push({{nby, nbx}, {nry, nrx}});
                        }
                    }else {
                        //좌
                        if(i==1) {
                            while(arr[by][nrx+dx[i]]!='#') {
                                nrx += dx[i];
                                if(arr[by][nrx] == 'O') {
                                    finished = true;
                                    nrx = -1; break;
                                }
                            }
                            while(arr[by][nbx+dx[i]]!='#' && nbx+dx[i] != nrx) {
                                nbx += dx[i];
                                if(arr[by][nbx] == 'O') canRecur = false;
                            }
                            if(finished && canRecur) ans = ret;
                            if(canRecur) q.push({{nby, nbx}, {nry, nrx}});
                        }
                        //우
                        else {
                            while(arr[by][nbx+dx[i]]!='#') {
                                nbx += dx[i];
                                if(arr[by][nbx] == 'O') canRecur = false;
                            }
                            while(arr[by][nrx+dx[i]]!='#' && nrx+dx[i] != nbx) {
                                nrx += dx[i];
                                if(arr[by][nrx] == 'O') {
                                    finished = true;
                                }
                            }
                            if(canRecur && finished) ans = ret;
                            if(canRecur) q.push({{nby, nbx}, {nry, nrx}});
                        }
                    }
                } else if((i==2||i==3)&&bx==rx) {
                    //blue 상
                    if(by<ry) {
                        //상
                        if(i==2) {
                            while(arr[nby+dy[i]][bx]!='#') {
                                nby += dy[i];
                                if(arr[nby][bx] == 'O') canRecur = false;
                            }
                            while(arr[nry+dy[i]][bx]!='#' && nry+dy[i] != nby) {
                                nry += dy[i];
                                if(arr[nry][bx] == 'O') {
                                    finished = true;
                                }
                            }
                            if(canRecur && finished) ans = ret;
                            if(canRecur) q.push({{nby, nbx}, {nry, nrx}});
                        }
                        //하
                        else{
                            while(arr[nry+dy[i]][bx]!='#') {
                                nry += dy[i];
                                if(arr[nry][bx] == 'O') {
                                    finished = true;
                                    nry = -1; break;
                                }
                            }
                            while(arr[nby+dy[i]][bx]!='#' && nby+dy[i] != nry) {
                                nby += dy[i];
                                if(arr[nby][bx] == 'O') canRecur = false;
                            }
                            if(canRecur && finished) ans = ret;
                            if(canRecur) q.push({{nby, nbx}, {nry, nrx}});
                        }
                    }
                    //red 상
                    else{
                        //상
                        if(i==2) {
                            while(arr[nry+dy[i]][bx]!='#') {
                                nry += dy[i];
                                if(arr[nry][bx] == 'O') {
                                    finished = true;
                                    nry = -1; break;
                                }
                            }
                            while(arr[nby+dy[i]][bx]!='#' && nby+dy[i] != nry) {
                                nby += dy[i];
                                if(arr[nby][bx] == 'O') canRecur = false;
                            }
                            if(canRecur && finished) ans = ret;
                            if(canRecur) q.push({{nby, nbx}, {nry, nrx}});
                        }
                        //하
                        else{
                            while(arr[nby+dy[i]][bx]!='#') {
                                nby += dy[i];
                                if(arr[nby][bx] == 'O') canRecur = false;
                            }
                            while(arr[nry+dy[i]][bx]!='#' && nry+dy[i] != nby) {
                                nry += dy[i];
                                if(arr[nry][bx] == 'O') {
                                    finished = true;
                                }
                            }
                            if(canRecur && finished) ans = ret;
                            if(canRecur) q.push({{nby, nbx}, {nry, nrx}});
                        }
                    }
                } else {
                    while(arr[nby+dy[i]][nbx+dx[i]]!='#') {
                        nby += dy[i];
                        nbx += dx[i];
                        if(arr[nby][nbx] == 'O') canRecur = false;
                    }
                    while(arr[nry+dy[i]][nrx+dx[i]]!='#') {
                        nry += dy[i];
                        nrx += dx[i];
                        if(arr[nry][nrx] == 'O') {
                            finished = true;
                        }
                    }
                    if(canRecur && finished) ans = ret;
                    if(canRecur) q.push({{nby, nbx}, {nry, nrx}});
                }
            }
        }
        ret++;
    }
    if(!ans) ans = -1;
    cout<<ans<<endl;
    return 0;
}