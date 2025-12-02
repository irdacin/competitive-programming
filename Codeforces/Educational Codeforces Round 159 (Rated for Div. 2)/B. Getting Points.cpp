#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
using namespace std;

void solve(){
    int n, p, l, t;
    cin >> n >> p >> l >> t;
    int pratical = n/7 + (n%7==0 ? 0:1);

    int k=n;
    for(int left=0, right=n;left<right;){
        int mid=left+(right-left)/2;
        if(mid*l+min(pratical,2*mid)*t>=p) k=mid, right=mid;
        else left=mid+1;
    }
    cout << n-k;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}