#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
using namespace std;

void solve(){
    int n; cin >> n;
    int a[n];
    int idx=1;
    for(auto &i:a) cin >> i, i+=idx++;

    sort(a, a+n, greater<int>());
    int prev = INT_MAX;
    for(auto &i:a){
        if(i>=prev) i=prev-1;
        prev = i;
    }

    for(auto &i:a) cout << i << ' ';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}