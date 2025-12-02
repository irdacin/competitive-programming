#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve(){
	string s;
	cin >> s;
	deque<pair<int, char>>lower,upper;
	int idx=0;
	for(auto &c:s){
		if(c=='a'||c>'b'&&c<='z') lower.push_back(make_pair(idx,c));
		else if(c=='A'||c>'B'&&c<='Z') upper.push_back(make_pair(idx,c));

		if(!lower.empty() && c=='b') lower.pop_back();
		else if(!upper.empty() && c=='B') upper.pop_back();
		idx++;
	}
	
	deque<pair<int, char>> result;
	for(auto &i:lower) result.push_back(i);
	for(auto &i:upper) result.push_back(i);
	sort(result.begin(), result.end());

	for(auto &i:result) cout << i.second;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}