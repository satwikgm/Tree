struct Node
{
  int data;
  Node *left,  *right;
  Node *nextRight;  // This has garbage value in input trees
};

class Solution
{
    public:
    //Function to connect nodes at same level.
    void connect(Node *root)
    {
        if(!root)
        {
            return;
        }
       queue<Node*> q;
       q.push(root);
       while(!q.empty())
       {
           int count = q.size();
           for(int i=0;i<count;i++)
           {
               Node* curr = q.front();
               q.pop();
               if(i==count-1)
               {
                   curr->nextRight=NULL;
               }
               else
               {
                   curr->nextRight=q.front();
               }
               if(curr->left)
               {
                   q.push(curr->left);
               }
               if(curr->right)
               {
                   q.push(curr->right);
               }
           }
       }
    }    
      
};
