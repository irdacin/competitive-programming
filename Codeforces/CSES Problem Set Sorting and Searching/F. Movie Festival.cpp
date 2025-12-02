#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
using namespace std;

void solve(){
    int n;
    cin >> n;

    pair<int,int>movie[n];
    for(auto &[a,b]:movie) cin >> a >> b;
    sort(movie, movie+n, [](const auto& x, const auto& y){
        return x.second < y.second;
    });
    int cur = 0, ans = 0;
    for(auto &[a,b]:movie)
        if(a>=cur) cur = b, ans++;
    cout << ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
}