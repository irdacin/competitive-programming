#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve(){
    int n; cin >> n;
    int a[n];
    for(auto &i:a) cin >> i;

    map<int,int>mp;
    function<void(int,int,int,int)>merge = [&](int aLeft, int aRight, int bLeft, int bRight){
        int n = bRight - aLeft + 1;
        int temp[n];

        int i=aLeft, j=bLeft, k=0;
        while(i<=aRight && j<=bRight)
            if(a[i]<a[j]) temp[k++] = a[i++];
            else temp[k++] = a[j++], mp[a[j-1]]++;
        
        while(i<=aRight) temp[k++] = a[i++];
        while(j<=bRight) temp[k++] = a[j++];

        for(int i=0;i<n;i++) a[aLeft+i] = temp[i];
    };

    function<void(int,int)>merge_sort = [&](int left, int right){
        if(left>=right) return;
        int mid= left+(right-left)/2;
        merge_sort(left,mid);
        merge_sort(mid+1, right);
        merge(left, mid, mid+1, right);
    };

    merge_sort(0,n-1);
    cout << mp.size();
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}