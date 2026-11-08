#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
	for(int r, c, y; cin >> r >> c >> y;){
		if(r==0 && c==0 && y==0) break;

		vector<vector<char>> grid(r, vector<char>(c));
		for(auto &row:grid) for(auto &c:row) cin >> c;

		vector<vector<int>> visited(r, vector<int>(c, -1));
		visited[0][y-1] = 1;

		auto func = [&](auto func, int row, int col, int cnt) -> void{

			if(grid[row][col]=='U') row--;
			else if(grid[row][col]=='S') row++;
			else if(grid[row][col]=='B') col--;
			else col++;

			if(row<0 || row>=r || col<0 || col>=c){
				cout << 1 << ' ' << cnt; 
				return;
			}

			if(visited[row][col]!=-1){
				cout << 1 << ' ' << --visited[row][col] << ' ' << 0  << ' ' << cnt-visited[row][col];
				return;
			}

			visited[row][col] = cnt + 1;
			func(func, row, col, cnt+1);
		};

		func(func, 0, y-1, 1);
		cout << endl;
	}
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// int t; cin >> t; while(t--)
	solve(), cout << endl;
}