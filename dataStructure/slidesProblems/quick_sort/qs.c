#include <stdio.h>

void swap(int *v1,int *v2){
    int i;
    
    i = *v1;
    *v1 = *v2;
    *v2 = i;
}

void quicksort(int *v, int size)
{
    
    if(size<=1){
        return;
    }
    
    else{
    
        int pivot = v[size/2];
        int a = 0; int b = size -1;
        int i;
        
        while(a < b){
        
            printf("antes da ordenacao: ");
            for(i=0;i<size;i++)printf(" %d",v[i]);
            printf("    a:%d  b:%d || v[a]:%d  v[b]:%d || pivot:%d",a,b,v[a],v[b],pivot);
            printf("\n");
        
            while(v[a] < pivot) a++;
            
            while(v[b] > pivot) b--;
            
            
            if(v[a]==v[b] && a < b) // se v[a] == v[b] apenas incrementa a, sem troca
                a++;
                
            else if(a < b){
                swap(v+a,v+b);
            }
            
            printf("apos a ordenacao:   ");
            for(i=0;i<size;i++)printf(" %d",v[i]);
            printf("    a:%d  b:%d || v[a]:%d  v[b]:%d || pivot:%d",a,b,v[a],v[b],pivot);
            printf("\n");
            
        }
        
        printf("antes da recursao: ");
        for(i=0;i<size;i++)printf(" %d",v[i]);
        printf("\n");
        
        quicksort(v,b);
        quicksort(v+a,size - a);
                                
        printf("depois da recursao: ");
        for(i=0;i<size;i++)printf(" %d",v[i]);
        printf("\n");
    }
    
}

int main()
{
    int i=0;
    int v[] = {1,2,3,4,5,5,5,5,5,5,4,3,2,1,1,1,1,5,9,8,7,5};
    
    printf("antes da primeira chamada do quicksort:");
    for(i=0;i<sizeof(v)/sizeof(int);i++)
        printf(" %d",v[i]);
    printf("\n");
    
    quicksort(v,sizeof(v)/sizeof(int));
    
    printf("depois do quicksort ser finalizado totalmente:");
    for(i=0;i<sizeof(v)/sizeof(int);i++)
        printf(" %d",v[i]);
    printf("\n");
    
    return 0;
}
