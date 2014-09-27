#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>
#include <string>
#include <new>
using namespace std;

/**
 * Classe Linked_list
 * Cria objeto de lista encadeada de um tipo específico
 * Tipos permitidos: int, float, double, char, string
 */
template<class Type>
class Linked_list {
    
    public:
    
    /** Construtor padrão */
    /** faz o nó inicial apontar para NULL */
    Linked_list();
    
    /** destrutor */
    ~Linked_list();
    
    /**
     * Insere nó no começo da lista
     * Retorna false se não conseguir alocar memória
     * Retorna true se conseguir
     *
     * Type item : objeto a ser inserido no nó
     */
    bool insertNode(Type item);
    
    /**
     * Imprime objeto armazenado em cada nó da lista
     * obs: o objeto precisa fazer overloading do operador <<
     */
    void printLinkedList();
    
    /**
     * Remove um nó com o conteúdo especificado e retorna um ponteiro
     * para o primeiro nó da lista
     * 
     * Node* first : o primeiro nó da lista
     * int item : o conteúdo do nó a ser removido
     */
    Node* removeNode(int item);
    
    private:
    
    /** Estrutura de cada nó */
    struct Node {
        Type item;
        Node *nextNode;
    };
    
    /** nó inicial da lista */
    Node *first;
    
};

#endif // LINKED_LIST_HPP
