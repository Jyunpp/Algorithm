// 20181022 00:52 ~ 00:56
#include <bits/stdc++.h>
using namespace std;

#define sd(x) scanf(" %d", &x);
#define pb push_back
#define xx first
#define yy second

typedef long long ll;
typedef pair<int, int> P;

int w, h, k, ans;

int main() {
    cin>>w>>h>>k;
    while(k--){
        ans += 2*(w+h-2);
        w-=4;h-=4;
    }
    cout<<ans<<endl;
    return 0;
}