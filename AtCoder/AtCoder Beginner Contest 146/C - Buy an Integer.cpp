#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x) 
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int a, b, x;
    cin >> a >> b >> x;

    auto d = [](int n){
        return len(to_string(n));
    };

    int ans = 0;
    for(int left=0, right=min((int)1e9,x);left<=right;){
        int mid = left+(right-left)/2;
        int res = a*mid + b*d(mid);
        if(res<=x) ans=mid, left=mid+1;
        else right=mid-1;
    }
    cout << ans;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// int t; cin >> t; while(t--)
	solve(), cout << endl;
}