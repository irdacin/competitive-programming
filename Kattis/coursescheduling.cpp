#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int n; cin >> n;

    map<string, set<string>> mp;
    while(n--){
        string first, second, course;
        cin >> first >> second >> course;
        string name = first + second;
        mp[name].insert(course);
    }

    map<string, int> reqCourse;
    for(auto [name, courses]:mp){
        for(auto course:courses){
            reqCourse[course]++;
        }
    }

    for(auto [course, cnt]:reqCourse){
        cout << course << ' ' << cnt << endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve();
}