#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define rcout(x) return void(cout << x)

template <typename T, typename U> istream& operator>>(istream& is, pair<T, U>& _p) { is >> _p.first >> _p.second; return is; }
template <typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U> _p) { os << _p.first << ' ' << _p.second; return os; }
template <typename T> istream& operator>>(istream& is, vector<T>& _v) { for(auto &_i : _v) is >> _i; return is; }
template <typename T> ostream& operator<<(ostream& os, const vector<T> _v) { for(auto &_i : _v) os << _i << " \n"[&_i == &_v.back()]; return os; }
template <typename T, typename U> ostream& operator<<(ostream& os, const vector<pair<T, U>> _v) { for(auto _i : _v) os << _i << endl; return os; }
template <typename T> struct vec : vector<T> { using vector<T>::vector; };
template <typename T> struct vvec : vec<vec<T>> {
    vvec(initializer_list<initializer_list<T>> _list) { for(const auto& _row : _list) this->emplace_back(_row); }
    vvec(int _n = 0, int _m = 0, const T& _init_value = T()) : vec<vec<T>>(_n, vec<T>(_m, _init_value)) {}
    friend ostream& operator<<(ostream &os, const vvec _v) { for(auto _i : _v) os << _i; return os; }
};
template <typename T> struct vvvec : vec<vvec<T>> {
    vvvec(initializer_list<initializer_list<initializer_list<T>>> _list) { for(const auto& _rows : _list) for(const auto& _row : _rows) this->emplace_back(_row); }
    vvvec(int _n = 0, int _m = 0, int _k = 0, const T& _init_value = T()) : vec<vvec<T>>(_n, vvec<T>(_m, _k, _init_value)) {}
    friend ostream& operator<<(ostream &os, const vvvec _v) { for(auto _i : _v) os << _i << endl; return os; }
};
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define len(x) (int) x.size()
using pii = pair<int, int>;
using iii = tuple<int, int, int>;
#define fi first
#define se second

const int MOD = 1e9 + 7;
const int INF = 2e9;

void solve(){
    int n, q;
    cin >> n >> q;
    vec<char> a(n, '.');
    a[0] = 'L';
    a[1] = 'R';

    int ans = 0;
    while(q--){
        char h; int t;
        cin >> h >> t;
        t--;
        int i = 0;
        for(; i < n && a[i] != h; i++);
        a[i] = '.';

        int cur = 0;
        if(h == 'L'){

            bool can1 = true;

            int count1 = 0;
            for(int tmp = i; can1; tmp++, count1++){
                tmp %= n;
                if(tmp == t) break;
                if(a[tmp] == 'R') can1 = false;
            }

            bool can2 = true;
            int count2 = 0;
            for(int tmp = i;  can2;  tmp--, count2++){
                tmp %= n;
                if(tmp < 0) tmp += n;
                if(tmp == t) break;
                if(a[tmp] == 'R') can2 = false;
            }


            // cout << a;
            if(can1 && can2){
                ans += min(count1, count2); 
            } else if(can1) ans += count1;
            else if(can2) ans+= count2;
            else cout << "ha masuk sini ";
        } else {
            bool can1 = true;

            int count1 = 0;
            for(int tmp = i;can1; tmp++, count1++){
                tmp %= n;
                if(tmp == t) break;

                if(a[tmp] == 'L') can1 = false;
            }

            bool can2 = true;
            int count2 = 0;
            for(int tmp = i; can2;  tmp--, count2++){
                tmp %= n;
                if(tmp < 0) tmp += n;
                if(tmp == t) break;

                if(a[tmp] == 'L') can2 = false;
            }


            // cout << a;
            if(can1 && can2){
                ans += min(count1, count2); 
            } else if(can1) ans += count1;

            else ans+= count2;

        }

        a[t] = h;
    }

    cout << ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
    // solve();
}