#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int n, m; cin >> n >> m;
    char a[n], b[m];
    for(auto &c:a) cin >> c;
    for(auto &c:b) cin >> c;
    
    int k=0;
    for(int i=0; k<n&&i<m;i++){
        if(a[k]==b[i]) k++;
    }
    cout << k;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}