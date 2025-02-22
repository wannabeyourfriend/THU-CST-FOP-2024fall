/*
2401
旅行商问题
动态规划，维护一个d[i, V] 表示从节点 i 出发，访问完集合 V 中的所有节点后，
返回起点的最短路径长度。这里 i 是一个具体的节点，而 V 是一个节点集合。->采用位掩码技术，二进制中1的位表示节点已经被访问
g++ -o main2401 2401.cpp
*/
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
void printMap(const vector<vector<int>> &dist) {
    for(int i = 0; i < dist.size(); i++) {
        for(int j = 0; j < dist[0].size(); j++)
            cout << dist[i][j] << " ";
        cout << endl;
    }
}
//这个其实是记忆化搜索的办法
int DP(int i, int mask, const vector<vector<int>> &dist, vector<vector<int>> &dp) {
    int n = dist.size();
    //全部的节点都已经被访问过掩码表示为111...111
    if(mask == (1 << n) - 1) {
        return dist[i][0];
    }
    //查表
    if(dp[i][mask] != -1) 
        return dp[i][mask];
    
    int ans = INT_MAX;
    for(int k = 0; k < n; k++){
        if((mask & (1 << k)) == 0) { //判断k不在已经访问的集合V中
            int newMask = mask | (1 << k); //标记k为已经访问
            ans = min(ans, DP(k, newMask, dist, dp) + dist[i][k]);
        }
    }

    dp[i][mask] = ans;
    return ans;

}
int main() {
    int n;
    cin >> n;
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, 0));
    for(int i = 0; i < n ; i++) {
        for(int j = 1 ; j <= n - i; j++) {
            cin >> dist[i][j + i];
            dist[j + i][i] = dist[i][j + i];
        }
    }
    //printMap(dist);
    vector<vector<int>> dp(n + 1, vector<int>(1 << (n + 1), -1));
    //0号节点被访问过，其他节点均没有被访问过
    cout << DP(0, 1, dist, dp) << endl;
    return 0;
}