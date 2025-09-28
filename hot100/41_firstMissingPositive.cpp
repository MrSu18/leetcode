#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        int n = nums.size();
        int result = n+1;
        for (int i = 0; i < n; i++)
        {
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
