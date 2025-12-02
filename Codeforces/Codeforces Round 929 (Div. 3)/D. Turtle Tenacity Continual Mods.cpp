#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int n; cin >> n;
    int a[n];
    map<int,int> mp;
    for(auto &i:a) cin >> i, mp[i]++;

    int mn = INT_MAX;
    for(auto i:a) mn = min(mn, i);

    int unique = INT_MAX;
    for(auto [value,cnt]:mp) if(cnt==1) unique = min(unique, value);
    
    if(unique==mn) exit("YES");

    for(auto i:a){
        if(i%mn != 0) exit("YES");
    }

    cout << "NO";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}