#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        int n = nums.size();
        int result = n+1; //初始值为n+1,如果遍历完发现都是排好序了的，那没出现的最小正整数就是n+1
        for (int i = 0; i < n; i++)
        {
            //如果是这个位置没有缺失，那他应该是正确的数字，即：nums[i]=i+1
            // 如果不在正确的位置，那就去把他换到他应该在的位置，就是num[i]的位置，因为C语言是从0开始，所以是nums[i]-1
            //如果当前数字是在[1~n]中，但是不在自己的位置上，就一直swap
            while(1<=nums[i] && nums[i]<=n && nums[i]!=nums[nums[i]-1])
            {
                int j = nums[i]-1;
                swap(nums[i],nums[j]);
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (nums[i]!=i+1)
            {
                result = i+1;
                break;
            }
            
        }
        

        return result;
    }
};

int main()
{
    Solution test;
    vector<int> nums = {1,2,0};
    test.firstMissingPositive(nums);
    return 0;
}
