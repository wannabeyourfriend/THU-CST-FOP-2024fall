#include <iostream>
#include <vector>
using namespace std;
int binarySearchInsertion(vector<int> &nums, int target)
{
    int i = 0, j = nums.size() - 1;//[0, n-1]
    while( i <= j ){
        int m = i + (j - i)/2;
        if(nums[m] < target){
            i = m + 1; // target in [m + 1, j]
        } else if (nums[m] > target){
            j = m - 1; // target in [i, m - 1]
        } else{ //这里非常难理解，要注意，在target = nums[m]的时候还是要进行搜索范围的缩小，
            j = m - 1; // target in [i, ]
        }
    }
  	//返回插入点i
    return i;
}

int main()
{
    vector<int> nums = {1,2,2,3,4,5,6,7,8,9};
    int target = 10;
    cout << binarySearchInsertion(nums, target) << endl;
    return 0;
}