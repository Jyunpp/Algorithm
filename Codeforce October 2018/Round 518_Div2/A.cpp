// 20181025 01:35 ~ 
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
    if(n<m || k+l>n) {
        cout<<-1<<endl;
        return 0;
    } else{
        if(m>=k+l) {
            cout<<1<<endl;
            return 0;
        } else {
            ll a = (k+l)/m;
            if(a*m<=n){
                if((k+l)%m){
                    cout<<a+1<<endl;
                    return 0;
                }else{
                cout<<a<<endl;
                return 0;
                }
            } else {
                cout<<-1<<endl;
                return 0;
            }
        }
    }
}