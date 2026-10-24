#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve(){
	string s; cin>>s;

	vector <string> soal;
	string temp="";
	for(int i=0;i<s.length();i++){
		if(s[i]=='+' || s[i]=='*' || s[i]==':'){
			soal.push_back(temp);
			temp="", temp+=s[i];
			soal.push_back(temp);
			temp="";
		}
		else if(s[i]=='-'){
			if(i==0) temp+= s[i];
			else if(s[i-1]=='+' || s[i-1]=='-' || s[i-1]=='*' || s[i-1]==':') temp+= s[i];
			else{
				soal.push_back(temp);
				temp="", temp+=s[i];
				soal.push_back(temp);
				temp="";
			}
		}
		else temp+= s[i];
	}
	soal.push_back(temp);
	for(auto &a:soal) cout << a;
	cout << endl;
	
	vector <int>first, second; // save index
	for(int i=0;i<soal.size();i++){
		if(soal[i]=="*" || soal[i]==":") first.push_back(i);
		else if(soal[i]=="+" || soal[i]=="-") second.push_back(i);
	}

	// for(auto &i:first) cout << i << ' ';
	// cout << endl;
	// for(auto &i:second) cout << i << ' ';
	// cout << endl;

	auto repeat = [](string str, int times){
		string res = "";
		for(int i=0;i<times;i++) res+=str;
		return res;
	};

	for(auto &i:first){
		string op = soal[i];
		int value1 = stoi(soal[i-1]), value2 = stoi(soal[i+1]);
		int res = op=="*" ? value1*value2 : value1/value2;

		for(int a=0;a<soal.size();a++) cout << (a>=i-1 && a<=i+1 ? repeat("-", soal[a].length()) : repeat(".", soal[a].length()) );
		cout << endl;

		soal[i-1] = to_string(res);
		soal.erase(soal.begin()+i);
		soal.erase(soal.begin()+i);

		for(auto &a:soal) cout << a;
		cout << endl;

		for(auto &next:first) if(next>i) next-=2;
		for(auto &next:second) if(next>i) next-=2;
	}

	for(auto &i:second){
		string op = soal[i];
		int value1 = stoi(soal[i-1]), value2 = stoi(soal[i+1]);
		int res = op=="+" ? value1+value2 : value1-value2;

		for(int a=0;a<soal.size();a++) cout << (a>=i-1 && a<=i+1 ? repeat("-", soal[a].length()) : repeat(".", soal[a].length()) );
		cout << endl;
		
		soal[i-1] = to_string(res);
		soal.erase(soal.begin()+i);
		soal.erase(soal.begin()+i);

		for(auto &a:soal) cout << a;
		cout << endl;

		for(auto &next:first) if(next>i) next-=2;
		for(auto &next:second) if(next>i) next-=2;
	}

}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// int t; cin >> t; while(t--)
	solve();
}