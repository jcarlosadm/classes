#include <stdio.h>
#include <stdlib.h>

float square_func(float num){
    return num*num;
}

float factorial_func(float num){
    
    if(num < 0){
        printf("os elementos devem ser maiores ou iguais a zero\n");
        exit(1);
    }
    
    if(num < 1)
        return 1;
    else
        return num * factorial_func(num - 1);
}

void map_func(float(*f)(float),float* array, int array_size){
    
    (*array) = (*f)(*array);
    
    if(array_size > 1)
        map_func(f,(array+1),array_size-1);
    
}

int main()
{
    float myarray[] = {1,2,3,4,5,6,7};
    map_func(square_func,myarray,sizeof(myarray)/sizeof(int));
    
    int i;
    for(i = 0; i<(sizeof(myarray)/sizeof(int));i++)
        printf(" %.2f ",myarray[i]);
    printf("\n");
    
    return 0;
}
