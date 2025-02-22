// /*
// 2439 暴力枚举法 用前缀和试一下 -> 70分做法
// g++ -o main2439 2439.cpp
// */
// #include <bits/stdc++.h>
// using namespace std;
// vector<int> prefix(const vector<int> &num) {
//     int n = num.size();
//     vector<int> presum(n + 1, 0);
//     for (int i = 1; i <= n; i++) {
//         presum[i] = presum[i - 1] + num[i - 1];
//     }
//     return presum;
// }
// int main() {
//     int n, k;
//     cin >> n >> k;
//     vector<int> num(n, 0);
//     for(int i = 0; i < n; i++)
//         cin >> num[i];
//     vector<int> presum = prefix(num);
//     int mintime = presum[2 * k];
//     int tmp1 = 1;
//     int tmp2 = k + 1;
//     for(int i = 1; i <= n + 1 - 2 * k; i++) {
//         for(int j = i + k; j <= n + 1 - k ; j++) {
//             int sum = presum[i + k - 1] - presum[i - 1] + presum[j + k - 1] - presum[j - 1];
//             if( sum < mintime) {
//                 mintime = sum;
//                 tmp1 = i;
//                 tmp2 = j;
//             }
//         }
//     }
//     cout << tmp1 << " " << tmp2  << endl;
//     return 0;
// }

// //王一丁给出的做法：开两个数组，存储某一个位置以及之后连续k个数和的最小值和相应的位置；这样经过O(n)预处理的复杂度，在给定周六之后，周日的查找复杂度是O(1)的
// #include <bits/stdc++.h>
// using namespace std;
// vector<int> prefix(const vector<int> &num){
//     int n = num.size();
//     vector<int> presum(n + 1, 0);
//     presum[0] = 0;
//     for(int i = 1 ; i <= n; i++){
//         for(int j = 1; j <= i; j++)
//             presum[i] += num[j -1];
//     }
//     return presum;
// }
// void findmink(const vector<int> &presum, vector<int> &index, vector<int> &min, int k) {
//     int minV = presum[k] - presum[0];
//     int idx = 1;
//     int n = presum.size() - 1;
//     for(int i = 1; i <= n - 2 * k + 1; i++) {
//         for(int j = i; j <= n - k + 1; j++) {
//             int tmp = presum[j + k - 1] - presum[j - 1];
//             if(tmp < minV) {
//                 index[i] = j;
//                 min[i] = minV;
//             }
//         }
//     }
// }
// int main() {
//     int n, k;
//     cin >> n >> k;
//     vector<int> num(n + 1, 0);
//     for(int i = 0; i < n; i++)
//         cin >> num[i];
//     vector<int> presum = prefix(num);
//     vector<int> index(n, 0);
//     vector<int> min(n, 0);
//     findmink(presum, index, min, k);
//     int minsum = presum[k] - presum[0] + min[1];
//     int tmp1 = 1;
//     int tmp2 = index[1 + k];
//     for(int i = 1; i <= n - 2 * k + 1; i++) {
//         int tmpsum = presum[i + k - 1] - presum[i -1];
//         if(tmpsum + min[i + k] < minsum) {
//             tmp1 = i;
//             tmp2 = index[i + k];
//         }
//     }
//     cout << tmp1 << " " << tmp2 << endl;
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

// 计算从某个位置开始的连续 k 个数的和
vector<int> calc_sum_k(const vector<int>& num, int k) {
    int n = num.size();
    vector<int> sum_k(n - k + 1);
    vector<int> presum(n + 1, 0);
    
    // 计算前缀和
    for (int i = 1; i <= n; i++) {
        presum[i] = presum[i - 1] + num[i - 1];
    }

    // 计算每个位置开始的连续 k 个数的和
    for (int i = 0; i <= n - k; i++) {
        sum_k[i] = presum[i + k] - presum[i];
    }
    
    return sum_k;
}

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    // 计算每个位置开始的连续 k 个数的和
    vector<int> sum_k = calc_sum_k(num, k);
    
    // 构建两个数组：min_pos[i] 存储从位置 i 开始的最小和及其位置
    vector<pair<int, int>> min_pos(n - k + 1);  // (最小和, 位置)
    
    // 初始化第一个位置
    min_pos[0] = {sum_k[0], 0};
    
    // 遍历计算最小值和最小值位置
    for (int i = 1; i <= n - k; i++) {
        if (sum_k[i] < min_pos[i - 1].first) {
            min_pos[i] = {sum_k[i], i};
        } else {
            min_pos[i] = min_pos[i - 1];
        }
    }
    
    // 查找最小值的最小和以及位置
    int mintime = INT_MAX;
    int tmp1 = -1, tmp2 = -1;
    
    // 遍历查找
    for (int i = 0; i <= n - 2 * k; i++) {
        // 第一个区间 [i, i+k-1] 和第二个区间 [min_pos[i+k], min_pos[i+k+k-1]]
        int left_sum = sum_k[i];  // 第一个区间的和
        int right_index = i + k;
        int right_sum = sum_k[min_pos[right_index].second];
        
        int total_sum = left_sum + right_sum;
        if (total_sum < mintime) {
            mintime = total_sum;
            tmp1 = i;
            tmp2 = min_pos[right_index].second;
        }
    }
    
    // 输出结果
    cout << tmp1 << " " << tmp2 << endl;
    return 0;
}
