#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()

#define vi vector<int>
#define vvi vector<vi>

const int MOD = 1e9 + 7;

void solve(){
    int n; cin >> n;
	
	auto isVowel = [](char c){
		return c=='a' || c=='i' || c=='u' || c=='e' || c=='o';
	};
	
	int cnt = 0;
	for(int a=1; a<=n; a++){
		string s;
		cin >> s;

		bool can = true;
		for(int i=0, vowel = 0, cons = 0; i<len(s) && can; i++){
			if(isVowel(s[i])) vowel++, cons = 0;
			else cons++, vowel = 0;

			if(vowel > 2 || cons > 2) can = false;
			if((i==1 || i==len(s)-1) && vowel > 1) can = false; 
		}

		cnt += can;
	}

	int fpb = gcd(cnt, n);
	cout << cnt / fpb << ' ' << n / fpb;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
}