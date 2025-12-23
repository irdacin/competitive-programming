#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
using namespace std;

void solve(){
    int b;
    cin >> b;

    auto power = [&](auto self, int a, int k){
        if(k==0) return (int)1;
        int res = self(self, a, k/2);
        return (k&1) ? res*res*a:res*res;
    };

    for(int left=0, right=15;left<=right;){
        int mid=left+(right-left)/2;
        int res=power(power, mid,mid);
        if(res==b) exit(mid);
        else if(res<b) left=mid+1;
        else right=mid-1;
    }
    cout << -1;

}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// int t; cin >> t; while(t--)
	solve(), cout << endl;
}