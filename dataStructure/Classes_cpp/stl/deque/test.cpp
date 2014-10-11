//http://www.cplusplus.com/reference/deque/deque/
#include <iostream>
#include <deque>

using namespace std;

int main()
{
    
    deque<int> mydeque;
    
    mydeque.push_front(20);
    mydeque.push_front(50);
    mydeque.push_back(66);
    mydeque.push_front(212);
    mydeque.push_back(31);
    mydeque.push_back(88);
    
    while(!mydeque.empty()){
        cout<<" "<<mydeque.front();
        mydeque.pop_front();
    }
    cout<<endl;
    
    return 0;
}
