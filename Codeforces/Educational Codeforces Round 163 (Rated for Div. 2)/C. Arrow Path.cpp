#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int n; cin >> n;
    vector<vector<char>> grid(2, vector<char>(n));
    for(auto &row:grid) for(auto &c:row) cin >> c;

    auto valid = [&](int row, int col){
        return row>=0 && row<2 && col>=0 && col<=n;
    };

    pair<int,int> dir[4] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    vector<vector<bool>> vis(2, vector<bool>(n, false));
    // vector<vector<int>> dp(2, vector<int>(n, -1));
    function<bool(int,int)> func = [&](int i, int row) -> bool{
        if(i==n-1 && row==1) return true;

        vis[row][i] = true;

        // int &res = dp[row][i];
        // if(res!=-1) return res;

        int res = 0;
        for(auto [x, y]:dir){
            x+=row, y+=i;
            if(valid(x, y)){
                if(grid[x][y]=='>' && valid(x, y+1) && !vis[x][y+1]) res |= func(y+1, x);
                else if(valid(x, y-1) && !vis[x][y-1]) res |= func(y-1, x);
            }
        }

        // vis[row][i] = false;
        return res;
    };

    cout << (func(0,0) ? "YES":"NO");
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}