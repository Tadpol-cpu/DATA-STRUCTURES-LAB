//IMPLEMENT LIST ADT USING ARRAY DATA STRUCTURE
#include<cstdio>
class list{
    private :
      int arr[5];
      int size;//current number of elements
    public :
      list(){size = 0;}//consrtuctor initialising empty list 
      //FUNCTION FOR INSERTION AT THE BEGINNING 
      void insertion_at_beginning(int num){
        if(size==5){
          printf("LIST IS FULL \n");
          return;
        }
        for(int i=size;i>0;i--){
          arr[i]=arr[i-1];
        }
        arr[0]=num;
        size++;
      }
      //FUNCTION FOR INSERTION AT THE END 
      void insertion_at_end(int num){
         if(size==5){
          printf("LIST IS FULL \n");
          return;
        }
        arr[size]=num;
        size++;
      }
      //FUNCTION TO INSERT AT A GIVEN POSITION 
      void insertion_at_pos(int pos,int num){
        if(size==5){
          printf("LIST IS FULL \n");
          return;
        }
        if(pos<0){
          printf("INVALID POSITION \n");
          return;
        }
        if(pos>size){
          insertion_at_end(num);
          return;
        }
        for(int i = size;i>pos;i--){
          arr[i]=arr[i-1];
        }
        arr[pos]=num;
        size++;

      }
      //DELETE AT THE BEGINNING 
      void del_at_beginning(){
        if(size==0){
          printf("LIST IS EMPTY \n");
          return;
        }
        
        for(int i=0;i<size-1;i++){
          arr[i]=arr[i+1];
        }
        size--;
        

      }
      //DELETE AT THE END 
      void del_at_end(){
        if(size==0){
          printf("LIST IS EMPTY \n");
          return;
        }
        size--;
      }
      //DELETE AT A GIVEN POSITION 
      void del_at_pos(int pos){
        if(size==0){
          printf("LIST IS EMPTY \n");
          return;
        }
        if(pos<0){
          printf("INVALID POSITION \n");
        }
        if(pos>size){
          del_at_end();
          return;
        }
        for(int i=pos;i<size-1;i++){
          arr[i]=arr[i+1];
        }
        size--;
      }
      //SEARCH FOR AN ELEMENT 
      void search(int num){
        if(size==0){
          printf("LIST IS EMPTY \n");
          return;
        }
        for(int i=0;i<size;i++){
          if(arr[i]==num){
            printf("ELEMENT FOUND IN INDEX %d \n",i);
            return;
          }
          printf("ELEMENT NOT FOUND \n");
          
        }
      }
      void display(){
        if(size==0){
          printf("LIST IS EMPTY \n");
          return;
        }
        printf("THE ELEMENTS ARE \n");
        for(int i=0;i<size;i++){
          printf("%d ",arr[i]);
        }
        printf("\n");
      }
      //ROTATE ARRAY BY K TIME TO THE RIGHT 
      void rotate(int k){
        if(size==0){
          printf("LIST IS EMPTY \n");
          return;
        }
        k = k%size;
        reverse(0,size-1);//REVERSE THE WHOLE ARRAY FIRST
        reverse(0,k-1);//REVERSE FIRST K ELEMENTS
        reverse(k,size-1);//REVERSE THE REMAINING 
    }
    void reverse(int start,int stop){
      while(start<stop){
        int temp = arr[start];
        arr[start]=arr[stop];
        arr[stop]=temp;
        start++;
        stop--;
      }
    }
};
int main(){
  list mylist;
  int choice,value,pos,k;
  do{
    printf("MENU\n");
    printf("\n1.INSERT AT THE BEGINNING \n2.INSERT AT THE END \n3.INSERT AT A GIVEN POSITION \n4.DELETE AT THE BEGINNING \n5.DELETE AT THE END \n6.DELETE AT A POSITION \n7.SEARCH AN ELEMENT \n8.DISPLAY THE LIST \n9.ROTATE \n10.EXIT \n");
    printf("ENTER YOU CHOICE \n");
    scanf("%d",&choice);
    switch(choice){
      case 1:
        printf("ENTER A VALUE \n");
        scanf("%d",&value);
        mylist.insertion_at_beginning(value);
        break;
      case 2:
        printf("ENTER A VALUE \n");
        scanf("%d",&value);
        mylist.insertion_at_end(value);
        break;
      case 3:
        printf("ENTER POSITION AND VALUE \n");
        scanf("%d %d",&pos,&value);
        mylist.insertion_at_pos(pos,value);
        break;
      case 4:
         mylist.del_at_beginning();
         break;
      case 5:
          mylist.del_at_end();
          break;
      case 6:
          printf("ENTER POSITION \n");
          scanf("%d",&pos);
          mylist.del_at_pos(pos);
          break;
      case 7:
           printf("ENTER SEARCH ELEMENT \n");
           scanf("%d",&value);
           mylist.search(value);
           break;
      case 8:
           mylist.display();
           break;
      case 9:
           printf("ENTER THE VALUE OF k FOR ROTAION \n");
           scanf("%d",&k);
           mylist.rotate(k);
           break;
      case 10:
           printf("SUCCEFULLY EXITED :) \n");
           break;
      default:
           printf("INCORRECT CHOICE ENTER AGAIN \n");
    }
  }while(choice!=10);

  return 0;

}
