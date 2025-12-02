#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int a, b, m;
    cin >> a >> b >> m;

    int firework1 = (m+1)/a + ((m+1)%a==0 ? 0:1);
    int firework2 = (m+1)/b + ((m+1)%b==0 ? 0:1);
    cout << firework1 + firework2;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}