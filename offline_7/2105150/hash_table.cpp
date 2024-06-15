#include <bits/stdc++.h>
using namespace std;
typedef unsigned long ll_int;
bool is_prime(ll_int num)
{
    int flag = 0;
    for (ll_int i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
ll_int find_prime(ll_int num)
{
    if (is_prime(num) == true)
    {
        return num;
    }
    else
    {
        while (1)
        {
            num++;
            if (is_prime(num) == true)
            {
                return num;
            }
        }
    }
}
ll_int hash1(string &key)
{
    int prime_num = 43;
    int hash_value = 0;
    int i = 0;
    while (i < key.length())
    {
        int asciiValue = static_cast<int>(key[i]);
        hash_value = prime_num * hash_value + asciiValue;
        i++;
    }
    return hash_value;
}
ll_int hash2(string key)
{

    const ll_int A = 54059;
    const ll_int B = 76963;
    ll_int hash = 31;

    for (char c : key)
    {
        hash = (hash * A) ^ (c * B);
    }
    return hash;
}
ll_int aux_hash(string &key, ll_int table_size)
{
    ll_int hash = 0;

    for (char c : key)
    {
        hash = (hash * 67 + c) % table_size;
    }
    if (hash == 0)
    {
        hash += 1;
    }
    return hash;
}
void init(vector<ll_int> &marked)
{
    for (int i = 0; i < marked.size(); i++)
    {
        marked[i] = 0;
    }
}
// class Node{
//     public:
//     string str;
//     int value;
//     int index;
//     Node()
//     {

//     }
//     Node(string str, int value)
//     {
//         this->str = str;
//         this->value = value;
//     }
// bool operator==(Node &obj)
// {
//     if(this->str == obj.str && this->value == obj.value )
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }
// bool operator!=(Node &obj)
// {
//     if(this->str != obj.str || this->value != obj.value )
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }

class Hash_table
{
public:
    int present_size;
    int table_size;
    string res_type;
    vector<list<pair<string, ll_int>>> node_list;
    vector<pair<string, ll_int>> node_list_double_hash;
    vector<pair<string, ll_int>> node_list_custom;
    vector<ll_int> is_filled;
    ll_int collision_double_hash_insert;
    ll_int collision_custom_insert;
    pair<ll_int, ll_int> doubleHash_find_pair;
    pair<ll_int, ll_int> custom_find_pair;
    pair<ll_int, ll_int> chain_find_pair;
    ll_int hash_type;
    ll_int insertion_time;
    ll_int max_chain_length;
    ll_int deletion_time;
    ll_int initial_size;
    vector<string> random_collection;
    
    // vector<ll_int> doubleHash_find_pair;
    Hash_table(ll_int table_size, ll_int hash_type, string res_type, ll_int max_chain_length)

    {
        this->hash_type = hash_type;
        this->present_size = 0;
        this->table_size = table_size;
        node_list.resize(table_size);
        this->res_type = res_type;
        node_list_double_hash.resize(table_size);
        is_filled.resize(table_size);
        init(is_filled);
        collision_double_hash_insert = 0;
        node_list_custom.resize(table_size);
        insertion_time = 0;
        this->max_chain_length = max_chain_length;
        deletion_time = 0;
        initial_size = table_size;
        
    }

    ll_int return_hash(string &str)

    {
        ll_int hash_value;
        if(hash_type == 1)
         hash_value = hash1(str);
        else
        hash_value = hash2(str);
        hash_value = hash_value % table_size;

        
        if (hash_value < 0)
        {
            hash_value = hash_value + table_size;
        }
        
        return hash_value;
    }
    // void help_insert(Node & new_node);
    double avg_prpbe_count(vector <string> & input);
    vector<string> selectRandomElements(const vector<string> &input);
    ll_int chain_insert(string key, ll_int value);
    ll_int rehash_chain(ll_int size);
    void chain_remove(string key);
    bool chain_search(string key);
    void print_chain();
    ll_int doubleHash_insert(string key, ll_int value);
    ll_int doubleHash_index(ll_int initial_hash, ll_int aux_hash_value, ll_int i);
    ll_int doubleHash_find(string key);
    void doubleHash_remove(string key);
    void print_doubleHash();
    ll_int insert(string key, ll_int value);
    void delete_hash(string key);
    pair<ll_int, ll_int> find(string key);
    void print();
    ll_int custom_insert(string key, ll_int value);
    ll_int hash_custom(ll_int initial_hash, ll_int aux_hash_value, ll_int i);
    ll_int custom_find(string key);
    void custom_remove(string key);
    void print_custom();
    ll_int get_max_chain_length(vector<list<pair<string, ll_int>>> &node_list);
};
double Hash_table::avg_prpbe_count(vector <string> & input)
{
    ll_int net_probe_count = 0;
    for(ll_int i =0 ;i<input.size();i++)
    {
        pair<ll_int,ll_int> p = find(input[i]);
        net_probe_count +=  p.second;
    }
    return 1.0*net_probe_count/input.size();
}
vector<string> Hash_table::selectRandomElements(const vector<string> &input)
{
    vector<string> selectedElements;

    int numElementsToSelect = input.size() * 0.10;

    srand(time(0));

    set<int> selectedIndices;

    while (selectedIndices.size() < numElementsToSelect)
    {

        int randomIndex = rand() % input.size();

        if (selectedIndices.find(randomIndex) == selectedIndices.end())
        {

            selectedIndices.insert(randomIndex);

            selectedElements.push_back(input[randomIndex]);
        }
    }

    return selectedElements;
}
void Hash_table::print_custom()
{
    for (ll_int i = 0; i < node_list_custom.size(); i++)
    {
        if (is_filled[i] == 1)
        {
            pair<string, ll_int> p = node_list_custom[i];
            cout << p.first << " " << p.second << endl;
        }
    }
}
void Hash_table::custom_remove(string key)
{
    ll_int index = custom_find(key);
    if (index == -1)
    {
        cout << "key does not exist" << endl;
    }
    else
    {
        // node_list_double_hash.erase(node_list_double_hash.begin() + index);
        present_size--;
        is_filled[index] = 2;
    }
}
ll_int Hash_table::custom_find(string key)
{
    ll_int initial_hash;

    if (hash_type == 1)
        initial_hash = hash1(key);
    else
        initial_hash = hash2(key);
    // ll_int initial_hash = return_hash(key);
    ll_int i = 0;
    ll_int aux_hash_value = aux_hash(key, table_size);
    ll_int collision = 0;
    ll_int count_probe = 0;
    ll_int index = return_hash(key);
    int flag = 0;
    while (is_filled[index] != 0)
    {
        count_probe++;
        if (node_list_custom[index].first == key && is_filled[index] != 2)
        {
            flag++;
            pair<ll_int, ll_int> p(node_list_custom[index].second, count_probe);
            custom_find_pair = p;
            break;
            //    doubleHash_find_pair.push_back(node_list_double_hash[index].second);
            //    doubleHash_find_pair.push_back(count_probe);
        }
        // if table is of full size
        else if (i > table_size )
        {
         //   cout << "this data does not exist" << endl;
            break;
        }
        i++;
        collision++;
        index = hash_custom(initial_hash, aux_hash_value, i);
    }
    // doubleHash_find_pair.push_back(0);
    // doubleHash_find_pair.push_back(count_probe);
    // IF WE COULD NOT FIND THE PAIR
    pair<ll_int, ll_int> p(0, count_probe);

    if (flag == 0)
    {
        custom_find_pair = p;
        return -1;
    }
    else
    {
        return index;
    }
}
ll_int Hash_table::hash_custom(ll_int initial_hash, ll_int aux_hash_value, ll_int i)

{
    ll_int c1 = 47;
    ll_int c2 = 53;

    return ((initial_hash + c1 * i * aux_hash_value + c2 * i * i) % table_size);
}

ll_int Hash_table::custom_insert(string key, ll_int value)
{
    ll_int initial_hash;
    if (hash_type == 1)
        initial_hash = hash1(key);
    else
        initial_hash = hash2(key);

    ll_int i = 0;
    ll_int aux_hash_value = aux_hash(key, table_size);
    ll_int collision = 0;
    ll_int index = return_hash(key);
    ll_int flag = 0;
    while (1)
    {
        if (is_filled[index] == 0 || is_filled[index] == 2)
        {
            flag = 1;
            break;
        }
        else if (i > table_size )
        {
         //   cout << "this data cannot be inserted" << endl;
            break;
        }
          else if(present_size >= table_size)
        {
            //DON'T RETURN COLLISION
            flag = 2;
            break;
        }
       // cout<<"custom " <<i<<endl;
        i++;
        collision++;
        index = hash_custom(initial_hash, aux_hash_value, i);
    }
    if (flag == 1)
    {
    pair<string, ll_int> p(key, value);
    node_list_custom[index] = p;
    is_filled[index] = 1;
    // collision_custom_insert = collision;
    present_size++;
    return collision;
}
else if(flag == 2)
{
    return 0 ;
}
else //   cout << "this data cannot be inserted" << endl;
return collision;
}
void Hash_table::print()
{
    if (res_type == "chain")
    {
        print_chain();
    }
    else if (res_type == "doubleHash")
    {
        print_doubleHash();
    }
    else
    {
        print_custom();
    }
}
pair<ll_int, ll_int> Hash_table::find(string key)
{
    if (res_type == "chain")
    {
        chain_search(key);
        pair<ll_int, ll_int> p = chain_find_pair;
        return p;
    }
    else if (res_type == "doubleHash")
    {
        doubleHash_find(key);
        pair<ll_int, ll_int> p = doubleHash_find_pair;
        return p;
    }
    else
    {
        custom_find(key);
        pair<ll_int, ll_int> p = custom_find_pair;
        return p;
    }
}
void Hash_table::delete_hash(string key)
{
    if (res_type == "chain")
    {
        chain_remove(key);
    }
    else if (res_type == "doubleHash")
    {
        doubleHash_remove(key);
    }
    else
    {
        custom_remove(key);
    }
}
ll_int Hash_table::insert(string key, ll_int value)
{
    ll_int collision = 0;
    
    if (res_type == "chain")
    {
        ll_int temp = chain_insert(key,value);
        collision += temp;
        // cout<<"temp collision "<<temp;
        // collision += chain_insert(key, value);
    }
    else if (res_type == "doubleHash")
    {
        if (doubleHash_find(key) == -1)
        {

            collision += doubleHash_insert(key, value);
        }
    }
    else
    {
        if (custom_find(key) == -1)
            collision += custom_insert(key, value);
    }
    return collision;
}
void Hash_table::doubleHash_remove(string key)
{
    ll_int index = doubleHash_find(key);
    if (index == -1)
    {
        cout << "key does not exist" << endl;
    }
    else
    {
        // node_list_double_hash.erase(node_list_double_hash.begin() + index);
        present_size--;
        is_filled[index] = 2;
    }
}
ll_int Hash_table::doubleHash_find(string key)
{
    ll_int initial_hash = return_hash(key);
    ll_int i = 0;
    ll_int aux_hash_value = aux_hash(key, table_size);
    ll_int collision = 0;
    ll_int count_probe = 0;
    ll_int index = initial_hash;
    int flag = 0;
    while (is_filled[index] != 0)
    {
        count_probe++;
        if (node_list_double_hash[index].first == key && is_filled[index] != 2)
        {
            flag++;
            pair<ll_int, ll_int> p(node_list_double_hash[index].second, count_probe);
            doubleHash_find_pair = p;
            break;
            //    doubleHash_find_pair.push_back(node_list_double_hash[index].second);
            //    doubleHash_find_pair.push_back(count_probe);
        }
        if(i>table_size)
        {
            break;
        }
        i++;
        collision++;
        index = (initial_hash + i * aux_hash_value) % table_size;
    }
    // doubleHash_find_pair.push_back(0);
    // doubleHash_find_pair.push_back(count_probe);
    pair<ll_int, ll_int> p(0, count_probe);

    if (flag == 0)
    {
        doubleHash_find_pair = p;
        return -1;
    }
    else
    {
        return index;
    }
}
ll_int Hash_table::doubleHash_index(ll_int initial_hash, ll_int aux_hash_value, ll_int i)
{
    ll_int new_hash = (initial_hash + i * aux_hash_value) % table_size;
    return new_hash;
}
ll_int Hash_table::doubleHash_insert(string key, ll_int value)
{
    ll_int initial_hash = return_hash(key);
    ll_int i = 0;
    ll_int aux_hash_value = aux_hash(key, table_size);
    ll_int collision = 0;
    ll_int index = initial_hash;
    ll_int flag = 0;
    while (1)
    {
        if (is_filled[index] == 0 || is_filled[index] == 2)
        {
            flag = 1;
            break;
        }
        else if (i > table_size)
        {
           // cout << "this data cannot be inserted" << endl;
            break;
        }
        else if(present_size >= table_size)
        {
            //DON'T RETURN COLLISION // don't insert
            flag = 2;
            break;
        }
        i++;
        //cout<<"double_hash "<<i<<endl;
        collision++;
        index = (initial_hash + i * aux_hash_value) % table_size;
    }
    if(flag == 1)
    {
    pair<string, int> p(key, value);
    node_list_double_hash[index] = p;
    is_filled[index] = 1;
   // random_collection.push_back(key);
    // collision_double_hash_insert = collision;
    present_size++;
    return collision;
}
else if(flag == 2)
{
    return 0 ;
}
else//IF FLAG = 0 THEN THIS DATA CANNOT BE INSERTED
return collision;
}
ll_int Hash_table::chain_insert(string key, ll_int value)
{

    // list <pair<string,ll_int> > & watch_list = node_list[return_hash(key)];
    if (chain_search(key) == true)
    {
        return 0;
    }
    pair<string, ll_int> p(key, value);
    
    node_list[return_hash(key)].push_back(p);
    //TO STORE THE STRING THAT LATER I CAN SEARCH
    random_collection.push_back(key);
    present_size = present_size + 1;
    insertion_time++;
   // cout<<"size of link list "<<node_list[return_hash(key)].size()<<endl;
    ll_int collision_rehash = 0;
    if (insertion_time % 100 == 0)
    {
        //cout << "Imposter" << endl;
        if (get_max_chain_length(node_list) > max_chain_length)
        //if (node_list[return_hash(key)].size() > max_chain_length)
        {
            cout << "before" << endl;
            cout << "load_factor " << (present_size / table_size) << endl;
            cout << "max_chain_length " << get_max_chain_length(node_list) << endl;
             vector<string> random_selected = selectRandomElements(random_collection);
                    cout<< "average_probe_count " << avg_prpbe_count(random_selected)<<endl;
           collision_rehash =  rehash_chain(table_size * 2);
            cout << "after" << endl;
            cout << "load_factor " << (present_size / table_size) << endl;
            cout << "max_chain_length " << get_max_chain_length(node_list) << endl;
            cout<< "average_probe_count " << avg_prpbe_count(random_selected)<<endl;
        }
    }
    // if(present_size > node_list.size())
    // {
    //     rehash_chain();
    // }
    ll_int temp_net_collison =0 ;
    if ((node_list[return_hash(key)].size() > 1) || collision_rehash  )
    {
        // temp_net_collison = collision_rehash + node_list[return_hash(key)].size();
        temp_net_collison = collision_rehash + 1;
       // cout<<"rehas_col "<<collision_rehash<<" temp_net "<<temp_net_collison<<endl;
        
    }
    return temp_net_collison;
}
//  void Hash_table::insert (string key,int value)
//  {
//     Node new_node(key,value);
//     help_insert(new_node);
//  }
bool Hash_table::chain_search(string key)
{
    list<pair<string, ll_int>> &watch_list = node_list[return_hash(key)];
    ll_int probe_count = 0;
    // list <Node>:: iterator itret = find(watch_list.begin(), watch_list.end(),searching_node);
    for (auto p : watch_list)
    {
        probe_count++;
        if (p.first == key)
        {
            pair<ll_int, ll_int> q(p.second, probe_count);
            chain_find_pair = q;
            return true;
        }
    }
    pair<ll_int, ll_int> q(0, probe_count);
    chain_find_pair = q;
    return false;
    // if(itret == watch_list.end() )
    // {
    //     cout<<" this node does not exist"<<endl;
    //     return false;
    // }
    // return true;
}
void Hash_table::chain_remove(string key)
{
    // list <pair<string,ll_int> > & watch_list = node_list[return_hash(key)];
    // list <Node>:: iterator itret = find(watch_list.begin(), watch_list.end(),removing_node);
    // if(itret == watch_list.end() )
    // {
    //     cout<<" this node does not exist"<<endl;
    //     return;
    // }
    if (chain_search(key) == true)
    {
        auto it = node_list[return_hash(key)].begin();
        while (it != node_list[return_hash(key)].end())
        {
            if (it->first == key)
            {
                node_list[return_hash(key)].erase(it);

                present_size--;
                break;
            }
            else
            {
                it++;
            }
        }
        deletion_time++;
        if (deletion_time % 100 == 0)
        {
            if (get_max_chain_length(node_list) < 0.8 * max_chain_length)
            {

                if ((table_size / 2) > initial_size)
                {
                    cout<<endl;
                    cout << "before" << endl;
                    cout << "load_factor " << (present_size / table_size) << endl;
                    cout << "max_chain_length " << get_max_chain_length(node_list) << endl;
                    vector<string> random_selected = selectRandomElements(random_collection);
                    cout<< "average_probe_count" << avg_prpbe_count(random_selected)<<" "<<endl;
                    rehash_chain(table_size / 2);
                    cout << "after" << endl;
                    cout << "load_factor " << (present_size / table_size) << endl;
                    cout << "max_chain_length " << get_max_chain_length(node_list) << endl;
                    cout<< "average_probe_count" << avg_prpbe_count(random_selected)<<" "<<endl;
                }
            }
        }
    }

    else
    {
       //cout << "this key does not exist" << endl;
        return;
    }
}
ll_int Hash_table::get_max_chain_length(vector<list<pair<string, ll_int>>> &node_list_max_length)
{
    ll_int max_length = node_list_max_length[0].size();
    for (auto p : node_list_max_length)
    {
        if (max_length < p.size())
        {
            max_length = p.size();
        }
    }
    return max_length;
}
ll_int Hash_table::rehash_chain(ll_int size)
{

    ll_int new_size = find_prime(size);
    ll_int old_capacity = table_size;
    vector<list<pair<string, ll_int>>> temp(table_size);
    for (ll_int i = 0; i < table_size; i++)
    {
        temp[i] = node_list[i];
    }
    ll_int j = 0;
    while (j < table_size)
    {
        node_list[j].clear();
        j++;
    }
    node_list.resize(new_size);
    table_size = new_size;
    ll_int collision = 0;
    for (ll_int i = 0; i < old_capacity; i++)
    {
        if (temp[i].size() != 0)
        {
            for (auto p : temp[i])
            {
               collision += insert(p.first, p.second);
            }
        }
    }
    return collision;
}

void Hash_table::print_chain()
{
    for (auto p : node_list)
    {
        if (p.size() != 0)
        {
            for (auto q : p)
            {
                cout << q.first << q.second << endl;
            }
        }
    }
}
void Hash_table::print_doubleHash()
{
    for (ll_int i = 0; i < node_list_double_hash.size(); i++)
    {
        if (is_filled[i] == 1)
        {
            pair<string, ll_int> p = node_list_double_hash[i];
            cout << p.first << " " << p.second << endl;
        }
    }
}

    // ll_int numbers = 0;
    // for(ll_int i = 0;i<10;i++)
    // {
    //     string word = word_gen(rand() % 6 + 5);

    // }
    // Hash_table table(10,1,"custom");
    // table.insert("ab",1);
    // table.insert("cd",2);
    // table.insert("ef",3);
    // table.print();
    // table.delete_hash("cd");
    // table.print();

    // cout<<table.find("ef")<<endl;
    // cout<<table.find("ab");

