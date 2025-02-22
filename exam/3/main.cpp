#include <cmath>
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
void printVec(vector<vector<double>> &nums) {
    int m = nums.size() - 1;
    int n = nums[0].size() - 1;
    for(int i = 1; i <= m; i++) {
        for(int j= 1; j <= n; j++)  
            cout << fixed << setprecision(1 ) << nums[i][j] << " ";
        cout << endl;         
    }
}
vector<vector<double>> cha(vector<vector<double>> M1, vector<vector<double>> M2){
    int M1m = M1.size() - 1;
    int M1n = M1[0].size() - 1;
    int M2m = M2.size() - 1;
    int M2n = M2[0].size() - 1;
    if(M1n != M2m){
        cout << "WRONG" << endl;
        
    }
    int m = M1m;
    int n = M2n;
    int K = M1n;
    vector<vector<double>> M(m + 1, vector<double>(n + 1, 0));
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= K; k++) {
                M[i][j] += M1[i][k] * M2[k][j];
            }
        }
    }
    return M;
}  
vector<vector<double>> norm(vector<vector<double>> &nums, int d) {
    int m = nums.size() - 1;  
    int n = nums[0].size() - 1;
    double e = 2.7182818;
    for(int i  = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++){
            nums[i][j]  = nums[i][j] / pow(d, 0.5);
        }
    }
    vector<double> sum(m + 1, 0);
    for(int i  = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++){
            sum[i] += pow(e, nums[i][j]);
        }
    }
    for(int i  = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++){
            nums[i][j] = pow(e, nums[i][j]) / sum[i];
        }
    }
    return nums;
}
vector<vector<double>> trans(vector<vector<double>> &nums) {
    int m = nums.size() - 1;  
    int n = nums[0].size() - 1;
    vector<vector<double>> M(n + 1, vector<double>(m + 1, 0));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m ; j++) {
            M[i][j] = nums[j][i];
        }
    }
    return M;
}
vector<vector<double>> in(int m, int n){
    vector<vector<double>> nums(m + 1, vector<double>(n + 1, 0));
    for(int i = 1; i <= m; i++) {
        for(int j= 1; j <= n; j++)  
            cin >> nums[i][j];
    }
    return nums;
}
int main() {
    int m, n, d;
    cin >> m >> n >> d;
    vector<vector<double>> Q = in(m, d);
    vector<vector<double>> K = in(n, d);
    vector<vector<double>> V = in(n, d);
    //cout << d << endl;
    // printVec(Q);
    // printVec(K);
    // printVec(V);
    //cout << "END" << endl;
    vector<vector<double>> KT = trans(K);
    //cout << "KT" << endl;
    //printVec(KT);

    vector<vector<double>> QKT = cha(Q, KT);
    //printVec(QKT);
    vector<vector<double>> QKTN = norm(QKT, d);
    //printVec(QKTN);

    vector<vector<double>> res = cha(QKTN, V);
    printVec(res);
    return 0;


}