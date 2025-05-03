//TO IMPLEMENT LIST ADT WITH BELOW OPERATIONS USING sll2.h header file
#include "sll2.h"
int main(){
    sll sll1,sll2,sll3;
    int choice,value;
    do{
        printf("\nMENU\n");
        printf("1.INSERT INTO LIST 1 \n");
        printf("2.INSERT INTO LIST 2 \n");
        printf("3.MERGE LIST1 AND LIST2 \n");
        printf("4.DISPLAY \n");
        printf("5.EXIT \n");
        printf("ENTER YOUR CHOICE : ");
        scanf("%d",&choice);
        switch(choice){
            case 1 :
            printf("ENTER THE VALUE TO BE INSERTED IN LIST 1 : ");
            scanf("%d",&value);
            sll1.insert_ascending(value);
            break;
            case 2 :
            printf("ENTER THE VALUE TO BE INSERTED IN LIST 2 : ");
            scanf("%d",&value);
            sll2.insert_ascending(value);
            break;
            case 3 :
            sll3.mergelists(sll1,sll2);
            printf("SUCCESSFULLY MERGED \n");
            break;
            case 4 :
            sll3.display();
            break;
            case 5 :
            printf("EXITED SUCCESSFULLY :) \n");
            break;
            default :
            printf("INVALID CHOICE PLEASE TRY AGAIN :( \n ");

        }

    }while(choice!=5);
    return 0;
}
