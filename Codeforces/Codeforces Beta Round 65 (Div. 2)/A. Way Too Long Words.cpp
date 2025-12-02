#include <bits/stdc++.h>
#define ez ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl '\n'
#define ll long long
using namespace std;

void solve(){
    string s;
    cin >> s;
    (s.length()>10) ?
        cout << s[0] << s.length()-2 << s[s.length()-1] :
        cout << s.substr(0,10);
    cout << endl;
}

int main(){
    ez;
    int t; cin >> t; while(t--)
    solve();
    return 0;
}