struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    int sum = 0;
public:
    void fun(TreeNode *root)
    {
        if (root)
        {
            fun(root->right);
            root->val = sum;
            sum += root->val;
            fun(root->left);
        }
    }
    TreeNode* bstToGst(TreeNode* root)
    {
        fun(root);
        return root;
    }
};