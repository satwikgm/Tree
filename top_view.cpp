struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        map<int,int> m;  // First for hd and second for root->val
        queue<pair<Node*,int>> q;  
        q.push({root,0});
        while(!q.empty())
        {
            pair<Node*,int> temp = q.front();  
            q.pop();
            Node* curr = temp.first;
            int hd = temp.second;
            if(m.find(hd) == m.end())
            {
                m[hd]=curr->data;
            }
            if(curr->left)
            {
                q.push({curr->left,hd-1});
            }
            if(curr->right)
            {
                q.push({curr->right,hd+1});
            }
        }
        vector<int> ans;
        for(auto it : m)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};
