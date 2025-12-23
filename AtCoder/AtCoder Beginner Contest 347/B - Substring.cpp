#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    string s; cin >> s;

    set<string> st;
    for(int i=0;i<len(s);i++){
        for(int j=0;j<len(s);j++){
            st.insert(s.substr(i,j));
        }
    }
    // for(auto i:st) cout << i << ' ';
    cout << len(st);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
}