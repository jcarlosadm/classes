#define BAIXA_PRIORIDADE 1
#define ALTA_PRIORIDADE 10

/**
 * retira alguém da fila de acordo com o contador passado
 * (a cada três de prioridade baixa, um de prioridade alta é atendido)
 * considera ainda que cada nó possui um dado 'priority' que
 * indica prioridade de acordo com as constantes declaradas acima
 *
 * se retornar -1, então ninguém daquela prioridade foi encontrado
 */
int QUEUE_dequeue_priority(Queue* queue, int* count){
    if(QUEUE_isEmpty(queue)){
        printf("queue is empty\n");
        return -1;
    }
    else{
        int value = -1;
            
        Node* current = queue->first;
        Node* previous = NULL;
        
        if(*count < 3){
            
            while(current!=NULL &&
                current->priority != BAIXA_PRIORIDADE){
                previous = current;
                current = current->nextNode;
            }
            
            if(!current){
                *count = 3;
                return -1;
            }
        }
        else{
            
            while(current!=NULL &&
                current->priority != ALTA_PRIORIDADE){
                previous = current;
                current = current->nextNode;
            }
            
            if(!current){
                *count = 0;
                return -1;
            }
        }
        
        value = current->item;
            
        if(!previous)
            queue->first = current->nextNode;
        else
            previous->nextNode = current->nextNode;
        
        free(current);
        
        if(*count < 3)
            *count = *count + 1;
        else
            *count = 0;
        
        return value;
    }
}
