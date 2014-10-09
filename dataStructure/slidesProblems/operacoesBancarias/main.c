#include<stdio.h>
#include "dStack.h"

int senha(DStack* stack,Cliente* cliente){

    printf("digite a senha: ");
    char senha[10];
    scanf("%10s",senha);
    
    if(checkSenha(cliente,senha)) return 1;
    else return 0;
}

int verificarSaldo(DStack* stack,Cliente* cliente){
    printf("valor atual na conta: R$ %.2f\n",getTotal(cliente));
    return 1;
}

int deposito(DStack* stack, Cliente* cliente){

    float value = -1;
    
    printf("valor na conta: R$ %.2f\n",getTotal(cliente));
    
    while(value<0){
        printf("digite um valor ou 0 para cancelar: ");
        scanf("%f",&value);
    }
    
    if(value==0){
        printf("operacao de deposito cancelada\n");
        return 1;
    }
    
    setTempDeposito(cliente,value);
    
    dStackPush(stack,senha);
    int result = dStackExecuteTopElement(stack,cliente);
    dStackPop(stack);
    if(!result){
        printf("senha nao confere\n");
        printf("operacao de deposito nao foi bem sucedida\n");
        return 0;
    }
    
    setTotal(cliente,getTotal(cliente)+value);
    setTempDeposito(cliente,0);
    
    
    printf("operacao de deposito bem sucedida\n");
    return 1;
}

int checkValue(DStack* stack,Cliente* cliente){
    
    if(getTempSaque(cliente) > getTotal(cliente)){
        printf("nao possui saldo suficiente\n");
        return 0;
    }
    
    dStackPush(stack,senha);
    int result = dStackExecuteTopElement(stack,cliente);
    dStackPop(stack);
    if(!result){
        printf("senha nao confere\n");
        return 0;
    }
    return 1;
    
}

int saque(DStack* stack,Cliente* cliente){
    
    float value = -1;
    
    printf("valor na conta: R$ %.2f\n",getTotal(cliente));
    
    if(getTotal(cliente)<=0){
        printf("nao possui saldo suficiente\n");
        return 0;
    }
    
    while(value<0){
        printf("escolha o valor ou digite 0 para cancelar: ");
        scanf("%f",&value);
    }
    
    if(value==0){
        printf("operacao cancelada\n");
        return 1;
    }
    
    setTempSaque(cliente,value);
    dStackPush(stack,checkValue);
    int result = dStackExecuteTopElement(stack,cliente);
    dStackPop(stack);
    if(!result){
        printf("operacao de saque nao foi bem sucedida\n");
        return 0;
    }
    
    setTotal(cliente,getTotal(cliente)-getTempSaque(cliente));
    setTempSaque(cliente,0);
    
    printf("operacao de saque bem sucedida\n");
    return result;
    
}

void mainOperation(DStack* stack,Cliente* cliente){

    int count;
    int intro = 0;
    for(count=0;count<3 && intro==0;count++){
        dStackPush(stack,senha);
        intro = dStackExecuteTopElement(stack,cliente);
        dStackPop(stack);
    }
    
    if(!intro){
        printf("maximo de tres tentativas atingido. saindo do sistema\n");
        return;
    }
    
    
    printf("escolha uma operacao: 1 para saque, 2 para deposito, 3 para saldo, e 0 para sair: ");
    int choice = -1;
    int result = 0;
    
    scanf("%d",&choice);
    
    while(choice){
        
        if(choice>0 && choice <4){
            switch(choice){
            case 1:
                dStackPush(stack,saque);
                break;
            case 2:
                dStackPush(stack,deposito);
                break;
            case 3:
                dStackPush(stack,verificarSaldo);
                break;
            }
            result = dStackExecuteTopElement(stack,cliente);
            dStackPop(stack);
        }
        printf("escolha uma operacao: 1 para saque, 2 para deposito, 3 para saldo, e 0 para sair: ");
        scanf("%d",&choice);
    }
    
    printf("bye\n");
}

int main()
{
    
    Cliente* cliente = createCliente(300,"hello");
    
    DStack* stack = dStackCreateStack();
    
    mainOperation(stack,cliente);
    
    cliente = freeCliente(cliente);
    
    stack = dStackFree(stack);
    
    return 0;
}
