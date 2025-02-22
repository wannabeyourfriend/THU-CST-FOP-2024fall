#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int backpackDP(vector<int> &time, vector<int> &value, int T){
    int n = time.size();
    //初始化dp表
    vector<vector<int>> dp(n + 1, vector<int>(T + 1));
    //开始状态转移，外层对n珠草药是否采集进行循环，内层检查剩余时间c:1->T
    for(int i = 1; i <= n; i++){
        for(int c = 1; c <= T; c++){
            // 选择采集或者不选采集
            if(time[i - 1] > c)
                dp[i][c] = dp[i - 1][c];
            else{//如果可以重复选择药物，则下面的dp[i - 1]要改为dp[i],因为若可以重复选，则前i个依然是选择的范围，否则只能从前i-1个中选择
                dp[i][c] = max(dp[i - 1][c], dp[i - 1][c - time[i - 1]] + value[i - 1]); //注意第i珠🌿的索引是i-1
                //cout << "dp[" << i << "][" << c << "]" <<" = "<<dp[i][c]<<endl;
            }
        }
    }
    return dp[n][T];
}
int main(){
    int T, M;
    cin >> T >> M;
    vector<int> time(M, 0);
    vector<int> value(M, 0);
    for(int i = 0; i < M; i++){
        cin>>time[i];
        cin>>value[i];
    }   
    int maxValue = backpackDP(time, value, T);
    cout<<maxValue;
    return 0;
}