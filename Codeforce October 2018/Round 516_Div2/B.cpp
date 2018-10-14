// 20181015
#include <bits/stdc++.h>
using namespace std;
#define sd(x) scanf(" %d", &x);
#define pb push_back
#define xx first
#define yy second
typedef long long ll;
typedef pair<int, int> P;

int t, n;

int main() {
    cin>>t;
    for(int i=1; i<=t; i++){
        cin>>n;
        cout<<(1<<__builtin_popcount(n))<<endl;
    }
}