// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q; cin >> n >> q;

    vector<int> v[n];
	
	for(int i = 0; i < n; i++) {
		int l; cin >> l;
		for(int j = 0, a; j < l; j++) {
			cin >> a;
			v[i].emplace_back(a);
		}
	}
	
	for(int s, t; q--;) {
		cin >> s >> t;
        s--, t--;
        cout << v[s][t] << '\n';
	}
}