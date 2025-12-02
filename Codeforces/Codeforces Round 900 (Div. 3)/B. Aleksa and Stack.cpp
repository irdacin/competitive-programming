#include <bits/stdc++.h>
#define keren ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl '\n'
#define ll long long
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int>ans={2,4};
    for(int i=2;i<n;i++){
        int temp=ans[i-1]+1;
        while((3*temp) % (ans[i-1]+ans[i-2]) == 0) temp++;
        ans.push_back(temp);
    }
    for(auto a:ans) cout << a << ' ';
    cout << endl;
}

int main(){
    keren;
    int t; cin >> t; while(t--)
    solve();
    return 0;
}