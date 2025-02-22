//利用函数跳转表实现指令控制
//g++ -o main2450 2450.cpp
//./main2450
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <functional>
using namespace std;
struct Person {
    string name;
    int height;
    Person(string name, int height) : name(name), height(height) {}
};
void printInfo(vector<struct Person> &q) {
    for(int i = 0; i < q.size(); i++) {
        cout << q[i].name << " " << q[i].height << endl;
    }
}
bool compare(Person &a, const Person &b) {
    if(a.height == b.height)
        return a.name < b.name;
    else
        return a.height < b.height;   
}
void ORDER(vector<struct Person> &q, string name, int height) {
    sort(q.begin(), q.end(), compare);
    return;
}
void ADD(vector<struct Person> &q, string name, int height) {
    Person p(name, height);
    q.push_back(p);
    return;
}
void LEAVE(vector<struct Person> &q, string name, int height) {
    vector<struct Person> tmp;
    for(int i = 0; i < q.size(); i++) {
        if(q[i].name != name)
            tmp.push_back(q[i]);
    }
    q = tmp;
    return;
}
void SELECT(vector<struct Person> &q, string name, int height) {
    vector<struct Person> tmp;
    for(int i = 0; i < q.size(); i++) {
        if(q[i].name == name) {
            tmp.push_back(q[i]);
            break;
        }
    }
    for(int i = 0; i < q.size(); i++) {
        if(q[i].name != name)
            tmp.push_back(q[i]);
    }
    q = tmp;
}
int main() {
    map<string, function<void(vector<struct Person>&, string, int)>> operations;
    operations["ADD"] = ADD;
    operations["ORDER"] = ORDER;
    operations["SELECT"] = SELECT;
    operations["LEAVE"] = LEAVE;
    vector<Person> q;
    int n;
    cin >> n;
    for(int i = 0; i < n ; i++) {
        string func = "";
        string name = "";
        int height = 0;
        //cin >> func >> name >> height;
        cin >> func;
        if(func == "ADD") {
            cin >> name >> height;
        }
        if(func == "SELECT" || func == "LEAVE") {
            cin >> name;
        }
        operations[func](q, name, height);
    }
    printInfo(q);
    return 0;
}