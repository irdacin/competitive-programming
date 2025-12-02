#include <bits/stdc++.h>
#define ez ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl '\n'
#define ll long long
using namespace std;

int search(auto arr, int x){
    int left=0, right=arr.size();
    while(left<=right){
        int mid=(left+right)/2;
        if(arr[mid]==x) return arr[mid];
        else if(arr[mid]<x) left=mid+1;
        else right=mid-1;
    }
    return -1;
}

int find_index(int arr[],int n, int x){
    for(int i=0;i<n;i++){
        if(arr[i]==x) return i;
    }
    return -1;
}
int find_index_2(int arr[],int n, int x){
    for(int i=n-1;i>=0;i--){
        if(arr[i]==x) return i;
    }
    return -1;
}

void solve(){
    int n, x;
    cin >> n >> x;
    pair<int,int> a[n];
    int cnt=0;
    for(auto &i:a) cin >> i.first, i.second=++cnt;
    
    // vector<int>arr(a,a+n);
    sort(a,a+n);
    // int ans1, ans2;
    // for(auto &i:a){
    //     ans1=i;
    //     int kurang=x-ans1;
    //     ans2=search(arr,kurang);
    //     // cout << ans1 << ' ' << ans2 << endl;
    //     if(ans2!=-1) break;
    // }
    
    // int index1=find_index(a, n, ans1),
    // index2=find_index_2(a, n, ans2);
    // (index2==-1 || index1==index2) ? cout << -1 :
    // cout << ++index1 << ' ' << ++index2;
    
    for(int i=0,j=n-1;i!=j;){
        if(a[i].first+a[j].first==x){
        cout << a[i].second << ' ' << a[j].second << endl;
         return;   
        }
        else if(a[i].first+a[j].first<x) i++;
        else j--;
    }
    cout << -1;
}

int main(){
    ez;
    // int t; cin >> t; while(t--)
    solve();
    return 0;
}