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
    if(rows<1 || columns<1)return NULL;
    
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
    if(!sparseMatrix) return 0;
    
    if(sparseMatrix->columns < column || sparseMatrix->rows < row){
        printf("dimensoes insuficientes na matriz\n");
        return 0;
    }
    
    if(value==0){
        SPARSE_MATRIX_delete(sparseMatrix,row,column);
        return 1;
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

/**
 * Deleta um nó da matriz esparsa (na prática, o valor do nó passa a ser zero)
 * \return 1 em caso de sucesso ou 0 em caso de falha
 * \param sparseMatrix ponteiro para uma matriz esparsa
 * \param row linha da localização do nó a ser removido
 * \param column coluna da localização do nó a ser removido
 */
int SPARSE_MATRIX_delete(SparseMatrix* sparseMatrix, int row, int column){
    if(sparseMatrix->rows < row || sparseMatrix->columns < column){
        printf("dimensoes insuficientes da matriz\n");
        return 0;
    }
    
    Node* current = sparseMatrix->head->nextRow;
    Node* previousNode = NULL;
    int foundRow = 0;
    while(current && current!=sparseMatrix->head){
        if(current->row == row){
            previousNode = current;
            while(previousNode->nextColumn && previousNode->nextColumn!=current){
                if(previousNode->nextColumn->column == column){
                    foundRow = 1;
                    break;
                }
                previousNode = previousNode->nextColumn;
            }
        }
        if(foundRow) break;
        
        current = current->nextRow;
    }
    
    if(!foundRow) return 0;
    
    current = sparseMatrix->head->nextColumn;
    Node* upNode = NULL;
    int foundColumn = 0;
    while(current && current!=sparseMatrix->head){
        if(current->column == column){
            upNode = current;
            while(upNode->nextRow && upNode->nextRow!=current){
                if(upNode->nextRow->row == row){
                    foundColumn = 1;
                    break;
                }
                upNode = upNode->nextRow;
            }
        }
        if(foundColumn) break;
        current = current->nextColumn;
    }
    
    if(!foundColumn) return 0;
    
    Node* node = previousNode->nextColumn;
    
    previousNode->nextColumn = previousNode->nextColumn->nextColumn;
    upNode->nextRow = upNode->nextRow->nextRow;
    
    free(node);
    return 1;
}

/**
 * Pega valor do nó de uma localização específica, e armazena em value
 * \return 1 em caso de suceso ou 0 em caso de falha
 * \param sparseMatrix ponteiro para uma matriz esparsa
 * \param row linha da localização do nó do valor a ser retornado
 * \param column coluna da localização do nó do valor a ser retornado
 * \param value ponteiro para inteiro, esse inteiro a ser preenchido
 * com o valor do nó, se encontrado
 */
int SPARSE_MATRIX_get(SparseMatrix* sparseMatrix, int row, int column, int *value){
    if(!sparseMatrix) return 0;
    
    if(sparseMatrix->rows < row || sparseMatrix->columns < column)
        return 0;
    
    Node* current = sparseMatrix->head->nextRow;
    Node* node = NULL;
    while(current && current!=sparseMatrix->head){
        if(current->row == row){
            node = current->nextColumn;
            while(node && node!=current){
                if(node->column == column){
                    (*value) = node->item;
                    return 1;
                }
                node = node->nextColumn;
            }
            return 0;
        }
        
        current = current->nextRow;
    }
    return 0;
}

/**
 * Armazena quantidade de linhas e colunas nas variáveis rows e columns
 * \return 1 em caso de sucesso e 0 em caso de falha (ponteiro sparseMatrix é igual a NULL)
 * \param sparseMatrix ponteiro para uma matriz esparsa
 * \param rows ponteiro para inteiro, esse inteiro a ser preenchido com número de linhas
 * \param columns ponteiro para inteiro, esse inteiro a ser preenchido com número de colunas
 */
int SPARSE_MATRIX_getDimension(SparseMatrix* sparseMatrix, int *rows, int *columns){
    if(!sparseMatrix) return 0;
    
    (*rows) = sparseMatrix->rows;
    (*columns) = sparseMatrix->columns;
    return 1;
}

/**
 * Adiciona mais colunas na matriz
 * \return 1 em caso de sucesso ou 0 em caso de falha
 * \param sparseMatrix ponteiro para uma matriz esparsa
 * \param columns número de colunas para adicionar
 */
int SPARSE_MATRIX_insertColumns(SparseMatrix* sparseMatrix, int columns){
    Node* current = sparseMatrix->head;
    while(current->nextColumn && current->nextColumn != sparseMatrix->head){
        current = current->nextColumn;
    }
    
    int count;
    for(count=0;count<columns;count++){
        current->nextColumn = malloc(sizeof(Node));
        if(!current->nextColumn){
            printf("%d columns added\n",count);
            current->nextColumn = sparseMatrix->head;
            return 0;
        }
        current->nextColumn->nextRow = current->nextColumn;
        current->nextColumn->column = sparseMatrix->columns+1;
        current->nextColumn->row = 0;
        sparseMatrix->columns = sparseMatrix->columns + 1;
        current = current->nextColumn;
    }
    current->nextColumn = sparseMatrix->head;
    return 1;
}

/**
 * Adiciona mais linhas na matriz
 * \return 1 em caso de sucesso ou 0 em caso de falha
 * \param sparseMatrix ponteiro para uma matriz esparsa
 * \param rows número de linhas para adicionar
 */
int SPARSE_MATRIX_insertRows(SparseMatrix* sparseMatrix, int rows){
    Node* current = sparseMatrix->head;
    
    while(current->nextRow && current->nextRow!=sparseMatrix->head){
        current = current->nextRow;
    }
    
    
    int count;
    for(count=0;count<rows;count++){
        current->nextRow = malloc(sizeof(Node));
        if(!current->nextRow){
            printf("%d rows added\n",count);
            current->nextRow = sparseMatrix->head;
            return 0;
        }
        current->nextRow->nextColumn = current->nextRow;
        current->nextRow->row = sparseMatrix->rows + 1;
        current->nextRow->column = 0;
        sparseMatrix->rows = sparseMatrix->rows + 1;
        current = current->nextRow;
    }
    current->nextRow = sparseMatrix->head;
    
    return 1;
}

/**
 * Diminui quantidade de colunas
 * As colunas mais à direita são removidas. Qualquer célula pertencente
 * a essas colunas são desalocadas. Como a matriz deve ter pelo menos uma
 * coluna, o retorno 0 é para quando tentar reduzir o número de colunas
 * para menos de 1.
 * \return 1 em caso de sucesso e 0 em caso de falha
 * \param sparseMatrix ponteiro para uma matriz esparsa
 * \param columns quantidade de colunas a serem removidas
 */
int SPARSE_MATRIX_removeColumns(SparseMatrix* sparseMatrix, int columns){
    if(!sparseMatrix) return 0;
    
    if(sparseMatrix->columns - columns < 1)
        return 0;
    
    int remove;
    Node* current = sparseMatrix->head->nextRow;
    Node* node = NULL;
    Node* nav = NULL;
    while(current && current != sparseMatrix->head){
        node = current;
        while(node->nextColumn && node->nextColumn!=current){
            remove = sparseMatrix->columns - columns + 1;
            while(remove <= sparseMatrix->columns){
                if(node->nextColumn->column == remove)
                    break;
                remove++;
            }
            if(remove <= sparseMatrix->columns){
                nav = node->nextColumn;
                node->nextColumn = node->nextColumn->nextColumn;
                free(nav);
            }
            node = node->nextColumn;
        }
        current = current->nextRow;
    }
    current = sparseMatrix->head;
    remove = sparseMatrix->columns - columns + 1;
    while(current->nextColumn && current->nextColumn!=sparseMatrix->head){
        
        if(current->nextColumn->column == remove){
            node = current->nextColumn;
            current->nextColumn = current->nextColumn->nextColumn;
            free(node);
            
            remove++;
        }
        else
            current = current->nextColumn;
    }
    
    sparseMatrix->columns = sparseMatrix->columns - columns;
    
    return 1;
}

/**
 * Diminui quantidade de linhas
 * As linhas mais à baixo são removidas. Qualquer célula pertencente
 * a essas linhas são desalocadas. Como a matriz deve ter pelo menos uma
 * linha, o retorno 0 é para quando tentar reduzir o número de linhas
 * para menos de 1.
 * \return 1 em caso de sucesso e 0 em caso de falha
 * \param sparseMatrix ponteiro para uma matriz esparsa
 * \param rows quantidade de linhas a serem removidas
 */
int SPARSE_MATRIX_removeRows(SparseMatrix* sparseMatrix, int rows){
    if(!sparseMatrix) return 0;
    
    if(sparseMatrix->rows - rows < 1) return 0;
    
    int remove;
    Node* current = sparseMatrix->head->nextColumn;
    Node* node = NULL;
    Node* nav = NULL;
    while(current && current!=sparseMatrix->head){
        node = current;
        while(node->nextRow && node->nextRow != current){
            remove = sparseMatrix->rows - rows + 1;
            while(remove <= sparseMatrix->rows){
                if(node->nextRow->row == remove)
                    break;
                remove++;
            }
            if(remove <= sparseMatrix->rows){
                nav = node->nextRow;
                node->nextRow = node->nextRow->nextRow;
                free(nav);
            }
            node = node->nextRow;
        }
        current = current->nextColumn;
    }
    current = sparseMatrix->head;
    remove = sparseMatrix->rows - rows + 1;
    while(current->nextRow && current->nextRow!=sparseMatrix->head){
        if(current->nextRow->row == remove){
            node = current->nextRow;
            current->nextRow = current->nextRow->nextRow;
            free(node);
            
            remove++;
        }
        else
            current = current->nextRow;
    }
    
    sparseMatrix->rows = sparseMatrix->rows - rows;
    return 1;
}

/**
 * Imprime a matriz esparsa
 * \param sparseMatrix ponteiro para uma matriz esparsa
 */
void SPARSE_MATRIX_print(SparseMatrix* sparseMatrix){
    if(!sparseMatrix) return;
    
    Node* current = sparseMatrix->head->nextRow;
    Node* node;
    int count;
    printf("matriz:\n");
    while(current && current!=sparseMatrix->head){
        printf("row %d - ",current->row);
        node = current;
        for(count=1;count <= sparseMatrix->columns;count++){
            if(node->nextColumn->column == count){
                node = node->nextColumn;
                printf("%d ",node->item);
            }
            else{
                printf("0 ");
            }
        }
        printf("\n");
        current = current->nextRow;
    }
    
    current = sparseMatrix->head->nextColumn;
    printf("matriz transposta:\n");
    while(current && current!=sparseMatrix->head){
        printf("column %d - ",current->column);
        node = current;
        for(count=1;count <= sparseMatrix->rows;count++){
            if(node->nextRow->row == count){
                node = node->nextRow;
                printf("%d ",node->item);
            }
            else{
                printf("0 ");
            }
        }
        printf("\n");
        current = current->nextColumn;
    }
}

