/**
 * Conta quantos ocorrências do primeiro caractere de item
 * ocorre em literal
 * Retorna a quantidade de ocorrência
 *
 * char* literal : string em que se verificará cada caractere
 * char* item : string onde o primeiro caractere é usado para
 *      comparação
 */
int countCharFreq(char* literal,char* item){
    if(literal[0] == 0)
        return 0;
    else{
        if(literal[0]==item[0])
            return 1 + countCharFreq(literal+1,item);
        else
            return countCharFreq(literal+1,item);
    }
}

/**
 * Preenche newCharLiteral a partir de literal, mas sem
 * o primeiro caractere de compare
 *
 * char* literal : sequência original de caracteres
 * char* newCharLiteral : sequência a ser preenchida
 * char* compare : sequência onde o primeiro caractere é
 *           o caractere de exclusão
 */
void fillNewChar(char* literal, char* newCharLiteral, char* compare){
    
    if(literal[0]==0){
        newCharLiteral[0]=0;
        return;
    }
    else{
        if(literal[0]!=compare[0]){
            newCharLiteral[0]=literal[0];
            fillNewChar(literal+1,newCharLiteral+1,compare);
        }
        else{
            fillNewChar(literal+1,newCharLiteral,compare);
        }
    }
    
}

/**
 * Cria uma lista de caracteres e a frequencia de cada um
 * Retorna o primeiro nó desta lista
 * 
 * char* literal : uma string literal contendo os caracteres
 * NodeCharFreq* first : lista de caracteres
 */
NodeCharFreq* listOfCharFreq(char* literal,int sizeLiteral, NodeCharFreq* first){
    
    if(literal[0] != 0){
        int totalFreq = countCharFreq(literal,literal);
        first = insertNodeCharFreq(first,literal,totalFreq);
        if((sizeLiteral-totalFreq) > 0){
            
            char* newCharLiteral = malloc(sizeof(sizeLiteral-totalFreq));
            
            fillNewChar(literal+1,newCharLiteral, literal);
            
            NodeCharFreq* newList = listOfCharFreq(newCharLiteral,sizeLiteral-totalFreq,first);
            free(newCharLiteral);
            return newList;
        }
        else
            return first;
        
    }
    else
        return first;
    
}
