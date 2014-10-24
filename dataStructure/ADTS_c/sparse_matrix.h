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
 * \param rows quantidade de linhas
 * \param columns quantidade de colunas
 */
SparseMatrix* SPARSE_MATRIX_create(int rows, int columns);

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
 * Deleta um nó da matriz esparsa (na prática, o valor do nó passa a ser zero)
 * \return 1 em caso de sucesso ou 0 em caso de falha
 * \param sparseMatrix ponteiro para uma matriz esparsa
 * \param row linha da localização do nó a ser removido
 * \param column coluna da localização do nó a ser removido
 */
int SPARSE_MATRIX_delete(SparseMatrix* sparseMatrix, int row, int column);

/**
 * Pega valor do nó de uma localização específica, e armazena em value
 * \return 1 em caso de suceso ou 0 em caso de falha
 * \param sparseMatrix ponteiro para uma matriz esparsa
 * \param row linha da localização do nó do valor a ser retornado
 * \param column coluna da localização do nó do valor a ser retornado
 * \param value ponteiro para inteiro, esse inteiro a ser preenchido
 * com o valor do nó, se encontrado
 */
int SPARSE_MATRIX_get(SparseMatrix* sparseMatrix, int row, int column, int *value);

/**
 * Armazena quantidade de linhas e colunas nas variáveis rows e columns
 * \return 1 em caso de sucesso e 0 em caso de falha (ponteiro sparseMatrix é igual a NULL)
 * \param sparseMatrix ponteiro para uma matriz esparsa
 * \param rows ponteiro para inteiro, esse inteiro a ser preenchido com número de linhas
 * \param columns ponteiro para inteiro, esse inteiro a ser preenchido com número de colunas
 */
int SPARSE_MATRIX_getDimensions(SparseMatrix* sparseMatrix, int *rows, int *columns);

/**
 * Adiciona mais colunas na matriz
 * \return 1 em caso de sucesso ou 0 em caso de falha
 * \param sparseMatrix ponteiro para uma matriz esparsa
 * \param columns número de colunas para adicionar
 */
int SPARSE_MATRIX_insertColumns(SparseMatrix* sparseMatrix, int columns);

/**
 * Adiciona mais linhas na matriz
 * \return 1 em caso de sucesso ou 0 em caso de falha
 * \param sparseMatrix ponteiro para uma matriz esparsa
 * \param rows número de linhas para adicionar
 */
int SPARSE_MATRIX_insertRows(SparseMatrix* sparseMatrix, int rows);

/**
 * Diminui quantidade de colunas
 * \return 1 em caso de sucesso e 0 em caso de falha
 * \param sparseMatrix ponteiro para uma matriz esparsa
 * \param columns quantidade de colunas a serem removidas
 */
/**
 * As colunas mais à direita são removidas. Qualquer célula pertencente
 * a essas colunas são desalocadas. Como a matriz deve ter pelo menos uma
 * coluna, o retorno 0 é para quando tentar reduzir o número de colunas
 * para menos de 1.
 */
int SPARSE_MATRIX_removeColumns(SparseMatrix* sparseMatrix, int columns);

/**
 * Diminui quantidade de linhas
 * \return 1 em caso de sucesso e 0 em caso de falha
 * \param sparseMatrix ponteiro para uma matriz esparsa
 * \param rows quantidade de linhas a serem removidas
 */
/**
 * As linhas mais à baixo são removidas. Qualquer célula pertencente
 * a essas linhas são desalocadas. Como a matriz deve ter pelo menos uma
 * linha, o retorno 0 é para quando tentar reduzir o número de linhas
 * para menos de 1.
 */
int SPARSE_MATRIX_removeRows(SparseMatrix* sparseMatrix, int rows);

/**
 * Imprime a matriz esparsa
 * \param sparseMatrix ponteiro para uma matriz esparsa
 */
void SPARSE_MATRIX_print(SparseMatrix* sparseMatrix);

#endif // SPARSE_MATRIX_H
