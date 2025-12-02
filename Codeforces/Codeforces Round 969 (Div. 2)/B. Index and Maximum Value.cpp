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
    using T = int;
    int n;
    vec<int> v;
    vec<T> tree;
    vec<T> lazy;

    SegmentTree(vec<int> _v) : n(len(_v)), v(_v), tree(4 * n), lazy(4 * n) {
        build(0, n - 1, 0);
    }

    T merge(T left, T right){
        return max(left, right);
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
        update(0, n - 1, 0, l, r, val);
    }

    void update(int l, int r, int id, int pl, int pr, int val){
        if(lazy[id]) propagate(l, r, id);
        if(l > pr || r < pl || l > r || pl > pr) return;
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

    int query(int pos){
        return query(0, n - 1, 0, pos);
    }

    T query(int l, int r, int id, int p){
        if(lazy[id]) propagate(l, r, id);
        if(l == r){
            return tree[id];
        }

        int mid = (l + r) / 2;
        if(p <= mid) return query(l, mid, 2 * id + 1, p);
        else return query(mid + 1, r, 2 * id + 2, p); 
    }
};

void solve(){
    int n, m; cin >> n >> m;
    vec<int> a(n); cin >> a;
    sort(all(a));

    SegmentTree seg(a);
    while(m--){
        char c; int l, r;
        cin >> c >> l >> r;
        
        int posLeft = n;
        for(int left = 0, right = n - 1; left <= right;){
            int mid = (left + right) / 2;
            if(seg.query(mid) < l) left = mid + 1;
            else posLeft = mid, right = mid - 1;
        }

        int posRight = n;
        for(int left = 0, right = n - 1; left <= right;){
            int mid = (left + right) / 2;
            if(seg.query(mid) <= r) left = mid + 1;
            else posRight = mid, right = mid - 1;
        }
        posRight--;
        // cout << posLeft << ' ' << posRight << endl;

        int val = c == '+' ? 1 : -1;
        seg.update(posLeft, posRight, val);
        cout << seg.tree[0] << ' ';
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
    // solve();
}