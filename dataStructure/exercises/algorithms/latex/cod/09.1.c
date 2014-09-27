void bubblesort(int *v, int size) {
    
    int i,j,ord = 0;
    
    for (j = size - 1; j >= 0; j--) {
        ord = 0;
        for (i = 0; i < j; i++) {
            if (v[i] > v[i+1])

