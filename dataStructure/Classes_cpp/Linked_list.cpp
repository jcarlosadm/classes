#include "Linked_list.hpp"


/** ************************************************************
 * Funções membros de Linked_list
 ***************************************************************/
 
/**
 * Construtor padrão
 */
template<class Type>
Linked_list<Type>::Linked_list(){
    // faz o primeiro nó apontar para NULL
    first = NULL;
}

/**
 * Destrutor
 */
template<class Type>
Linked_list<Type>::~Linked_list(){

    Node *before = NULL;
    
    if(first != NULL){
        
        before = first;
        first = first->nextNode;
    }
    
    for(first ; first != NULL; first = first->nextNode){
        delete before;
        before = first;
    }
    
    if(before != NULL) delete before;
    
}

/** 
 * Insere um nodo na lista
 * Retorna false se não conseguir alocar o nodo
 * Returna true se conseguir alocar
 *
 * Type item : valor a ser guardado no nodo
 */
template<class Type>
bool Linked_list<Type>::insertNode(Type item){

    // cria um ponteiro para Node e aloca memória
    Node *newNode = new Node;
    
    // Se não conseguir alocar, retorna false
    if(newNode==NULL)return false;
    
    // guarda objeto no nó
    newNode->item = item;
    
    // nextNode do novo nó aponta para first
    newNode->nextNode = first;
    
    // first aponta para o novo nó
    first = newNode;
    
    // returna operação bem sucedida
    return true;
}



/**
 * Imprime objeto armazenado em cada nó da lista
 * obs: o objeto precisa fazer overloading do operador <<
 */
template<class Type>
void Linked_list<Type>::printLinkedList(){

    // cria um ponteiro para Node
    Node *p;
    
    // percorre a lista, e imprime o objeto armazenado em cada nó
    for(p=first; p != NULL; p = p->nextNode)
        cout<<" "<< p->item;
    cout<<endl;
}

/** *********************************************************************
 * Implementações explícitas da classe Linked_list
 ************************************************************************/

template class Linked_list<int>; // int
template class Linked_list<float>; // float
template class Linked_list<double>; // double
template class Linked_list<string>; // string
template class Linked_list<char>; // char
