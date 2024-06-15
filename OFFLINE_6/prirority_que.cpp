#include "heap.cpp"
class Priority_queue
{
    public:
 //FibonacciHeap heap;
FibonacciHeap * make_heap();
bool is_empty(FibonacciHeap &heap);
void insert(FibonacciHeap &heap,int key,int value);
int  extract_max(FibonacciHeap &heap);
void increase_key(FibonacciHeap &heap,int value,int new_key);
void delete_key(FibonacciHeap &heap,int value);
void meld (FibonacciHeap &heap1,FibonacciHeap &heap2);
int find_max(FibonacciHeap &heap);
void print (FibonacciHeap &heap);
void test(FibonacciHeap &heap,FibonacciHeap & heap1);

};
int Priority_queue::find_max(FibonacciHeap &heap)
{
   Node * node =  heap.find_max();

   cout<<"max_node "<<node->key<<" "<<node->value<<endl;
}
FibonacciHeap * Priority_queue::make_heap()
{
    
    return new FibonacciHeap();
}
bool Priority_queue::is_empty(FibonacciHeap &heap)
{
    if(heap.is_empty() == true)
    {
        cout<<"empty true"<<endl;
    }
    cout<<"empty false"<<endl;
}
void Priority_queue::insert(FibonacciHeap &heap,int key,int value)
{
    heap.insert(key,value);
}

int  Priority_queue::extract_max(FibonacciHeap &heap)
{
  Node * max_node =  heap.extract_max();
  return max_node->value;
}
void Priority_queue::increase_key(FibonacciHeap &heap,int value,int new_key)
{
    heap.increase_key(value,new_key);
}
void Priority_queue::delete_key(FibonacciHeap &heap,int value)
{
    heap.delete_node_from_heap(value);
}
void Priority_queue:: meld (FibonacciHeap &heap1,FibonacciHeap &heap2)
{
     heap1.meld(heap2);
    //return heap_3;
}
void Priority_queue::print (FibonacciHeap &heap)
{
    heap.Print();
}
void Priority_queue::test(FibonacciHeap &fibo_heap,FibonacciHeap &fibo_heap_2)
{
//    insert(fibo_heap,20,20);
//    insert(fibo_heap,16,16);
//     insert(fibo_heap,17,17);
//       insert(fibo_heap,12,12);
//       insert(fibo_heap,11,11);
//       insert(fibo_heap,13,13);
//       insert(fibo_heap,10,10);
//       insert(fibo_heap,15,15);
//       insert(fibo_heap,18,18);
//       insert(fibo_heap,19,19);

//  //   cout<<fibo_heap.no_node_in_root_list<<endl;
//    // fibo_heap.show();
//   print(fibo_heap);
//    extract_max(fibo_heap);
//      //cout<<pq.no_node_in_root_list<<endl;
//    print(fibo_heap);
   
//    extract_max(fibo_heap);
//    print(fibo_heap);
//     increase_key(fibo_heap,12,19);
//    print(fibo_heap);
//    delete_key(fibo_heap,17);
//     cout<<"after deleting"<<endl;
//    print(fibo_heap);
//    extract_max(fibo_heap);
//     cout<<"after delete + extract max"<<endl;
//    print(fibo_heap);
//    extract_max(fibo_heap);
//       cout<<"after delete + extract max+ 2nd"<<endl;
//    print(fibo_heap);
//string line;
    ifstream in("input2.txt");
    int key,value,new_key;
    string str,com;
    while(!in.eof())
    {
       in>>com;
       if(com == "I")
       {
        in>>key;
       insert(fibo_heap,key,key);
       insert(fibo_heap_2,key-1,key-1);
        
       }
       else if(com == "EX")
       {
       
       extract_max(fibo_heap);
        cout<<"after extract max"<<endl;
       }
       else if(com == "INCREASE" )
       {
        in>>value>>new_key;
        increase_key(fibo_heap,value,new_key);
        cout<<"after increase"<<endl;
        
       }
       else if(com == "P" )
       {
       print(fibo_heap);
        cout<<endl;
       }
       else if(com == "EM")
       {
       is_empty(fibo_heap);
       
       }
        else if(com == "del")
        {
           in>>value;
           delete_key(fibo_heap,value);
           cout<<"after delete"<<endl;
          
        }
        else if(com == "meld")
        {
            meld(fibo_heap,fibo_heap_2);
            cout<<"after meld"<<endl;
           
        }
        else if(com == "find_max")
        {
            find_max(fibo_heap);
        }
        // else if(com == "S")
        // {
        //     six
        // }
    }
  
}

int main()
{
    Priority_queue pq;
    FibonacciHeap fibo_heap = *(pq.make_heap());
    FibonacciHeap fibo_heap_2 = *(pq.make_heap());
    ofstream fileOut("output2.txt"); 
    streambuf * mainbuff = cout.rdbuf();
    cout.rdbuf(fileOut.rdbuf());
    pq.test(fibo_heap,fibo_heap_2);
    cout.rdbuf(mainbuff);
      ifstream in1("output1.txt");
    ifstream in2("expected_output1.txt");
    string line1,line2;
    int flag = 0;
     while (getline(in1, line1) && getline(in2, line2)) {
        if (line1 != line2) {
           
            cout << "File 1: " << line1 << endl;
            cout << "File 2: " << line2 << endl;
          flag = 1;
           break;
        }

       
    }
    if(flag == 1)
    {
        cout<<"not passed"<<endl;
    }
    else
    {
        cout<<"passed"<<endl;
    }
    
      //  fibo_heap.insert(20,20);
//       pq.insert(fibo_heap,20,20);
//     pq.insert(fibo_heap,16,16);
//      pq.insert(fibo_heap,17,17);
//        pq.insert(fibo_heap,12,12);
//        pq.insert(fibo_heap,11,11);
//        pq.insert(fibo_heap,13,13);
//        pq.insert(fibo_heap,10,10);
//        pq.insert(fibo_heap,15,15);
//        pq.insert(fibo_heap,18,18);
//        pq.insert(fibo_heap,19,19);

//  //   cout<<fibo_heap.no_node_in_root_list<<endl;
//    // fibo_heap.show();
//    pq.print(fibo_heap);
//     pq.extract_max(fibo_heap);
//      //cout<<pq.no_node_in_root_list<<endl;
//     pq.print(fibo_heap);
   
//     pq.extract_max(fibo_heap);
//     pq.print(fibo_heap);
//      pq.increase_key(fibo_heap,12,19);
//     pq.print(fibo_heap);
//     pq.delete_key(fibo_heap,17);
//     cout<<"after deleting"<<endl;
//     pq.print(fibo_heap);
//     pq.extract_max(fibo_heap);
//     cout<<"after delete + extract max"<<endl;
//     pq.print(fibo_heap);
//     pq.extract_max(fibo_heap);
//       cout<<"after delete + extract max+ 2nd"<<endl;
//     pq.print(fibo_heap);
//     // fibo_heap.extract_max();
//     // fibo_heap.Print();

}

