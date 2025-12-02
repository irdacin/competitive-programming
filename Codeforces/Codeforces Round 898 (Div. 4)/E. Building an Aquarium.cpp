#include <bits/stdc++.h>
#define ez ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl '\n'
#define ll long long
using namespace std;

int search(auto arr, int x){
    int left=0, right = INT_MAX;
    while(left<=right){
        int mid = right - ((right-left)/2);
        // cout << mid << ' ';
        ll sum=0;
        for(auto &a:arr) 
        if(a<mid) sum+=(ll) (mid-a);
        
        if(sum==x) return mid;
        else if(sum<x) left=mid+1;
        else right=mid-1;
        // cout << sum << endl;
    }
    return right;
}
// 4

// 3 1 2 4 6 2 5
// 1+3+2+0+0+2+0 = 8

void solve(){
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(auto &i:a) cin >> i;
    cout << search(a, x) << endl;
}   

int main(){
    ez;
    int t; cin >> t; while(t--)
    solve();
    return 0;
}