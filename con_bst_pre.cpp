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
/* Updated This File*/

class Solution {
public:
    int preIndex=0;
    TreeNode* fun(vector<int>& pre , vector<int> &in , int s , int e)
    {
        if(s>e)
        {
            return NULL;
        }
        TreeNode* root = new TreeNode(pre[preIndex++]);
        int i;
        for(i=s;i<=e;i++)
        {
            if(root->val == in[i])
            {
                break;
            }
        }
        root->left = fun(pre,in,s,i-1);
        root->right = fun(pre,in,i+1,e);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) 
    {
        vector<int> inorder = preorder;
        sort(inorder.begin(),inorder.end());
        return fun(preorder,inorder ,0,preorder.size()-1);
    }
};
