#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

class Solution 
{
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int mat_row=matrix.size();//因为mat是容器里面，每一行都是一个元素，所以第一层的size就是有多少行
        int mat_col=matrix[0].size();
        
        vector<int> row_has_zero(mat_row,1);//记录行坐标为0
        vector<int> col_has_zero(mat_col,1);//记录列坐标为0

#if 1   //方法一：用额外空间
        for (int i = 0; i < mat_row; i++)
        {
            for (int j = 0; j < mat_col; j++)
            {
                if (matrix[i][j]==0)
                {
                    row_has_zero[i]=col_has_zero[j]=0;
                }
            }
            
        }

        for (int i = 0; i < mat_row; i++)
        {
            for (int j = 0; j < mat_col; j++)
            {
                if (row_has_zero[i]==0 || col_has_zero[j]==0)
                {
                    matrix[i][j]=0;
                }
            }
            
        }
        
#else
#endif
    }
};

int main()
{
    vector<vector<int>> mat={{1,1,1},{1,0,1},{1,1,1}};
    Solution test;
    test.setZeroes(mat);

    return 0;

}
