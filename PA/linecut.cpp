//MD5:
/// CertUtil -hashfile linecut.cpp MD5
//钢条切割问题
//g++ -o linecut linecut.cpp
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
void printVec(const vector<int> &nums) {
    for(int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";
    cout << endl;
    return;
}
int DP(int n, vector<int> price) {
    vector<int> dp(n + 1, 0);
    dp[1] = price[1];
    for(int i = 1; i <= n; i++) {
        int max = 0;
        for(int k = 1; k <= i; k++){
            int val = dp[i - k] + price[k];
            if(val > max)
                max = val;
        }
        dp[i] = max;
    }

    return dp[n];
}
int main() {
    int n;
    cin >> n;
    vector<int> price(n + 1, 0);
    for(int i = 1; i <= n ; i++) 
        cin >> price[i];
    int len;
    cin >> len;
    cout << DP(len, price) << endl;
    return 0;
}