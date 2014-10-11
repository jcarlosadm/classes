//http://www.cplusplus.com/reference/stack/stack/
#include <iostream>
#include <stack>

using namespace std;

int main()
{
    
    stack<int> mystack;
    
    mystack.push(5);
    mystack.push(10);
    mystack.push(1);
    mystack.push(20);
    mystack.push(0);
    
    while(!mystack.empty())
    {
        cout<<" "<<mystack.top();
        mystack.pop();
    }
    cout<<endl;
    
    return 0;
}
