// 20180324 17:24 ~ 17:47
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

int r, c;
vector<string> v;
char arr[21][21];

void add(int R, int C){
    string str(1, arr[R][C]);
    if(str=="#") return;
    string s;
    if(arr[R-1][C]=='#'||R==1){
        s = str;
        for(int i=R+1; i<=r; i++){
            if(arr[i][C]=='#') break;
            s += string(1, arr[i][C]);
        }
        if(s.size()>=2) v.pb(s);
    }
    if(arr[R][C-1]=='#'||C==1){
        s = str;
        for(int i=C+1; i<=c; i++){
            if(arr[R][i]=='#') break;
            s += string(1, arr[R][i]);
        }
        if(s.size()>=2) v.pb(s);
    }
}

int main(){
    cin>>r>>c;
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++)
            cin>>arr[i][j];
    }
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++)
            add(i, j);
    }
    sort(v.begin(), v.end());
    cout<<v[0]<<endl;
    return 0;
}