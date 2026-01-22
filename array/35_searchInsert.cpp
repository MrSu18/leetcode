//二分法
/*
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

请必须使用时间复杂度为 O(log n) 的算法。
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        int left=0,right=nums.size()-1;//[left,rtight]
        
        while (left<=right)
        {
            int mid=(right+left)/2;
            if (nums[mid]==target)
            {
                return mid;
            }
            else if (nums[mid]>target)
            {
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
        //发现里面没有target，最后一次循环的时候肯定是left=right=mid，
        //如果此时nums[mid]<target的，那left会++,那left的位置就是需要插入的位置,此时nums[left]>target && nums[right]<target
        //如果此时nums[mid]>target的，那right会--，意味着nums[left]>target，而nums[right]<target所以还是left
        return left;//简单来说，循环结束时 left和 right的关系是 left = right + 1，而插入位置永远是 left所指向的位置
    }
};

int main()
{
    Solution test;
    vector<int> nums = {1,3,5,6};
    int target = 2;
    cout<<test.searchInsert(nums,target)<<endl;
    return 0;
}

