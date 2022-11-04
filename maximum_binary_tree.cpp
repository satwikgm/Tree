/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* fun(vector<int> &arr , int l , int r)
    {
        if(l>r)
        {
            return NULL;
        }
        int max_i = l;
        for(int i=l;i<=r;i++)
        {
            if(arr[i] > arr[max_i])
            {
                max_i = i;
            }
        }
        TreeNode* root = new TreeNode(arr[max_i]);
        root->left = fun(arr , l , max_i-1);
        root->right = fun(arr , max_i+1 , r);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) 
    {
        return fun(nums,0,nums.size()-1);
    }
};
