#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int seqDP(const string &a, const string &b){
    int n = a.size(), m = b.size();
    //初始化dp表
    vector<vector<int>> dp(n, vector<int>(m, 0));
    //边界状态转移
    if (a[0] == b[0])
        dp[0][0] = 1;
    for(int i = 1; i < n; i++)
        if(a[i] == b[0])
            dp[i][0] = max(1, dp[i - 1][0]);
        else
            dp[i][0] = dp[i - 1][0];
    for(int j = 1; j < m; j++)
        if(b[j] == a[0])
            dp[0][j] = max(1, dp[0][j - 1]);
        else
            dp[0][j] = dp[0][j - 1];
    //状态转移
    for(int i = 1; i < n ; i++){
        for(int j = 1; j < m; j++){
            if(a[i] ==  b[j]) 
                dp[i][j] = dp[i - 1][j - 1] + 1;//这行代码非常关键，原本写错了写成了dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]) + 1;仔细看这个逻辑是有问题的
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    return dp[n - 1][m - 1];
}
int main()
{
    string a;
    string b;
    cin>>a;
    cin>>b;
    int seq = seqDP(a,b);
    cout<<seq<<endl;
    return 0;
}