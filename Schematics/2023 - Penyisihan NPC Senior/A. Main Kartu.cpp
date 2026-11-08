#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
	int n, m; char r;
	cin >> n >> m >> r;
	vector<string> pemain(n), lawan(m);
	for(auto &i:pemain) cin >> i;
	for(auto &i:lawan) cin >> i;

	map<char,pair<vector<char>, vector<char>>> mp;
	for(auto s:"SCDH"){
		vector<char> team, musuh;
		for(auto &i:pemain) if(i[1]==s) team.push_back(i[0]);
		for(auto &i:lawan) if(i[1]==s) musuh.push_back(i[0]);

		mp[s] = {team, musuh};
	}

	char kartu[9] = {'6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
	auto winTeams = [&](char musuh, char team){
		int i=0, j=0;
		for(;kartu[i]!=musuh;i++);
		for(;kartu[j]!=team;j++);

		return i<j;
	};

	for(auto s:"SCDH"){
		auto &[team, musuh] = mp[s];
		sort(team.begin(), team.end(), winTeams);
		sort(musuh.begin(), musuh.end(), winTeams);
	}

	auto &[team, musuh] = mp[r];

	int trufWin=0, trufLose=0;
	for(; trufWin<len(team) && trufLose<len(musuh); trufWin++){
		if(winTeams(musuh[trufLose], team[trufWin])) trufLose++;
	}
	// sisa team
	trufWin = len(team) - trufWin;

	// sisa musuh
	trufLose = len(musuh) - trufLose; 

	// nobody can defeat musuh
	if(trufLose > 0) exit("TIDAK");

	for(auto s:"SCDH"){
		if(s==r) continue;

		auto &[team, musuh] = mp[s];

		int cntWin=0, cntLose=0;
		for(; cntWin<len(team) && cntLose<len(musuh); cntWin++){
			if(winTeams(musuh[cntLose], team[cntWin])) cntLose++;
		}
		
		// sisa musuh
		cntLose = len(musuh) - cntLose; 
		// cout << cntLose << endl;

		// musuh has been defeated
		if(cntLose <= 0) continue;
		
		// trufWin can win all card
		trufWin -= cntLose;

		// nobody truf left	
		if(trufWin < 0) exit("TIDAK");
	}

	cout << "YA";
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t; while(t--)
	solve(), cout << endl;
}