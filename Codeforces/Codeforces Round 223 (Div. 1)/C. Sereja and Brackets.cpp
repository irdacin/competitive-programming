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

struct SegmentTree {
    struct node {
        int open, close;
        int length;

        node(char c = ' ') : open(0), close(0), length(0) {
            if(c == '(') open = 1;
            else if(c == ')') close = 1;
        }
    };

    vec<node> tree;
    string s;
    int n;

    SegmentTree(string _s) : n(len(s)), s(_s) {
        int sz = 1;
        for(; sz < n; sz <<= 1);
        tree.resize(sz << 1);
        build(0, n - 1, 0);
    }

    node merge(node left, node right){
        node res;
        int match = min(left.open, right.close);
        res.open = left.open + right.open - match;
        res.close = left.close + right.close - match;
        res.length = left.length + right.length + match * 2;
        return res;
    }

    void build(int l, int r, int id){
        if(l == r){
            tree[id] = node(s[l]);
            return;
        }

        int mid = (l + r) / 2;
        build(l, mid, 2 * id + 1);
        build(mid + 1, r, 2 * id + 2);
        tree[id] = merge(tree[2 * id + 1], tree[2 * id + 2]);
    }

    int query(int l, int r){
        return query(0, n - 1, 0, l - 1, r - 1).length;
    }

    node query(int l, int r, int id, int pl, int pr){
        if(l > pr || r < pl) return node();
        if(pl <= l && r <= pr) return tree[id];

        int mid = (l + r) / 2;
        return merge(query(l, mid, 2 * id + 1, pl, pr), query(mid + 1, r, 2 * id + 2, pl, pr));
    }
};

void solve(){
    string s; cin >> s;
    SegmentTree seg(s);

    int m; cin >> m;
    for(int l, r; m--;) cout << (cin >> l >> r, seg.query(l, r)) << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    // solve(), cout << endl;
    solve();
}