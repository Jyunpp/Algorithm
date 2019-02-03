// 20190204 02:55 ~ 02:58
#include <iostream>
using namespace std;

int n;
int arr[101];

void clear() {
    for(int i=1; i<=100; i++) arr[i] = 0;
}

void solve() {
    int ans = 0;
    for(int i=1; i<=50; i++) {
        ans += arr[i]&&arr[i*2];
    }
    cout<<ans<<endl;
}

int main() {
    while(cin>>n){
        if(n==-1) break;
        if(n==0) {
            solve();
            clear();
        }
        else arr[n] = 1;
    }
    return 0;
}