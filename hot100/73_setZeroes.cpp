#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>

using namespace std;

class Solution 
{
public:
#if 0   //方法一：用额外空间
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int mat_row=matrix.size();//因为mat是容器里面，每一行都是一个元素，所以第一层的size就是有多少行
        int mat_col=matrix[0].size();
        
        vector<int> row_has_zero(mat_row,1);//记录行坐标为0
        vector<int> col_has_zero(mat_col,1);//记录列坐标为0

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
    }
#elif 0
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int m = matrix.size(), n = matrix[0].size();
        bool first_row_has_zero = ranges::contains(matrix[0], 0);

        for (int i = 1; i < m; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                if (matrix[i][j] == 0) 
                {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < m; i++) 
        {
            // 倒着遍历，避免提前把 matrix[i][0] 改成 0，误认为这一行要全部变成 0
            for (int j = n - 1; j >= 0; j--) 
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) 
                {
                    matrix[i][j] = 0;
                }
            }
        }

        if (first_row_has_zero) 
        {
            ranges::fill(matrix[0], 0);
        }
    }  
#else
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int mat_row=matrix.size();
        int mat_col=matrix[0].size();

        bool first_row_has_zero = ranges::contains(matrix[0],0);//检测第一行是是否有0

        //第一遍遍历记录0的位置
        for (int i = 1; i < mat_row; i++)//遍历从第二行开始因为第一行用于记录行坐标为0的地方
        {
            for (int j = 0; j < mat_col; j++) //因为遍历第一列的时候这一行还没被遍历，所以这个地方不会有问题
            {
                if (matrix[i][j]==0)
                {
                    matrix[0][j]=matrix[i][0]=0;
                }
            }
            
        }
        
        //记录好之后开始置零,列要倒着遍历，不然第一个记录的值会被修改，让它最后被修改
        for (int i = 1; i < mat_row; i++)
        {
            for (int j = mat_col-1; j >= 0; j--)
            {
                if (matrix[i][0]==0 || matrix[0][j]==0)
                {
                    matrix[i][j]=0;
                }
            }
        }
        
        //最后一步看看第一行要不要全0
        if (first_row_has_zero==true)
        {
            ranges::fill(matrix[0],0);
        }
    }    
#endif
};

int main()
{
    vector<vector<int>> mat={{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    Solution test;
    test.setZeroes(mat);

    return 0;

}
