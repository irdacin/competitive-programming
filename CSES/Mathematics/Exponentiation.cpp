#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define rcout(x) return void(cout << x)

template <typename T> using vec = vector<T>;
template <typename T> using vvec = vector<vec<T>>;
template <typename T> using vvvec = vector<vvec<T>>;
#define pb push_back
#define all(x) x.begin(), x.end()
#define len(x) (int) x.size()

const int MOD = 1e9 + 7;
const int INF = 2e9;

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

	friend ModInt power(ModInt a, int k){ 
		ModInt res = 1;
		for(; k > 0 ; a*= a, k>>=1){
			if(k & 1) res *= a;
		}
		return res;
	}
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
	mi a, b; cin >> a >> b;
	cout << power(a, b);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--) 
    solve(), cout << endl;
}