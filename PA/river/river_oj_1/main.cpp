#include <iostream>
#include <queue>
#include <set>
#include <tuple>
#include <algorithm>
using namespace std;
struct State {
    //lw: left wolves rw: left sheep bp: boat place st: what steps now 
    int lw, ls, bp, st;
    //状态的构造函数
    State(int lw, int ls, int bp, int st) : lw(lw), ls(ls), bp(bp), st(st) {};
    //重载<运算符
    bool operator<(const State &other) const {
        return tie(lw, ls, bp, st) < tie(other.lw, other.ls, other.bp, other.st);
    }
};
bool is_valid(int wolves, int sheep) {
    return sheep >= wolves || sheep == 0; // 保证狼数不超过羊数，除非羊数为0
}
bool is_finished(int wolves, int sheep) {
    return (wolves == 0 && sheep == 0);
}
int bfs(int n, int m) 
{
    queue<State> q;
    set<State> visited;
    //初始化状态
    State init_state(n, n, 0, 0);
    q.push(init_state);
    visited.insert(init_state);
    
    while(!q.empty()) {
        State current = q.front();
        q.pop();
        if(is_finished(current.lw, current.ls)) return current.st;
        if(current.bp == 0) {
            //双层遍历求所有的送法
            for(int w = 0; w <= min(m, current.lw); ++w){
                for(int l = 0; l <= min(m - w, current.ls); ++l){
                    int nlw = current.lw - w, nls = current.ls - l;
                    int nrw = n - current.lw, nrs = n - current.ls;
                    //不符合条件提前剪枝
                    if(w == 0 && l == 0) continue; //船上至少一只羊
                    if(!is_valid(w, l)) continue; // 船上yang >= lang
                    if(!is_valid(nlw, nls)) continue; // 左岸yang >= lang
                    if(!is_valid(nrw, nrs)) continue;
                    State new_state(nlw, nls, 1, current.st + 1);
                    if(visited.find(new_state) == visited.end()){
                        visited.insert(new_state);
                        q.push(new_state);
                    }
                }
            }
        }
        else {
            //双层遍历求所有的送法
            for(int w = 0; w <= min(m, n - current.lw); ++w){
                for(int l = 0; l <= min(m - w, n - current.ls); ++l){
                    int nrw = n - current.lw, nrs = n - current.ls;
                    int nlw = current.lw + w, nls = current.ls + l;
                    //不符合条件提前剪枝
                    if(w == 0 && l == 0) continue; //船上至少一只羊
                    if(!is_valid(w, l)) continue; // 船上yang >= lang
                    if(!is_valid(nlw, nls)) continue; // 左岸yang >= lang
                    if(!is_valid(nrw, nrs)) continue; // 右岸yang >= lang
                    State new_state(nlw, nls, 0, current.st + 1);
                    if(visited.find(new_state) == visited.end()){
                        visited.insert(new_state);
                        q.push(new_state);
                    }
                }
            }
        }
    }
    return -1;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    int result = bfs(n, m);
    cout << result << endl;
    
    return 0;
}