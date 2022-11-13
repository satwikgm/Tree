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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>> ans;
        if(!root)
        {
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        // rev=1 for even level and rev=0 for odd levels
        bool rev=0;
        while(!q.empty())
        {
            int count = q.size();
            vector<int> v(count,0);
            for(int i=0;i<count;i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                // if rev is true elements addition starts from last else it starts from beginning
                int index = rev ? count-i-1 : i;
                v[index] = curr->val;
                if(curr->left)
                {
                    q.push(curr->left);
                }
                if(curr->right)
                {
                    q.push(curr->right);
                }
            }
            ans.push_back(v);
            rev = !rev;
        }
        return ans;
    }
};