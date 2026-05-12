#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n; cin >> n;
	char truth[n];
	for(auto &c:truth) cin >> c;
	cin.ignore();
	string s; getline(cin, s);

	int idx = 0;
	stack<char> st;
	for(auto c:s){
		if(c==' ') continue;
		if(c>='A' && c<='Z') st.push(truth[idx++]);
		else if(c=='*'){
			if(st.size()<2) continue;
			bool cond1 = st.top()=='T'; st.pop();
			bool cond2 = st.top()=='T'; st.pop();
			bool res = cond1 && cond2;
			st.push(res ? 'T':'F');
		} 
		else if(c=='+'){
			if(st.size()<2) continue;
			bool cond1 = st.top()=='T'; st.pop();
			bool cond2 = st.top()=='T'; st.pop();
			bool res = cond1 || cond2;
			st.push(res ? 'T':'F');
		} 
		else if(c=='-'){
			if(st.empty()) continue;
			bool cond = st.top()=='T'; st.pop();
			bool res = !cond;
			st.push(res ? 'T':'F');
		} 
	}
	cout << st.top();
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}