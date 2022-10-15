
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

//Function to return a list containing elements of left view of the binary tree.
void printLeft(Node* root , vector<int> &vec , int level , int &maxLevel)
{
    if(root==NULL)
    {
        return;
    }
    if(maxLevel<level)
    {
        vec.push_back(root->data);
        maxLevel=level;
    }
    printLeft(root->left,vec,level+1 , maxLevel);
    printLeft(root->right,vec,level+1,maxLevel);
}
vector<int> leftView(Node *root)
{
   vector<int> v;
   int maxL=0;
   printLeft(root,v,1,maxL);
   return v;
}
