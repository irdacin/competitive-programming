#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()

#define vi vector<int>
#define vvi vector<vi>

const int MOD = 1e9 + 7;

template <int MOD>
struct ModInt {
	int val;
	ModInt(int v = 0) : val(v % MOD){ if(val < 0) val += MOD; }

	ModInt operator+(ModInt other){ return (val + other.val) % MOD ; }
	ModInt operator-(ModInt other){ return (val - other.val + MOD) % MOD; }
	ModInt operator*(ModInt other){ return (val % MOD) * (other.val % MOD) % MOD; }
	ModInt operator/(ModInt other){ return *this * power(other, MOD - 2); }
	ModInt& operator+=(ModInt other){ return *this = *this + other; }
	ModInt& operator-=(ModInt other){ return *this = *this - other; }
	ModInt& operator*=(ModInt other){ return *this = *this * other; }
	ModInt& operator/=(ModInt other){ return *this = *this / other; }
	ModInt& operator++(){ return *this += 1; }
	ModInt& operator--(){ return *this -= 1; }
	ModInt operator++(int32_t){ ModInt a = *this; *this += 1; return a; }
	ModInt operator--(int32_t){ ModInt a = *this; *this -= 1; return a; }

	friend ModInt power(ModInt a, int k){ return k==0 ? 1 : power(a * a, k / 2) * (k & 1 ? a : 1); }
	friend ModInt power(ModInt a, ModInt k){ return power(a, k.val); }

	bool operator==(ModInt other){ return val == other.val; }
	bool operator!=(ModInt other){ return val != other.val; }
	bool operator>=(ModInt other){ return val >= other.val; }
	bool operator<=(ModInt other){ return val <= other.val; }
	bool operator>(ModInt other){ return val > other.val; }
	bool operator<(ModInt other){ return val < other.val; }

	friend istream& operator>>(istream &is, ModInt &mi){ return mi = ModInt(mi.val), is >> mi.val; }
	friend ostream& operator<<(ostream &os, const ModInt &mi){ return os << mi.val; }
};

using mi = ModInt<MOD>;

void solve(){
    mi n, m; cin >> n >> m;
    if(n > m) swap(n, m);

    cout << n * (n + 1) * (n - 1) * (m * 2 - n) / 12;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
}