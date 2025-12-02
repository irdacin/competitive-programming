#include <bits/stdc++.h>
#define start ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl '\n'
#define ll long long
using namespace std;

void solve(){
    string str;
    for(int i=0;i<8;i++){
        cin >> str;
        for(int j=0;j<8;j++){
            if(str[j]!='.') cout << str[j];
        }
    }
    cout << endl;
}

int main(){
    start;
    int t; cin >> t; while(t--)
    solve();
    return 0;
}