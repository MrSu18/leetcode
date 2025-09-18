#include <vector>
#include <iostream>
#include <algorithm>
#include <ranges>    // 包含 ranges 头文件 (C++20)

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        k=k%nums.size();
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};

int main()
{
    Solution test;
    vector<int> nums = {-1};
    test.rotate(nums,2);
    return 0;
}
