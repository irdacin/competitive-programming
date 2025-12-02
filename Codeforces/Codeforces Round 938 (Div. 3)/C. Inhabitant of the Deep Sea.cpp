#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;

    int a[n];
    for(auto &i:a) cin >> i;


    int ans = 0;
    int i=0, j=n-1;
    // shoot left => ceil k/2 
    int left = k/2 + k%2;

    // shoot right => floor k/2
    int right = k/2;

    for(; i<n; i++){
        if(left-a[i]<0){
            a[i] -= left;
            break;
        }
        left-=a[i];
        a[i] = 0;
        ans++;
    }
    k-=(k/2 + k%2 - left);

    for(; j>=0; j--){
        if(right-a[j]<0){
            a[j] -= right;
            break;
        }
        right-=a[j];
        a[j] = 0;
        ans++;
    }
    k-=(k/2 - right);   

    // if(k>0){
    //     for(; i<=j; i++){
    //         if(k-a[i]<0) break;
    //         k-=a[i];
    //         ans++;
    //     }
    // }

    if(i>j) cout << n;
    else cout << ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}