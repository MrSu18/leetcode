#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//递归版本
class Solution 
{
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> result;
        traveltree(root,result);
        return result;
    }
private:
    void traveltree(TreeNode* root, vector<int> &result)
    {
        if (root==nullptr)
        {
            return;
        }
        
        traveltree(root->left,result);
        result.push_back(root->val);
        traveltree(root->right,result);
    }
};

//迭代写法
class Solution 
{
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while(cur!=nullptr||!st.empty())
        {
            while(cur!=nullptr)
            {
                st.push(cur);//遍历左边的
                cur=cur->left;
            }
            //一直在左边最下面然后就开始弹栈把结果开始遍历
            cur=st.top();
            st.pop();
            result.push_back(cur->val);
            cur=cur->right;
        }
        return result;
    }
};