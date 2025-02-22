#include <iostream>
using namespace std;
struct position {int x, y;};
//满足题目的走法，用结构体数组来存储
position dxy[4] = {{1,2},{2,1},{2,-1},{1,-2}};
position start_pos = {0,0}, goal_pos ={8, 4};
position position_path[100];
int num;
void Jump(position pos, int step);
int main() {
    num = 0;
    Jump(start_pos, 0);
    return 0;
}
void Jump(position pos, int step){
	//判断是否达到目标,实际上这里可以
    if((pos.x == 8) && (pos.y == 4)){
		num++;//找到了新的方案
        cout << num << ":";
        for(int i = 0; i < step; i++)
            cout << "(" << position_path[i].x << "," << position_path[i].y <<")" ;
    	cout << endl;
	}
    //选择
	for(int k = 0;k < 4; k++){
		//试探
		position next_pos = {pos.x + dxy[k].x, pos.y + dxy[k].y};
		if( next_pos.x > 8 || next_pos.x < 0 || next_pos.y < 0 || next_pos.y > 4)
			continue;
		position_path[step] = next_pos;
		Jump(next_pos, step + 1);
	}    	
}