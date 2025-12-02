#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int n, c, d;
    cin >> n >> c >> d;

    int a[n*n];
    for(auto &i:a) cin >> i;
    sort(a, a+n*n);

    int grid[n][n], b[n*n];
    grid[0][0] = a[0];

    int idx = 0;
    for(int i=0; i<n; i++){
        if(i!=0) grid[i][0] = grid[i-1][0] + c;

        for(int j=0; j<n; j++){
            if(j!=0) grid[i][j] = grid[i][j-1] + d;
            // cout << grid[i][j] << ' ';
            b[idx++] = grid[i][j];
        }
        // cout << endl;

    }

    sort(b, b+n*n);
    for(int i=0; i<n*n; i++) if(a[i]!=b[i]) exit("NO");

    cout << "YES";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}