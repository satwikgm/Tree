#include <bits/stdc++.h>
using namespace std;
 
// A Binary Tree Node
struct Node 
{
    int data;
    struct Node *left, *right;
};
 
// A utility function to create a new
// Binary Tree Node
struct Node* newNode(int item)
{
    struct Node* temp = new Node();
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}
 
// Function to find sum of cousins of
// a given node.
int sumOfCousin(Node *root, int key)
{
    if (!root)
    {
        return -1;
    }
    if (root->data == key)
    {
        return -1;
    }
    queue<Node *> q;
    q.push(root);
    int count;
    int cousinSum = 0;
    bool foundKey = false;
    while (!q.empty())
    {
        if(foundKey)
        {
            return cousinSum;
        }
        count = q.size();
        cousinSum = 0;
        for (int i = 0; i < count; i++)
        {
            Node *curr = q.front();
            q.pop();
            if ((curr->left && curr->left->data == key) || (curr->right && curr->right->data == key))
            {
                foundKey = true;
            }
            else
            {
                if (curr->left)
                {
                    q.push(curr->left);
                    cousinSum += curr->left->data;
                }
                if (curr->right)
                {
                    q.push(curr->right);
                    cousinSum += curr->right->data;
                }
            }
        }
    }
    return -1;
}

 
// Driver Code
int main()
{
    /*
                1
              /  \
             3    7
           /  \  / \
          6   5  4  13
             /  / \
            10 17 15
    */
 
    struct Node* root = newNode(1);
    root->left = newNode(3);
    root->right = newNode(7);
    root->left->left = newNode(6);
    root->left->right = newNode(5);
    root->left->right->left = newNode(10);
    root->right->left = newNode(4);
    root->right->right = newNode(13);
    root->right->left->left = newNode(17);
    root->right->left->right = newNode(15);
 
    cout << sumOfCousin(root, 13) << "\n";
    return 0;
}
