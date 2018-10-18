// 20181018 20:30 ~ 
#include <bits/stdc++.h>
using namespace std;
#define sd(x) scanf(" %d", &x);
#define pb push_back
#define xx first
#define yy second
typedef long long ll;
typedef pair<int, int> P;

int n;
int arr[200001];
stack<int> ans;

int main() {
    cin>>n;
    for(int i=2; i<=n; i++) cin>>arr[i];
    while(n){
        ans.push(n);
        n = arr[n];
    }
    while(!ans.empty()){
        cout<<ans.top()<<" ";
        ans.pop();
    }
    return 0;
}