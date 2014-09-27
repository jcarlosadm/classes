#include <stdio.h>

void swap(int *v1,int *v2){
    int i;
    i = *v1;
    *v1 = *v2;
    *v2 = i;
}

void bubblesort(int *v, int size) {
    
    int i,j,ord = 0;
    
    for (j = size - 1; j >= 0; j--) {
        ord = 0;
        for (i = 0; i < j; i++) {
            if (v[i] > v[i+1])
                swap(v+i, v+i+1);
            else
                ord++;
        }
        if(ord==j){
            printf("ordenado em j=%d\n",j);
            break;
        }
    }
}

int main()
{
    int v[] = {1,2,3,4};
    bubblesort(v,sizeof(v)/sizeof(int));
    
    return 0;
}
