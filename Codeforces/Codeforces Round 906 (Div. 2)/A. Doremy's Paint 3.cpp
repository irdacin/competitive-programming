#include <bits/stdc++.h>
#define ez ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl '\n'
#define ll long long
using namespace std;

void solve(){
    int n;
    cin >> n;
    int a[n];
    for(auto &i:a) cin >> i;
    map <int, int> arr;
    for(auto &i:a) 
    arr[i]++;
    if(arr.size()==1) cout << "Yes";
    else if(arr.size()>2) cout << "No";
    else{
        int dif=0;
        for(auto &i:arr)
        dif ? dif-=i.second : dif+=i.second;
        dif==0 || dif==1 || dif==-1 ? cout << "Yes" : cout << "No";
    }
    cout << endl;
    // for(auto &i:arr)
    // cout << i.first << ' ' << i.second << endl ;
}

int main(){
    ez;
    int t; cin >> t; while(t--)
    solve();
    return 0;
}