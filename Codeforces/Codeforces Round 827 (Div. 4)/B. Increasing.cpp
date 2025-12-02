#include <bits/stdc++.h>
#define ez ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl '\n'
#define ll long long
using namespace std;

void solve(){
    int n; cin >> n;
    int a[n];
    for(auto &i:a) cin >>i;
    sort(a,a+n);

    int current=0;
    for(auto &i:a){
        if(current>=i) {
            cout << "NO" << endl;
            return;
        }
        else current=i;
    }
    cout << "YES" << endl;
}

int main(){
	ez;
	int t; cin >> t; while(t--)
	solve();
	return 0;
}