#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int mat_h = matrix.size(),mat_w = matrix[0].size();
        int i = 0, j = mat_w-1;//从右上角开始

        while (i<mat_h && j>=0)
        {
            if (matrix[i][j]==target)
            {
                return true;
            }
            else if(matrix[i][j]>target)//如果比目标要大的话，最后一列所有的数字都要比target要大
            {
                j--;
            }
            else if(matrix[i][j]<target)//如果比目标要笑，那么这一行的所有数字都比target要小
            {
                i++;
            }
        }
        return false;
    }
};

int main()
{
    Solution test;
    vector<vector<int>> mat={{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    test.searchMatrix(mat,5);
    return 0;
}
