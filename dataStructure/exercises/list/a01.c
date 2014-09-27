/**
 * Verifica se uma lista B é um subconjunto de uma lista A
 * Retorna 1 em caso positivo, e 0 em caso negativo
 *
 * Node* firstB : primeiro nó da lista B
 * Node* firstA : primeiro nó da lista A
 */
int isSubset(Node* firstB, Node* firstA){
    
    if(firstB==NULL)
        return 1;
    else{
        if(search(firstA,firstB->item)==NULL)
            return 0;
        else
            return isSubset(firstB->nextNode, firstA);
    }
    
}
