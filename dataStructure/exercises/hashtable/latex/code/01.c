    
// tamanho da table da hash = 11
// função de hash = k mod n, onde k: key, n: tamanho da table da hash
Hashtable* hashtable = createHashtable();
if(!hashtable) return 1;

put(hashtable,2,4322340);
put(hashtable,20,154550);
put(hashtable,45,43440);
put(hashtable,35,8979840);
put(hashtable,2,34343440);

// imprime:
// index  -  key  -  value
//   1       45       43440
//   2       2        34343440
//   3       35       8979840
//   9       20       154550
printHashtable(hashtable);

