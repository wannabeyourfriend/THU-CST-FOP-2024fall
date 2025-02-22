/*
2431
矩阵查询
g++ -o main2431 2431.cpp
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
void add(vector<vector<int>> &arr, int x1, int y1, int x2, int y2, int d) {
    for(int i = x1 - 1; i < x2; i++) {
        for(int j = y1 - 1; j < y2; j++)
            arr[i][j] += d;
    }
}
void exchange(vector<vector<int>> &arr, int x1, int x2) {
    swap(arr[x1 - 1], arr[x2 - 1]);
}
int question(vector<vector<int>> &arr, int x, int y) {
    return arr[x - 1][y - 1];
}
int main() {
    int x, y;
    cin >> x >>y;
    vector<vector<int>> arr(x, vector<int>(y, 0));
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++)
            cin >> arr[i][j];
    }
    int n;
    cin >> n;
    vector<int> res;
    for(int i = 0; i < n; i++) {
        string instruction;
        cin >> instruction;
        if(instruction == "A") {
            int x1, y1, x2, y2, d;
            cin >> x1 >> y1 >> x2 >> y2 >> d;
            add(arr, x1, y1, x2, y2, d);
        }
        if(instruction == "E") {
            int x1, x2;
            cin >> x1 >> x2;
            exchange(arr, x1,x2);
        }
        if(instruction == "Q") {
            int x, y;
            cin >> x >> y;
            res.push_back(question(arr, x, y));
        }
    }
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << endl;
    return 0;

}