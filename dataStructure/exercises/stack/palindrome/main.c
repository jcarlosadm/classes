#include <stdio.h>
#include <string.h>
#include "dStack.h"

int isPalindrome(char* name, int sizeName){
    
    int result = 0;
    
    DStack* stack = dStackCreateStack();
    if(!stack)return 0;
    
    int count;
    for(count=0;count<sizeName-1;count++){
        dStackPush(stack,name[count]);
    }
    
    char name2[sizeName];
    name2[sizeName-1] = 0;
    
    for(count=0;count < sizeName-1;count++){
        name2[count] = dStackPop(stack);
    }
    
    if(strcmp(name,name2)==0) result = 1;
    else result = 0;
    
    stack = dStackFree(stack);
    
    return result;
}

int main()
{
    char name[] = "sopapos";
    
    if(isPalindrome(name,sizeof(name)/sizeof(char)))
        printf("%s is a palindrome\n",name);
    else
        printf("%s is not a palindrome\n",name);
    
    return 0;
}
