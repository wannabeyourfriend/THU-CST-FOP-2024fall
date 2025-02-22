#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
void  DP(vector<vector<int>> map, int n, int m) {
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for(int i = 1; i <= n; i++) {
        if(i % 2 == 0) {
            if((map[i / 2][1] == 1 || map[i / 2][1] == 2) && map[i - 1][1] == 2 ){
                dp[i][1] = min(dp[i / 2][1], dp[i - 1][1]) + 1;
            }
            else if(!(map[i / 2][1] == 1 || map[i / 2][1] == 2) && map[i - 1][1] == 2) {
                dp[i][1] = dp[i -1][1]  + 1;
            } else if((map[i / 2][1] == 1 || map[i / 2][1] == 2) &&  !(map[i - 1][1] == 2)){
                dp[i][1] = dp[i / 2][1] + 1;
            } else {
                dp[i][1] = 1000000;
            }
        }
        else {
            if(map[i - 1][1] == 2){
                dp[i][1] = dp[i - 1][1] + 1;
            }
            else
                dp[i][1] = 1000000;
        }
    }
    for(int j = 1; j <= m; j++) {
        if(j % 2 == 0) {
            if((map[1][ j / 2] == 1 || map[1][j / 2] == 2) && map[1][j - 1] == 2)
            {
                dp[1][j] = min(dp[1][j / 2], dp[1][ j -1]) + 1;
                continue;
            }
            else if(!(map[1][j / 2] == 1 || map[1][j /2] == 2) &&  (map[1][j / 2] == 2))
            {
                dp[1][j] = dp[1][j - 1]  + 1;
                continue;
            } 
            else if((map[1][j / 2] == 1 || map[1][j /2] == 2) &&  !(map[1][j / 2] == 2))
            {
                dp[1][j] = dp[1][j / 2] + 1;
            } 
            else 
            {
                dp[1][j] = 1000000;
            }
        }
        else {
            if(map[1][j - 1] == 2){
                dp[1][j] = dp[1][j] + 1;
            }
            else
                dp[1][j] = 100000;
        }
    }
    for(int i = 2; i <= n; i++) {
        for(int j = 2; j <= m; j++) {
            if(i % 2 == 0 && j % 2 == 0)
                dp[i][j] = min(dp[i / 2][j], dp[i][j / 2], dp[i - 1][j], dp[i][j - 1]) + 1;
        }
    }
    return dp[n][m];
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> map(n + 1, vector<int>(m + 1, 0));
    //cout << n << m<< endl;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++){
            cin >> map[i][j];
        }
    }
    int res = DP(map,n,m);
    cout << res << endl;
    return 0;

}