// 20190325 20:24 ~ 21:50
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
int c[5001], a[5001];
P arr[5001];
int num[12];
int aa,bb,cc,dd;
int pa, pb, pc, pd;

int main() {
    cin>>n;
    rep(i, 1, n+1) {
        char ch; cin>>ch;
        c[i] = (ch=='1');
    }
    rep(i, 1, n+1) {
        char ch; cin>>ch;
        a[i] = (ch=='1');
    }
    rep(i, 1, n+1) {
        arr[i] = {c[i], a[i]};
        num[c[i]*10+a[i]]++;
    }
    int finished = 0;
    int temp = num[01];
    rep(i, 0, num[10] +1) {
        rep(j, 0, num[11] + 1) {
            if(i+j>n/2) continue;
            if(num[11] - j + temp >= i+j) {
                int tempbb = num[11] - j + temp - i - j ;
                if(tempbb<0 || tempbb > temp) continue;
                if (tempbb+i+j > n/2) continue;
                int tempaa = n/2 - tempbb - i - j;
                if(tempaa > num[0] || tempaa < 0) continue;
                aa = tempaa;
                bb = tempbb;
                cc = i;
                dd = j;
                finished = 1;
            }
        }
        if(finished) break;
    }
    if(!finished) {
        cout<<-1<<endl;
        return 0;
    } else {
        rep(i, 1, n+1) {
            if(arr[i].xx == 0 && arr[i].yy == 0) {
                if(pa<aa){
                    cout<<i<<" ";
                    pa++;
                }
            } else if(arr[i].xx == 0 && arr[i].yy == 1) {
                if(pb<bb){
                    cout<<i<<" ";
                    pb++;
                }
            } else if(arr[i].xx == 1 && arr[i].yy == 0) {
                if(pc<cc){
                    cout<<i<<" ";
                    pc++;
                }
            } else {
                if(pd<dd){
                    cout<<i<<" ";
                    pd++;
                }
            }
        }
    }
    return 0;
}