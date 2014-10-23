#include "sparse_matrix.h"

/**
 * Estrutura do nó de uma matriz esparsa
 */
typedef struct node Node;
struct node{
    int item; ///< valor armazenado no nó
    int row; ///< linha da localização do nó
    int column; ///< coluna da localização do nó
    Node* nextRow; ///< ponteiro para a próxima linha
    Node* nextColumn; ///< ponteiro para a próxima coluna
};

/**
 * Estrutura da matriz esparsa
 */
struct sparseMatrix{
    Node* head; ///< ponteiro para a linha 1 e coluna 1
};

/**
 * Aloca a matriz esparsa
 * \return Retorna o ponteiro para a matriz esparsa, ou
 * NULL se não foi possível alocar memória
 */
SparseMatrix* SPARSE_MATRIX_create(){
    SparseMatrix* sparseMatrix = malloc(sizeof(SparseMatrix));
    if(!sparseMatrix) return NULL;
    
    sparseMatrix->head = NULL;
    return sparseMatrix;
}

/**
 * Desaloca uma matriz esparsa
 * \return Retorna NULL
 * \param sparseMatrix ponteiro para uma matriz esparsa
 */
SparseMatrix* SPARSE_MATRIX_free(SparseMatrix* sparseMatrix){
    if(sparseMatrix){
        if(sparseMatrix->head){
            Node* row = sparseMatrix->head->nextRow;
            Node* currentNode = NULL;
            Node* tempNode = NULL;
            while(row && row!=sparseMatrix->head){
                currentNode = row->nextColumn;
                while(currentNode && currentNode!=row){
                    tempNode = currentNode;
                    currentNode = currentNode->nextColumn;
                    free(tempNode);
                }
                tempNode = row;
                row = row->nextRow;
                free(tempNode);
            }
            sparseMatrix->head->nextRow = NULL;
            Node* column = sparseMatrix->head->nextColumn;
            while(column && column!=sparseMatrix->head){
                tempNode = column;
                column = column->nextColumn;
                free(tempNode);
            }
            sparseMatrix->head->nextColumn = NULL;
            free(sparseMatrix->head);
        }
        
        free(sparseMatrix);
    }
}

/**
 * Insere ou atualiza um nó na matriz esparsa
 * \return 1 em caso de sucesso, ou 0 em caso contrário
 * \param sparseMatrix ponteiro para uma matriz esparsa
 * \param row linha da localização onde o nó será inserido
 * \param column coluna da localização onde o nó será inserido
 * \param value valor a ser inserido
 */
int SPARSE_MATRIX_insert(SparseMatrix* sparseMatrix, int row, int column, int value){
    
}




