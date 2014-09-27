#include<stdio.h>

// return -1 : not found
int linearsearch(int *v, int size, int element){
    
    int returned;
    
    if(size <= 0)
        return -1;
    else if(*(v) == element)
        return 0;
    else{
        returned = linearsearch(v+1,size-1,element);
        if(returned == -1)
            return -1;
        else
            return (1+returned);
    }
}

int main()
{
    int myVec[] = {2,1,4,3,5,4,2,34};
    
    int found = linearsearch(myVec,sizeof(myVec)/sizeof(int),34);
    
    if(found != -1)
        printf("indice: %d\n",found);
    else
        printf("nao encontrado\n");
    
    return 0;
}
