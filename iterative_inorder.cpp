/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};*/
class Solution {
public:
    vector<int> inOrder(Node* root)
    {
        vector<int> v;
        if(!root)
        {
            return v;
        }
        stack<Node*> s;
        Node* curr = root;
        while(curr || !s.empty())
        {
            while(curr)
            {
                s.push(curr);
                curr=curr->left;
            }
            curr = s.top();
            s.pop();
            v.push_back(curr->data);
            curr=curr->right;
        }
        return v;
    }
};
