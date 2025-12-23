#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x) 
#define len(x) (int) x.size()
using namespace std;

void solve(){
	int n, x, y, z;
	cin >> n >> x >> y >> z;
	
	pair<int,int> math[n], english[n];
	int i=1;
	for(auto &[a, idx]:math) cin >> a, idx=i++;
	i=1;
	for(auto &[a, idx]:english) cin >> a, idx=i++;
	
	pair<int,int> both[n];
	for(int i=0;i<n;i++){
		auto &[m, person1] = math[i];
		auto &[e, person2] = english[i];
		auto &[a, idx] = both[i];
		a = m+e, idx=i+1;
	}

	auto custSort = [&](auto a, auto b){
		if(a.first==b.first) return a.second < b.second;
		return a.first > b.first;
	};

	sort(math, math+n, custSort);
	sort(english, english+n, custSort);
	sort(both, both+n, custSort);
	// for(auto [a,person]:math) cout << a << ' ' << person << endl;
	// for(auto [a,person]:english) cout << a << ' ' << person << endl;
	// for(auto [a,person]:both) cout << a << ' ' << person << endl;

	set<int> ans;
	for(int i=0, cnt=1;i<n && cnt<=x;i++){
		while(i<n && ans.find(math[i].second)!=ans.end()) i++;
		auto &[m, person] = math[i];
		ans.insert(person), cnt++;
	}
	for(int i=0, cnt=1;i<n && cnt<=y;i++){
		while(i<n && ans.find(english[i].second)!=ans.end() ) i++;
		auto &[e, person] = english[i];
		ans.insert(person), cnt++;
	}
	for(int i=0, cnt=1;i<n && cnt<=z;i++){
		while(i<n && ans.find(both[i].second)!=ans.end()) i++;
		auto &[b, person] = both[i];
		ans.insert(person), cnt++;
	}

	for(auto i:ans) cout << i << endl;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// int t; cin >> t; while(t--)
	solve(), cout << endl;
}