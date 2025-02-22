#include <iostream>
#include <vector>
using namespace std;
int count;//全局变量count记录当前状态索引
struct state //状态（人数，鬼数），也可以用来表船的状态
{
    int R;
    int G;
};
vector<struct state> S;
vector<int> choice;//记录每一步的决策
void transfer_state();//状态转移函数
void display(){//输出渡河状态
    for(int i = 1; i <= count; ++i)
        cout << i << ": (" << S[i].R << "," << S[i].G << ")" << endl;
}
int main()
{
    transfer_state();
    display();
    return 0;
}
void transfer_state()
{
    vector<struct state> d = {{0,0}, {1,0}, {2,0}, {1,1}, {0,2}, {0,1}};
    //状态初始化
    count = 1;
    S.resize(20, {3,3});
    choice.resize(20, 0);
    state initial_state = {3,3};
    S[0] = initial_state;
    while(!(S[count].R == 0 && S[count].G == 0)){
        int fx = 1;
        if (count % 2 == 1)
            fx = -1;
		int i;
        for(i = choice[count + 1] + 1; i <= 5; i++){
            //遍历并试探
            int u = S[count].R + fx * d[i].R;
            int v = S[count].G + fx * d[i].G;
            //减枝
            if( u > 3 || v > 3 || u < 0 || v < 0) continue;//越界 (1)
            if (!(u == 3 || u == 0 || u == v)) continue;//不满足约束->安全性检查：两边都需要安全 (2)
            //避免走回重复的状态节点->只考虑东岸的所有状态的集合，通过遍历来排除重复 (3)
            bool is_repeat = false;
            for(int j = count - 1; j >= 1; j -= 2)
                if(S[j].R == u && S[j].G == v)
                    is_repeat = true;
            if(is_repeat) continue;
            //试探
            count++;
            S[count].R = u;
            S[count].G = v;
            //记录解
            choice[count] = i;
            break;
        }
        //回退
        if(i > 5){ 
			count--;
		}
    }
}