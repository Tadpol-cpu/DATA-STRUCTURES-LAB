//PROGRAM TO CHECK WHETHER A STRING CONTAINING A COLLECTION OF '(' AND ')'ONLY ARE BALANCED OR NOT  
#include "stack_sll.h"
#include<cstdio>
#include<cstdlib>
//FUNCTION TO CHECK BALANCE USING STACK O(n)
bool checkbalancestack(char* str){
    stack st;
    for(int i=0;str[i]!='\0';i++){
        if(str[i]=='('){
            st.push(str[i]);
        }else if(str[i]==')'){
            if(st.isempty()) return false;
            st.pop();
        }else{
            return false;
        }
    }
    return st.isempty();
}
//FUNCTION TO CHECK WHETHER IT IS BALANCED USING COUNTER O(n) WITH O(1) EXTRA SPACE COMPLEXITY HENCE OPTIMAL AS NO MATTER THE SIZE OF THE STRING ONLY USES ONE INTEGER VARIABLE IN THE MEMORY 
bool checkbalancecounter(char *str){
    int count = 0;
    for(int i = 0;str[i]!='\0';i++){
        if(str[i]=='('){
            count++;
        }else if(str[i]==')'){
            count--;
        }else{
            return false;
        }
    }
    if(count == 0){
        return true;
    }else{
        return false;
    }
}
//DRIVER CODE 
int main(){
   int choice;
   char str[100];
   do{
    printf("MENU\n");
    printf("1.CHECK BALANCE\n");
    printf("2.EXIT\n");
    printf("ENTER YOUR CHOICE : ");
    scanf("%d",&choice);
    switch(choice){
       case 1 :
       printf("ENTER THE STRING WITH OPENING AND CLOSING PARENTHESIS ONLY : ");
       scanf("%s",str);
       if(checkbalancecounter(str)){
          printf("%s IS A BALANCED STRING OF PARENTHESIS \n",str);
          break;
       }else{
        printf("%s IS NOT A BALANCED STRING OF PARENTHESIS\n",str);
        break;
       }
       case 2 :
       printf("SUCCESSFULLY EXITED :) \n");
       break; 
       default :
       printf("INVALID CHOICE TRY AGAIN :( \n");
    }
   }while(choice!=2);
   return 0;
}
