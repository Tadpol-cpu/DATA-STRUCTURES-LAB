//EXPRESSION TREE MENU DRIVEN CODE IMPLEMENTATION USING EXPRESSIONTREE HEADER FILE
#include<cstdio>
#include "EXPRESSIONTREE.h"
//DRIVER CODE 
int main(){
    class Binarytree b;
    int choice;
    char postfix[100];
    do{
       printf("MENU \n");
       printf("1.POSTFIX EXPRESSION \n");
       printf("2.CONSTRUCT EXPRESSION TREE \n");
       printf("3.PREORDER \n");
       printf("4.INORDER \n");
       printf("5.POSTORDER \n");
       printf("6.EXIT \n");
       printf("ENTER YOU CHOICE : ");
       scanf("%d",&choice);
       switch(choice){
        case 1 :
        printf("ENTER THE POSTFIX EXPRESSION : ");
        scanf("%s",postfix);
        if(!b.isvalidpostfix(postfix)){
            printf("INVALID POSTFIX EXPRESSION TRY AGAIN \n");
        }
        break;
        case 2 :
        if(b.isvalidpostfix(postfix)){
            b.call_expressiontree(postfix);
        }else{
            printf("INVALID POSTFIX EXPRESSION TRY AGAIN \n");
        }
        break;
        case 3 :
        if(b.isvalidpostfix(postfix)){
            b.displaypreorder();
        }else{
            printf("INVALID POSTFIX EXPRESSION TRY AGAIN \n");
        }
        break;
        case 4 :
        if(b.isvalidpostfix(postfix)){
            b.displayinorder();
        }else{
            printf("INVALID POSTFIX EXPRESSION TRY AGAIN \n");
        }
        break;
        case 5 :
        if(b.isvalidpostfix(postfix)){
            b.displaypostorder();
        }else{
            printf("INVALID POSTFIX EXPRESSION TRY AGAIN \n");
        }
        break;
        case 6 :
        printf("SUCCESSFULLY EXITED :)\n");
        break;
        default :
        printf("INVALID CHOICE TRY AGAIN :(\n");
       }
    }while(choice!=6);
    return 0;
}
