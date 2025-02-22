/*
2428
找到覆盖给定点集的最小正方形（正方形平行于坐标轴）
g++ -o main2428 2428.cpp
第一次试了一下：时间超限
*/
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct P
{
    int x, y;
    P(int x, int y) : x(x), y(y) {}
};
bool compare_x(struct P p, struct P q) {
    return p.x < q.x;
}
bool compare_y(struct P p, struct P q) {
    return p.y < q.y;
}

int main() {
    int n;
    cin >> n;
    vector<struct P> points;
    for(int i = 0; i < n; i++) {
        int x,y;
        cin >> x >> y;
        P p(x,y);
        points.push_back(p);
    }
    sort(points.begin(), points.end(), compare_x);
    int max_x = points[n - 1].x - points[0].x;
    sort(points.begin(), points.end(), compare_y);
    int max_y = points[n - 1].y - points[0].y;
    
    // int maxX = -1;
    // for(int i = 0; i < n; i++) {
    //     for(int j = i; j < n; j++)
    //         maxX = max(maxX, abs(points[i].x - points[j].x));
    // }
    // int maxY = -1;
    // for(int i = 0; i < n; i++) {
    //     for(int j = i; j < n; j++)
    //         maxY = max(maxY, abs(points[i].y - points[j].y));
    // }
    cout << max(max_x, max_y) << endl;
    return 0;
}