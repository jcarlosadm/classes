//http://www.cplusplus.com/reference/queue/queue/
#include <iostream>
#include <queue>

using namespace std;

int main (int argc, char * argv[])
{
    
    queue<int> myqueue;
    
    myqueue.push(4);
    myqueue.push(1);
    myqueue.push(6);
    myqueue.push(9);
    myqueue.push(2);
    
    while(!myqueue.empty()){
        cout<<" "<<myqueue.front();
        myqueue.pop();
    }
    cout<<endl;
    
    return 0;
}
