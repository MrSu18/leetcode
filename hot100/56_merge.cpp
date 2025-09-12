#include <vector>
#include <iostream>
#include <algorithm> // 包含 algorithm 头文件
#include <ranges>    // 包含 ranges 头文件 (C++20)

using namespace std;

class Solution 
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        ranges::sort(intervals);//对intervals进行排序，按照区间左端进行升序排序
        vector<vector<int>> result;
        for (auto &p : intervals)
        {
            if (!result.empty() && p[0]<=result.back()[1])//比较一下现在这个区间的左端点是否小于答案区间里的右边端点，如果是可以合并
            {
                result.back()[1]=max(p[1],result.back()[1]);//右端点是这两个区间的最大值
            }
            else //不相交就不合并，因为之前排序好了，所以这里把当前区间作为回答的第二个元素
            {
                result.push_back(p);
            }
        }
        return result;
    }
};

int main()
{
    Solution test;
    vector<vector<int>> intervals = {{1,3},{11,17},{8,10},{15,18}};
    test.merge(intervals);
    return 0;
}


