/*
给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target ，写一个函数搜索 nums 中的 target，如果 target 存在返回下标，否则返回 -1。
你必须编写一个具有 O(log n) 时间复杂度的算法。
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    int search(vector<int>& nums, int target) 
    {
        int result_index=-1;
        if (nums.empty())//判断数组是不是空的
        {
            return result_index;
        }
        int l_index=0,r_index=nums.size()-1;
        while (l_index<=r_index) //[l,r]
        {
            int mid = (r_index+l_index)/2;
            if (nums[mid]==target)
            {
                result_index=mid;
                break;
            }
            else if (target<nums[mid])
            {
                r_index=mid-1;
            }
            else
            {
                l_index=mid+1;
            }
        }
        
        return result_index;
    }
};


int main()
{
    Solution test;
    vector<int> nums={2,5};
    int target=5;
    cout<<test.search(nums,target)<<endl;
    return 0;
}