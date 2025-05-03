#include<cstdio>
#include "sort.h"
//FUNCTION PROTOTYPES
int linearsearch(int arr[],int length,int target);
int binarysearch(int arr[],int length,int target);

int main(){
    int choice,target;
    int length;
    printf("ENTER THE LENGTH OF THE ARRAY : ");
    scanf("%d",&length);
    int arr[length];
    for(int i=0;i<length;i++){
       printf("ENTER THE %dTH ELEMENT : ",i+1);
       scanf("%d",arr+i);
    }
    do{
        printf("MENU\n");
        printf("1.LINEAR SEARCH\n");
        printf("2.BINARY SEARCH\n");
        printf("3.EXIT \n");
        printf("ENTER YOUR CHOICE :");
        scanf("%d",&choice);
        
        printf("\n");
       
        switch(choice){
            case 1:
            printf("ENTER YOUR TARGET :");
            scanf("%d",&target);
            if(int index = linearsearch(arr,length,target);index!=-1){
                printf("ELEMENT FOUND IN INDEX : %d \n",index);
            }else{
                printf("ELEMENT NOT FOUND \n");
            }
            break;
            case 2:
            bubblesort(arr,length);
            printf("ENTER YOUR TARGET :");
            scanf("%d",&target);
            if(int index = binarysearch(arr,length,target);index!=-1){
                printf("ELEMENT FOUND IN INDEX : %d \n",index);
            }else{
                printf("ELEMENT NOT FOUND \n");
            }
            break;
            case 3:
            printf("EXITED SUCCESSFULLY \n");
            break;
            default:
            printf("INVALID CHOICE TRY AGAIN :(");
            
        }
    }while(choice!=3);
    return 0;
}
//FUNCTION DEFINITION FOR LINEAR SEARCH
int linearsearch(int arr[],int length,int target){
    for(int i = 0;i<length;i++){
        if(arr[i]==target){
            return i;
        }

    }
    return -1;//IF NOT FOUND
}
int binarysearch(int arr[],int length,int target){
    int low = 0,high = length -1;
    while(low<=high){
        int mid = low +(high-low)/2;
        if(arr[mid]==target){
            return mid;
        }
        if(arr[mid]<target){
            low = mid + 1;
        }else{
            high = mid -1;
        }
    }
    return -1;//WHEN NOT FOUND
}
