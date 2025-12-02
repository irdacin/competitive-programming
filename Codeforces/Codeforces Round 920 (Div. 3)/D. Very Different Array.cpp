#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
using namespace std;

void solve(){
    int n, m; cin >> n >> m;
    int a[n], b[m];
    for(auto &i:a) cin >> i;
    for(auto &i:b) cin >> i;
    sort(a,a+n);
    sort(b,b+m,greater<int>());

    /*
    6 1 2 4
    3 5 1 7 2 3

    after sorting we get
    1 2 4 6
    7 5 3 3 2 1

    we choose from left or right which their abs is max
    left = |1-7| = 6
    right = |6-1| = 5
    since 6>5, we take left
    */

    int ans=0;
    for(int i=0, j=n-1, k=0, l=m-1;i<=j;){
        int left=abs(a[i]-b[k]);
        int right=abs(a[j]-b[l]);
        if(left>right) ans+=left, i++, k++;
        else ans+=right, j--, l--;
    }
    cout << ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}