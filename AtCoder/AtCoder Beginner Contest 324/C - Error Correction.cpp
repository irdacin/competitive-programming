#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x) 
#define len(x) (int) x.size()
using namespace std;

void solve(){
	int n; string t;
	cin >> n >> t;
	
	int lenT = len(t);
	vector<int> ans;
	for(int k=1;k<=n;k++){
		string s; cin >> s;
		int lenS = len(s);

		if(s==t) ans.push_back(k);
		else if(lenT==lenS){
			int dif=0;
			for(int i=0;i<lenS;i++){
				if(s[i]!=t[i]) dif++;
				if(dif>2) break;
			}
			if(dif==1) ans.push_back(k);
		}
		else if(lenT-lenS==1){
			int j=0;
			int dif=0;
			for(int i=0; i<lenT;){
				if(t[i]==s[j]) i++, j++;
				else i++, dif++;
				if(dif>2) break;
			}
			if(dif==1) ans.push_back(k);
		}
		else if(lenS-lenT==1){
			int j=0;
			int dif=0;
			for(int i=0; i<lenS;){
				if(t[j]==s[i]) i++, j++;
				else i++, dif++;
				if(dif>2) break;
			}
			if(dif==1) ans.push_back(k);
		}
	}

	cout << len(ans) << endl;
	for(auto i:ans) cout << i << ' ';
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// int t; cin >> t; while(t--)
	solve(), cout << endl;
}