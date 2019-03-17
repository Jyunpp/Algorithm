// 20190317 14:04 ~ 14:19
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
vector<string> v[101];
string arr[203];
int visited[100];

int main() {
    cin>>n;
    for(int i=1; i<=(2*n-2); i++) {
        string s;
        cin>>s;
        arr[i] = s;
        v[s.size()].pb(s);
    }
    string str;
    if(v[n-1][0].substr(1, n-2) == v[n-1][1].substr(0, n-2)
    && ( n<=2
        || (v[n-1][0].substr(0, n-2) == v[n-2][0])
        || (v[n-1][0].substr(0, n-2) == v[n-2][1]) )) {
        str = v[n-1][0] + v[n-1][1].substr(n-2, 1);
    } else {
        str = v[n-1][1] + v[n-1][0].substr(n-2, 1);
    }
    for(int i=1; i<=(2*n-2); i++) {
        int len = arr[i].size();
        if(visited[len]) cout<<(char)('S' + 'P' - visited[len]);
        else {
            if(str.substr(0, len) == arr[i]) {
                visited[len] = 'P';
            } else {
                visited[len] = 'S';
            }
            cout<<(char)visited[len];
        }
    }
    return 0;
}