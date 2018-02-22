//20180222 22:10 ~ 22:50
#include <iostream>
#include <string>
#define xx first
#define yy second
using namespace std;

typedef pair<int, int> P;
/*
idx
8
7
6
5
4
3
2
1
  A B C D E F G H
  1 2 3 4 5 6 7 8 <- idx.. int
*/
int n;
P king; // 1
P stone;// 2
int dy[8] = {0, 0, -1, 1, 1, 1, -1, -1};
int dx[8] = {1, -1, 0, 0, 1, -1, 1, -1};
string moving[8] = {"R", "L", "B", "T", "RT", "LT", "RB", "LB"};

void move(string s){
    int idx, nky, nkx, nsy, nsx;
    for(int i=0; i<8; i++){
        if(moving[i]==s) idx = i;
    }
    //cout<<idx<<endl;
    nky = king.yy + dy[idx];
    nkx = king.xx + dx[idx];
    //cout<<nky<<", "<<nkx<<endl;
    
    // out
    if(nky*nkx == 0 || nky > 8 || nkx > 8) return ;
    
    // next king location == stone location
    if(nky == stone.yy && nkx == stone.xx) {
        //change next stone location
        nsy = stone.yy + dy[idx];
        nsx = stone.xx + dx[idx];
        
        //stone can't move
        if(nsy*nsx==0 || nsy > 8 || nsx > 8 ) return ;
        
        //stone can move
        king.yy = nky; king.xx = nkx;
        stone.yy = nsy; stone.xx = nsx;
    }
    // next king location != stone location
    else{
        king.yy = nky; king.xx = nkx;
    }
}

void solve(){
    cout<<(char)('A' + king.xx - 1)<<king.yy<<endl;
    cout<<(char)('A' + stone.xx - 1)<<stone.yy;
}

int main(){
    string k, s;
    cin>>k>>s>>n;
    king.yy = k[1] - '0'; king.xx = k[0] - 'A' + 1;
    stone.yy = s[1] - '0'; stone.xx = s[0] -'A' + 1;
    for(int i=1; i<=n; i++){
        string s;
        cin>>s;
        move(s);
        //cout<<"times #"<<i<<endl;
        //solve();
        //cout<<endl;
    }
    solve();
    return 0;
}   