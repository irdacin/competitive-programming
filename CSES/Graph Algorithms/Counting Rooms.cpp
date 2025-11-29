#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for(auto &s:grid) for(auto &c:s) cin >> c;

    pair<int,int> dir[4] = {{0,1}, {1,0}, {-1,0}, {0,-1}};
    auto valid = [&](int row, int col){
        return row>=0 && row<n && col>=0 && col<m;
    };

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    function<void(int,int)> func = [&](int i, int j){
        visited[i][j] = true;

        for(auto [x, y]:dir){
            x+=i, y+=j;
            
            if(valid(x,y) && !visited[x][y] && grid[x][y]=='.') func(x,y);
        }
    };

    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            if(grid[i][j]=='.' && !visited[i][j]) func(i,j), ans++;
    }
    cout << ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
}