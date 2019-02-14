// 20190214 01:37 ~ 01:53
/* *** pair 안의 한 정보로 sort 시, 같은 경우 정의 안하던지, 하려면 제대로.
* O : [](P a, P b){return a.yy < b.yy;} 
* O : [](P a, P b){return a.yy < b.yy ? a.yy < b.yy : a.yy == b.yy ? a.xx < b.xx : false;}
* X : [](P a, P b){return a.yy < b. yy ? a.yy < b.yy : a.xx < b. xx;}
*  => a.yy == b.yy 인 경우에 3항으로 넘어가길 의도했지만, a.yy > b.yy 도 넘어감.
*/
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

int arr[27];
int n; 

void solve(int currT, int total) {
    int rest = total;
    vector<P> v;
    rep(i, 1, n+1) {
        if(arr[i] >= 1) v.push_back({i, arr[i]});
    }
    cout<<"Case #"<<currT<<":";
    while(rest) {
        sort(v.begin(), v.end(), [](P a, P b){return a.yy > b. yy;});
        if(rest == 3) {
            cout<<" "<<(char)(('A'-1) + v[0].xx);
            v[0].yy--;
            rest -=1;
        } else {
            cout<<" "<<(char)(('A'-1) + v[0].xx)<<(char)(('A'-1) + v[1].xx);
            v[0].yy--;
            v[1].yy--;
            rest -=2;
        }
    }
    cout<<endl;
}

int main() {
    int T; sd(T);
    rep(t, 1, T+1) {
        sd(n);
        int total = 0;
        rep(i, 1, n+1) {
            sd(arr[i]);
            total += arr[i];
        }
        solve(t, total);
    }
}