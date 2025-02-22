/* 2437 单词查找
本题目考察枚举基本功
细节决定成败！！！！！找了非常久，发现只是因为一个正负号取反了
g++ -o main2437 2437.cpp
./main2437
*/
#include <bits/stdc++.h>
using namespace std;
char a[300][300];
int m[300][300];
bool in_program(char a, char b, char c, char d, char e, char f, char g){
    if(a == 'p' && b == 'r' && c == 'o' && d == 'g' && e == 'r' && f == 'a' && g == 'm')
        return true;
    else
        return false;
}
int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= n; j++) 
            cin >> a[i][j];
    //横排检查
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n - 6; j++)
            if(in_program(a[i][j], a[i][j + 1], a[i][j + 2], a[i][j +3], a[i][j + 4], a[i][j + 5], a[i][j + 6]) || in_program(a[i][j + 6], a[i][j + 5], a[i][j + 4], a[i][j + 3], a[i][j + 2], a[i][j + 1], a[i][j]))
                m[i][j] =  m[i][j + 1] =  m[i][j + 2] =  m[i][j +3] = m[i][j + 4] =  m[i][j + 5] =  m[i][j + 6] = 1;
   
    //竖排检查
    for(int j = 1; j <= n; j++)
        for(int i = 1; i <= n -6; i++)
            if(in_program(a[i][j], a[i + 1][j], a[i + 2][j], a[i + 3][j], a[i + 4][j], a[i + 5][j], a[i + 6][j]) || in_program(a[i + 6][j], a[i + 5][j], a[i + 4][j], a[i + 3][j], a[i + 2][j], a[i + 1][j], a[i][j]))
                m[i][j] = m[i + 1][j] = m[i + 2][j] = m[i + 3][j] = m[i + 4][j] = m[i + 5][j] = m[i + 6][j] = 1;
   
    //左上角到右下角
    for(int i = 7 - n; i <= n - 7; i++) {
        for(int j = 1 + max(0, (-1) * i); j <= n - max(0, i) -6; j++)
            if(in_program(a[i + j][j], a[i + j + 1][j + 1], a[i + j + 2][j + 2], a[i + j + 3][j + 3], a[i + j + 4][j + 4], a[i + j + 5][j + 5], a[i + j + 6][j + 6]) || in_program(a[i + j + 6][j + 6], a[i + j + 5][j + 5], a[i + j + 4][j + 4], a[i + j + 3][j + 3], a[i + j + 2][j + 2], a[i + j + 1][j + 1], a[i + j][j]))
                m[i + j][j] = m[i + j + 1][j + 1] = m[i + j + 2][j + 2] = m[i + j + 3][j + 3] = m[i + j + 4][j + 4] = m[i + j + 5][j + 5] = m[i + j + 6][j + 6] = 1; 
    }
 
    //以及右上角到左下角
    for(int i = 7 - n; i <= n - 7; i++) {
        for(int j = 1 + max(0, (-1) * i); j <= n - max(0, i) -6; j++)
            if(in_program(a[n + 1 - i - j][j], a[n + 1 - i - j - 1][j + 1], a[n + 1 - i - j - 2][j + 2], a[n + 1 - i - j - 3][j + 3], a[n + 1 - i - j - 4][j + 4], a[n + 1 - i - j - 5][j + 5], a[n + 1 - i - j - 6][j + 6]) || in_program(a[n + 1 - i - j - 6][j + 6], a[n + 1 - i - j - 5][j + 5], a[n + 1 - i - j - 4][j + 4], a[n + 1 - i - j - 3][j + 3], a[n + 1 - i - j - 2][j + 2], a[n + 1 - i - j - 1][j + 1], a[n + 1 - i - j][j]))
                m[n + 1 - i - j][j] = m[n + 1 - i - j - 1][j + 1] = m[n + 1 - i - j - 2][j + 2] = m[n + 1 - i - j - 3][j + 3] = m[n + 1 - i - j - 4][j + 4] = m[n + 1 - i - j - 5][j + 5] = m[n + 1 - i - j - 6][j + 6] = 1; 
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++)
            if(m[i][j])
                cout << a[i][j];
            else
                cout << '*';
        cout << endl;
    }
    return 0;
}