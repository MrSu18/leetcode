#include <iostream>
#include <vector>

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