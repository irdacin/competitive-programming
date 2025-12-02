#include <bits/stdc++.h>
#define AC ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl '\n'
#define ll long long
using namespace std;

void solve(){
    int n; cin >> n;
    int a[n];
    for(auto &i:a) cin >> i;
    int min=a[0];
    for(auto &i:a) if(min>i) min=i;
    for(auto &i:a) if(min==i) {i++; break;}
    int ans=1;
    for(auto &i:a) ans*=i;
    cout << ans << endl;
}

int main(){
    AC;
    int t; cin >> t; while(t--)
    solve();
    return 0;
}