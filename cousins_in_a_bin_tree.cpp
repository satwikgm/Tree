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
    bool isCousins(TreeNode* root, int x, int y) 
    {
        if(root->val==x || root->val==y)
        {
            return false;
        }    
        queue<TreeNode*> q;
        q.push(root);
        bool f1=0,f2=0;
        while(!q.empty())
        {
            int count = q.size();
            f1=0,f2=0;
            for(int i=0;i<count;i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                if(((curr->left && curr->left->val==x) && (curr->right && curr->right->val==y))   ||  ((curr->left && curr->left->val==y) && (curr->right && curr->right->val==x)) )
                {
                    return false;    // Nodes are siblings 
                }
                else if(curr->left && (curr->left->val==x || curr->left->val==y))
                {
                    // Found one key
                    if(curr->left->val==x)
                    {
                        f1=1;   
                    }
                    if(curr->left->val==y)
                    {
                        f2=1;
                    }
                }
                else if(curr->right && (curr->right->val==x || curr->right->val==y))
                {
                    // Found one key
                    if(curr->right->val==x)
                    {
                        f1=1;
                    }
                    if(curr->right->val==y)
                    {
                        f2=1;
                    }
                }

                if(curr->left)
                {
                    q.push(curr->left);
                    if(f1)
                    {
                        // Found cousin key
                        if(curr->left->val==y)
                        {
                            return true;
                        }
                    }
                    if(f2)
                    {
                        // Found cousin key
                        if(curr->left->val==x)
                        {
                            return true;
                        }
                    }
                }
                if(curr->right)
                {
                    q.push(curr->right);
                    if(f1)
                    {
                        // Found cousin key
                        if(curr->right->val==y)
                        {
                            return true;
                        }
                    }
                    if(f2)
                    {
                        // Found cousin key
                        if(curr->right->val==x)
                        {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};
