#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int n, c; cin >> n >> c;
    pair<int,int> a[n];
    for(int idx=0; auto &[value, i]:a) i = idx++, cin >> value;
    sort(a, a+n);

    vector<tuple<int,int,int>> counter;
    for(int prev=0; auto [value, idx]:a){
        if(prev != value) {
            counter.push_back({value, 1, idx});
        }
        else {
            auto &[value, cnt, idx] = counter.back();
            cnt++;
        }
        prev = value;
    }
    
    sort(counter.begin(), counter.end(), [](auto a, auto b){
        auto [value1, cnt1, idx1] = a;
        auto [value2, cnt2, idx2] = b;
        if(cnt1 > cnt2) return true;
        if(cnt1 == cnt2 && idx1 < idx2) return true;
        return false;
    });

    for(auto [value, cnt, idx]:counter) 
        while(cnt--) cout << value << ' ';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
}