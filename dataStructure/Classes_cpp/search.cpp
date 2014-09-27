#include "search.hpp"

template<class Type>
int Search<Type>::linearsearch(Type element, Type *array, int size){

    if(size>0){
        if(array[0]==element)
            return 0;
        else{
            int search = linearsearch(element, array+1, size-1);
            if(search != -1)
                return 1+search;
            else
                return -1;
        }
    }
    else
        return -1;
        
}

template<class Type>
int Search<Type>::binarysearch(Type element, Type *array, int size){
    
    int begin = 0;
    int end = size - 1;
    int middle = (begin + end)/2;
    
    int returned;
    
    if(begin > end)
        return -1;
    
    else if(array[middle] < element){
        returned = binarysearch(element,array+middle+1,size-middle-1);
        if(returned == -1)
            return -1;
        else
            return (middle + 1 + returned);
    }
    
    else if(array[middle] > element){
        returned = binarysearch(element,array,middle);
        if(returned == -1)
            return -1;
        else
            return returned;
    }
    
    else
        return middle;
    
}

template class Search<int>;
template class Search<float>;
template class Search<double>;
template class Search<char>;
template class Search<string>;
