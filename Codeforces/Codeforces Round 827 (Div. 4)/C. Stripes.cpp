#include <bits/stdc++.h>
#define ez ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl '\n'
#define ll long long
using namespace std;

void solve(){
    char ans='B';
    for(int i=0;i<8;i++){
        string row;
        cin>>row;
        int r=0;
        for(auto col:row) {
            if(col=='R') r++;
            // else if(col=='B') b++;
        }
        if(r==8) ans='R';
    }
    // cout << (r>b ? "R":"B") << endl;
    cout << ans << endl;
}

int main(){
	ez;
	int t; cin >> t; while(t--)
	solve();
	return 0;
}