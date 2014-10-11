//http://www.cplusplus.com/reference/forward_list/forward_list/
#include<iostream>
#include<forward_list> // usar a opção -std=c++11
using namespace std;

int main()
{
    forward_list<int> mylist;
    mylist.push_front(4);
    mylist.push_front(1);
    mylist.push_front(5);
    mylist.push_front(6);
    
    cout<<mylist.front()<<endl;
    
    for(forward_list<int>::iterator it = mylist.begin(); it!=mylist.end(); it++){
        cout<<" "<<*it;
    }
    cout<<endl;
    
    mylist.remove(5);
    
    for(forward_list<int>::iterator it = mylist.begin(); it!=mylist.end(); it++){
        cout<<" "<<*it;
    }
    cout<<endl;
    
    return 0;
}
