struct Node {
    int data;
    Node* left;
    Node* right;
};

class Solution{
    public:
    vector<int> preOrder(Node* root)
    {
        vector<int> preorder;
        stack<Node*> s;
        s.push(root);
        while(!s.empty())
        {
            Node* curr = s.top();
            s.pop();
            preorder.push_back(curr->data);
            if(curr->right)
            {
                s.push(curr->right);
            }
            if(curr->left)
            {
                s.push(curr->left);
            }
        }
        return preorder;
    }
};
