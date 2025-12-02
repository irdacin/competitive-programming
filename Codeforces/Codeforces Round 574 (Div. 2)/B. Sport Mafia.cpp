#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;

    for(int left=0, right=n;left<=right;){
        int mid = left+(right-left)/2;
        int res = mid*(mid+1)/2 + (n-mid)*-1;
        if(res==k) exit(n-mid);
        else if(res<k) left=mid+1;
        else right=mid-1;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
}