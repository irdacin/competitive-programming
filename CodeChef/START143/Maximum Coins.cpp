#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t; cin >> t;
    while(t--){
        int n, x; cin >> n >> x;
        int i = n, ans = 0;
        for(; i > n - x; i--) ans += (1 << i);
        for(; i >= 1; i--) ans -= (1 << i);
        cout << ans << endl;
    }
}