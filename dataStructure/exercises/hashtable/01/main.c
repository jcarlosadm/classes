#include <stdio.h>
#include "hashtable.h"

int
main (int argc, char *argv[])
{
    
    // tamanho da table da hash = 11
    // função de hash = k mod n, onde k: key, n: tamanho da table da hash
    HashTable* hashTable = HASHTABLE_createHashTable();
    if(!hashTable) return 1;
    
    HASHTABLE_put(hashTable,2,4322340);
    HASHTABLE_put(hashTable,20,154550);
    HASHTABLE_put(hashTable,45,43440);
    HASHTABLE_put(hashTable,35,8979840);
    HASHTABLE_put(hashTable,2,34343440);
    
    // imprime:
    // index  -  key  -  value
    //   1       45       43440
    //   2       2        34343440
    //   3       35       8979840
    //   9       20       154550
    HASHTABLE_printHashTable(hashTable);
    
    hashTable = HASHTABLE_free(hashTable);
    
    return 0;
}
