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
    int n, m; cin >> n >> m;
    vec<int> a(m);
    for(auto &i : a) cin >> i;

    vvec<int> x(n, vec<int>(m));
    for(auto &row : x) for(auto &i : row) cin >> i;

    for(int j = 0; j < m; j++){
        int sum = 0;
        for(int i = 0; i < n; i++) sum += x[i][j];
        if(a[j] > sum) rcout("No");
    }
    
    cout << "Yes";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
}