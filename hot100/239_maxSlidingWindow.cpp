#include <vector>
#include <iostream>
#include <deque>

using namespace std;

class Solution 
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        int n = nums.size();
        vector<int> result(n-k+1);
        deque<int> q;//使用双端队列存储下标，并且这个队列从左到右是单调递减的
        for (int i = 0; i < n; i++)
        {
            // 1. 进入窗口
            while(!q.empty() && nums[q.back()]<nums[i])
            {
                q.pop_back();
            }
            q.push_back(i);
            // 2. 离开窗口
            int left=i-k+1;//窗口左边的下标
            if (left>q.front() && left>=0)
            {
                q.pop_front();
            }
            
            // 3.放入结果
            if (left>=0)
            {
                result[left]=nums[q.front()];//因为是单调递减的，所以只需要记录队头的数值就是最大的
            }
        }
        return result;
    }
};

int main ()
{
    vector<int> nums={1,3,-1,-3,5,3,6,7};
    int k = 3;
    Solution test;
    test.maxSlidingWindow(nums,k);
    cout <<"hello"<<endl;
}
