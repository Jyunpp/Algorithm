// 20190421 08:00 ~ 08:36
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

int t;
int n, q;
int dp[100000][26]; // use idx from 0
int alphabet[26];
string s;

int main() {
    cin>>t;
    rep(T, 1, t+1) {
        cin>>n>>q;
        cin>>s;
        rep(i, 0, 26) alphabet[i] = 0;
        rep(i, 0, 100000){
            rep(j, 0, 26) {
                dp[i][j] = 0;
            }
        }
        rep(i, 0, n) {
            int idx = s[i]-'A';
            alphabet[idx]++;
            if(i!=0) {
                rep(j, 0, 26) {
                    dp[i][j] = dp[i-1][j];
                }
            }
            dp[i][idx] = alphabet[idx];
        }
        int ret = 0;
        rep(i, 0, q) {
            int l, r;
            cin>>l>>r;
            l--;
            r--;
            int odds = 0;
            int evens = 0;
            rep(j, 0, 26) {
                int curr = dp[r][j];
                if(l!=0) curr -= dp[l-1][j];
                // cout<<curr<<endl;
                if(curr%2 == 0) {
                    evens++;
                } else {
                    odds++;
                }
            }
            // cout<<evens<<", "<<odds<<endl;
            if(odds == 1 || odds == 0) {
                ret ++;
            }
        }
        cout<<"Case #"<<T<<": "<<ret<<endl;
    }
    return 0;
}