#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int a, b, c; cin >> a >> b >> c;
    int ans1 = a*c, ans2=b*c;
    cout << max(ans1, ans2);
}