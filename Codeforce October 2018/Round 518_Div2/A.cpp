// 20181025 01:35 ~ 
// 20181025 11:55 ~ 12:03
#include <bits/stdc++.h>
using namespace std;
#define sd(x) scanf(" %d", &x);
#define pb push_back
#define xx first
#define yy second
typedef long long ll;
typedef pair<int, int> P;

ll n, k,m,l;

int main() {
    cin>>n>>m>>k>>l;
    ll ans = ((k+l)/m) + ((k+l)%m!=0);
    if(ans*m>n) ans = -1;
    cout<<ans<<endl;
    return 0;    
}