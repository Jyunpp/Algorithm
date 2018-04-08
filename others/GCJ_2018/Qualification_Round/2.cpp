// 20180408 04:04 ~ 04:16
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

typedef long long ll;
typedef pair<int, int> P;

int T, N;

int main(){
    cin>>T;
    for(int i=1; i<=T; i++){
        int ret = -1;
        cin>>N;
        vector<int> v;
        vector<int> sub_odd, sub_even;
        for(int j=1, a; j<=N; j++){
            sd(a); v.pb(a);
        }
        for(int j=1; j<=N; j++){
            if(j%2) sub_odd.pb(v[j-1]);
            else sub_even.pb(v[j-1]);
        }
        sort(sub_odd.begin(), sub_odd.end());
        sort(sub_even.begin(), sub_even.end());
        v.clear();
        int len = sub_odd.size();
        for(int j=0; j<len-1; j++){
            v.pb(sub_odd[j]);
            v.pb(sub_even[j]);
        }
        v.pb(sub_odd[len-1]);
        if(sub_odd.size()==sub_even.size()){
            v.pb(sub_even[len-1]);
        }
        for(int j=0; j<N-1; j++){
            int curr = j;
            int next = j+1;
            if(v[curr]>v[next]) {
                ret = curr;
                break;
            }
        }
        cout<<"Case #"<<i<<": ";
        if(ret !=-1) cout<<ret;
        else cout<<"OK";
        if(i!=T) cout<<endl;
    }
    return 0;
}