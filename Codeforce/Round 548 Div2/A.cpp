// 20190322 00:35 ~ 
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

ll ans;
int n;
string s;

int main() {
    cin>>n;
    cin>>s;
    rep(i, 0, n) {
        if(s[i]=='0'||s[i]=='8'||s[i]=='6'||s[i]=='4'||s[i]=='2'){
            ans += (i+1);
        }
    }
    cout<<ans<<endl;
    return 0;
}