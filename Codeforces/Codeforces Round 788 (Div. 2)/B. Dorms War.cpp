#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int n; string s;
    cin >> n >> s;
    
    int k; cin >> k;
    set<char> st;
    for(char c;k--;) cin >> c, st.insert(c);

    int ans = 0;
    for(int i=0, j=0; i<n; i++){
        if(st.find(s[i])!=st.end()){
            ans = max(ans, i-j);
            j = i;
        }
    }
    cout << ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}