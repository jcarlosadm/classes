//http://www.cplusplus.com/reference/list/list/
#include <iostream>
#include <list> // use a opção -std=c++11

using namespace std;

int main()
{
    
    list<int> mylist;
    
    mylist.push_front(20);
    mylist.push_front(10);
    mylist.push_front(40);
    mylist.push_front(70);
    mylist.push_front(90);
    
    for(list<int>::iterator it=mylist.begin(); it!=mylist.end(); it++){
        cout<<" "<<*it;
        if(*it==40){
            it = mylist.erase(it);
            cout<<" "<<*it;
        }
    }
    cout<<endl;
    
    mylist.remove(10);
    
    for(list<int>::iterator it=mylist.begin(); it!=mylist.end(); it++){
        cout<<" "<<*it;
    }
    cout<<endl;
    
    return 0;
}
