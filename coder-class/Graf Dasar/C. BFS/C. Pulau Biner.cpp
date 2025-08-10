#include <bits/stdc++.h>
using namespace std;

const int INF = 2e9;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  vector grid(n, vector<char>(n));
  for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> grid[i][j];

  vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  deque<pair<int, int>> q;
  vector dist(n, vector<int>(n, INF));
  dist[0][0] = 0;
  q.emplace_back(0, 0);

  while(!q.empty()) {
    auto [row, col] = q.front(); q.pop_front();

    if(row + 1 == n && col + 1 == n) {
      cout << dist[row][col] << '\n';
      return 0;
    }

    for(auto [x, y] : dir) {
      x += row, y += col;

      if(x >= 0 && x < n && y >= 0 && y < n && dist[x][y] > dist[row][col] + (grid[x][y] == '1')) {
        dist[x][y] = dist[row][col] + (grid[x][y] == '1');
        if(grid[x][y] == '1') q.emplace_back(x, y);
        else q.emplace_front(x, y);
      }
    }
  }
}