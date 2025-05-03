//PROGRAM TO IMPLEMENT ROUND ROBIN 
#include "roundrobin.h"
//DRIVER CODE
int main(){
   cll cll1;
   int choice,fixed_time,value;
   printf("ENTER THE FIXED TIME FOR EACH ACTION : ");
   scanf("%d",&fixed_time);
   do{
     printf("MENU \n");
     printf("1.INSERT PROCESS \n");
     printf("2.EXECUTE \n");
     printf("3.EXIT \n");
     printf("ENTER YOUR CHOICE : ");
     scanf("%d",&choice);
     switch(choice){
        case 1 :
        printf("ENTER THE TIME PERIOD FOR YOUR PROCESS : ");
        scanf("%d",&value);
        if(value<=0){
            printf("INVALID VALUE \n");
            break;
        }
        cll1.insert(value);
        break;
        case 2 :
        cll1.execute(fixed_time);
        cll1.display();
        break;
        case 3 :
        printf("EXITED SUCCESSFULLY :) \n");
        break;
        default :
        printf("INVALID CHOICE TRY AGAIN :)\n");
     }
   }while(choice!=3);
   return 0;

}
