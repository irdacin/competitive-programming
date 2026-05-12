#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

struct Matrix{
    int N, M;
    vector<vector<int>> Mat;

    Matrix(vector<vector<int>> mat){
        N = len(mat), M = len(mat[0]);
        Mat = mat;
    }
    
    Matrix(int n, int m){
        N = n, M = m;
        Mat.assign(N, vector<int>(M, 0));
    }

    Matrix operator*(Matrix other){
        Matrix result(N, other.M);
        for(int i=0; i<N; i++){
            for(int j=0; j<other.M; j++){
                int sum = 0;
                for(int k=0; k<M; k++) 
                    sum += Mat[i][k] * other.Mat[k][j];

                result.Mat[i][j] = sum;
            }
        }
        return result;
    }

    Matrix operator*=(Matrix other){
        return *this = *this * other;
    }
};

void solve(int n){
    // dp solution

    // vector<vector<int>> dp(n+1, vector<int>(8, 0));
    // dp[0][7] = 1;
    // for(int i=1; i<=n; i++){
    //     dp[i][0] = dp[i-1][7];
    //     dp[i][1] = dp[i-1][6];
    //     dp[i][2] = dp[i-1][4];
    //     dp[i][3] = dp[i-1][5];
    //     dp[i][4] = dp[i-1][2];
    //     dp[i][5] = dp[i-1][3] + dp[i-1][7];
    //     dp[i][6] = dp[i-1][1] + dp[i-1][7];
    //     dp[i][7] = dp[i-1][0] + dp[i-1][5] + dp[i-1][6];
    // }
    // cout << dp[n][7] << endl;

    Matrix result({
        {0},
        {0},
        {0},
        {0},
        {0},
        {0},
        {0},
        {1},
    });

    Matrix trans({
        {0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 1},
        {0, 1, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 1, 1, 0},
    });

    for(; n > 0; trans *= trans, n >>= 1)
        if(n & 1) result = trans * result;

    cout << result.Mat[7][0];
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    for(int n; cin >> n;)
    if(n!=-1)
    solve(n), cout << endl;
}