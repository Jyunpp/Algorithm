// 20190429 01:00 ~ 01:15
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
#include <set>
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

int T;
int p, q;
int x[100001];
int y[100001];
int retX, retY;
int maxX, maxY;

int main() {
    cin>>T;
    rep(t, 1, T+1) {
        rep(i, 0, 100001) {
            x[i] = y[i] = 0;
        }
        maxY = maxX = -987654321;
        cin>>p>>q;
        rep(i, 0, p) {
            int cx, cy;
            char ch;
            cin>>cx>>cy>>ch;
            if(ch=='N') {
                rep(j, cy+1, q+1) {
                    y[j]++;
                }
            } else if(ch=='S') {
                rep(j, 0, cy) {
                    y[j]++;
                }
            } else if(ch=='E') {
                rep(j, cx+1, q+1) {
                    x[j]++;
                }
            } else {
                rep(j, 0, cx) {
                    x[j]++;
                }
            }
        }
        rep(i, 0, q+1) {
            if(maxX < x[i]){
                maxX = x[i];
                retX = i;
            }
            if(maxY < y[i]) {
                maxY = y[i];
                retY = i;
            }
        }
        cout<<"Case #"<<t<<": ";
        cout<<retX<<" "<<retY<<endl;
    }
    return 0;
}