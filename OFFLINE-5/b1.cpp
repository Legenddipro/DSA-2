#include<iostream>
#include <fstream>
#include <string>
using namespace std;
 ofstream out("output1.txt");
class Node {
    public:
int data;
Node *left,*right;
Node(int val)
{
    data = val;
    left = NULL;
    right = NULL;

}
};
class Bst{
    public:
Node* insert(Node *root,int v)
{
    if(root == NULL)
    {
        return new Node(v);
    }
   else if(v<root->data)
    {
     root->left = insert(root->left,v);
    }
    else
    {
        root->right = insert(root->right,v);
    }
    return root;
}
void inorder(Node *root)
{
if(root == NULL)
return ;
inorder(root->left);
out<< root->data<<" ";
inorder(root->right);
}
void preorder(Node *root)
{
if(root == NULL)
return ;
out<< root->data<<" ";
preorder(root->left);

preorder(root->right);
}
void postorder(Node *root)
{
if(root == NULL)
return ;
postorder(root->left);
postorder(root->right);
out<< root->data<<" ";

}
Node * search(Node *root, int k)
{
   if(root == NULL)
   {
    return NULL;
   }
   if(root->data == k)
   {
    return root;
   }
   else if(root->data> k)
   {
    return search(root->left,  k);
   }
   else
   return search(root->right,  k);
}
Node *inorderSucc(Node * root)
{
    Node * curr = root;
    while (curr != NULL && curr->left != NULL)
    {
       curr = curr->left;
        /* code */
    }
    return curr;
}
Node *deleteBst(Node * root, int k)
{
    if(k < root->data  )
    {
        root->left = deleteBst(root->left,k);
    }
    else if (k > root->data)
    {
       root->right = deleteBst(root->right,k);
    }
    else if (k == root->data)
    {
        if(root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        Node *temp = inorderSucc(root->right);
        root->data = temp->data;
        root->right = deleteBst(root->right,temp->data);


    }

    return root;
}
void show(Node *root)
{
if(root == NULL)
return ;

out<< root->data;
if(root->left == NULL && root->right == NULL)
{
    return;
}
out<<"(";
show(root->left);
out<<",";
show(root->right);
out<<")";
}
};