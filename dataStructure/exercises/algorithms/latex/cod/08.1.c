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
        
    
    left[n1]=INT_MIN; // ao invés de INT_MAX
    right[n2]=INT_MIN; // ao invés de INT_MAX
    
    i = 0;
    j = 0;
    for(k=begin;k<=end;k++){
        if(left[i]>=right[j]){ // ao invés de <=
            v[k]=left[i];
            i++;
        }
        else{
            v[k]=right[j];
            j++;
        }
    }
}
