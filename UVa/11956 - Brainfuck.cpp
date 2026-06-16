// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;

    for(int tc = 1; tc <= t; tc++){
        cout << "Case " << tc << ": ";
        vector<int> v(100, 0);
        string s; cin >> s;

        int id = 0;

        for(auto c : s){
            if(c == '+') (v[id] += 1) %= 256;
            else if(c == '-') (v[id] += 255) %= 256;
            else if(c == '<') (id += 99) %= 100;
            else if(c == '>') (id += 1) %= 100;
        }

        auto convert = [&](int i) -> char {
            if(i >= 10){
                i -= 10;
                return i + 'A';
            }

            return i + '0';
        };

        for(auto &i : v) cout << convert(i / 16) << convert(i % 16) << " \n"[&i == &v.back()];
    }
}
