#include <stdio.h>
#include <stdlib.h>
#include "dStack_BinaryTree.h"
#include "binary_tree.h"

#include "calc.h"

int CALC_isNumber(char* value){
    if(48 <= value[0] && value[0] <= 57)
        return 1;
    return 0;
}

/**
 * Calcula uma expressão pósfixa
 * \return Retorna o valor da expressão
 * \param expression Expressão na forma de string
 */
double CALC_evalExpression(char* expression){
    
    double result;
    
    DStack *dStack = dStackCreateStack_bt();
    BinaryTree* firstTree = NULL;
    BinaryTree* secondTree = NULL;
    
    int currentPosition = 0;
    while(expression[currentPosition]!=0){
        
        if(CALC_isNumber(expression+currentPosition)){
            dStackPush_bt(dStack, BINARYEXPRESSIONTREE_create(expression[currentPosition]));
        }
        else{
            firstTree = dStackPop_bt(dStack);
            secondTree = dStackPop_bt(dStack);
            dStackPush_bt(dStack, BINARYEXPRESSIONTREE_insertOperator(firstTree, 
                secondTree, expression[currentPosition]));
            firstTree = NULL;
            secondTree = NULL;
        }
        
        currentPosition++;
    }
    
    result = BINARYEXPRESSIONTREE_evalExpression(dStackPop_bt(dStack));
    
    while(!dStackIsEmpty_bt(dStack)){
        firstTree = dStackPop_bt(dStack);
        firstTree = BINARYTREE_free(firstTree);
        firstTree = NULL;
    }
    
    dStack = dStackFree_bt(dStack);
    
    return result;
}


