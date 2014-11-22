#include <stdio.h>
#include "hashtable.h"

int main()
{
    HashTable* hashTable = HASHTABLE_createHashTable();
    
    HASHTABLE_put(hashTable,2,30);
    HASHTABLE_put(hashTable,4,450);
    HASHTABLE_put(hashTable,21,320);
    HASHTABLE_put(hashTable,34,350);
    HASHTABLE_put(hashTable,4,240);
    HASHTABLE_put(hashTable,15,600);
    HASHTABLE_put(hashTable,35,62200);
    HASHTABLE_remove(hashTable,2);
    HASHTABLE_put(hashTable,45,600);
    HASHTABLE_remove(hashTable,34);
    HASHTABLE_put(hashTable,45,232323600);
    
    HASHTABLE_put(hashTable,12,2000);
    
    int get;
    if(HASHTABLE_get(hashTable,15,&get)){
        printf("search result: %d\n",get);
    }
    
    if(HASHTABLE_containsKey(hashTable,35)){
        printf("key 35 found!\n");
    }
    
    
    HASHTABLE_printHashTable(hashTable);
    
    
    hashTable = HASHTABLE_free(hashTable);
    
    return 0;
}
