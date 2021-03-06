#include <stdio.h>
#include <limits.h>

void merge(int *v, int begin, int mid, int end){
    int n1 = mid - begin + 1;
    int n2 = end - mid;
    
    int left[n1+1];
    int right[n1+1];
    
    int i,j,k;
    
    for(i=0;i<n1;i++)
        left[i] = v[begin+i];
        
    for(i=0;i<n2;i++)
        right[i] = v[mid+i+1];
        
    
    left[n1]=INT_MIN; // mudança 1
    right[n2]=INT_MIN; // mudança 2
    
    i = 0;
    j = 0;
    for(k=begin;k<=end;k++){
        if(left[i]>=right[j]){ // mudança 3
            v[k]=left[i];
            i++;
        }
        else{
            v[k]=right[j];
            j++;
        }
    }
}

void mergesort(int *v, int begin, int end){
    
    if(begin < end){
        int mid = (begin+end)/2;
        
        printf("begin: %d, mid: %d, end: %d\n",begin,mid,end);
        mergesort(v,begin,mid);
        mergesort(v,mid+1,end);
        merge(v,begin,mid,end);
    }
    
}

int main(int argc, char *argv[])
{
    int v[]={5,4,5,6,1,1,3,1,2,2,0,-4,-3,10,20,-5,1};
    
    int i;
    for(i=0;i<sizeof(v)/sizeof(int);i++)
        printf(" %d",v[i]);
    printf("\n");
    
    mergesort(v,0,sizeof(v)/sizeof(int)-1);
    
    for(i=0;i<sizeof(v)/sizeof(int);i++)
        printf(" %d",v[i]);
    printf("\n");
    
    return 0;
}
