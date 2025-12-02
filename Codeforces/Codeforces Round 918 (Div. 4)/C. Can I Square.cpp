#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve(){
    int n; cin >> n;
    int a[n];
    int sum=0;
    for(auto &i:a) cin >> i, sum+=i;
    
    int temp=sum;
    for(int left=0, right=1e9;left<=right;){
        int mid=left+(right-left)/2;
        int res=mid*mid;
        if(res<=sum) temp=mid*mid, left=mid+1;
        else right=mid-1;
    }
    cout << (temp==sum?"YES":"NO");
}   

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}