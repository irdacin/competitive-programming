#include <bits/stdc++.h>
#define keren ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl '\n'
#define ll long long
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    int a[n];
    for(auto &i:a) cin >> i;

    bool yes=false;
    for(auto &i:a) if(i==k) yes=true;
    cout << (yes ? "YES" : "NO") << endl;
}

int main(){
    keren;
    int t; cin >> t; while(t--)
    solve();
    return 0;
}