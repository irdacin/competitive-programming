#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
using namespace std;

void solve(){
    int n, m, k; 
    cin >> n >> m >> k;
    int a[n], b[m];
    for(auto &i:a) cin >> i;
    for(auto &i:b) cin >> i;

    set<int>sa,sb;
    for(auto &i:a) if(i<=k) sa.insert(i);
    for(auto &i:b) if(i<=k) sb.insert(i);

    if(sa.size()*2<k || sb.size()*2<k) exit("NO");

    for(auto &i:sa){
        if(sb.find(i)!=sb.end()) sb.erase(i);
    }

    // for(auto &i:sa) cout << i << ' ';
    // cout << endl;
    // for(auto &i:sb) cout << i << ' ';

    if(sa.size()+sb.size()==k) cout << "YES";
    else cout << "NO";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}