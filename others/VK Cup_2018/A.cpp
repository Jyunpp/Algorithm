// 20190313 12:41 ~ 12:48
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

int r, c;
char arr[501][501];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int main() {
    cin>>r>>c;
    rep(i, 1, r+1) rep(j, 1, c+1) cin>>arr[i][j];
    rep(i, 1, r+1) {
        rep(j, 1, c+1) {
            if(arr[i][j] == 'W') {
                rep(k, 0, 4) {
                    int ny = i+dy[k];
                    int nx = j+dx[k];
                    if(ny>r || nx>c || ny*nx==0) continue;
                    if(arr[ny][nx] == '.') arr[ny][nx] = 'D';
                    else if (arr[ny][nx] == 'S') {
                        cout<<"No"<<endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout<<"Yes"<<endl;
    rep(i, 1, r+1) {
        rep(j, 1, c+1) {
            cout<<arr[i][j];
        }
        cout<<endl;
    }
    return 0;
}