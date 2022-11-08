/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
// We will be given the key in form of nodes

class Solution {
public:
    bool findPath(TreeNode* root , TreeNode* key , vector<TreeNode*> &path)
    {
        if(!root)
        {
            return false;
        }
        path.push_back(root);
        if(root == key)
        {
            return true;
        }
        if((root->left && findPath(root->left,key,path)) || (root->right && findPath(root->right,key,path)))
        {
            return true;
        }
        path.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        vector<TreeNode*> path1,path2;
        if(!findPath(root,p,path1) || !findPath(root,q,path2))
        {
            return NULL;
        }
        TreeNode* lca=NULL;
        int i;
        for(i=0;i<min(path1.size(),path2.size());i++)
        {
            if(path1[i] != path2[i])
            {
                lca=path1[i-1];
                break;
            }
        }
        if(!lca)
        {
            if(path1.size() <= path2.size())
            {
                lca=path1[i-1];
            }
            else
            {
                lca=path2[i-1];
            }
        }
        return lca;
    }
};
