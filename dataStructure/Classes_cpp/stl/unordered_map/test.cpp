//http://www.cplusplus.com/reference/unordered_map/unordered_map/
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<int,string> hashtable;
    
    hashtable.insert(make_pair(44,"j carlos"));
    hashtable.insert(make_pair(32,"tatiana"));
    hashtable.insert(make_pair(12,"daniel"));
    
    hashtable.erase(12);
    
    for(unordered_map<int,string>::iterator itr = hashtable.begin(); itr != hashtable.end(); itr++){
        cout<<(*itr).first << ": "<<(*itr).second<<endl;
    }    
    
    return 0;
}
