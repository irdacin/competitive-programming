#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m; cin >> n >> m;
  vector<vector<int>> adj(n);
  for(int a, b; m--;) {
    cin >> a >> b;
    a--, b--;
    adj[a].emplace_back(b);
    adj[b].emplace_back(a);
  }

  for(int i = 0; i < n; i++) {
    if(!adj[i].empty()) {

      queue<int> q;
      vector<int> color(n, -1);
      color[i] = 0;
      q.emplace(i);

      while(!q.empty()) {
        auto u = q.front(); q.pop();
        for(auto v : adj[u]) {
          if(color[v] == -1) {
            color[v] = color[u] ^ 1;
            q.emplace(v);
          } else if(color[u] == color[v]) {
            cout << "TIDAK\n";
            return 0;
          }
        }
      }

      break;
    }
  }
  
  cout << "YA\n";
  return 0;
}