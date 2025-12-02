#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    int plus = 0, min=0;
    for(auto &c:s)
        plus+=c=='+', min+=c=='-';
    cout << abs(plus-min);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}