// 20181025 01:35 ~ 
#include <bits/stdc++.h>
using namespace std;
#define sd(x) scanf(" %d", &x);
#define pb push_back
#define xx first
#define yy second
typedef long long ll;
typedef pair<int, int> P;

ll b, ans;

int main() {
    cin>>b;
    if(b==1) ans = 1;
    for(int i=1; i<sqrt(b); i++){
        if(b%i ==0) {
            ans += 2;
        }
    }
    ll sq = sqrt(b);
    if(b!=1 && b%sq == 0 && sq*sq==b) ans++;
    cout<<ans<<endl;
}
