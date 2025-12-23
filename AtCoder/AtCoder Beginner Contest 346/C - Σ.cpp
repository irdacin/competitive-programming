#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    set<int> st; int a;
    while(n--) cin >> a, st.insert(a);

    int ans = k*(k+1)/2;
    for(auto i:st){
        if(i<=k) ans-=i;
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