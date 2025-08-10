#include <bits/stdc++.h>
using namespace std;

const int INF = 2e9;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, k; cin >> n >> m >> k;
  vector<vector<int>> adj(n);
  for(int u, v; m--;) {
    cin >> u >> v;
    u--, v--;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }

  queue<int> q;
  vector dist(k + 1, vector<int>(n, INF));
  dist[0][0] = 0;
  q.emplace(0);

  while(!q.empty()) {
    auto u = q.front(); q.pop();

    for(auto v : adj[u]) {
      if(dist[0][u] + 1 < dist[0][v]) {
        dist[0][v] = dist[0][u] + 1;
        q.emplace(v);
      }
    }
  }

  vector<int> f(k + 1);
  f[0] = 0;
  for(int i = 1, x; i <= k; i++) {
    cin >> x;
    x--;
    f[i] = x;

    dist[i][x] = 0;
    q.emplace(x);

    while(!q.empty()) {
      auto u = q.front(); q.pop();

      for(auto v : adj[u]) {
        if(dist[i][u] + 1 < dist[i][v]) {
          dist[i][v] = dist[i][u] + 1;
          q.emplace(v);
        }
      }
    }
  }

  vector dp(n, vector<int>(1 << (k + 1), -1));
  auto func = [&](auto func, int last, int mask) {
    if(mask == (1 << (k + 1)) - 1) return dist[last][0];

    int &res = dp[last][mask];
    if(res != -1) return res;

    res = INF;
    for(int i = 1; i <= k; i++) {
      if(!(mask >> i & 1)) {
        res = min(res, func(func, i, mask | (1 << i)) + dist[last][f[i]]);
      }
    }

    return res;
  };

  cout << func(func, 0, 1) << '\n';

  return 0;
}