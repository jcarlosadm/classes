#include "sparse_matrix4.h"

/**
 * Estrutura do nó de uma matriz esparsa
 */
typedef struct node Node;
struct node{
    int item; ///< valor armazenado no nó
    int row; ///< linha da localização do nó
    int column; ///< coluna da localização do nó
    Node* nextRow; ///< ponteiro para a próxima linha
    Node* previousRow; ///< ponteiro para a linha anterior
    Node* nextColumn; ///< ponteiro para a próxima coluna
    Node* previousColumn; ///< ponteiro para a coluna anterior
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
    // verifica se a quantidade de linhas e colunas informadas
    // são o mínimo necessário
    if(rows<1 || columns<1)return NULL;
    
    // aloca a matriz
    SparseMatrix* sparseMatrix = malloc(sizeof(SparseMatrix));
    if(!sparseMatrix) return NULL;
    
    // aloca no nó raiz
    sparseMatrix->head = malloc(sizeof(Node));
    if(!sparseMatrix->head){
        free(sparseMatrix);
        return NULL;
    }
    
    // configura os valores do nó raiz
    sparseMatrix->head->row = 0;
    sparseMatrix->head->column = 0;
    sparseMatrix->head->item = 0;
    sparseMatrix->head->previousRow = NULL;
    sparseMatrix->head->previousColumn = NULL;
    
    // Aloca um nó coluna
    Node* current = malloc(sizeof(Node));
    current->column = 1;
    current->row = 0;
    current->nextRow = current;
    current->previousRow = current;
    current->previousColumn = sparseMatrix->head;
    sparseMatrix->head->nextColumn = current;
    
    // aloca vários nós colunas
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
        current->nextColumn->previousRow = current->nextColumn;
        current->nextColumn->previousColumn = current;
        
        current = current->nextColumn;
    }
    current->nextColumn = sparseMatrix->head;
    sparseMatrix->head->previousColumn = current;
    
    // Aloca um nó linha
    current = malloc(sizeof(Node));
    current->row = 1;
    current->column = 0;
    current->nextColumn = current;
    current->previousColumn = current;
    current->previousRow = sparseMatrix->head;
    sparseMatrix->head->nextRow = current;
    
    // Aloca vários nós linhas
    for(i=1;i<rows;i++){
        current->nextRow = malloc(sizeof(Node));
        if(!current->nextRow){
            SPARSE_MATRIX_free(sparseMatrix);
            return NULL;
        }
        current->nextRow->row = i+1;
        current->nextRow->column = 0;
        current->nextRow->nextColumn = current->nextRow;
        current->nextRow->previousColumn = current->nextRow;
        current->nextRow->previousRow = current;
        
        current = current->nextRow;
    }
    current->nextRow = sparseMatrix->head;
    sparseMatrix->head->previousRow = current;
    
    // guarda a quantidade de linhas e colunas
    sparseMatrix->rows = rows;
    sparseMatrix->columns = columns;
    
    // retorna ponteiro para a matriz
    return sparseMatrix;
}

/**
 * Desaloca uma matriz esparsa
 * \return Retorna NULL
 * \param sparseMatrix ponteiro para uma matriz esparsa
 */
SparseMatrix* SPARSE_MATRIX_free(SparseMatrix* sparseMatrix){
    // se a matriz esparsa não estiver alocada, retorna NULL
    if(!sparseMatrix) return NULL;
    
    // apenas se o nó raiz estiver alocado...
    if(sparseMatrix->head){
        // nó linha atual
        Node* row = sparseMatrix->head->nextRow;
        // nó interno atual
        Node* currentNode = NULL;
        // nó auxiliar para o nó interno
        Node* tempNode = NULL;
        // enquanto nó linha e nó linha diferente do nó raiz...
        while(row && row!=sparseMatrix->head){
            // pega um nó interno
            currentNode = row->nextColumn;
            // enquanto nó intero e nó interno diferente de nó linha atual...
            while(currentNode && currentNode!=row){
                // libera memória do nó interno
                tempNode = currentNode;
                currentNode = currentNode->nextColumn;
                free(tempNode);
            }
            // libera memória do nó linha atual
            tempNode = row;
            row = row->nextRow;
            free(tempNode);
        }
        
        sparseMatrix->head->nextRow = NULL;
        sparseMatrix->head->previousRow = NULL;
        
        // nó coluna atual aponta para a primeira coluna
        Node* column = sparseMatrix->head->nextColumn;
        // enquanto nó coluna e nó coluna diferente do nó raiz...
        while(column && column!=sparseMatrix->head){
            // libera nó coluna
            tempNode = column;
            column = column->nextColumn;
            free(tempNode);
        }
        sparseMatrix->head->nextColumn = NULL;
        sparseMatrix->head->previousColumn = NULL;
        
        // libera nó raiz
        free(sparseMatrix->head);
    }
    
    // libera a matriz
    free(sparseMatrix);
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
    // se a matriz não estiver alocada, retorna 0
    if(!sparseMatrix) return 0;
    
    // se a quantidade de linhas ou colunas não for suficiente, retorna 0
    if(sparseMatrix->columns < column || sparseMatrix->rows < row){
        printf("dimensoes insuficientes na matriz\n");
        return 0;
    }
    
    // se o valor a ser inserido for zero, deleta o valor daquela posição
    if(value==0){
        SPARSE_MATRIX_delete(sparseMatrix,row,column);
        return 1;
    }
    
    // nó que aponta para a coluna atual
    Node* currentColumn = sparseMatrix->head->nextColumn;
    
    // procura a coluna correta
    while(currentColumn){
        if(currentColumn->column == column)
            break;
        currentColumn = currentColumn->nextColumn;
    }
    
    // procura a linha correta
    Node* currentRow = sparseMatrix->head->nextRow;
    while(currentRow){
        if(currentRow->row == row)
            break;
        currentRow = currentRow->nextRow;
    }
    
    // nó que aponta para uma célula uma coluna anterior ao local desejado
    Node* cell = currentRow;
    // variável que verifica se a célula com a localização informada já existe
    int found = 0;
    
    // procura se o nó já existe ou a localização correta para inserção
    while(cell->nextColumn != currentRow){
    
        // encontrou uma célula já existente
        if(cell->nextColumn->column == column){
            found = 1;
            break;
        }
        // a próxima célula possui coluna maior que a deseja inserir
        else if(cell->nextColumn->column > column)
            break;
        cell = cell->nextColumn;
    }
    // se encontrou uma célula já existente, atualiza o valor e sai
    if(found){
        cell->nextColumn->item = value;
        return 1;
    }
    
    // não encontrou uma célula já existente. cria uma nova
    Node* newCell = malloc(sizeof(Node));
    if(!newCell) return 0;
    newCell->item = value;
    newCell->column = column;
    newCell->row = row;
    // configura ponteiros da nova célula
    if(cell->nextColumn == currentRow){
        cell->nextColumn = newCell;
        newCell->previousColumn = cell;
        newCell->nextColumn = currentRow;
        currentRow->previousColumn = newCell;
    }
    else{
        newCell->nextColumn = cell->nextColumn;
        newCell->previousColumn = cell;
        cell->nextColumn->previousColumn = newCell;
        cell->nextColumn = newCell;
    }
    
    // agora verifica os ponteiros a partir da coluna
    cell = currentColumn;
    while(cell->nextRow != currentColumn){
        // se a próxima linha for maior que a linha desejada, encontrou o local correto
        if(cell->nextRow->row > row)
            break;
        cell = cell->nextRow;
    }
    
    // configura os ponteiros do novo nó
    if(cell->nextRow == currentColumn){
        cell->nextRow = newCell;
        newCell->previousRow = cell;
        newCell->nextRow = currentColumn;
        currentColumn->previousRow = newCell;
    }
    else{
        newCell->nextRow = cell->nextRow;
        newCell->previousRow = cell;
        cell->nextRow->previousRow = newCell;
        cell->nextRow = newCell;
    }
    
    // todas as operações foram bem sucedidas
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
    if(!sparseMatrix) return 0;
    
    // se informou quantidade insuficiente de linha ou coluna, sai da função
    if(sparseMatrix->rows < row || sparseMatrix->columns < column){
        printf("dimensoes insuficientes da matriz\n");
        return 0;
    }
    
    // ponteiro que aponta para um nó linha da matriz
    Node* current = sparseMatrix->head->nextRow;
    // nó interno procurado
    Node* node = NULL;
    // variável que indica se o nó interno foi encontrado
    int foundRow = 0;
    // procura a linha correta
    while(current && current!=sparseMatrix->head){
        // encontrou a linha correta
        if(current->row == row){
            // pega referência para o próximo nó interno da linha
            node = current->nextColumn;
            // procura o nó da posição informada
            while(node && node!=current){
                if(node->column == column){
                    foundRow = 1;
                    break;
                }
                else if(node->column > column)
                    break;
                node = node->nextColumn;
            }
        }
        else if(current->row > row)
            break;
        
        if(foundRow) break;
        
        current = current->nextRow;
    }
    
    // se não foi encontrado, retorna 0
    if(!foundRow) return 0;
    
    // configura os ponteiros dos nós próximos ao encontrado
    node->previousRow->nextRow = node->nextRow;
    node->nextRow->previousRow = node->previousRow;
    node->previousColumn->nextColumn = node->nextColumn;
    node->nextColumn->previousColumn = node->previousColumn;
    
    // libera nó
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
    // se matriz não alocada, retorna 0
    if(!sparseMatrix) return 0;
    // se quantidade de linhas ou colunas informadas não suficiente, retorna 0
    if(sparseMatrix->rows < row || sparseMatrix->columns < column)
        return 0;
    
    // nó linha atual
    Node* current = sparseMatrix->head->nextRow;
    // nó interno atual
    Node* node = NULL;
    // procura nó interno
    while(current && current!=sparseMatrix->head){
        if(current->row == row){
            node = current->nextColumn;
            while(node && node!=current){
                if(node->column == column){
                    // encontrou
                    (*value) = node->item;
                    return 1;
                }
                else if(node->column > column)
                    return 0;
                node = node->nextColumn;
            }
            return 0;
        }
        else if(current->row > row)
            return 0;
        
        current = current->nextRow;
    }
    // não encontrou
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
    
    if(!sparseMatrix) return 0;
    
    // última coluna
    Node* current = sparseMatrix->head->previousColumn;
    
    int count;
    // aloca todas as colunas
    for(count=0;count<columns;count++){
        // aloca próxima coluna
        current->nextColumn = malloc(sizeof(Node));
        if(!current->nextColumn){
            printf("%d columns added\n",count);
            current->nextColumn = sparseMatrix->head;
            sparseMatrix->head->previousColumn = current;
            return 0;
        }
        current->nextColumn->nextRow = current->nextColumn;
        current->nextColumn->previousRow = current->nextColumn;
        current->nextColumn->column = sparseMatrix->columns+1;
        current->nextColumn->row = 0;
        sparseMatrix->columns = sparseMatrix->columns + 1;
        current->nextColumn->previousColumn = current;
        current = current->nextColumn;
    }
    current->nextColumn = sparseMatrix->head;
    sparseMatrix->head->previousColumn = current;
    
    return 1;
}

/**
 * Adiciona mais linhas na matriz
 * \return 1 em caso de sucesso ou 0 em caso de falha
 * \param sparseMatrix ponteiro para uma matriz esparsa
 * \param rows número de linhas para adicionar
 */
int SPARSE_MATRIX_insertRows(SparseMatrix* sparseMatrix, int rows){

    if(!sparseMatrix) return 0;
    
    Node* current = sparseMatrix->head->previousRow;    
    
    int count;
    for(count=0;count<rows;count++){
        current->nextRow = malloc(sizeof(Node));
        if(!current->nextRow){
            printf("%d rows added\n",count);
            current->nextRow = sparseMatrix->head;
            sparseMatrix->head->previousRow = current;
            return 0;
        }
        current->nextRow->nextColumn = current->nextRow;
        current->nextRow->previousColumn = current->nextRow;
        current->nextRow->row = sparseMatrix->rows + 1;
        current->nextRow->column = 0;
        sparseMatrix->rows = sparseMatrix->rows + 1;
        current->nextRow->previousRow = current;
        current = current->nextRow;
    }
    current->nextRow = sparseMatrix->head;
    sparseMatrix->head->previousRow = current;
    
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
