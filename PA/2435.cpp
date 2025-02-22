/*
2435 圆内点的数量统计
g++ -o main2435 2435.cpp
*/
#include <algorithm>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
};
struct Circle {
    int x, y, r;
    Circle(int x, int y, int r) : x(x), y(y), r(r) {}
};
bool is_inner(struct Point point, struct Circle circle) {
    double d2 = pow((point.x - circle.x),2) + pow((point.y - circle.y),2);
    if(d2 < pow(circle.r, 2))
        return true;
    if(abs(d2 - pow(circle.r,2)) <= 0.0001)
        return true;
    else
        return false;
}
int cnt(const vector<struct Point> points, struct Circle circle) {
    int count = 0;
    for(auto point : points)
        if(is_inner(point, circle))
            count++;
    return count;
}
int main(){
    int N, M;
    vector<struct Point> points;
    cin >> N;
    for(int i = 0; i < N; i++){
        int x, y;
        cin >> x >> y;
        Point point(x, y);
        points.push_back(point);
    }
    cin >> M;
    vector<struct Circle> circles;
    for(int i = 0; i < M; i++){
        int x, y, r;
        cin >> x >> y >> r; 
        Circle circle(x, y, r);
        circles.push_back(circle);
    }
    for(int i = 0; i < M; i++){
        cout << cnt(points, circles[i]) << " ";
    }
    cout << endl;
    return 0;

}