#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
using namespace std;

void solve(){
    int n, f, a, b;
    cin >> n >> f >> a >> b;
    int m[n];
    for(auto &i:m) cin >> i;

    int prev=0;
    for(auto &i:m){
        f-=min(b,abs(i-prev)*a);
        prev=i;
        if(f<=0) exit("NO");
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