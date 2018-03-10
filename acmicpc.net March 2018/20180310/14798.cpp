//20180310 23:26 ~ 01:12 ~ 02:24
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define xx first
#define yy second
#define pb push_back

int T, r, c;
int row, column;                    // the number of initial alphabet
char arr[26][26];
pair<int ,int> apArr['Z'-'A'+1];    // alphabet -> position (y, x)
vector<char> paArr[2][26];          // position -> alphabet 
                                    // firstIndex == 0 ? row 
                                    // firstIndex == 1 ? column     // column is not used
                                    // both Ascending index
int rows[26], columns[26];          // boolean.. 0 -> no initial alphabet this row(or column).  // columns is not used
void printing(){
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            cout<<arr[i][j];
        }
        if(i!=r) cout<<endl;
    }
}
// fill idx row with same state of idx+1 row
int duplicateRows(int idx){
    if(idx>=r) return -1;  // last => exception
    // if idx+1 row is also empty, then recursion to fill idx+1 before filling idx row
    if(!rows[idx+1]){
        // if fail to fill idx+1 then fail
        if(duplicateRows(idx+1)==-1) return -1;
    }
    // fill idx. duplicate
    for(int i=1; i<=c; i++){
        if(arr[idx+1][i]!='?'){
            arr[idx][i] = arr[idx+1][i];
            rows[idx]++;
            paArr[0][idx].pb(arr[idx+1][i]);
        }
    }
    return 1;
}
void solve(){
    // if can't fill with first state, duplicate rows and filling with horizontal direction
    if(row!=r){         // && column !=c){
        // then duplicate rows to make row == r
        for(int i=1; i<=r; i++){
            if(!rows[i]) duplicateRows(i);  // duplicate i rows with i+1 rows.. recursively
        }
        // duplicate last rows with last-1 rows.. recursively
        if(!rows[r]){
            int idx = r;
            while(!rows[--idx]){}   // find row have alphabet, duplicate with that row
            for(int i=idx; i<r; i++){
                for(int j=1; j<=c; j++){
                    if(arr[i][j]!='?'){
                        arr[i+1][j] = arr[i][j];
                        rows[i+1]++;
                        paArr[0][i+1].pb(arr[i][j]);
                    }
                }
            }
        }
    }
    // filling alphabet with horizontal direction
    // for all row
    for(int i=1; i<=r; i++){
        // while loop, fill with curr alphabets
        char prev = 'x';
        for( char curr : paArr[0][i]){
            int prevArrIdx = prev == 'x' ? 0 : apArr[prev-'A'].yy;
            for(int j=prevArrIdx+1; j<=apArr[curr-'A'].yy; j++) arr[i][j] = curr;
            prev = curr;
        }
        // fill rest with last alphabet
        char last = paArr[0][i][paArr[0][i].size()-1];
        for(int j=apArr[last-'A'].yy+1; j<=c; j++) arr[i][j] = last;
    }
    printing();
    return ;
}

int main(){
    cin>>T;
    for(int i=1; i<=T; i++){
        cin>>r>>c;
        // reset
        for(int j=0; j<'Z'-'A'+1; j++) {
            apArr[j] = {0, 0};
        }
        for(int j=0; j<=1; j++){
            for(int k=0; k<=25; k++)
                paArr[j][k].clear();
        }
        row = column = 0;
        for(int j=1; j<=r; j++) rows[j] = 0;
        for(int j=1; j<=c; j++) columns[j] = 0;
        // input & solve
        for(int j=1; j<=r; j++){
            for(int k=1; k<=c; k++){
                char curr; cin>>curr; arr[j][k] = curr;
                if(curr != '?'){
                    apArr[curr-'A'] = {j, k};   //y, x
                    paArr[0][j].pb(curr); 
                    paArr[1][k].pb(curr); 
                    if(paArr[0][j].size() == 1) row++; 
                    if(paArr[1][k].size() == 1) column++; 
                    rows[j]++;
                    columns[k]++;
                }
            }
        }
        cout<<"Case #"<<i<<":"<<endl;
        solve();
        if(i!=T)cout<<endl;
    }
    return 0;
}