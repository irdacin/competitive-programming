#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
	string s; cin >> s;

    int b = -1, rOpen = -1, rClose = -1;
    int idx = 1;
    for(auto c:s){
        if(c=='B'){
            if(b==-1) b=idx;
            else if(b%2==0 && idx%2==0) exit("No");
            else if(b%2==1 && idx%2==1) exit("No");
        } else if(c=='R'){
            if(rOpen==-1) rOpen = idx;
            else rClose = idx;
        } else if(c=='K'){
            if(rOpen==-1) exit("No");
            else if(rClose !=-1) exit("No");
        }
        idx++;
    }
    cout << "Yes";
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// int t; cin >> t; while(t--)
	solve(), cout << endl;
}