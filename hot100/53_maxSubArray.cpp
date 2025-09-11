#include <vector>
#include <iostream>

using namespace std;

class Solution 
{
public:
    int maxSubArray(vector<int>& nums) 
    {
        int s=0,min_s=0;//前缀和和最小前缀和
        int n = nums.size();
        int result=-9999999;
        for (int i = 0; i < n; i++)
        {
            s+=nums[i];
            result = max(result,s-min_s);
            min_s = min(min_s,s);
        }
        return result;
    }
};

int main()
{
    Solution test;
    vector<int> nums = {-1};
    cout<<test.maxSubArray(nums)<<endl;
    return 1;
}
