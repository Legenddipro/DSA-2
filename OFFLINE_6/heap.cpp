#include<bits/stdc++.h>
using namespace std;
//node create

class Node
{
    public:
    int rank;
    Node * parent;
    Node *left;
    Node * right;
    Node * child;
    int value;
    int key;
    bool marked;
    Node ()
    {

    }
    Node(int key,int value)
    {
        this->key = key;
        this->value = value;
    }
};
unordered_map <int,Node *> mp;
class FibonacciHeap
{
    public:
    int no_node_in_root_list;
    Node *max_node;
    Node * root_list;
    int node_count;
   // Node * array_node [100000];
    FibonacciHeap()
    {
        no_node_in_root_list = 0;
        max_node = NULL;
        root_list = NULL;
        node_count = 0;
    }
    bool is_empty();
    void junk_insert(int key,int value);
    void insert(int key,int value);
    void merge_with_list(Node * node);
    void show();
    void ready_for_insert(Node * node);
    Node * extract_max();
    void delete_from_root_list(Node * node);
    void consolidate();
    void meld (FibonacciHeap &fh2);
    void link_heap(Node * node_y,Node * node_x);
    void combine_with_child_list(Node * parent,Node *child);
    void show_child(Node * parent);
    void Print();
    void Recur_print(Node *node, int degree);
    void increase_key(int value,int new_key);
    void subtree_cut(Node * parent, Node * child);
    void recut(Node * node);
    void erase_from_child_list(Node * parent, Node * child);
    void delete_node_from_heap(int value);
    FibonacciHeap make_heap();
    Node * find_max();
    void increase_junk_key(int value,int new_key);
};
//junk functions


  FibonacciHeap FibonacciHeap::make_heap()
  {
        return FibonacciHeap();
        
          }
 bool FibonacciHeap::is_empty()
 {
    if(node_count == 0)
    {
        return true;
    }
    return false;
 }
void FibonacciHeap::delete_node_from_heap(int value)
{
    int new_key = 1e7;
    if(mp.find(value) != mp.end())
    {
        increase_key(value,new_key);
        extract_max();

    }
    else
    {
        cout<<"this value does not exist"<<endl;
    }
}
 void FibonacciHeap::recut(Node * node)
 {
    Node * node_parent = node->parent;
    if(node->parent != NULL)
    {
        if(node->marked == false)
        {
            node->marked = true;
        }
        else
        {
            subtree_cut(node_parent,node);
            recut(node_parent);
        }
    }
 }
void FibonacciHeap::erase_from_child_list(Node * parent, Node * node)
{
    if(parent->child == parent->child->left)
    {
        parent->child = NULL;
    }
    else if(parent->child  == node)
    {
        parent->child = node->right;
    }
   
    node->left->right = node->right;
    node->right->left = node->left;
    parent->rank-- ;
    node->parent = NULL;
    
}
void FibonacciHeap::subtree_cut(Node * parent, Node * child)
{
    erase_from_child_list(parent,child);
    merge_with_list(child);
    child->marked = false;
}
void FibonacciHeap:: increase_key(int value , int new_key)
{
    if(mp.find(value) != mp.end())
    {
    Node * node = mp[value];
    if(node->key > new_key)
    {
        return;
    }
    node->key = new_key;
    Node * parent = node->parent;
    if(parent != NULL && node->key > parent->key)
    {
        subtree_cut(parent,node);
        recut(parent);
    }
    if(node->key > max_node->key)
    {
        max_node = node;
    }
}
else{
    cout<<"this value does not exist"<<endl;
}

}
void FibonacciHeap:: increase_junk_key(int value , int new_key)
{
    if(mp.find(value) != mp.end())
    {
    Node * node = mp[value];
    // if(node->key > new_key)
    // {
    //     return;
    // }
    node->key = new_key;
    Node * parent = node->parent;
    if(parent != NULL && node->key > parent->key)
    {
        // subtree_cut(parent,node);
        // recut(parent);
    }
    if(node->key > max_node->key)
    {
        max_node = node;
    }
}
else{
    cout<<"this value does not exist"<<endl;
}

}
void FibonacciHeap::Recur_print(Node *node, int degree)
    {
        if (node == NULL)
        {
            return;
        }
        Node *temp = node;
        // cout << "(" << node->key << "," << node->value << ")-> ";
        for (int i = 0; i < degree; i++)
        {
            cout << "(" << temp->key << "," << temp->value << ") ";
            temp = temp->right;
        }
        cout << endl;
        temp = node;
        for (int i = 0; i < degree; i++)
        {
            // cout<<"("<<node->key<<","<<node->value<<") ";
            //
            if (temp->child != NULL)
            {
                cout << "(" << temp->key << "," << temp->value << ")-> ";
            }

            Recur_print(temp->child, temp->rank);
            temp = temp->right;
        }
    return;
    }
    void FibonacciHeap::junk_insert(int key,int value)
{
    Node * new_node = new Node (key,value);
    new_node->parent = NULL;
    new_node->child = NULL;
    new_node->rank = 0;
    new_node->left = new_node;
    new_node->right = new_node;
    new_node->marked = false;
    list <Node> li;
    li.push_back(*new_node);
   // merge_with_list(new_node);
    // if(max_node != NULL)
    // {
    //     (max_node->left)->right = new_node;
    //     new_node->right = max_node;
    //     new_node->left = max_node->left;
    //     max_node->left = new_node;
    //     if(new_node->key > max_node->key)
    //      {
    //         max_node = new_node;
    //      }


    // }
    //  else{
    //         max_node = new_node;
    //      }
    if(max_node == NULL || max_node->key < new_node->key)
    {
        max_node = new_node;
    }
         no_node_in_root_list = no_node_in_root_list +1;
}
 Node * FibonacciHeap::find_max()
 {
    return max_node;
 }

void FibonacciHeap::Print()
    {
        // cout<<H->min->key<<
        Node *temp;
        temp = root_list;

       //cout << "hel"<<root_list << endl;
        for (int i = 1; i <= no_node_in_root_list; i++)
        {
            cout << "Tree " << i << ":";
            cout << "(" << temp->key << "," << temp->value << ")-> ";
            // if(temp->Child!=nullptr)
            // {
            //     cout<<"Child"<<temp->Child->key<<endl;
            // }

            Recur_print(temp->child, temp->rank);
            temp = temp->right;
            cout << endl;
            }
            }
// void FibonacciHeap::show_child(Node * parent)
// {
//     Node * child_node = parent->child;
//     for(int i =0;i<parent->rank;i++)
//     {
//     cout<<"("<<child_node->key<<","<<child_node->value <<") ";
//     child_node = child_node->right;
//     }
//     cout<<endl;
//     Node * child_node_recur = parent->child;
//     for(int i =0;i<parent->rank;i++)
//     {
//     show_child(child_node_recur);
//     }
// }
void FibonacciHeap::combine_with_child_list(Node * parent,Node *node)
{
    if(parent->child == NULL)
    {
        parent->child = node;
    }
    else{
        node->right = parent->child->right;
        node->left = parent->child;
        parent->child->right->left = node;
        parent->child->right = node;
    }
}
void FibonacciHeap::link_heap(Node * node_y,Node * node_x)
{
    delete_from_root_list(node_y);
    node_y->left = node_y->right = node_y;
    combine_with_child_list(node_x,node_y);
    node_x->rank += 1;
    node_y->parent = node_x;
    node_y->marked = false;
}
void FibonacciHeap::consolidate()
{
    double d = log2(node_count);
    int max_rank = floor(d);
    // max_rank = 150;
  //  cout<<max_rank<< "max_rank"<<endl;
    vector<Node *> rank_vector(max_rank+1,NULL);
     Node * x = root_list;
     int count = no_node_in_root_list;
    for(int i =0 ;i<count;i++)
    {

        int d = x->rank;
        while(rank_vector[d] != NULL)
        {
            Node * y = rank_vector[d];
            if(x->key < y->key)
            {
                Node * temp = x;
                x = y;
                y = temp;
            }
            link_heap(y,x);
            rank_vector[d] = NULL;
            d += 1;
        }
        rank_vector[d] = x;
        x = x->right;
    }
    for(int i = 0;i<=max_rank;i++)
    {
        if(rank_vector[i] != NULL)
        {
            if(rank_vector[i]->key > max_node->key)
            {
                max_node = rank_vector[i];
            }
        }
    }

}
void FibonacciHeap::delete_from_root_list(Node * node)
{
    if(node == root_list)
    {
        root_list = node->right;
    }
    node->left->right = node->right;
    node->right->left = node->left;
    no_node_in_root_list--;
}
 Node * FibonacciHeap::extract_max()
 {
    Node * extracting_max_node = this->max_node;

    if(extracting_max_node != NULL)
    {
        if(extracting_max_node->child != NULL)
        {
        Node *child_max_node = extracting_max_node->child;
            while(1)
            {
                 erase_from_child_list(extracting_max_node,child_max_node);
                merge_with_list(child_max_node);
               
               // child_max_node->parent = NULL;
                child_max_node = extracting_max_node->child;
                if(child_max_node == NULL)
                {
                    break;
                }
            }
        }
        delete_from_root_list(extracting_max_node);
        if(extracting_max_node == extracting_max_node->left)
        {
            max_node = NULL;
            root_list = NULL;
            no_node_in_root_list = 0;
             node_count = 0;
        }
        else
        {
            max_node = extracting_max_node->right;
           //  no_node_in_root_list -= 1;
             node_count --;
            //consolidate
            consolidate();
        }

        mp.erase(extracting_max_node->value);
       // return extracting_max_node;
    }

    return extracting_max_node;

 }
 void  FibonacciHeap::ready_for_insert(Node * new_node)
 {
     new_node->parent = NULL;
    new_node->child = NULL;
    new_node->rank = 0;
    new_node->left = new_node;
    new_node->right = new_node;
    new_node->marked = false;
 }

 void FibonacciHeap::merge_with_list(Node * new_node)
 {
    if(root_list != NULL)
    {
        (root_list->left)->right = new_node;
        new_node->right = root_list;
        new_node->left = root_list->left;
        root_list->left = new_node;
        // if(new_node->key > root_list->key)
        //  {
        //     root_list = new_node;
        //  }


    }
     else{
      //  cout<<"touched"<<endl;
            root_list = new_node;
         }
          no_node_in_root_list = no_node_in_root_list +1;
 }
void FibonacciHeap::insert(int key,int value)
{
    Node * new_node = new Node (key,value);
    // new_node->parent = NULL;
    // new_node->child = NULL;
    // new_node->rank = 0;
    // new_node->left = new_node;
    // new_node->right = new_node;
    // new_node->marked = false;
    ready_for_insert(new_node);
    merge_with_list(new_node);
    // if(max_node != NULL)
    // {
    //     (max_node->left)->right = new_node;
    //     new_node->right = max_node;
    //     new_node->left = max_node->left;
    //     max_node->left = new_node;
    //     if(new_node->key > max_node->key)
    //      {
    //         max_node = new_node;
    //      }


    // }
    //  else{
    //         max_node = new_node;
    //      }
   // array_node[value] = new_node;
   mp[value] = new_node;
    if(max_node == NULL || max_node->key < new_node->key)
    {
        max_node = new_node;
    }
       //  no_node_in_root_list = no_node_in_root_list +1;
         node_count++;
}
// void FibonacciHeap::show ()
// {
//     Node * node = root_list;
//     if(node == NULL)
//     {
//         cout<<"empty heap"<<endl;

//     }
//     else{
//         cout << "Root Nodes: " << endl;
//         // cout<<node<<" ";
//         // if(node->right != NULL)
//         // {
//         //     cout<< "->";
//         //     while(node->right != max_node)
//         //     {
//         //         node = node->right;
//                 // cout<<"("<<node->key<<","<<node->value <<") ";
//         //         if(node != max_node)
//         //         {
//         //             cout<<" -> ";
//         //         }
//         //     }
//         // }
//         int i = 1;
//        while(1)
//        {
//                  cout<<"Tree:"<<i<<"("<<node->key<<","<<node->value <<") ->";
//                  if(node->child != NULL)
//                  {
//                 show_child(node);
//                  }

//                  node = node->right;
//                 i++;
//                 //  if(node != max_node)
//                 //  {
//                 //     cout<< "->";
//                 //  }
//                 if(node == root_l
//                 {
//                     break;
//                 }
//        }
//        cout<<endl;
//     }

// }
void FibonacciHeap::meld (FibonacciHeap &fh2)
{
   // FibonacciHeap fh3 = FibonacciHeap();
  //  fh3.root_list = this->root_list;
    if(this->max_node->key > fh2.max_node->key)
    {
        max_node = this->max_node;
    }
    else{
         max_node = fh2.max_node;
    }
    Node * end = fh2.root_list->left;
    fh2.root_list->left = root_list->left;
    root_list->left->right = fh2.root_list;
    root_list->left = end;
    root_list->left->right = root_list;
    int prev_no_node_in_root_list = no_node_in_root_list;
    no_node_in_root_list = prev_no_node_in_root_list + fh2.no_node_in_root_list;
    node_count = node_count + fh2.node_count;
   // return fh3;

}
// int main ()
// {
//     FibonacciHeap fibo_heap,fibo_heap_2;
//     // fibo_heap.insert(10,1);
//     // fibo_heap.insert(20,2);
//     // fibo_heap.insert(30,3);
//     // for(int i = 10;i<=80;i = i+10)
//     // {
//     //     fibo_heap.insert(i,i);
//     // }
//     fibo_heap.insert(20,20);
//     fibo_heap.insert(16,16);
//      fibo_heap.insert(17,17);
//        fibo_heap.insert(12,12);
//        fibo_heap.insert(11,11);
//        fibo_heap.insert(13,13);
//        fibo_heap.insert(10,10);
//        fibo_heap.insert(15,15);
//        fibo_heap.insert(18,18);
//        fibo_heap.insert(19,19);

//  //   cout<<fibo_heap.no_node_in_root_list<<endl;
//    // fibo_heap.show();
//    fibo_heap.Print();
//     fibo_heap.extract_max();
//      cout<<fibo_heap.no_node_in_root_list<<endl;
//     fibo_heap.Print();
   
//     fibo_heap.extract_max();
//     fibo_heap.Print();
//      fibo_heap.increase_key(12,19);
//     fibo_heap.Print();
//     fibo_heap.delete_node_from_heap(17);
//     cout<<"after deleting"<<endl;
//     fibo_heap.Print();
//     fibo_heap.extract_max();
//     cout<<"after delete + extract max"<<endl;
//     fibo_heap.Print();
//     fibo_heap.extract_max();
//       cout<<"after delete + extract max+ 2nd"<<endl;
//     fibo_heap.Print();
//     // fibo_heap.extract_max();
//     // fibo_heap.Print();
//     // fibo_heap_2.insert(56,1);
//     // fibo_heap_2.insert(78,2);
//     // fibo_heap_2.insert(40,3);
//     // FibonacciHeap fh3 = fibo_heap.meld(fibo_heap_2);
//     // fh3.show();
    
// }
