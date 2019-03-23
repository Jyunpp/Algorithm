// 20190322 00:13 ~ 00:24
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

int t, n;
string s;

int main() {
    cin>>t;
    while(t--) {
        cin>>n;
        cin>>s;
        int temp1, temp2;
        temp1 = temp2 = 987654321;
        rep(i, 0, n) {
            if(s[i]=='>') {
                temp1 = i;
                break;
            }
        }
        int iter = 0;
        for(int i=n-1; i>=0; i--) {
            if(s[i] == '<') {
                temp2 = iter;
                break;
            }
            iter++;
        }
        cout<<min(temp1, temp2)<<endl;
    }
    return 0;
}