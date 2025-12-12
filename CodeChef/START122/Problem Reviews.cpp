#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    int s[n];
    for(auto &i:s) cin >> i;
    for(auto &i:s) if(i<=4) return void(cout << "NO");
    cout << "YES";
}

int main() {
	// your code goes here
    int t; cin >> t; while(t--)
    solve(), cout << endl;
}