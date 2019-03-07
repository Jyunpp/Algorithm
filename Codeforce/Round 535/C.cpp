// 20190306 20:48 ~ 21:02
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
char arr[6][3] = {'R', 'G', 'B'
                 ,'R', 'B', 'G'
                 ,'G', 'B', 'R'
                 ,'G', 'R', 'B'
                 ,'B', 'G', 'R'
                 ,'B', 'R', 'G'};
int retSIdx;

int main() {
    cin>>n;
    cin>>s;
    if(n==1){
        cout<<0<<endl<<s<<endl;
        return 0;
    }
    if(n==2) {
        if(s[0] != s[1]) {
            cout<<0<<endl<<s<<endl;
            return 0;
        } else {
            cout<<1<<endl;
            if(s[0] == 'R') {
                cout<<"RB"<<endl;
                return 0;
            } else {
                cout<<"BR"<<endl;
                return 0;
            }
        }
    }
    int ret = 987654321;
    string retS;
    rep(i, 0, 7) {
        int currRet = 0;
        rep(j, 0, n) {
            int idx = j%3;
            if(s[j] != arr[i][idx]) currRet++;
        }
        if(currRet<ret) {
            ret = currRet;
            retSIdx = i;
        }
    }
    cout<<ret<<endl;
    rep(i, 0, n){
        cout<<arr[retSIdx][i%3];
    }
    return 0;
}