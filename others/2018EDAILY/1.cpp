// 20181026 12:55 ~ 13:05
#include <bits/stdc++.h>
using namespace std;
#define sd(x) scanf(" %d", &x);
#define pb push_back
#define xx first
#define yy second
typedef long long ll;
typedef pair<int, int> P;

int arr[11][11];
int n, ans;

void solve(int idx){
    int ret = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            ret += arr[i][j];
        }
    }
    ans = min(ans, ret);
    if(idx==n+1) return;
    solve(idx+1);
    for(int i=1; i<=n; i++) arr[idx][i] = !arr[idx][i];
    solve(idx+1);
    for(int i=1; i<=n; i++) arr[i][idx] = !arr[i][idx];
    solve(idx+1);
    for(int i=1; i<=n; i++) arr[idx][i] = !arr[idx][i];
    solve(idx+1);
}

int main() {
    ans = 987654321;
    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            char ch;
            cin>>ch;
            arr[i][j] = ch=='W';
        }
    }
    solve(1);
    cout<<ans<<endl;
    return 0;
}