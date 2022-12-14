struct Node {
    int data;
    Node* left;
    Node* right;
};

class Solution{
    public:
    vector<int> postOrder(Node* node) 
    {
        vector<int> v;
        if(!node)
        {
            return v;
        }
        stack<Node*> s1,s2;
        s1.push(node);
        while(!s1.empty())
        {
            Node* curr = s1.top();
            s1.pop();
            s2.push(curr);
            if(curr->left)
            {
                s1.push(curr->left);
            }
            if(curr->right)
            {
                s1.push(curr->right);
            }
        }
        while(!s2.empty())
        {
            v.push_back(s2.top()->data);
            s2.pop();
        }
        return v;
    }
};
