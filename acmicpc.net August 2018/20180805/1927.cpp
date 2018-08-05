#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <memory.h>
#include <algorithm>
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

int n;

int main(){
    cin>>n;
    queue<int> q;
    string s;
    for(int i=1,a; i<=n; i++){
        cin>>s;
        if(s=="push") {
            cin>>a;
            q.push(a);
        }
        else if(s=="pop"){
            if(!q.empty()){
                int b = q.front();
                q.pop();
                cout<<b<<endl;
            } else cout<<-1<<endl;
        }
        else if(s=="size"){
            cout<<q.size()<<endl;
        }
        else if(s=="empty"){
            cout<<q.empty()<<endl;
        }
        else if(s=="front"){
            if(q.empty()) cout<<-1<<endl;
            else cout<<q.front()<<endl;
        }
        else if(s=="back"){
            if(q.empty()) cout<<-1<<endl;
            else cout<<q.back()<<endl;;
        }
    }
    return 0;
}