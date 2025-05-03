#ifndef SORT_H
#define SORT_H
//DEFINITION FOR BUBBLE SORT
 inline void bubblesort(int arr[],int length){
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
inline void selectionsort(int arr[],int length){
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
inline void insertionsort(int arr[],int length){
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
#endif
