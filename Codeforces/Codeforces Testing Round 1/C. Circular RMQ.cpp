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
const int INF = 2e18;

struct SegmentTree {
    using T = int;
    vec<T> tree;
    vec<int> lazy;
    vec<int> v;
    int n;

    SegmentTree(vec<int> _v) : n(len(_v)), v(_v){
        int sz = 1;
        for(; sz < n; sz <<= 1);
        tree.resize(sz << 1);
        lazy.resize(sz << 1);
        build(0, n - 1, 0);
    }

    T merge(T left, T right){
        return min(left, right);
    }

    void build(int l, int r, int id){
        if(l == r){
            tree[id] = v[l];
            return;
        }

        int mid = (l + r) / 2;
        build(l, mid, 2 * id + 1);
        build(mid + 1, r, 2 * id + 2);
        tree[id] = merge(tree[2 * id + 1], tree[2 * id + 2]);
    }

    void propagate(int l, int r, int id){
        tree[id] += lazy[id];
        if(l != r){
            lazy[2 * id + 1] += lazy[id];
            lazy[2 * id + 2] += lazy[id];
        }
        lazy[id] = 0;
    }

    void update(int l, int r, int val){
        if(l <= r) update(0, n - 1, 0, l, r, val);
        else update(0, n - 1, 0, l, n - 1, val), update(0, n - 1, 0, 0, r, val);
    }

    void update(int l, int r, int id, int pl, int pr, int val){
        if(lazy[id]) propagate(l, r, id);
        if(l > pr || r < pl || l > r) return;
        if(pl <= l && r <= pr){
            lazy[id] += val;
            propagate(l, r, id);
            return;
        }

        int mid = (l + r) / 2;
        update(l, mid, 2 * id + 1, pl, pr, val);
        update(mid + 1, r, 2 * id + 2, pl, pr, val);
        tree[id] = merge(tree[2 * id + 1], tree[2 * id + 2]);
    }

    int query(int l, int r){
        if(l <= r) return query(0, n - 1, 0, l, r);
        else return merge(query(0, n - 1, 0, l, n - 1), query(0, n - 1, 0, 0, r));
    }

    T query(int l, int r, int id, int pl, int pr){
        if(lazy[id]) propagate(l, r, id);
        if(l > pr || r < pl || l > r) return INF;
        if(pl <= l && r <= pr){
            return tree[id];
        }

        int mid = (l + r) / 2;
        return merge(query(l, mid, 2 * id + 1, pl, pr), query(mid + 1, r, 2 * id + 2, pl, pr));
    }
};

void solve(){
    int n; cin >> n;
    vec<int> a(n); cin >> a;
    
    SegmentTree seg(a);

    int m; cin >> m;
    for(cin.ignore(); m--;){
        vec<int> tmp;

        int num = 0; bool neg = false;
        for(char c; cin.get(c) && c != '\n';){
            if(c == ' ') tmp.eb(num), num = 0;
            else if(c == '-') neg = true;
            else num = num * 10 + (c - '0');
        }
        if(neg) num *= -1;
        tmp.eb(num);

        // cout << tmp;
        if(len(tmp) == 3) seg.update(tmp[0], tmp[1], tmp[2]);
        else cout << seg.query(tmp[0], tmp[1]) << endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
    // solve();
}