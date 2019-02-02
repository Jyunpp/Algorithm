// 20190202 12:38 ~ 
#include <iostream>
#include <vector>
#include <math.h>
#include <string>
using namespace std;

int n;
vector<vector<char> > v;
int ans[3];
int maxScores;
string name[3] = {"Adrian", "Bruno", "Goran"};

int main() {
    v.push_back(vector<char> {'A', 'B', 'C'});
    v.push_back(vector<char> {'B', 'A', 'B', 'C'});
    v.push_back(vector<char> {'C', 'C', 'A', 'A', 'B', 'B'});
    cin>>n;
    for(int i=0; i<n; i++) {
        char ch; cin>>ch;
        for(int j=0; j<3; j++) {
            ans[j] += v[j][i % v[j].size()] == ch;
            maxScores = max(maxScores, ans[j]);
        }
    }
    cout<<maxScores<<endl;
    for(int i=0; i<3; i++) {
        if(ans[i] == maxScores) {
            cout<<name[i]<<endl;
        }
    }
    return 0;
}