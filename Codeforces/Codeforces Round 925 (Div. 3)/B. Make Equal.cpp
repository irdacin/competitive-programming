#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(auto &i:a) cin >> i;

    int med = 0;
    for(auto &i:a) med+=i;
    med/=n;

    int need = 0;
    for(auto &i:a){
        // cout << i << ' ';
        need+=(i-med);
        if(need<0) exit("NO");
    }

    cout << "YES";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}