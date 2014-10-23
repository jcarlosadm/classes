/**
 * \file
 * TAD de matriz esparsa
 * (Cada nó guarda um inteiro)
 */
 
#ifndef SPARSE_MATRIX_H
#define SPARSE_MATRIX_H

#include <stdio.h>
#include <stdlib.h>

/**
 * Estrutura da matriz esparsa
 */
typedef struct sparseMatrix SparseMatrix;

/**
 * Aloca a matriz esparsa
 * \return Retorna o ponteiro para a matriz esparsa, ou
 * NULL se não foi possível alocar memória
 */
SparseMatrix* SPARSE_MATRIX_create();

/**
 * Desaloca uma matriz esparsa
 * \return Retorna NULL
 * \param sparseMatrix ponteiro para uma matriz esparsa
 */
SparseMatrix* SPARSE_MATRIX_free(SparseMatrix* sparseMatrix);

/**
 * Insere ou atualiza um nó na matriz esparsa
 * \return 1 em caso de sucesso, ou 0 em caso contrário
 * \param sparseMatrix ponteiro para uma matriz esparsa
 * \param row linha da localização onde o nó será inserido
 * \param column coluna da localização onde o nó será inserido
 * \param value valor a ser inserido
 */
int SPARSE_MATRIX_insert(SparseMatrix* sparseMatrix, int row, int column, int value);

/**
 * Deleta um nó da matriz esparsa
 * \return 1 em caso de sucesso ou 0 em caso de falha
 * \param sparseMatrix ponteiro para uma matriz esparsa
 * \param row linha da localização do nó a ser removido
 * \param column coluna da localização do nó a ser removido
 */
int SPARSE_MATRIX_delete(SparseMatrix* sparseMatrix, int row, int column);

/**
 * Pega valor do nó de uma localização específica, e armazena em value
 * \return 1 em caso de suceso ou 0 em caso de falha
 * \param row linha da localização do nó do valor a ser retornado
 * \param column coluna da localização do nó do valor a ser retornado
 * \param *value ponteiro para inteiro, esse inteiro a ser preenchido
 * com o valor do nó, se encontrado
 */
int SPARSE_MATRIX_get(SparseMatrix* sparseMatrix, int row, int column, int *value);

#endif // SPARSE_MATRIX_H
