#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void printVec(vector<int> &nums){
	int n = nums.size();
	for(int i =0; i < n; i++){
		cout << nums[i] << " ";
	}
	cout << endl;
	return;
}
/* pivot 划分, 区间为[left, right] */
int partition(vector<int> &nums, int left, int right){
    //以left作为基准数字
    int i = left, j = right;
    while( i < j ) {
        while(i < j && nums[j] >= nums[left])
           j--;
        while(i < j && nums[i] <= nums[left])
           i++;
        swap(nums[i], nums[j]);
    }
    swap(nums[i], nums[left]);//将基准数字交换到两个子数组的分界线
    return i;//返回基准数的索引
}
void quickSort(vector<int> &nums, int left, int right){
    //子数组长度为1时候停止递归
    if(left >= right)
        return;
    int pivot = partition(nums, left, right);
	printVec(nums);
    quickSort(nums, left, pivot - 1 );
    quickSort(nums, pivot + 1, right);
}
int main(){
	vector<int> nums = {4,5,2,6,8,7,9};
	quickSort(nums, 0, nums.size() - 1);
	return 0;
}
