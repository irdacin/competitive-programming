#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m; cin >> n >> m;

  vector<vector<int>> adj(n);
  for(int u, v; m--;) {
    cin >> u >> v;
    u--, v--;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }

  int start = -1;
  for(int i = 0; i < n && start == -1; i++) {
    if(!adj[i].empty()) start = i;
  }

  if(start == -1) {
    cout << "Tipe A\n";
    return 0;
  }

  queue<int> q;
  vector<bool> vis(n, false);
  vis[start] = true;
  q.emplace(start);

  while(!q.empty()) {
    int u = q.front(); q.pop();

    for(auto v : adj[u]) {
      if(!vis[v]) {
        vis[v] = true;
        q.emplace(v);
      }
    }
  }

  int odd = 0;
  for(int i = 0; i < n; i++) {
    if(!vis[i]) {
      cout << "Tipe C\n";
      return 0;
    }

    odd += adj[i].size() & 1;
  }

  if(odd == 0) cout << "Tipe A\n";
  else if(odd == 2) cout << "Tipe B\n";
  else cout << "Tipe C\n";

  return 0;
}