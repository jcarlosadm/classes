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
