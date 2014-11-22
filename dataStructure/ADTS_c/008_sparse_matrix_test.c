#include <stdio.h>
#include "sparse_matrix.h"

int
main (int argc, char *argv[])
{
    
    SparseMatrix* sparseMatrix = SPARSE_MATRIX_create(3,4);
    if(!sparseMatrix) return 1;
    
    SPARSE_MATRIX_insert(sparseMatrix,1,1,10);
    SPARSE_MATRIX_insert(sparseMatrix,1,2,34);
    SPARSE_MATRIX_insert(sparseMatrix,2,1,77);
    SPARSE_MATRIX_insert(sparseMatrix,3,1,88);
    SPARSE_MATRIX_insert(sparseMatrix,2,3,1010);
    
    SPARSE_MATRIX_print(sparseMatrix);
    
    SPARSE_MATRIX_delete(sparseMatrix,2,1);
    SPARSE_MATRIX_print(sparseMatrix);
    
    int value = 0;
    if(SPARSE_MATRIX_get(sparseMatrix,1,1,&value))
        printf("na posicao %d %d: %d\n",1,1,value);
    
    int rows,columns;
    if(SPARSE_MATRIX_getDimension(sparseMatrix, &rows, &columns))
        printf("dimension: %d x %d\n", rows, columns);
    
    SPARSE_MATRIX_insertColumns(sparseMatrix,2);
    SPARSE_MATRIX_insert(sparseMatrix,3,5,20);
    SPARSE_MATRIX_print(sparseMatrix);
    
    if(SPARSE_MATRIX_getDimension(sparseMatrix, &rows, &columns))
        printf("dimension: %d x %d\n", rows, columns);
        
    SPARSE_MATRIX_insertRows(sparseMatrix,2);
    if(SPARSE_MATRIX_getDimension(sparseMatrix, &rows, &columns))
        printf("dimension: %d x %d\n", rows, columns);
    SPARSE_MATRIX_insert(sparseMatrix,5,5,1230);
    SPARSE_MATRIX_print(sparseMatrix);
    
    SPARSE_MATRIX_removeColumns(sparseMatrix,2);
    if(SPARSE_MATRIX_getDimension(sparseMatrix, &rows, &columns))
        printf("dimension: %d x %d\n", rows, columns);
    SPARSE_MATRIX_print(sparseMatrix);
    
    SPARSE_MATRIX_removeRows(sparseMatrix,3);
    if(SPARSE_MATRIX_getDimension(sparseMatrix, &rows, &columns))
        printf("dimension: %d x %d\n", rows, columns);
    SPARSE_MATRIX_print(sparseMatrix);
    
    sparseMatrix = SPARSE_MATRIX_free(sparseMatrix);
    
    return 0;
}
