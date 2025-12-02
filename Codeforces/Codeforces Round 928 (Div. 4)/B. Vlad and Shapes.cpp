#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int n; cin >> n;
    char grid[n][n];
    for(auto &s:grid) for(auto &c:s) cin >> c;

    int one=-1;
    for(int i=0;i<n;i++){
        int j=0;
        for(;j<n && grid[i][j]!='1';j++);
        if(j==n) continue;
        if(one==-1) one=j;
        else if(one!=j) exit("TRIANGLE");
        else exit("SQUARE");
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}