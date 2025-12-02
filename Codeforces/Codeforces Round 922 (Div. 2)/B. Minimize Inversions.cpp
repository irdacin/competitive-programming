#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
using namespace std;

void solve(){
    int n;
    cin >> n;

    int a[n], b[n];
    for(auto &i:a) cin >> i;
    for(auto &i:b) cin >> i;

    int idx=0;
    pair<int,int>p[n];
    for(auto &[i,j]:p) i=a[idx], j=b[idx++]; 
    sort(p,p+n);

    for(auto &[i,j]:p) cout << i << ' '; cout << endl;
    for(auto &[i,j]:p) cout << j << ' ';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}