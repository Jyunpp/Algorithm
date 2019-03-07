// 20190306 21:05 ~ 21:35
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
string s;

char get(char a, char b) {
    if(a==b){
        return 'R'!=a?'R':'B';
    }
    return 'R' + 'G' + 'B' - a - b;
}

int main() {
    cin>>n;
    cin>>s;
    if(n==1) {
        cout<<0<<endl<<s<<endl;return 0;
    }
    char curr = s[0];
    int currLen = 1;
    queue<int> q;
    rep(i, 1, n) {
        if(curr == s[i]) {
            currLen++;
            continue;
        } else {
            q.push(currLen);
            curr = s[i];
            currLen = 1;
        }
    }
    q.push(currLen);
    int ret = 0;
    int i = 0;
    int currSz;
    while(i<n) {
        currSz = q.front(); q.pop();
        int cnt = 2;
        while(cnt<=currSz) {
            if(i+2<=n-1){
                s[i+1] = get(s[i], s[i+2]);
            } else {
                s[i+1] = (s[i+1] != 'R' ? 'R':'B');
            }
            i+=2;
            cnt+=2;
            ret++;
        }
        if(currSz%2) i++;
    }
    cout<<ret<<endl;
    cout<<s<<endl;
    return 0;
}