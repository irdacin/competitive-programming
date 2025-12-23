# include <bits/stdc++.h>
using namespace std;

# define GRIND      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

# define db(x)      cout << #x << " -> " << x << endl

// Data Type
# define int        long long

// Constants
const int INF       = 1e18;
const int MOD       = 1e9 + 7;
const int MOD2      = 998244353;
const int MAXN      = 100000;
const int MAXN2     = 200000;

// Pairs
# define pii        pair<int, int>
# define fi         first
# define se         second

// Vector
# define pb         push_back
# define All(v)     v.begin(), v.end()
# define AllR(v)    v.rbegin(), v.rend()
# define Rev(v)     reverse(All(v))
# define Sort(v)    sort(All(v))
# define SortR(v)   sort(AllR(v))

signed main() {
    GRIND

    int n, m;  cin >> n >> m;

    int a[n + 1];
    for (int i = 1; i <= n; i++) cin >> a[i];

    int pow[11] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000};

    map<pii, int> count;

    for (int i = 1; i <= n; i++) {
        for (int ten = 0; ten <= 9; ten++) {
            if (a[i] < pow[ten]) {
                count[{a[i] % m, ten}]++;
                break;
            } else if (a[i] == pow[ten]) {
                count[{a[i] % m, ten + 1}]++;
                break;
            }
        }
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        for (int ten = 0; ten <= 10; ten++) {
            int a1 = (a[i] % m * pow[ten] % m) % m;
            ans += count[{(m - a1) % m, ten}];
        }
    }

    cout << ans;
}