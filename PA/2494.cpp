/*
2494
书写卷积算子，看起来还是蛮有趣的
*/
//g++ -o main2494 2494.cpp
//./main2494
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void printMap(const vector<vector<int>> map) {
    for(int i = 0; i < map.size(); i++){
        for(int j = 0; j < map[0].size(); j++)
            cout << map[i][j] << " ";
        cout << endl;
    }
    return;
}
struct Feature {
    int M_1, N_1;
    vector<vector<int>> feature;

    Feature(int m_1, int n_1, vector<vector<int>> feature) : M_1(m_1), N_1(n_1), feature(feature) {} 

};
struct Feature Padding(const struct Feature &map, int P) {
    vector<vector<int>> newMap( map.M_1 + 2 * P, vector<int>(map.N_1 + 2 * P, 0));
    for(int i = P; i < map.M_1 + P; i++) {
        for (int j = P; j < map.N_1 + P; j++) {
            newMap[i][j] = map.feature[i - P][j - P];
        }
    }
    Feature newFeature(map.M_1 + 2 * P, map.N_1 + 2 * P, newMap);
    return newFeature;
}
int Dot(const struct Feature &map, const struct Feature &kernal, int x, int y) {
    int sum = 0;
    for(int i = 0; i < kernal.M_1; i++) {
        for(int j = 0; j < kernal.N_1; j++) {
            sum += map.feature[i + x][j + y] * kernal.feature[i][j];
        }
    }
    return sum;
}
struct Feature Conv(const struct Feature &map, const struct Feature &kernal, int S) {
    int x = (map.M_1 - kernal.M_1) / S + 1;
    int y = (map.N_1 - kernal.N_1) / S + 1;
    vector<vector<int>> newMap(x,vector<int>(y, 0));
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            newMap[i][j] = Dot(map, kernal, i * S, j * S);
        }
    }
    Feature newFeature(x, y, newMap);
    return newFeature;
}
int main() {
    int M_1, N_1, M_2, N_2, S, P;
    cin >> M_1>> N_1 >> M_2 >> N_2 >> S >> P;

    vector<vector<int>> map(M_1, vector<int>(N_1, 0));
    vector<vector<int>> kernal(M_2, vector<int>(N_2, 0));
    for(int i = 0; i < M_1; i++){
        for(int j = 0; j < N_1; j++)
            cin >> map[i][j];
    }
    for(int i = 0; i < M_2; i++){
        for(int j = 0; j < N_2; j++)
            cin >> kernal[i][j];
    }

    Feature Map(M_1, N_1, map);
    Feature Ker(M_2, N_2, kernal);

    // printMap(map);
    // printMap(kernal);

    // printMap(Padding(Map, P).feature);

    Feature result = Conv(Padding(Map, P), Ker, S);
    for(int i = 0; i < result.M_1; i++){
        for(int j = 0; j < result.N_1; j++){
            cout << result.feature[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

