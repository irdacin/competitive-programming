#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int n; cin >> n;

    auto palindrom = [](int n){
        string s = to_string(n);
        for(int i=0;i*2<len(s);i++) if(s[i]!=s[len(s)-i-1]) return false;
        return true;
    };

    int ans = n;
    int cubes = n;
    for(int left=0, right=min((int)1e6,n); left<=right;){
        int mid = left+(right-left)/2;
        int res = mid*mid*mid;
        if(res<=n) ans = res, cubes = mid, left=mid+1;
        else right=mid-1;
    }

    if(palindrom(ans)) exit(ans);

    while(cubes--){
        int res = cubes*cubes*cubes;
        if(palindrom(res)) exit(res);
    }

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
}