#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int min_time = 1000000;
int dfs(vector<int>& time, vector<bool>& visited, int count) {
    
    if (count == time.size() - 2){
        for (int i = 0; i < time.size(); i++){
            for(int j = 0; j < time.size(); j++) {
                if (!visited[i] && !visited[j])
                    return max(time[i], time[j]);
            }
        }
    }
    if (count == time.size()) 
        return 0;
    for (int i = 0; i < time.size(); ++i) {
        if (visited[i]) continue; 
        for (int j = i + 1; j < time.size(); ++j) {
            if (visited[j]) continue; 
            visited[i] = true; 
            visited[j] = true; 
            int bridge_time = max(time[i], time[j]);
            int min_time1 = min(time[i], time[j]);
            //走的快的人要回去接下一个人
            if (min_time1 == time[i])
                visited[i] = false;
            else
                visited[j] = false;
            // 递归计算剩下人的最少过桥时间
            cout << i << " " << j << ":" << " min_time:" << min_time <<endl;
            min_time = min(min_time, bridge_time + min_time1 + dfs(time, visited, count + 1));
            visited[i] = false; // 还原状态
            visited[j] = false; // 还原状态
        }
    }
    return min_time;
}

int main() {
    int n;
    cin >> n;

    vector<int> time(n);
    for (int i = 0; i < n; ++i) {
        cin >> time[i]; // 输入每个人的过桥时间
    }
    sort(time.begin(), time.end()); 
    vector<bool> visited(n, false); 
    int result = dfs(time, visited, 0); 
    cout << result << endl; 
    return 0;
}
