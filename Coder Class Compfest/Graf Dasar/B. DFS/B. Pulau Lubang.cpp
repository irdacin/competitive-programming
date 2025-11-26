#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m; cin >> n >> m;
  vector grid(n, vector<char>(m));
  for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> grid[i][j];

  pair<int, int> dir[4] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
  vector vis(n, vector<bool>(m, false));
  int cnt = 0, mx = 0;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(grid[i][j] == '.' && !vis[i][j]) {
        vis[i][j] = true;
        
        auto dfs = [&](auto dfs, int row, int col) -> int {
          int res = 1;
          for(auto [x, y] : dir) {
            x += row, y += col;
            if(x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && grid[x][y] == '.') {
              vis[x][y] = true;
              res += dfs(dfs, x, y);
            }
          }

          return res;
        };

        mx = max(mx, dfs(dfs, i, j));
        cnt++;
      }
    }
  }

  cout << cnt << ' ' << mx << '\n';

  return 0;
}