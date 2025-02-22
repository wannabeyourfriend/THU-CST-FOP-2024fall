/*
2429
统计区间字母个数
g++ -o main2429 2429.cpp
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
struct Pair {
    int L, R;
    Pair(int x, int y) : L(x), R(y) {}
};
struct alpha {
    char ch;
    int count;
    alpha(int ch, int count) : ch(char(ch)), count(count) {}
};
int askalpha(string S, int L, int R, int ch) {
    int count = 0;
    for(int i = L; i <= R; i++) {
        if(S[i] == char(ch))
            count++;
    }
    return count;
}
void ask(string S, int L, int R) {
    vector<struct alpha> sh;
    for(int i = int('a'); i <= int('z'); i++) {
        int count = askalpha(S, L, R, i);
        if(count) {
            alpha ah(i, count);
            sh.push_back(ah);
        }
    }
    for(int i = 0; i < sh.size(); i++){
        cout << sh[i].ch <<":" << sh[i].count << " ";
    }
    cout << endl;
    return;
}

int main() {
    string S;
    cin >> S;
    int n;
    cin >> n;
    vector<struct Pair> ques;
    for(int i = 0; i < n ; i++) {
        int L, R;
        cin >> L >> R;
        Pair que(L, R);
        ques.push_back(que);
    }
    for(int i = 0; i < n; i++) {
        ask(S, ques[i].L, ques[i].R);
    }
    return 0;
}