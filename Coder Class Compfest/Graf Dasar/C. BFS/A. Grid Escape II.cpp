#include <bits/stdc++.h>
using namespace std;

const int INF = 2e9;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m; cin >> n >> m;
  vector grid(n, vector<char>(m));
  for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> grid[i][j];

  pair<int, int> dir[4] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
  queue<pair<int, int>> q;
  vector dist(n, vector<int>(m, INF));
  dist[0][0] = 0;
  q.emplace(0, 0);

  while(!q.empty()) {
    auto [row, col] = q.front(); q.pop();

    if(row + 1 == n && col + 1 == m) {
      cout << dist[row][col] << '\n';
      return 0;
    }

    for(auto [x, y] : dir) {
      x += row, y += col;
      if(x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '.' && dist[x][y] > dist[row][col] + 1) {
        dist[x][y] = dist[row][col] + 1;
        q.emplace(x, y);
      }
    }
  }

  cout << -1 << '\n';
  return 0;
}