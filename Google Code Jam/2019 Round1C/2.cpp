// 20190504 19:30 ~ 
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

int T, F;
char judge;
int arr[6];
char ans[596];
int temp[6];

int main() {
    cin>>T>>F;
    rep(t, 1, T+1) {
        rep(i, 1, 595) ans[i] = '.';
        rep(i, 1, 6) temp[i] = 0;
        string ret = "";
        //357
        rep(i, 1, 4) {
            rep(j, 1, 6) arr[j] = 0;
            rep(j, 0, 119) {
                int curr = i + j*5;
                cout<<curr<<endl;
                char ch; cin>>ch;
                ans[curr] = ch;
                arr[(1 + (int)(ch - 'A'))]++;
            }
            int idx = 0;
            rep(j, 1, 6) if(arr[j] == 23) idx = j;
            ret += (char)('A' - 1 + idx);
            temp[idx] = 1;
        }
        int idx = 0;
        int iidx = 0;
        rep(i, 1, 6) {
            if(!temp[i]) {
                if(!idx) idx = i;
                else iidx = i;
            }
        }
        rep(j, 1, 6) arr[j] = 0;
        rep(i, 0, 119) {
            int curr = 4 + i*5;
            if(ans[curr-1] == (char)('A'-1+idx)
              ||ans[curr-2] == (char)('A'-1+idx)
              ||ans[curr-3] == (char)('A'-1+idx)) {
                  continue;
            }
            cout<<curr<<endl;
            char ch; cin>>ch;
            ans[curr] = ch;
            arr[(1 + (int)(ch - 'A'))]++;
        }
        if(arr[idx] == 24) {
            ret += (char)('A'-1 + iidx);
            ret += (char)('A'-1 + idx);
        } else {
            ret += (char)('A'-1 + idx);
            ret += (char)('A'-1 + iidx);
        }
        cout<<ret<<endl;
        cin>>judge;
        if(judge!='Y') return 0;
    }
    return 0;
}