#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int n = nums.size();
        
        vector<int> pre(n,1);
        for (int i = 1; i < n; i++) //定义 pre[i] 表示从 nums[0] 到 nums[i−1] 的乘积。
        {
            pre[i]=pre[i-1]*nums[i-1];
        }

        vector<int> suf(n,1);
        for (int i = n-2; i >= 0; i--) //定义 suf[i] 表示从 nums[i+1] 到 nums[n−1] 的乘积。
        {
            suf[i]=suf[i+1]*nums[i+1];
        }
        
        vector<int> result(n);
        for (int i = 0; i < n; i++)
        {
            result[i]=pre[i]*suf[i];
        }

        return result;
        
    }
};

int main()
{
    Solution test;
    vector<int> nums = {1,2,3,4};
    test.productExceptSelf(nums);
}
