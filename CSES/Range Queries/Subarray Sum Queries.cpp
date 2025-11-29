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
    struct node {
        int pref, suff, sum, maxSum;
        node(int val = INF){
            pref = suff = sum = maxSum = val;
        }
    };

    int n;
    vec<int> v;
    vec<node> tree;

    SegmentTree(vec<int> _v) : n(len(_v)), v(_v) {
        int sz = 1;
        for(; sz < n; sz <<= 1);
        tree.resize(sz << 1);
        build(0, n - 1, 0);
    }

    node merge(node left, node right){
        if(left.maxSum == INF) return right;
        if(right.maxSum == INF) return left;

        node res;
        res.pref = max(left.pref, left.sum + right.pref);
        res.suff = max(right.suff, right.sum + left.suff);
        res.sum = left.sum + right.sum;
        res.maxSum = max({left.maxSum, right.maxSum, left.suff + right.pref});
        return res;
    }

    void build(int l, int r, int id){
        if(l == r){
            tree[id] = node(v[l]);
            return;
        }

        int mid = (l + r) / 2;
        build(l, mid, 2 * id + 1);
        build(mid + 1, r, 2 * id + 2);
        tree[id] = merge(tree[2 * id + 1], tree[2 * id + 2]);
    }

    void update(int pos, int val){
        update(0, n - 1, 0, pos - 1, val);
    }

    void update(int l, int r, int id, int pos, int val){
        if(l == r){
            tree[id] = node(val);
            return;
        }

        int mid = (l + r) / 2;
        if(pos <= mid) update(l, mid, 2 * id + 1, pos, val);
        else update(mid + 1, r, 2 * id + 2, pos, val);
        tree[id] = merge(tree[2 * id + 1], tree[2 * id + 2]);
    }

    int query(){
        return max(0LL, tree[0].maxSum);
    }
};

void solve(){
    int n, m; cin >> n >> m;
    vec<int> a(n); cin >> a;

    SegmentTree seg(a);

    for(int k, x; m--;){
        cin >> k >> x;
        seg.update(k, x);
        cout << seg.query() << endl;
    }
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    // int t; cin >> t; while(t--)
    // solve(), cout << endl;
    solve();
}