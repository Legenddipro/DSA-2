#include "hash_table.cpp"
string word_gen(int length)
{

    if (length < 0)
        return "";
    string ans = "";
    for (int i = 0; i < length; i++)

    {
        char ch = ('a' + (rand() % 26));
        ans += ch;
    }
    return ans;
}
ll_int collision_insert(Hash_table &table, vector<pair<string,ll_int>> & word_collection)
{
    ll_int net_collision = 0;
    for( ll_int i = 0;i<word_collection.size();i++)
    {
        net_collision += table.insert(word_collection[i].first,word_collection[i].second);
    }
    return net_collision;
}

ll_int final_avg_probe_count (Hash_table &table,vector<string> & select_elements)
{
   return  table.avg_prpbe_count(select_elements);
}
void test_delete(Hash_table &table, vector<pair<string,ll_int>> & word_collection)
{
    ll_int flag = 0;
    while(1)
    {

        if(flag == 1)//IF FLAG EQUALS TO 1 THEN delete has reduced table to lower limit size
        {
            break;
        }
        else if(flag == 2)//if flag == 2 then delete does not reduce table to lower limit size
        {
            break;
        }
        for(int i = 0;i<word_collection.size();i++)
       {
        flag = 2;
        if(table.table_size < table.initial_size)
        {
            flag = 1;
            break;
        }
        table.delete_hash(word_collection[i].first);
       }
    }
}
class Layer_hash
{
    public:
    Hash_table doubleHash_table_1;
    vector<Hash_table> hash_tables;
    ll_int table_size;
    ll_int index_of_1st_key;
    Layer_hash(ll_int table_size)
    {
        index_of_1st_key =0 ;
        this->table_size = table_size;
        hash_tables.resize(table_size);
        doubleHash_table_1 = Hash_table(table_size,1,"doubleHash",1000);
       // doubleHash_table_1 = new Hash_table()
    //    for(int i =0 ;i<table_size;i++)
    //    {
        
    //     hash_tables.push_back(doubleHash_table_1);
    //    }
    //doubleHash_table_1.find()
    }
    void insert(string key1,string key2,ll_int value)
    {
     //ll_int index_1st =   hash1(key1)% table_size;
    // doubleHash_table_1.insert(key1,value);
   pair<ll_int,ll_int> p = doubleHash_table_1.find(key1);
    if(p.first == -1)
    {
        Hash_table doubleHash_table_2(table_size,1,"doubleHash",1000);
        doubleHash_table_2.insert(key2,value);
        hash_tables.push_back(doubleHash_table_2);
        doubleHash_table_1.insert(key1,index_of_1st_key);
    }
    else{
        hash_tables[p.second].insert(key2,value);
    }
    index_of_1st_key++;
    // hash_tables[index_1st].insert(key2,value);
    }
    ll_int find(string key1,string key2)
        {
        ll_int index_of_key_2 = doubleHash_table_1.find(key1).first;
      if(index_of_key_2 == -1)
      {
        cout<<"this key does not exist"<<endl;
        return -1;
      }
    else if( hash_tables[index_of_key_2].find(key2).first == -1)
    { 
        cout<<"this key does not exist"<<endl;
        return -1;
    }
    else{
        return hash_tables[index_of_key_2].find(key2).first == -1;
    }
        }
    void find(string key1)
        {
        ll_int index_of_key_2 = doubleHash_table_1.find(key1).first;
      if(index_of_key_2 == -1)
      {
        cout<<"this key does not exist"<<endl;
        return ;
      }
    // else if( hash_tables[index_of_key_2].find(key2).first == -1)
    // { 
    //     cout<<"this key does not exist"<<endl;
    //     return ;
    // }
    // else{
    //     return hash_tables[index_of_key_2].find(key2).first == -1;
    // }
    else
    {
        ll_int index = doubleHash_table_1.find(key1).first;
        hash_tables[index].print();
    }
        }

    
};
int main()
{
    // ll_int max_chain_length,table_size;
    // cin>>max_chain_length>>table_size;
    // //demo for inserting words
    // Hash_table table(15000,1,"chain",500);
    // vector<pair<string,ll_int>> word_collection;
    // vector<string> key_collection;
    // ll_int i = 0;
    // srand(1234);
    // //TO REMOVE DUPLICACY 
    // while(i<=10000)
    // // for(ll_int i = 1;i<=10000;i++)
    // {
    //     string word = word_gen(rand() % 6 +5);
    //     if(table.find(word).first == 0)
    //     {
    //         table.insert(word,i);
    //         word_collection.push_back({word,i});
    //         key_collection.push_back(word);
    //         i++;
    //     }
        
    // }
    // table_size = find_prime(table_size);
    // //10 percent elements
    // vector<string> selected_elements = table.selectRandomElements(key_collection);
    // Hash_table chain_table_1(table_size,1,"chain",max_chain_length);
    // Hash_table chain_table_2(table_size,2,"chain",max_chain_length);
    // Hash_table doubleHash_table_1(table_size,1,"doubleHash",max_chain_length);
    // Hash_table doubleHash_table_2(table_size,2,"doubleHash",max_chain_length);
    // Hash_table custom_table_1(table_size,1,"custom",max_chain_length);
    // Hash_table custom_table_2(table_size,2,"custom",max_chain_length);
    // cout<< "For chain_table 1:....................."<<endl;
    // ll_int collision_insert_1 = collision_insert(chain_table_1,word_collection);
    // cout<<endl;
    // cout<<"collision_insert "<<collision_insert_1<<" average probe count "<<final_avg_probe_count (chain_table_1,selected_elements);
    // cout<<endl;

    //  cout<< " For chain_table 2:......................."<<endl;
    //   ll_int collision_insert_2 = collision_insert(chain_table_2,word_collection);
    //   cout<<endl;
    // cout<<"collision_insert "<<collision_insert_2<<" average probe count "<<final_avg_probe_count (chain_table_2,selected_elements)<<endl;
    //  cout<< "For  doubleHash_table_1:............................"<<endl;
    // cout<<"collision_insert "<<collision_insert(doubleHash_table_1,word_collection)<<" average probe count "<<final_avg_probe_count (doubleHash_table_1,selected_elements)<<endl;
    //  cout<< "For doubleHash_table_2:.................."<<endl;
    // cout<<"collision_insert "<<collision_insert(doubleHash_table_2,word_collection)<<" average probe count "<<final_avg_probe_count (doubleHash_table_2,selected_elements)<<endl;
    //  cout<< "For  custom_table_1:......................."<<endl;
    // cout<<"collision_insert "<<collision_insert(custom_table_1,word_collection)<<" average probe count "<<final_avg_probe_count (custom_table_1,selected_elements)<<endl;
    //  cout<< "For custom_table_2:...................................."<<endl;
    // cout<<"collision_insert "<<collision_insert(custom_table_2,word_collection)<<" average probe count "<<final_avg_probe_count (custom_table_2,selected_elements)<<endl;
    // cout<<"for deleting test "<<endl;
    // cout<<"Test delete for chain_table_1..........................."<<endl;

    // test_delete(chain_table_1,word_collection);
    //  cout<<"Test delete for chain_table_2..................................."<<endl;
    
    // test_delete(chain_table_2,word_collection);
    ll_int key_1,key_2,table_size;
    cout<<"insert key 1 & 2"<<endl;
    //cin>>key_1>>key_2>>table_size;
    table_size = find_prime(table_size);
    Layer_hash layer_hash(table_size);
     layer_hash.insert("bd", "dhaka", 500);
    layer_hash.insert("bd","ctg",500);
    //layer_hash.insert("bd”, "ctg”, 300);
     layer_hash.insert("uk", "london", 800);
cout<< layer_hash.find("bd", "dhaka")<<endl;
cout<< layer_hash.find("bd", "syl")<<endl;
 layer_hash.find("bd");
 layer_hash.find("china");
}