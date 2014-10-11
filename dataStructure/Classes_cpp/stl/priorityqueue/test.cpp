//http://www.cplusplus.com/reference/queue/priority_queue/
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Person
{
    public:
    Person(int id_,int value_){
        id = id_;
        value = value_;
    }
    
    int id;
    int value;
};

struct menorId
{
    bool operator()(const Person& lhs, const Person& rhs) const
    {
        return lhs.id < rhs.id;
    }
};

int main (int argc, char const* argv[])
{
    
    priority_queue<Person,vector<Person>,menorId> myqueue;
    
    myqueue.push(Person(40,1));
    myqueue.push(Person(20,6));
    myqueue.push(Person(50,4));
    
    while(!myqueue.empty()){
        cout<<" "<<myqueue.top().value;
        myqueue.pop();
    }
    cout<<endl;
    
    
    return 0;
}

