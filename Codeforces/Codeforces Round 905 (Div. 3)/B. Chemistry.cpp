#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int n, k; string s;
    cin >> n >> k >> s;

    map<char,int> mp;
    for(auto c:s) mp[c]++;

    int count = 0;
    for(auto [ch,cnt]:mp) if(cnt&1) count++;

    if(count <= k+1) cout << "YES";
    else cout << "NO";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}