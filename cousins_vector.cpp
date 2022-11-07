    vector<int> fun(Node* root , int key)
    {
        vector<int> v;
        queue<Node*> q;
        q.push(root);
        bool f=0;
        while(!q.empty())
        {
            if(f)
            {
                return v;
            }
            int count = q.size();
            v.clear();
            for(int i=0;i<count;i++)
            {
                Node* curr = q.front();
                q.pop();
                if((curr->left && curr->left->data==key) || (curr->right && curr->right->data==key))
                {
                    f=1;
                }
                else
                {
                    if(curr->left)
                    {
                        q.push(curr->left);
                        v.push_back(curr->left->data);
                    }
                    if(curr->right)
                    {
                        q.push(curr->right);
                        v.push_back(curr->right->data);
                    }
                }
            }
        }
        return v;
    };
