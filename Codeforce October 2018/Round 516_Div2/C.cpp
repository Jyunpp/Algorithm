// 20181019 20:20 ~ 
#include <bits/stdc++.h>
using namespace std;

#define sd(x) scanf(" %d", &x);
#define pb push_back
#define xx first
#define yy second

typedef long long ll;
typedef pair<int, int> P;

int n;
string s;

int main() {
    cin>>n;
    cin>>s;
    sort(s.begin(), s.end());
    cout<<s;
    return 0;
}