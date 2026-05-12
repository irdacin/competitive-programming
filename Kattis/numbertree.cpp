#include <bits/stdc++.h>
using namespace std;

void solve(){
	int h; cin >> h;
// 	cin.ignore();
	string s;
// 	getline(cin, s);
    cin >> s;
	int prev = 0, cur = (1<<h);
	int grid[h+2];
	grid[h+1] = 0;
	for(int i=h; i>=0;i--,cur/=2) grid[i] = prev+cur, prev=grid[i];
	// for(int i=0;i<=h+1;i++) cout << grid[i] << ' ';

	int idx = s.length();
	// berada di antara grid idx dan idx+1

	int atas = grid[idx], bawah = grid[idx+1] + 1;
	int get_range = atas - bawah + 1;
	for(auto c:s){
		get_range/=2;
		if(c=='L') bawah+=get_range;
		else atas-=get_range;
		// cout << atas << ' ' << bawah << endl;
	}
	cout << atas;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}