/**
 * Extrai o vetor não visitado com o menor custo
 * retorna o valor do vetor com o menor custo
 * o vetor com o menor custo é configurado como visitado
 */
int extractMin(int *costs, int *visited){
    int count;
    int min=0;
    while(visited[min] && min<MAX_SIZE){
        min++;
    }
    for(count=min; count<MAX_SIZE; count++){
        if(!visited[count] && costs[count] <= costs[min]){
            min = count;
        }
    }
    visited[min] = 1;
    return min;
}
