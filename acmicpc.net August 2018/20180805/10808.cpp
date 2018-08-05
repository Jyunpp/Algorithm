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

int ret[100];

int main(){
    string s;
    cin>>s;
    for(int i=0; i<s.size(); i++){
        ret[s[i]-'a']++;
    }
    for(int i=0; i<='z'-'a'; i++){
        cout<<ret[i];
        if(i!='z'-'a') cout<<" ";
    }
    return 0;
}