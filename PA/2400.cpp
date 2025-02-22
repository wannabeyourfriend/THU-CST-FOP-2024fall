/*
2400
拼接最小字符串
解法：如果直接按照字典顺序来拼接，比如有abc,abca这两个字符串进行拼接，会得到abcabca > abcaabc，所以要自定义sort函数
g++ -o main2400 2400.cpp
*/
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

using namespace std;
bool compare(string a, string b) {
    return (a + b) < (b + a);
}
int main() {
    int n;
    cin >> n;
    vector<string> str;
    for(int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        str.push_back(tmp);
    }
    sort(str.begin(), str.end(), compare);
    string result;
    for(int i = 0; i < n; i++) {
        result += str[i];
    }
    cout << result << endl;
    return 0;
}