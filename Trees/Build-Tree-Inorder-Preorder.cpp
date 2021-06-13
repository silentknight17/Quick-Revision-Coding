/* Question---> Given Preorder and Inorder traversals of a tree; we have to build to a Binary Tree.

Algorithm---> 1) We initialise an index idx which stores the index we are at while traversing the preorder traversal.
Now, we initialise two variables start =0 and end= (size of array-1). Now in the inorder array, we search for the element at index idx.
Once we find that value, we are quite sure that the left subtree will consist of the elements in inorder array from start to pos-1.
The right subtree will consist of the elements in the inorder array from pos+1 to end. */

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};

void inorder(Node*root)
{
    if(root==NULL)
    return;
    inorder(root->left);
    cout<<root->data;
    inorder(root->right);
}
int position(int in[],int curr,int start,int end)
{
    for(int i=start;i<=end;i++)
    {
        if(in[i]==curr)
        return i;
    }
    return -1;
}
Node* buildTree(int pre[],int in[],int start,int end)
{
    static int idx=0;
    if(start>end)
    return NULL;
    
    int x=pre[idx];
    idx++;
    Node* n=new Node(x);
    if(start==end)
    return n;
    
    int pos=position(in,x,start,end);
    n->left=buildTree(pre,in,start,pos-1);
    n->right=buildTree(pre,in,pos+1,end);
    return n;
}


int main()
{
    int n;
    cin>>n;
    int pre[n];
    int in[n];
    for(int i=0;i<n;i++)
    {
        cin>>pre[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>in[i];
    }
    Node* root=buildTree(pre,in,0,n-1);
    inorder(root);
    return  0;
}
