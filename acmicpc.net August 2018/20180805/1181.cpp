#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <memory.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <math.h>
using namespace std;

#define sd(x) scanf(" %d", &x);
#define slld(x) scanf(" %lld", &x);
#define pb push_back
#define xx first
#define yy second

typedef long long ll;
typedef pair<int, int> P;

int n;
set<string> s;
vector<string> v;

int main(){
    cin>>n;
    string str;
    for(int i=1; i<=n; i++){
        cin>>str;
        s.insert(str);
    }
    for(auto i : s)
        v.pb(i);
    sort(v.begin(), v.end(),[](string a, string b){return a.length()!=b.length()?a.length()<b.length():a<b;});
    for(int i=0; i<n; i++){
        cout<<v[i]<<endl;
    }
    return 0;
}