#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int leftBorder = getLeftBorder(nums, target);
        int rightBorder = getRightBorder(nums, target);
        // 情况一
        if (leftBorder == -2 || rightBorder == -2) return {-1, -1};
        // 情况三
        if (rightBorder - leftBorder > 1) return {leftBorder + 1, rightBorder - 1};
        // 情况二
        return {-1, -1};
    }
private:
    int getRightBorder(vector<int>&nums,int target)//找到最后一个target的右边那个值
    {
        int left=0,right=nums.size()-1;
        int right_border=-1;//如果target在区间的左边的画，right_border有可能是-1
        while (left<=right)
        {
            int mid=(left+right)/2;
            if (nums[mid]>target)
            {
                right=mid-1;//taget在左区间，所以[left,mid-1]
            }
            else //当nums[mid]==target的时候，要找到最后一个target，所以要找的可能在右区间，或者自己，如果这里自己是最后一个target，那么left只会比最后一个target多1而已。不会再继续往右边找，只会往左缩小
            {
                left=mid+1;
                right_border=left; //这个地方left会一直停在最后一个target位置的下一个而已
            }
        }
        return right_border;
    }
    int getLeftBorder(vector<int>& nums,int target) //找到第一个target的左边那个值
    {
        int left=0,right=nums.size()-1;
        int left_border=-1;
        while (left<=right)
        {
            int mid=(left+right)/2;
            if (nums[mid]<target)
            {
                left=mid+1;//taget在左区间，所以[left,mid-1]
            }
            else //当nums[mid]==target的时候，要找到最后一个target，所以要找的可能在右区间，或者自己，如果这里自己是最后一个target，那么left只会比最后一个target多1而已。不会再继续往右边找，只会往左缩小
            {
                right=mid-1;
                left_border=right; //这个地方left会一直停在最后一个target位置的下一个而已
            }
        }
        return left_border;
    }

};

int main()
{
    Solution test;
    vector<int> nums = {5,7,7,8,8,10};
    int target = 5;
    test.searchRange(nums,target);
}
