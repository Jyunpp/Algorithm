// 20190504 18:00 ~ 18:24
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

int T, n;
int arr[4][501]; //1 R , 2 P, 3 S
string A[256];
int remain[256];
int remainNum;

int main() {
    cin>>T;
    rep(t, 1, T+1) {
        cin>>n;
        remainNum = n;
        rep(i, 1, 501) {
            rep(j, 1, 4) arr[j][i] = 0;
        }
        rep(i, 1, 255) remain[i] = 1;
        string ret = "";
        bool can = true;
        rep(i, 1, n+1) {
            string s;
            cin>>s;
            A[i] = s;
        }
        //make ret;
        rep(i, 1, 501) {
            if(remainNum==0) break;
            rep(j, 1, n+1) {
                if(!remain[j]) continue;
                char opp = A[j][(i-1)%A[j].size()];
                if(opp=='R') arr[1][i]++;
                else if(opp=='P') arr[2][i]++;
                else arr[3][i]++;
            }
            if(arr[1][i]!= 0 && arr[2][i]!=0 &&arr[3][i] != 0) {
                can = false;
            }
            char curr;
            if(arr[1][i]!= 0 && arr[2][i] != 0) curr = 'P';
            else if(arr[2][i] != 0 && arr[3][i] != 0) curr = 'S';
            else if(arr[1][i] != 0 && arr[3][i] != 0) curr = 'R';
            else if(arr[1][i]) curr = 'P';
            else if(arr[2][i]) curr = 'S';
            else curr = 'R';
            ret += curr;
            rep(j, 1, n+1) {
                if(!remain[j]) continue;
                char opp = A[j][(i-1)%A[j].size()];
                if((opp=='R' && curr == 'P')
                    ||(opp=='P' && curr == 'S')
                    ||(opp=='S' && curr == 'R')) {
                        remain[j]=0;
                        remainNum--;            
                }
            }
        }
        cout<<"Case #"<<t<<": ";
        if(!can || remainNum != 0) {
            cout<<"IMPOSSIBLE"<<endl;
        } else {
            cout<<ret<<endl;
        }
    }
    return 0;
}