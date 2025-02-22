#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
struct position {int x,y;};
position dxy[] = {{1,0}, {0,1}, {1,1}, {2,0}, {0,2}};//所有可能的状态转移量
struct state {
    int dir;//将方向纳入状态的考量
    position pos;
};
state start = {-1, {3, 3}}, goal = {1,{0, 0}};//定义状态转移的初态和末态
state path[100];//100在此题目中被认为是一个足够大的量;path结构体数组在多个函数体内部共享,用来存储经过的路径,也可以看作是状态路径栈.
int num;//全局变量用来存储有多少个可能的解法
int minStep;//全局变量来存储最短的路径
bool isEq(state st1, state st2){
	return (st1.dir == st2.dir) && (st1.pos.x == st2.pos.x) && (st1.pos.y == st2.pos.y);
}
bool isValid(state st, int step){//剪枝函数
    if(st.pos.x < 0 || st.pos.x > 3 || st.pos.y < 0 || st.pos.y > 3)
        return false;
    if(st.pos.x != 0 && st.pos.x != 3 && st.pos.x != st.pos.y)
        return false;
    for(int i = step - 1; i >= 0; i--)
        if(isEq(st, path[i]))
            return false;
   	return true;
}
state getNewstate(state st, int k, int step){//根据分支序号k获取此状态的后继状态
    state next_st = {-st.dir, {st.pos.x + st.dir * dxy[k].x, st.pos.y + st.dir * dxy[k].y}};
    return next_st;
}
bool isDone(state st){//判断终止条件
	if(isEq(st, goal))
		return true;
	return false;
}
void logStep(state st, int step){//将状态中的节点记录到path中
	path[step] = st;
}
void printStep(state st){//将某个节点的信息打印在屏幕上
	cout << setw(2) << st.dir << "(" << st.pos.x << st.pos.y << ")" ;
}
void printPath(int step){//将路径信息打印出来
	for(int i = 0; i <= step; i++)
		printStep(path[i]);
    cout << endl;
}
void Jump(state st, int step){
	//判断递归终止条件
	if(isDone(st)){
		num++;
		minStep = min(minStep, step);
		cout << num << ": ";
		printPath(step);
		return;
	}
	//遍历每一种决策分支
	for(int k = 0; k < sizeof(dxy) / sizeof(dxy[0]) ; k++){
		state next_state = getNewstate(st, k, step);
		if(!isValid(next_state, step + 1))
			continue;//不符合的解会提前跳出，因此不需要再回溯了
		logStep(next_state, step + 1);
		Jump(next_state, step + 1);
	}
}
int main()
{
    num = 0;
    minStep = 1000;
    logStep(start, 0);
    Jump(start, 0);
    cout << "minStep:" << minStep << endl;
    return 0;
}
