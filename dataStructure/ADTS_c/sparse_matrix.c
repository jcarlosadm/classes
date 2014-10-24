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
    Node* head; ///< ponteiro para a linha 0 e coluna 0
    int rows; ///< guarda quantidade de linhas
    int columns; ///< guarda quantidade de colunas
};

/**
 * Aloca a matriz esparsa
 * \return Retorna o ponteiro para a matriz esparsa, ou
 * NULL se não foi possível alocar memória
 * \param rows quantidade de linhas
 * \param columns quantidade de colunas
 */
SparseMatrix* SPARSE_MATRIX_create(int rows, int columns){
    if(rows<1 || columns<1)return 0;
    
    SparseMatrix* sparseMatrix = malloc(sizeof(SparseMatrix));
    if(!sparseMatrix) return NULL;
    
    sparseMatrix->head = malloc(sizeof(Node));
    if(!sparseMatrix->head){
        free(sparseMatrix);
        return NULL;
    }
    
    sparseMatrix->head->row = 0;
    sparseMatrix->head->column = 0;
    sparseMatrix->head->item = 0;
    
    Node* current = malloc(sizeof(Node));
    current->column = 1;
    current->row = 0;
    current->nextRow = current;
    sparseMatrix->head->nextColumn = current;
    
    int i;
    for(i=1;i<columns;i++){
        current->nextColumn = malloc(sizeof(Node));
        if(!current->nextColumn){
            SPARSE_MATRIX_free(sparseMatrix);
            return NULL;
        }
        current->nextColumn->column = i+1;
        current->nextColumn->row = 0;
        current->nextColumn->nextRow = current->nextColumn;
        
        current = current->nextColumn;
    }
    current->nextColumn = sparseMatrix->head;
    
    current = malloc(sizeof(Node));
    current->row = 1;
    current->column = 0;
    current->nextColumn = current;
    sparseMatrix->head->nextRow = current;
    
    for(i=1;i<rows;i++){
        current->nextRow = malloc(sizeof(Node));
        if(!current->nextRow){
            SPARSE_MATRIX_free(sparseMatrix);
            return NULL;
        }
        current->nextRow->row = i+1;
        current->nextRow->column = 0;
        current->nextRow->nextColumn = current->nextRow;
        
        current = current->nextRow;
    }
    current->nextRow = sparseMatrix->head;
    
    sparseMatrix->rows = rows;
    sparseMatrix->columns = columns;
    
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
        return NULL;
    }
    return NULL;
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
    if(sparseMatrix->columns < column || sparseMatrix->rows < row){
        printf("dimensoes insuficientes na matriz\n");
        return 0;
    }
    
    Node* currentColumn = sparseMatrix->head->nextColumn;
    while(currentColumn){
        if(currentColumn->column == column)
            break;
        currentColumn = currentColumn->nextColumn;
    }
    Node* currentRow = sparseMatrix->head->nextRow;
    while(currentRow){
        if(currentRow->row == row)
            break;
        currentRow = currentRow->nextRow;
    }
    
    Node* cell = currentRow;
    int found = 0;
    while(cell->nextColumn != currentRow){
        if(cell->nextColumn->column == column){
            found = 1;
            break;
        }
        else if(cell->nextColumn->column > column)
            break;
        cell = cell->nextColumn;
    }
    if(found){
        cell->nextColumn->item = value;
        return 1;
    }
    
    Node* newCell = malloc(sizeof(Node));
    if(!newCell) return 0;
    newCell->item = value;
    newCell->column = column;
    newCell->row = row;
    if(cell->nextColumn == currentRow){
        cell->nextColumn = newCell;
        newCell->nextColumn = currentRow;
    }
    else{
        newCell->nextColumn = cell->nextColumn;
        cell->nextColumn = newCell;
    }
    
    cell = currentColumn;
    while(cell->nextRow != currentColumn){
        if(cell->nextRow->row > row)
            break;
        cell = cell->nextRow;
    }
    
    if(cell->nextRow == currentColumn){
        cell->nextRow = newCell;
        newCell->nextRow = currentColumn;
    }
    else{
        newCell->nextRow = cell->nextRow;
        cell->nextRow = newCell;
    }
    
    return 1;
}

void SPARSE_MATRIX_test(SparseMatrix* sparseMatrix){
    Node* current = sparseMatrix->head->nextColumn;
    Node* cell = NULL;
    if(current!=sparseMatrix->head){
        printf("colunas:\n");
    }
    while(current!=sparseMatrix->head){
        cell = current->nextRow;
        if(cell!=current){
            while(cell != current){
                printf("%d ",cell->item);
                cell = cell->nextRow;
            }
            printf("\n");
        }
        current = current->nextColumn;
    }
    current = sparseMatrix->head->nextRow;
    cell = NULL;
    if(current!=sparseMatrix->head){
        printf("linhas:\n");
    }
    while(current!=sparseMatrix->head){
        cell = current->nextColumn;
        if(cell!=current){
            while(cell != current){
                printf("%d ",cell->item);
                cell = cell->nextColumn;
            }
            printf("\n");
        }
        current = current->nextRow;
    }
}

