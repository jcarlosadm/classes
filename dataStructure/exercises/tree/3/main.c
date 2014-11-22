/**
gcc -o main main.c calc.c binary_tree.c dStack_BinaryTree.c dStack_double.c
*/
#include <stdio.h>
#include "calc.h"

int
main (int argc, char *argv[])
{
    printf("%.2f\n",CALC_evalExpression("38+42-*25*/0/"));
    
    
    return 0;
}
