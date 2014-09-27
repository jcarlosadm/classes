#include "sort.hpp"


/** **************************************************************
 * Funções privadas
 *****************************************************************/

/*
 * Troca a posição de dois elementos no array
 *
 * int *array : array de inteiros
 * int pos1 : posição 1 a ser trocada
 * int pos2 : posição 2 a ser trocada
 */
template<typename Type>
void swap(Type *array,int pos1, int pos2){
    Type aux = array[pos1];
    array[pos1] = array[pos2];
    array[pos2] = aux;
}

/*
 * Função auxiliar do selectionsort
 * Pega o menor valor do array e retorna o seu índice
 *
 * int *array : ponteiro para o início de um array de inteiros
 * int size : tamanho do array
 * int min : o índice do valor mínimo, até o momento
 */
template<typename Type>
int selectMin(Type *array, int size, int min){
    
    if(size > 0){
        min--;
        if(array[0] <= array[min])
            return 1+selectMin(array+1,size-1,0);
        else
            return 1+selectMin(array+1,size-1,min);
    }
    else
        return min;
    
}

/*
 * Função auxiliar do insertionsort
 * coloca a key atual em seu lugar
 *
 * int *array : ponteiro para array de inteiros
 * int size : tamanho do array
 * int key : chave que será movida para o local correto
 */
template<typename Type>
void insertion(Type *array, int size, Type key){
    
    int index = size-1;
    
    if(index>=0 && array[index] > key){
        array[index+1] = array[index];
        insertion(array,size-1,key);
    }else{
        array[index+1] = key;
    }
}

/*
 * Função auxiliar para o bubblesort
 * Coloca o maior elemento na última posição do array
 *
 * int *array : ponteiro para o início de um array de inteiros
 * int size : tamanho do array
 */
template<typename Type>
void bubble(Type *array, int size){
    
    if(size>1){
        
        if(array[0] > array[1])
            swap(array,0,1);
        bubble(array+1,size-1);
        
    }
    
}

template<typename Type>
int maxDefinition(Type* array){
    return INT_MAX;
}

template<>
int maxDefinition<char>(char* array){
    return CHAR_MAX;
}

template<>
int maxDefinition<string>(string* array){
    return CHAR_MAX;
}

/*
 * Função auxiliar para o mergesort
 * Junta dois arrays individualmente ordenados
 * os arrays são ordenados entre si no processo
 * 
 * int *array : ponteiro para o início de um array de inteiros
 * int begin : início do primeiro array
 * int mid : fim do primeiro array
 * int end : fim do segundo array
 */
template<typename Type>
void merge(Type *array, int begin, int mid, int end){
    int size1 = mid - begin + 1;
    int size2 = end - mid;
    
    Type left[size1+1];
    Type right[size2+1];
    
    int index1;
    for(index1=0;index1<size1;index1++)
        left[index1] = array[begin+index1];
        
    for(index1=0;index1<size2;index1++)
        right[index1] = array[mid+index1+1];
    
    left[size1]=maxDefinition<Type>(left);
    right[size2]=maxDefinition<Type>(right);
    
    index1 = 0;
    int index2 = 0;
    int index3;
    for(index3=begin;index3<=end;index3++){
        if(left[index1]<=right[index2]){
            array[index3]=left[index1];
            index1++;
        }
        else{
            array[index3]=right[index2];
            index2++;
        }
    }
}

/** *****************************************************************
 * Funções públicas
 ********************************************************************/

/*
 * Ordena array de inteiros
 *
 * int *array : ponteiro para o início de um array de inteiros
 * int size : tamanho do array
 */
template<class Type>
void Sort<Type>::selectionsort(Type *array, int size){
    
    if(size>0){
        int min = selectMin(array+1, size-1, 0);
        swap(array,0,min);
        selectionsort(array+1,size-1);
    }
    
}

/*
 * Ordena array de inteiros
 *
 * int *array : ponteiro para o início de um array de inteiros
 * int size : tamanho do array
 */
template<class Type>
void Sort<Type>::insertionsort(Type *array, int size){
    
    if(size > 1){
        
        insertionsort(array,size-1);
        
        insertion(array,size-1,array[size-1]);
        
    }
    
}

/*
 * Ordena array de inteiros
 *
 * int *array : ponteiro para o início de um array de inteiros
 * int size : tamanho do array
 */
template<class Type>
void Sort<Type>::bubblesort(Type *array, int size){
    
    if(size>0){
        
        bubble(array,size);
        bubblesort(array,size-1);
        
    }
    
}

/*
 * Ordena array de inteiros
 *
 * int *array : ponteiro para o início de um array de inteiros
 * int size : tamanho do array
 */
template<class Type>
void Sort<Type>::quicksort(Type *array, int size){
    
    if(size > 1){
        
        Type pivot = array[size/2];
        int index1 = 0;
        int index2 = size - 1;
        
        while(index1 < index2){
            
            while(array[index1] < pivot) index1++;
            while(array[index2] > pivot) index2--;
            
            if( (array[index1] == array[index2]) &&
                (index1 < index2) )
                index1++;
            else if(index1 < index2)
                swap(array, index1, index2);
        }
        quicksort(array, index2);
        quicksort(array + index1, size - index1);
        
    }
    
}

/*
 * Ordena array de inteiros
 *
 * int *array : ponteiro para o início de um array de inteiros
 * int begin : início do array (começa com 0)
 * int end : final do array (size-1)
 */
template<class Type>
void Sort<Type>::mergesort(Type *array, int begin, int end){
    
    if(begin < end){
        int mid = (begin+end)/2;
        
        mergesort(array,begin,mid);
        mergesort(array,mid+1,end);
        merge(array,begin,mid,end);
    }
    
}

template class Sort<int>;
template class Sort<float>;
template class Sort<double>;
template class Sort<char>;
template class Sort<string>;
