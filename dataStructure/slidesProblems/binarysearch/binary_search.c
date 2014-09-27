#include<stdio.h>

int binarysearch(int *v, int size, int element){
    
    int begin = 0;
    int end = size - 1;
    int middle = (begin + end)/2;
    
    int returned;
    
    if(begin > end)
        return -1;
    
    else if(v[middle] < element){
        returned = binarysearch(v+middle+1,size-middle-1,element);
        if(returned == -1)
            return -1;
        else
            return (middle + 1 + returned);
    }
    
    else if(v[middle] > element){
        returned = binarysearch(v,middle,element);
        if(returned == -1)
            return -1;
        else
            return returned;
    }
    
    else
        return middle;
    
}

int main()
{
    int myVec[] = {4,5,6,7,8,9};
    
    printf("%d\n",binarysearch(myVec,sizeof(myVec)/sizeof(int),9));
    
    return 0;
}
