//PROGRAM TO FIND WHETHER THE ENTERED NUMBER IS AN ARMSTRONG OR NOT
#include<cstdio>
#include<cstdlib>
//FUNTION PROTOTYPES
int count(int n);
int sop(int n);
int armstrong(int n);
//PROGRAM TO FIND WHETHER THE ENTERED NUMBER IS A PALINDROME 
//FUNCTION PROTOCOLS
int count(int num);
int *create(int num);
int palindrome(int num);
int checkpalindrome(int num);
//FUNCTION PROTOTYPES FOR PERFECT NUMBER
int perfect(int n);
int isperfect(int n);
int main(){
    int *choice = (int *)malloc(sizeof(int));
    int *num = (int *)malloc(sizeof(int));
    int *ans = (int *)malloc(sizeof(int));
    
   
    
    do{
        printf("MENU\n");
        printf("1.PALINDROME\n");
        printf("2.ARMSTRONG\n");
        printf("3.PERFECT NUMBER\n");
        printf("4.EXIT \n");
        printf("ENTER YOUR CHOICE :");
        scanf("%d",choice);
        
       
        switch(choice[0]){
            case 1:
            printf("ENTER A NUMBER TO CHECK WHETHER IT IS A PALINDROME OR NOT \n");
            scanf("%d",num);
            ans[0]=checkpalindrome(num[0]);
            if(ans[0]==1){
               printf("IT IS A PALINDROME \n");
            }else{
               printf("IT IS NOT A PALINDROME \n");
            }        
            break;
            case 2:
            printf("ENTER A NUMBER FOR CHECKING WHETHER ARMSTRONG OR NOT : ");
            scanf("%d",num);
            ans[0]=armstrong(num[0]);
            if(ans[0]==1){
               printf("THE ENTERED NUMBER IS AN ARMSTRONG NUMBER \n");
            }else{
               printf("THE ENTERED NUMBER IS NOT AN ARMSTRONG NUMBER \n");
            }  
            break;
            case 3:
            printf("ENTER A NUMBER TO TEST WHETHER PERFECT OR NOT : ");
            scanf("%d",num);
            ans[0] = isperfect(num[0]);
            if(ans[0]==1){
               printf("IT IS A PERFECT NUMBER \n");
            }else{
               printf("IT IS NOT A PERFECT NUMBER \n");
            }
              
            break;
            case 4:
            printf("EXITED SUCCESSFULL \n");
            break;
            default:
            printf("INVALID CHOICE TRY AGAIN !\n");
        }
    }while(choice[0]!=4);
    free(num);
    free(ans); 
    return 0; 
}
//FUNCTION DEFINITION FOR COUNTING THE NUMBER OF DIGITS
// int count(int n){
//     int *count1=(int*)malloc(sizeof(int));
//     while(n>0){
//         n=n/10;
//         count1[0]=count1[0]+1;
//     }
//     return count1[0];
//     free(count1);
// }
//FUNCTION DEFINITION TO SUM EACH DIGIT RAISED TO THE POWER OF COUNT
int sop(int n){
   int *i=(int *)malloc(sizeof(int));
   //int *n2=(int *)malloc(sizeof(int));
   int *n1=(int*)malloc(sizeof(int));
   int *sum=(int*)malloc(sizeof(int));
   int *product = (int *)malloc(sizeof(int));
   int *count1 = (int *)malloc(sizeof(int));
   count1[0]=count(n);
   sum[0]=0;
   while(n>0){
       n1[0]=n%10;
       product[0]=1;
       for(i[0]=0;i[0]<count1[0];i[0]++){
        product[0]=product[0]*n1[0];
        }
       sum[0]=sum[0]+product[0];
       n=n/10;
       
   } 
   return sum[0];
   free(i);
   free(n1);
   free(sum);
   free(product);
   free(count1);
}
//TO CHECK WHETHER THE NUMBER IS ARMSTONG 
int armstrong(int n){
    int *sum2 = (int *)malloc(sizeof(int));
    sum2[0]=sop(n);
    if(sum2[0]==n){
        return 1;
    }else{
        return 0;
    }
    free(sum2);
}

//FUNCTION TO COUNT THE NUMBER OF DIGITS IN ENTERED NUMBER
int count(int num){
    int * count1=(int*)malloc(sizeof(int));
    count1[0]=0;
    while(num>0){
        num = num/10;
        count1[0]=count1[0]+1;
    }
    return count1[0];
}
//CREATE A INTEGER CONTAINER TO STORE EACH DIGIT IN THE NUMBER IN REVERSE ORDER
int *create(int num){
    int *count1=(int *)malloc(sizeof(int));
    int *i = (int *)malloc(sizeof(int));
    count1[0]=count(num);
    int *arr=(int *)malloc(count1[0]*sizeof(int));
    for(i[0]=0;i[0]<count1[0];i[0]++){
        arr[i[0]]=num%10;
        num=num/10;
    }
    return arr;
    
}
//RETURN THE COUNT OF DIGITS IN THE NUMBER IF IT IS A PALINDROME
int palindrome(int num){
    int *count1=(int *)malloc(sizeof(int));
    count1[0]=count(num);
    int *i = (int *)malloc(sizeof(int));
    int *count2 = (int *)malloc(sizeof(int));
    count2[0]=0;
    int *ptr = (int *)malloc(count1[0]*sizeof(int));
    ptr = create(num);
    for(i[0]=0;i[0]<count1[0];i[0]++){
        if(ptr[i[0]]==ptr[count1[0]-i[0]-1]){
            count2[0]=count2[0]+1;
        }
    }  
    return count2[0];
}
//CHECK PALINDROME 
int checkpalindrome(int num){
    int *count1=(int *)malloc(sizeof(int));
    count1[0]=palindrome(num);
    int *count2 = (int *)malloc(sizeof(int));
    count2[0]=count(num);
    if(count1[0]==count2[0]){
        return 1;
    }else{
        return 0;
    }
}
//SUM = NUMBER IF IT IS PERFECT
int perfect(int n){
    int *sum = (int *)malloc(sizeof(int));
    int *i = (int *)malloc(sizeof(int));
    sum[0]=0;
    for(i[0]=1;i[0]<n;i[0]++){
        if(n%i[0]==0){
            sum[0]=sum[0]+i[0];
        }
    }
    return sum[0];
}
//CHECKING IF PERFECT 
int isperfect(int n){
    int *n1 = (int*)malloc(sizeof(int));
    n1[0]=perfect(n);
    if(n1[0]==n){
        return 1;
    }else{
        return 0;
    }
} 

