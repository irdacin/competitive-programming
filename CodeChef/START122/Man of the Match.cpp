#include <bits/stdc++.h>
using namespace std;

void solve(){
    int mx =-1, idx=0;
    for(int i=0;i<22;i++){
        int a, b; cin >> a >> b;
        int res = a + b*20;
        if(mx<res) mx = res, idx=i+1;
    }
    cout << idx;
}

int main() {
	// your code goes here
    int t; cin >> t; while(t--)
    solve(), cout << endl;
}