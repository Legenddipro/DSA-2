#include "RBT.cpp"
class Map_contain{
    public:
    RBT tree;
    void insert(int data,string str)
    {
        tree.insert(data,str);
    }
    void erase (int data)
    {
        tree.delete_RBT(data);
    }
    void clear()
    {
        tree.is_clear();
    }
    void find(int key)
    {
       bool is_exist = tree.search(tree.root,key);
       if(is_exist == true)
       {
        cout<<key<<" found"<<endl;
       }
       else{
        cout<<key<<" not found"<<endl;
       }
    }
    void empty()
    {
        if( tree.is_empty() == true)
        {
            cout<<"yes"<<endl;
        }
        else
        {
            cout<<"no"<<endl;
        }
    }
    void size()
    {
        cout<<tree.size()<<endl;
    }
    void iteration()
    {
        tree.inorder(tree.root);
            }
            void preorder_map()
            {
                tree.preorder(tree.root);
            }
};
int main()
{
    Map_contain map;
    string line;
    ifstream in("input.txt");
    int data;
    string str,com;
    while(!in.eof())
    {
       in>>com;
       if(com == "I")
       {
        in>>data>>str;
        map.insert(data,str);
        map.preorder_map();
        cout<<endl;
       }
       else if(com == "F")
       {
        in>>data;
        map.find(data);
        cout<<endl;
       }
       else if(com == "S" )
       {
        map.size();
        
       }
       else if(com == "E" )
       {
        in>>data;
        map.erase(data);
        map.preorder_map();
        cout<<endl;
       }
       else if(com == "Em")
       {
        map.empty();
       
       }
        else if(com == "Itr")
        {
            map.iteration();
          
        }
        else if(com == "Clr")
        {
            map.clear();
           
        }
    }
}