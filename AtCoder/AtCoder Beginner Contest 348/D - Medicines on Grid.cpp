#include <bits/stdc++.h>
// #define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int h, w; cin >> h >> w;
    vector<vector<char>> grid(h, vector<char>(w));
    for(auto &row:grid) for(auto &col:row) cin >> col;

    int n; cin >> n;
    vector<vector<int>> medicine(h, vector<int>(w, 0));
    for(int row, col, energy; n--;) 
        cin >> row >> col >> energy, 
        medicine[row-1][col-1] = energy;

    pair<int,int> dir[4] = {{0,1}, {1,0}, {-1,0}, {0,-1}};
    auto valid = [&](int row, int col){
        return row>=0 && row<h && col>=0 && col<w;
    };

    vector<vector<int>> vis(h, vector<int>(w, 0)); // previous energy
    /*
    auto func = [&](auto func, int row, int col, int energy){
        if(grid[row][col]=='T') return true;
        
        // cout << row <<' '<< col << ' ' <<energy << endl;

        int curEnergy = max(energy, medicine[row][col]);
        bool res = false;

        // if current energy greater than visited previous energy
        if(curEnergy > vis[row][col])
        for(auto [x,y]:dir){
            x+=row, y+=col;
            if(valid(x,y) && grid[x][y]!='#'){
                
                vis[row][col] = curEnergy;
                // vis[x][y] = true;

                res |= func(func, x, y, curEnergy-1);
                if(res) return res;
                
                // vis[x][y] = false;
            }
        }

        return res;
    };
    
    int row = 0, col = 0;
    for(;row<h && grid[max(0,row-1)][col]!='S'; row++) 
        for(col=0; col<w; col++) if(grid[row][col]=='S') break;
    row = max(0, row-1);

    // vis[row][col] = true;
    cout << (func(func, row, col, 0) ? "Yes":"No");
    */

    // dfs too slow
    // let's change into bfs

    int row = 0, col = 0;
    for(;row<h && grid[max(0,row-1)][col]!='S'; row++) 
        for(col=0; col<w; col++) if(grid[row][col]=='S') break;
    row = max(0, row-1);

    queue<array<int,3>> q;
    q.push({row, col, 0});

    while(!q.empty()){
        auto [row, col, energy] = q.front(); q.pop();

        if(grid[row][col]=='T') exit("Yes");

        int curEnergy = max(energy, medicine[row][col]);

        if(curEnergy > vis[row][col]){
            vis[row][col] = curEnergy;

            for(auto [x,y]:dir){
                x+=row, y+=col;
                if(valid(x,y) && grid[x][y]!='#'){
                    q.push({x,y,curEnergy-1});
                }
            }
        }        
    }
    
    cout << "No";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
}