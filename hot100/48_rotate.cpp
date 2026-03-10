#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//做这种题你先看旋转之后的坐标怎么变化的，比如这题是：(i,j)->(j,n-1-i)
//那么就拆分成了，(i,j)->(j,i)->(j,n-1-i)，前一步是通过矩阵转置，后一步是相当于根据中轴翻转，同理如果是j变成n-1-j就是上下翻转

class Solution 
{
public:
#if 0
    void rotate(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();

        //矩阵转置
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < i; j++) //遍历的是对角线下方
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        //左右翻转,这种也叫行翻转（即水平翻转，将每一行的元素顺序反转）
        for (auto& row : matrix) //遍历每一行
        {
            ranges::reverse(row);
        }
    }
#else
    //如果修改为遍历的是对角线的上方，那么转置完一行，则全完成了转置，所以可以，边转置边翻转
    void rotate(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();

        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = i+1; j < n; j++) //这部分就是矩阵对角线的上半部分
            {
                swap(matrix[i][j],matrix[j][i]);
            }
            ranges::reverse(matrix[i]);
        }
        
    }
#endif
};