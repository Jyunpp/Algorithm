// 20190214 16:26 ~  17:08
/*
* float 말고 double 쓰기..
cout<<fixed; cout.precision(6);
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
#define sortV(v, lambda) sort(v.begin(), v.end(), lambda)

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;

int t, d, n, k, s;
double maxTime;

int main() {
    cin>>t;
    rep(T, 1, t+1) {
        cin>>d>>n;
        maxTime = 0;
        rep(i, 1, n+1){
            cin>>k>>s;
            maxTime = max(maxTime, (double)(d-k)/s);
        }
        cout<<fixed; cout.precision(6);
        cout<<"Case #"<<T<<": "<<(double)d / maxTime<<endl;
    }
    return 0;
}