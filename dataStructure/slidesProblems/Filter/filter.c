#include <stdio.h>

int even_func(int num){
    return (num%2 == 0);
}

int odd_func(int num){
    return (num%2 != 0);
}

void filter_func(int(*f)(int),int *array,int array_size){

    if((*f)(*array))
        printf(" %d ",(*array));
        
    if(array_size > 1)
        filter_func(f,(array+1),array_size-1);
    else
        printf("\n");
}

int main(int argc, char* argv[]){
    int myarray[] = {1,2,3,4,5,6,7,8};
    
    filter_func(even_func,myarray,sizeof(myarray)/sizeof(int));
    filter_func(odd_func,myarray,sizeof(myarray)/sizeof(int));
    
    return 0;
}
