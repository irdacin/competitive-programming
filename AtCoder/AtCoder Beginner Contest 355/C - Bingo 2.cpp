#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()

#define vi vector<int>
#define vvi vector<vi>

const int MOD = 1e9 + 7;

void solve(){
    int n, t; cin >> n >> t;

    vi row(n+1, 0), col(n+1, 0);
    int d1 = 0, d2 = 0;
    for(int turn = 1; t--; turn++){
        int a; cin >> a;
        
        int r = a / n + 1, c = a % n;
        if(c==0) r--, c = n;

        row[r]++, col[c]++;
        if(r == c) d1++;
        if(r+c == n+1) d2++;
        
        if(row[r]==n || col[c]==n || d1==n || d2==n) exit(turn);
    }
    cout << -1;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
}