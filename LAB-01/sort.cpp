#include<cstdio>
//PROTOTYPES
void bubblesort(int arr[],int length);
void selectionsort(int arr[],int length);
void insertionsort(int arr[],int length);
void printarray(int arr[],int length);
//DRIVER CODE
int main(){
    int choice;
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
        printf("1.BUBBLE SORT\n");
        printf("2.SELECTION SORT\n");
        printf("3.INSERTION SORT\n");
        printf("4.EXIT \n");
        printf("ENTER YOUR CHOICE :");
        scanf("%d",&choice);
        printf("\n");
       
        switch(choice){
            case 1:
            bubblesort(arr,length);
            printarray(arr,length);
            break;
            case 2:
            selectionsort(arr,length);
            printarray(arr,length);
            break;
            case 3:
            insertionsort(arr,length);
            printarray(arr,length);
            break;
            case 4:
            printf("EXITED SUCCESSFULLY \n");
            break;
            default:
            printf("INVALID CHOICE TRY AGAIN !\n");
        }
    }while(choice!=4);
    return 0;

}    
//DEFINITION FOR BUBBLE SORT
void bubblesort(int arr[],int length){
    for(int i=0;i<length-1;i++){
        for(int j=0;j<length-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
//DEFINITION FOR SELECTION SORT
void selectionsort(int arr[],int length){
    for(int i = 0;i<length-1;i++){
        int min = i;
        for(int j = i+1;j<length;j++){
           if(arr[j]<arr[min]){
            min = j;
           }
           
           
        }
        int temp = arr[min];
        arr[min]=arr[i];
        arr[i]=temp;
        
        
    }
}
//DEFINITION FOR INSERTION SORT 
void insertionsort(int arr[],int length){
    for(int i=0;i<length;i++){
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
           int temp = arr[j];
           arr[j]=arr[j-1];
           arr[j-1]=temp;
           j--;
        }

    }

}
//DEFINITION FOR PRINTING ARRAY
void printarray(int arr[],int length){
    printf("THE SORTED ARRAY ELEMENTS ARE : ");
    for(int i = 0;i<length;i++){
        
        printf("%d ",arr[i]);
    }
    printf("\n");
}
