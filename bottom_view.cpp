class Solution {
  public:
    vector <int> bottomView(Node *root) 
    {
        vector<int> ans;
        if(!root)
        {
            return ans;
        }
        queue<pair<Node*,int>> q;
        map<int,int> m;  // first for horizontal distance and sec for root->val
        q.push({root,0});
        while(!q.empty())
        {
            pair<Node*,int> temp = q.front();
            q.pop();
            Node* curr = temp.first;
            int hd = temp.second;
            m[hd]=curr->data;
            if(curr->left)
            {
                q.push({curr->left,hd-1});
            }
            if(curr->right)
            {
                q.push({curr->right,hd+1});
            }
        }
        for(auto it : m)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};
