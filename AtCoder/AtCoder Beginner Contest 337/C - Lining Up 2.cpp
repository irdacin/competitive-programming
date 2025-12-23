#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
using namespace std;

void solve(){
    int n; cin >> n;
    int a[n];
    for(auto &i:a) cin >> i;

    vector<pair<int,int>>person;
    for(int i=0;i<n;i++)
        if(a[i]==-1) person.push_back(make_pair(0,i+1));
        else person.push_back(make_pair(a[i],i+1));

    sort(person.begin(), person.end());
    int cur=0;
    vector<int>res;
    while(res.size()<n){
        int left=0, right=n-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            auto [i,j] = person[mid];
            if(i==cur){
                res.push_back(j), cur=j;
                break;
            }
            else if(i<cur) left=mid+1;
            else right=mid-1;
        }
    }
    for(auto &i:res) cout << i << ' ';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
}