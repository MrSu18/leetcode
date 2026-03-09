#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        vector<vector<int>> dir={{0,1},{1,0},{0,-1},{-1,0}};//记录遍历的方向

        int mat_h=matrix.size();
        int mat_w=matrix[0].size();
        int count=0;
        uint8_t i=0;//用于记录方向数组的下标 i=(i+1)%4
        vector<int> result(mat_h*mat_w);

        for(int x=0,y=0;count<mat_h*mat_w;x+=dir[i][1],y+=dir[i][0])
        {
            // if (x>=0 && x<mat_w && y>=0 && y<mat_h && matrix[x][y]!=-200) //边界判断
            // {
            //     result[count]=matrix[x][y];
            //     matrix[x][y]=-200;//遍历过了标记一下
            //     count++;
            // }
            // else
            // {
            //     i=(i+1)%4;//否则不满足上面的情况就转向
            // }

            result[count]=matrix[y][x];
            matrix[y][x]=-200;//遍历过了标记一下
            count++;

            int temp_x=x+dir[i][1];
            int temp_y=y+dir[i][0];

            if (temp_x<0 || temp_x >=mat_w || temp_y<0 || temp_y>=mat_h || matrix[temp_y][temp_x]==-200)
            {
                i=(i+1)%4;//否则不满足上面的情况就转向
            }
            
            
        }
        
        return result;
    }
};


int main()
{
    Solution test;

    vector<vector<int>> mat = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};

    vector<int> test_vector = test.spiralOrder(mat);

    for (size_t i = 0; i < test_vector.size(); i++)
    {
        cout<<test_vector[i]<<' ';
    }
    

    return 0;
}

