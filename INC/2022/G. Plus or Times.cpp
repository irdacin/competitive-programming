#include <bits/stdc++.h>
#define ez ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl '\n'
#define ll long long
using namespace std;

ll plusortimes(ll a, ll b, char op){
	return (op=='+' ? a+b : a*b);
}

void solve(){
    ll n, p; 
	cin >> n >> p;
	vector<pair<ll,ll>>num = {{p,p}};

	auto min4 = [](ll a, ll b, ll c, ll d){
		return min(min(a,b), min(c,d));
	};
	
	auto max4 = [](ll a, ll b, ll c, ll d){
		return max(max(a,b), max(c,d));
	};

	for(int i=0;i<n;i++){
		char op1, op2; ll c1, c2;
		cin >> op1 >> c1 >> op2 >> c2;

		ll angka1 = plusortimes(num[i].first, c1, op1),
		angka2 = plusortimes(num[i].first, c2, op2),
		angka3 = plusortimes(num[i].second, c1, op1),
		angka4 = plusortimes(num[i].second, c2, op2);
		num.push_back(make_pair(
			min4(angka1,angka2,angka3,angka4),
			max4(angka1,angka2,angka3,angka4)
		));

		// if(num[i+1].first > num[i+1].second) swap(num[i+1].first,num[i+1].second);
	}
	// for(auto &a:num)
	// cout << a.first << ' ' << a.second << endl;
	cout << num[n].second;
}

int main(){
	ez;
	// int t; cin >> t; while(t--)
	solve();
	return 0;
}