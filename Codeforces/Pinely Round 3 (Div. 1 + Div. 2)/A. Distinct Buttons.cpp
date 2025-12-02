#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve(){
	int n; cin >> n;
	pair<bool, bool>numX={false,false},numY={false, false};
	while(n--){
		int x, y;
		cin >> x >> y;
		if(x<0) numX.first=true;
		else if(x>0) numX.second=true;

		if(y<0) numY.first=true;
		else if(y>0) numY.second=true;
	}
	cout << (numX.first&&numX.second&&numY.first&&numY.second ? "NO":"YES"); 
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}