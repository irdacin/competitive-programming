#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()

#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>

const int MOD = 1e9 + 7;

void solve(){
    int n, m, u, v;
	cin >> n >> m >> u >> v;

	queue<tuple<int,int,int>> jahat, baik;
	for(int i, j; u--;){
		cin >> i >> j;
		i--, j--;
		jahat.push({i, j, 0});
	}

	for(int i, j; v--;){
		cin >> i >> j;
		i--, j--;
		baik.push({i, j, 0});
	}

	pair<int,int> dir[4] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
	auto valid = [&](int row, int col){
		return row>=0 && row<n && col>=0 && col<m;
	};

	auto bfs = [&](auto q){
		vvb vis(n, vb(m, false));
		vvi dis(n, vi(m, 0));

		queue<tuple<int,int,int>> qu;
		while(!q.empty()){
			auto [row, col, cnt] = q.front(); q.pop();
			vis[row][col] = true;
			dis[row][col] = cnt;
			qu.push({row, col, cnt});
		}

		while(!qu.empty()){
			auto [row, col, cnt] = qu.front(); qu.pop();
			
			for(auto [r,c]:dir){
				r += row, c += col;
				if(valid(r, c) && !vis[r][c]){
					vis[r][c] = true;
					dis[r][c] = cnt + 1;
					qu.push({r, c, cnt+1});
				}
			}
		}
		return dis;
	};

	vvi disJahat = bfs(jahat);
	vvi disBaik = bfs(baik);

	int cntJahat = 0, cntBaik = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(disJahat[i][j] < disBaik[i][j]) cntJahat++;
			else cntBaik++;
		}
	}

	if(cntJahat == cntBaik) cout << "TIE!";
	else if(cntJahat > cntBaik) cout << "LOSE! " << cntJahat - cntBaik;
	else cout << "WIN! " << cntBaik - cntJahat;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
}