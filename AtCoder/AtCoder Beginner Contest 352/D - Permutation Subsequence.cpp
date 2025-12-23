#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    int pos[n];
    for(int i=0, p; i<n; i++) cin >> p, pos[--p] = i;

    set<int> st;
    int ans = n;
    for(int i=0, j=0; j<n; i++){
        for(; j < i+k; j++) st.insert(pos[j]);
        ans = min(ans, *--st.end() - *st.begin());
        st.erase(pos[i]);
    }
    cout << ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
}