struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution
{
  public:
    //Function to check if S is a subtree of tree T.
    bool fun(Node* r1 , Node* r2)
    {
        if(!r1 && !r2)
        {
            return true;
        }
        else if(!r1 || !r2)
        {
            return false;
        }
        return r1->data==r2->data && fun(r1->left,r2->left) && fun(r1->right,r2->right);
    }
    bool isSubTree(Node* T, Node* S) 
    {
        if(!S)
        {
            return true;
        }
        if(!T)
        {
            return false;
        }
        if(fun(T,S))
        {
            return true;
        }
        return isSubTree(T->left,S) || isSubTree(T->right,S);
    }
};
