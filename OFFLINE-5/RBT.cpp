#include <bits/stdc++.h>
#include "color.hpp"
using namespace std;
 ofstream out("output1.txt");
class Node {
    public:
int data;
Node *left,*right,*parent;
char colour;
string str;
Node()
{
    //data = 0;
    left = NULL;
    right = NULL;
    parent = NULL;
   // colour = 'b';
}

Node(int val,string s1)
{
    data = val;
    left = NULL;
    right = NULL;
    parent = NULL;
    colour = 'r';
    str= s1;
}
void clear_node()
{
    parent = NULL;
    left = NULL;
    right = NULL;
}
bool is_left(Node * node)
{
      if(node->parent != NULL)
    {
        if(node->parent->left == node)
        {
            return true;
        }
        else return false;
    }
    cout<<"no parent"<<endl;
    return false;
}

//    ~Node(){
 //       cout << "Deleted" << endl;
//    }
};
class RBT{
    public:
   int node_no;
    Node *root;
    Node *new_node;
    Node *T_null;
    int  left_left;
   int right_right;
   int left_right;
   int right_left;

     RBT()
    {
        node_no = 0;
        root = NULL;
        new_node = NULL;
        T_null = new Node();
        T_null->data = 0;
        T_null->colour = 'b';
        left_left = 0;
        right_right = 0;
        left_right = 0;
        right_left = 0;
    }
    bool is_left(Node * node)
{
      if(node->parent != NULL)
    {
        if(node->parent->left == node)
        {
            return true;
        }
        else return false;
    }
    cout<<"no parent"<<endl;
    return false;
}
    Node * sibling_return(Node * node)
{
    if(node->parent != NULL)
    {
        if(is_left(node) == false)
        {
            return node->parent->right;
        }
        else
        {
            return node->parent->left;
        }
    }
    cout<<"NO parent"<<endl;
    return NULL;
}
    void left_rotate(Node *x)
    {
        Node *y = x->right;
        x->right = y->left;
        if(y->left != NULL)
        {
            y->left->parent = x;
        }
        y->parent = x->parent;
        if(x->parent == NULL)
        {
            root = y;
        }
        else if(x == x->parent->left)
        {
            x->parent->left = y;
        }
        else{
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;

    }
    void right_rotate(Node *y)
    {
       Node *x = y->left;
        y->left = x->right;
        if(x->right != NULL)
        {
            x->right->parent = y;
        }
        x->parent = y->parent;
        if(y->parent == NULL)
        {
            root = x;
        }
        else if(y == y->parent->right)
        {
            y->parent->right = x;
        }
        else{
            y->parent->left = x;
        }
        x->right = y;
        y->parent = x;
    }
    void recolour(Node *node)
    {
        if(node->colour == 'b')
        {
            node->colour = 'r';
        }
        else
        node->colour = 'b';
    }
   /*  Node* rotate_left(Node * node)
    {
        Node* x = node
    } */
    void balance_tree(Node * new_node1)
    {
       // CASE A
        if(new_node1->parent->colour == 'b')
        {
            return;
        }
        else{
            Node * uncle;
            int is_parent_left_child = 0;
            int is_parent_right_child = 0;
            int is_new_node_left_child = 0;
            int is_new_node_right_child = 0;
            Node *parent;
           parent = new_node1->parent;
            //if(parent == parent->parent)
            if(new_node1 == parent->left)
            {
                is_new_node_left_child = 1;
            }
            else{
                is_new_node_right_child = 1;
            }
            //IF PARENT IS RIGHT CHILD OF GP
            if(new_node1->parent == new_node1->parent->parent->right)
            {
                uncle = new_node->parent->parent->left;
                is_parent_right_child = 1;
            }
            //IF PARENT IS left CHILD OF GP
            else{
                uncle = new_node1->parent->parent->right;
                is_parent_left_child = 1;
            }

            if(uncle == NULL || uncle->colour == 'b')
            {
            //SUITABLE ROTATION AND RECOLOUR
            Node *gp = parent->parent;
            Node *gp1 = parent->parent;
//IF NEW NODE IS RIGHT CHILD AND PARENT IS LEFT CHILD
            if(is_parent_left_child == 1 && is_new_node_right_child == 1 )
            {
                    //1ST DO LR ON PARENT
                    left_rotate(parent);
                    // DO RR ON GP
                    right_rotate(gp);
                    //recolour
                    recolour(gp1);
                    recolour(new_node1);

            }

            ///IF NEW NODE IS LEFT CHILD AND PARENT IS RIGHT CHILD
            else if(is_parent_right_child == 1 && is_new_node_left_child == 1)
            {
                 //1ST DO RR ON PARENT
                    right_rotate(parent);
                    // DO LR ON GP
                    left_rotate(gp);
                    //recolour
                    recolour(gp1);
                    recolour(new_node1);
            }
         ///IF NEW NODE IS RIGHT CHILD AND PARENT IS RIGHT CHILD
         else if(is_parent_right_child == 1 && is_new_node_right_child == 1)
         {
            left_rotate(gp);
            recolour(gp1);
            recolour(parent);
         }
         else if(is_parent_left_child == 1 && is_new_node_left_child == 1){
             right_rotate(gp);
            recolour(gp1);
            recolour(parent);

         }
            }
            //UNCLE COLOUR IS RED
            else{
                recolour(uncle);
                recolour(new_node1->parent);
                if(new_node1->parent->parent == root)
                {
                    return;
                }
                else{
                    recolour(new_node1->parent->parent);
                    balance_tree(new_node1->parent->parent);
                }
            }

        }
    }
Node* helpInsert(Node *root,int v,string s)//Node *root,int v)
{
    if(root == NULL)
    {
        new_node = new Node(v,s);
        return new_node;
       // return new Node(v);
    }
    else if(v == root->data)
    {
        root->str = s;
    }
   else if(v<root->data)
    {
     root->left = helpInsert(root->left,v,s);
     root->left->parent = root;
    }
    else
    {
        root->right = helpInsert(root->right,v,s);
         root->right->parent = root;
    }
    return root;
}
void insert(int data,string s1)
{
    if(root == NULL)
    {
        root = new Node(data,s1);
        node_no++;
        root->colour = 'b';
    }
    else
    {
        root = helpInsert(root,data,s1);
        node_no++;
        //balance tree
        balance_tree(new_node);
    }
}
void inorder(Node *root1)
{
if(root1 == NULL)
return ;
inorder(root1->left);
if(root1->colour == 'r')
{
    cout<<root1->data<<" ";
    
    cout << dye::red(root1->str);
    cout<<endl;
}
else
{
    cout<<root1->data<<" ";
    cout << dye::black(root1->str);
    cout<<endl;
}
// if(root1->parent !=  NULL)
// {
//   cout<<  root1->parent->data ;
// }

inorder(root1->right);
}
void preorder(Node *root1)
{
if(root1 == NULL)
return ;
if(root1->colour == 'r')
{
    cout<<root1->data<<" ";
    cout << dye::red(root1->str);
    
}
else
{
    cout<<root1->data<<" ";
    cout << dye::black(root1->str);
}

if(root1->left!= NULL || root1->right != NULL)
{
    cout<<"(";
}
preorder(root1->left);
if(root1->left!= NULL || root1->right != NULL)
{
    cout<<",";
}
preorder(root1->right);
if(root1->left!= NULL || root1->right != NULL)
{
    cout<<")";
}
}
int size()
 {
    return node_no;
 }
 bool is_empty()
 {
    if(node_no == 0)
    {
        return true;
    }
    else
    return false;
 }
 bool search(Node *root1, int k)
{
   if(root1 == NULL)
   {
    return false;
   }
   if(root1->data == k)
   {
    return true;
   }
   else if(root1->data> k)
   {
     search(  root1->left,k);
   }
   else
    search(root1->right,  k);
}
Node * find_node(Node * root_for_find,int key)
{
  Node * curr = root_for_find;
  while(curr != NULL)
  {
    if(curr->data == key)
    {
        return curr;
    }
    else if(curr->data > key)
    {
        curr = curr->left;
    }
    else{
        curr = curr->right;
    }
     }
     return curr;
}
void pointer_change(Node *deleting_node ,Node *replacing_node)

{
if(deleting_node->parent == NULL)
{
    root = replacing_node;

}
else if(deleting_node == deleting_node->parent->left)
{
    deleting_node->parent->left = replacing_node;
}
else{
    deleting_node->parent->right = replacing_node;
}
//cout << "Here ?" << endl;
replacing_node->parent = deleting_node->parent;
//cout << "Here ?" << endl;
}
Node *inorderSucc(Node * node1)
{
    Node * curr = node1;
    while (curr != NULL && curr->left != NULL)
    {
       curr = curr->left;
        /* code */
    }
    return curr;
}
  
//   //node1 == NULL ? cout<<"NULL"<<endl:cout<<"not NULL"<<endl;
//   Node *z ;

//   Node *x ;
//   Node *y ;


//    if(search(root,data) == true)
//    {
//       while(1)
//    {
//     //node1 == NULL ? cout<<"NULL"<<endl:cout<<"not NULL"<<endl;
//     if(node1->data == data)
//     {
//         z = node1;
//         break;
//     }
//     else if(node1->data >= data)
//     {
//         node1 = node1->left;
//     }
//     else
//     {
//         node1 = node1->right;
//     }
//   }
//    }
//    else
//    {
//     cout<<"key not found"<<endl;
//     return;
//    }
//    y = z;
//    cout<<z->data<<endl;
//    char real_colour_y = y->colour;
//    if (z->right == NULL && z->left != NULL) {
//       x = z->left;
//       pointer_change(z, z->left);
//       //cout << "Here ?" << endl;
//     }

//    else  if (z->left == NULL && z->right != NULL) {
//       x = z->right;
//       pointer_change(z, z->right);
//       //cout << "Here ?" << endl;
//     }
//     else if(z->left != NULL && z->right != NULL){
//         y = inorderSucc(z->right);
//         real_colour_y = y->colour;
//         x = y->right;
//         if(y->parent == z)
//         {
//             x->parent = y;
//         } else{
//             if(y->right != NULL)
//             {
//                 pointer_change(y,y->right);
//             }

//             //cout << "Here ?" << endl;
//             y->right = z->right;
//             y->right->parent = y;
//         }
//         pointer_change(z,y);
//        // cout << "Here ?" << endl;
//         y->left  = z->left;
//         if(y->left != NULL)
//         {
//              y->left->parent = y;
//         }
//         y->left->parent = y;
//         y->colour = z->colour;
//     }
//     else{
//         if(z == root)
//         {
//             root = NULL;
//         }
//         else
//         {
//          if(z->parent->left == z)
//          {
//             z->parent->left = NULL;
//          }
//          else{
//              z->parent->right = NULL;
//          }
//         }
//     }
//       delete z;
bool is_black(Node * node)
{
    if(node == NULL)
    {
        return true;
    }
    else if(node->colour == 'b')
    {
        return true;
    }
    else
    return false;
}
void delete_fix(Node * replacing)
{
    Node * sibling = sibling_return(replacing);
    while(replacing != root && replacing->colour == 'b')
    {
        if(replacing == replacing->parent->left)
        {
            sibling = replacing->parent->right;
            if(sibling->colour == 'r')
            {
                sibling->colour = 'b';
                replacing->parent->colour = 'r';
                left_rotate(replacing->parent);
                sibling = replacing->parent->right;
            }
            if(is_black(sibling->left) == true &&  is_black(sibling->right) == true)
            {   
                sibling->colour = 'r';
                replacing = replacing->parent;
                continue;
            }
            else if(is_black(sibling->right))
            {
                sibling->left->colour = 'b';
                sibling->colour = 'r';
                right_rotate(sibling);
                sibling = replacing->parent->right;
            }
            sibling->colour = replacing->parent->colour;
        replacing->parent->colour = 'b';
        sibling->right->colour = 'b';
        left_rotate(replacing->parent);
        replacing = root;
        }
        
            else
        {
            sibling = replacing->parent->left;
            if(sibling->colour == 'r')
            {
                sibling->colour = 'b';
                replacing->parent->colour = 'r';
                right_rotate(replacing->parent);
                sibling = replacing->parent->left;
            }
            if(is_black(sibling->right) == true &&  is_black(sibling->right) == true)
            {   
                sibling->colour = 'r';
                replacing = replacing->parent;
            }
            else if(is_black(sibling->left))
            {
                sibling->right->colour = 'b';
                sibling->colour = 'r';
                left_rotate(sibling);
                sibling = replacing->parent->left;
            }
            sibling->colour = replacing->parent->colour;
        replacing->parent->colour = 'b';
        sibling->left->colour = 'b';
        right_rotate(replacing->parent);
        replacing = root;
        }
            
        

    }
    replacing->colour = 'b';
}
void helper_delete(Node * deleting_node)

 {
    Node * successor ;
    Node * replacing;
    if(deleting_node->left == NULL && deleting_node->right == NULL)
    {
        deleting_node->right = T_null;
        T_null->parent = deleting_node;
        successor = deleting_node;
        replacing = T_null;
        pointer_change(successor,replacing);
    }
    else if(deleting_node->left != NULL && deleting_node->right == NULL)
    {
        successor = deleting_node;
        replacing  = deleting_node->left;
        pointer_change(successor,replacing);

    }
    else if(deleting_node->left == NULL && deleting_node->right != NULL)
    {
        successor = deleting_node;
        replacing  = deleting_node->right;
        pointer_change(successor,replacing);

    }
    else{
        successor = inorderSucc(deleting_node->right);
        if(successor ->right == NULL)
        {
            T_null ->parent = successor;
            successor->right = T_null;
        }
        replacing = successor->right;
        pointer_change(successor,replacing);
        deleting_node->data = successor->data;
        deleting_node ->str = successor->str;

    }
    if(successor->colour == 'b')
    {
    delete_fix(replacing);
 }
    if(T_null->parent!= NULL)
    {
        if(T_null->parent->left == T_null)
        {
            T_null->parent->left = NULL;
        }
        else
        {
            T_null->parent->right = NULL;
        }
    }
    T_null->parent = NULL;
 }

void delete_RBT(int data)
{
    Node * deleting_node = find_node(root,data);
    if(deleting_node != NULL)
    {
     helper_delete(deleting_node);
     node_no--;
    }
    else{
        cout<<data<<" not found"<<endl;
    }

}
void clear(Node * root_clear)
{
    if(root_clear == NULL)
    {
        return;
    }
    clear(root_clear->left);
clear(root_clear->right);
 //delete_RBT( root_clear->data);
 root_clear->clear_node();
 root_clear = NULL;

}
void is_clear()
    {
        if(node_no == 0)
        {
            cout<<"unsuccessful"<<endl;
        }
        else{
           clear(root);
           root = NULL;
           cout<<"successful"<<endl;
           node_no = 0;

        }
    }
};
// int main()
// {
//     RBT tree;
//     // Node * n1 = new Node(10);
//     // Node * n2 = new Node(50);
//     // n1->left = n2;
//     // cout << n1->left->data << endl;
//     // delete n2;
//     // if (n2==NULL) cout << "Hola" << endl;
//      tree.insert(10,"Th");
//      tree.insert(34,"q");
//      tree.insert(43,"p");

//        tree.insert(15,"t");
//         tree.insert(40,"o");
//         tree.insert(53,"m");
//         tree.insert(90,"n");
//         tree.insert(12,"k");
//         tree.insert(78,"k");
//          tree.preorder(tree.root);
//          cout<<endl;
//         tree.delete_RBT(40);
//         //tree.delete_RBT(78);
//         tree.preorder(tree.root);
//         tree.delete_RBT(78);
//          cout<<endl;
//         tree.preorder(tree.root);
//         tree.delete_RBT(12);
//          cout<<endl;
//         tree.preorder(tree.root);
//         tree.delete_RBT(43);
//          cout<<"del 43"<<endl;
//         tree.preorder(tree.root);
//         tree.is_clear();
//         cout<<tree.size()<<endl;
//         tree.inorder(tree.root);
// }
        //  cout<<endl;
        //  tree.delete_RBT(56);
        
//         // tree.preorder(tree.root);
//        //tree.inorder(tree.root);
//     //    cout<<tree.search(tree.root,16)<<endl;
//     //     cout<<tree.search(tree.root,17)<<endl;
//     //     cout<<tree.size()<<endl;
// //  tree.insert(50);
// //      tree.insert(30);
// //      tree.insert(20);

// //        tree.insert(40);
// //         tree.insert(70);
// //         tree.insert(60);

//         // tree.insert(25);
//         // tree.insert(40);
//         //  tree.delete_RBT(20);
//         //  //cout<<"h"<<endl;
//         //  tree.delete_RBT(70);
//         //  tree.delete_RBT(50);
//         // tree.insert(10,"Th");
//         // tree.insert(34,"Ca");
//         // int data;
//         // string str;
//         // char c;
//         // for(int i = 0;i<9;i++)
//         // {
//         //     cin>>c>>data>>str;
//         //     tree.insert(data,str);
//         // }
//         // tree.preorder(tree.root);
//     // Node * node =     tree.find_node(tree.root,53);
//     // if(node == NULL)
//     // {
//     //     cout<<"NUll";
//     // }
//     // else{
//     //     cout<<node->data;
//     // }


// }
