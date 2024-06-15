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
    ll_int choice;
    cout<<"enter option"<<endl;
    cin>>choice;
    string nid_no,phone_no,name;
    vector<pair<string,string>> records;
    Hash_table doubleHash_table_1(1000,1,"doubleHash",25);
    int i = 0;
    while(1)
    {
    if(choice == 1)
    {
        cout<<"enter name: "<<endl;
        cin>>name;
         cout<<"enter nid: "<<endl;
         cin>> nid_no;
          cout<<"enter phone: "<<endl;
          cin>>phone_no;
           
           doubleHash_table_1.insert(name,i);
           doubleHash_table_1.insert(nid_no,++i);
           doubleHash_table_1.insert(phone_no,++i);
          
    }
    else if(choice == 2)
    {
        string str;
        cout<<"enter"<<endl;
        cin>>str;
        ll_int index = doubleHash_table_1.find(str).first;
        if(index == -1)
        {
            cout<<"cannot found"<<endl;
        }
        else{
            cout<<records[index].first<<" "<<records[index].second<<endl;
        }
    }
    else
    {
        break;
    }
    }

}