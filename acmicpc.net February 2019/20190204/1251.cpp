// 20190204 13:43 ~ 13:54
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string s;
vector<string> v;

string rev(string s) {
    reverse(s.begin(), s.end());
    return s;
}

void solve() {
    for(int i=1; i<s.size(); i++) {
        for(int j=1; i+j<s.size(); j++) {
            v.push_back(rev(s.substr(0, i)) + rev(s.substr(i, j)) + rev(s.substr(i+j)));
        }
    }
    sort(v.begin(), v.end(), [](string s1, string s2){return s1<s2;});
    cout<<v[0]<<endl;
}

int main() {
    cin>>s;
    solve();
    return 0;
}