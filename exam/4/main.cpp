    #include <algorithm>
    #include <vector>
    #include <iostream>
    #include <iomanip>
    #include <cmath>
    using namespace std;
    double dist(long long  delta) {
        double s = pow(delta, 2) + 1;
        double d = pow(s, 0.5);
        return d;
    }
    struct Point {
        int name;
        long long  pos;
        Point(int name, int pos) : name(name), pos(pos) {}
    };
    bool compare(struct Point a, struct Point b) {
        return a.pos < b.pos;
    }
    int main () {
        long long m, p, q;
        cin >> m >> p >> q;
        vector<struct Point> A;
        vector<struct Point> B;
        vector<struct Point> all;
        for(int i = 0; i < p; i++) {
            long long pos;
            cin >> pos;
            Point pointa(1, pos);
            A.push_back(pointa);
            all.push_back(pointa);
        }
        for(int i = 0; i < q; i++) {
            long long pos;
            cin >> pos;
            Point pointb(2, pos);
            B.push_back(pointb);
            all.push_back(pointb);
        }
        sort(all.begin(), all.end(), compare);
        long long min = m;
        for(int i = 0; i < p + q; i++) {
            for(int j = 1; i + j < p + q; j++){
                if(all[i + j].name != all[i].name) {
                    long long dis = abs(all[i].pos - all[i + j].pos);
                    if(dis < min){
                        min = dis;
                    }
                    break;
                }
            }
        }
        cout << fixed << setprecision(2) << dist(min) << endl;
        return 0;
    }