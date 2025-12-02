#include <bits/stdc++.h>
#define keren ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl '\n'
#define ll long long
using namespace std;

void solve(){
    ll n, k, x;
    cin >> n >> k >> x;
    
    // Sn = n*(a+Un)/2
    // n=k; a=1; Un=k;
    ll awal = k*(1+k) / 2;
    // n=k; a=n-k-1; Un=n
    ll akhir = k*(n-k+1+n)/2;
    // cout << awal << ' ' << akhir << endl;
    
    cout << (awal<=x && x<=akhir ? "YES" : "NO") << endl; 
}

int main(){
    keren;
    int t; cin >> t; while(t--)
    solve();
    return 0;
}