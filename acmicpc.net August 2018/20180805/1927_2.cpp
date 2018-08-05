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
#include <math.h>
using namespace std;

#define sd(x) scanf(" %d", &x);
#define slld(x) scanf(" %lld", &x);
#define pb push_back
#define xx first
#define yy second

typedef long long ll;
typedef pair<int, int> P;

int main(){
    int n;
    cin>>n;
    for(int i=1,a; i<=n; i++){
        sd(a);
        if(a) pq.push(a);
        else{
            if(pq.empty()) cout<<0<<endl;
            else {
                cout<<pq.top()<<endl;
                pq.pop();
            }
        }
    }
    return 0;
}