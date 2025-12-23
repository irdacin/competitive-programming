#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define rcout(x) return void(cout << x)

template <typename T> using vec = vector<T>;
template <typename T> using vvec = vector<vec<T>>;
template <typename T> using vvvec = vector<vvec<T>>;
#define pb push_back
#define all(x) x.begin(), x.end()
#define len(x) (int) x.size()

const int MOD = 1e9 + 7;
const int INF = 2e9;

void solve(){
    int n, l, r; cin >> n >> l >> r;
    for(int i = 1; i <= n; i++){
        if(i >= l && i <= r) for(; r >= l; i++) cout << r-- << ' ';
        if(i <= n) cout << i << ' ';
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
}