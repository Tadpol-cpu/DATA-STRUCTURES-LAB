//TO USE THE OPTIMAL SOLUTION TO IMPLEMENT STRING BASED PROGRAM GIVEN BELOW 
//OPTIMAL = STACK BECAUSE THIS USED LAST IN FIRST OUT MECHANISM FREQUENTLY 
#include<cstdio>
#include "stack.h"
//DRIVER CODE 
int main(){
    char input[100];
    class stack s;
    printf("ENTER THE STRING  : ");
    scanf("%s",input);
    //ITERATING THE INPUT STRING FOR PUSHING AND POPING APPROPRIATELY 
    for(int i = 0;input[i]!='\0';i++){
        if(input[i]=='+'){
            if(!s.isempty()) s.pop();
        }else{
            s.push(input[i]);
        }
    }
    int index = 0;
    char result[100];
    //TO STORE IT IN AN ARRAY
    while(!s.isempty()){
        result[index++]=s.pop();
    }
    result[index]='\0';
    int count = 0;
    int i = 0;
    //COUNT THE NUMBER OF ELEMENTS IN THE STRING IN ORDER TO REVERSE IT 
    while(result[i]!='\0'){
        count++;
        i++;
    }
    //REVERSING THE STRING TO GET THE CORRECT ORDER 
    for(int i = count;i>=0;i--){
        printf("%c",result[i]);
    }
    return 0;
}
