/*
2432
g++ -o main2432 2432.cpp
记忆化搜索的办法会递归爆栈，不可以，必须要用动态规划
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long long DP(vector<vector<int>> &dp, vector<vector<int>> &upw, vector<vector<int>> &rtw, int N, int M) {
    
    for(int i = 2; i <= N; i++) {
        for(int j = 2; j <= M; j++) {
            dp[i][j] = max(dp[i - 1][j] + upw[i - 1][j], dp[i][j - 1] + rtw[i][j - 1]);
        }
    }
    return dp[N][M];
}
int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> upw(N + 1, vector<int>(M + 1, 0));
    vector<vector<int>> rtw(N + 1, vector<int>(M + 1, 0));
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++)
            cin >> rtw[i][j];
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++)
            cin >> upw[i][j];
    }   
    vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));
    for(int i = 2; i <= M; i++) 
        dp[1][i] = dp[1][i-1] + rtw[1][i-1];  // 进行累加
    for(int j = 2; j <= N; j++) 
        dp[j][1] = dp[j-1][1] + upw[j-1][1];  // 进行累加
    long long res = DP(dp, upw, rtw, N, M);
    cout << res << endl;
    return 0;
}